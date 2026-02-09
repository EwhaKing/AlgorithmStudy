#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            //반복문 대신 for(char ch:s)
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
            }
            //단점: push하고 나서도 switch문 기웃거림
            //해결: if, else 로 열린, 닫힌 괄호 명확히 구분
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
            
            //st.empty()확인과 pop이 반복되니까 묶자:
            //닫힌 괄호일 때 st.empty()->false, 그 뒤로 st.pop();
            }
        }
        if(st.empty())return true;
        else return false;

        //== return st.empty();
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



        