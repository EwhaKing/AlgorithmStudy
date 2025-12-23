#include <stack>
using namespace std;
class MyQueue {
private: 
    stack <int> st;
    stack <int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int val;
        if(st2.empty()){
            while(!st.empty()){
                st2.push(st.top()); 
                //c++ 스택은 pop의 반환값 없음
                st.pop();
            }
        }
        val=st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st.empty()){
                st2.push(st.top()); 
                //c++ 스택은 pop의 반환값 없음
                st.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return (st2.empty()&& st.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */