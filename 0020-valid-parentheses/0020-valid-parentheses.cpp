#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
            }
            switch(s[i]){
                case '}':
                if(st.empty() || st.top()!='{') return false;
                else st.pop();
                break;

                case ')':
                if(st.empty() || st.top()!='(') return false;
                else st.pop();
                break;

                case ']':
                if(st.empty() || st.top()!='[') return false;
                else st.pop();
                break;

            }
        }
        if(st.empty())return true;
        else return false;
    }

};

//공부기록
//[스택] LIFO
//설정: #include <stack>
//생성: stack<char> st;
//사용: st.push(val), st.pop(), st.top(), st.empty()

//[switch문] 
//switch(val){
//     case val1:
//         ...
//         break;
//     case val2:
//         ...
//         break;
// }



        