// problem link --> https://leetcode.com/problems/implement-queue-using-stacks/



class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int val=st1.top();
        st1.pop();
        return val;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
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

// another approach

stack<int> s1, s2;
void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    // Your Code       
    while(s1.size()) {
        s2.push(s1.top()); s1.pop();
    }
    int res = s2.size() ? s2.top() : -1;
    if(s2.size()) s2.pop();
    while(s2.size()) {
        s1.push(s2.top()); s2.pop();
    }
    return res;
}
