// problem link --> https://leetcode.com/problems/evaluate-reverse-polish-notation/

// my solution link --> https://leetcode.com/problems/evaluate-reverse-polish-notation/discuss/2922041/C%2B%2B-oror-Short-and-Simple-oror-Easy

#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> st;
        for(string s: tokens) {
            if(s == "+") {
                ll val = st.top();st.pop();
                val += st.top(); st.pop();
                st.push(val);
            }    
            else if(s =="-") {
                ll val = st.top(); st.pop();
                ll val1 = st.top(); st.pop();
                st.push(val1 - val);
            }
            else if(s == "*") {
                ll val = st.top(); st.pop();
                val *= st.top(); st.pop();
                st.push(val);
            }
            else if(s == "/") {
                ll val = st.top(); st.pop();
                ll val1 = st.top();st.pop();
                st.push(val1/val);
            }
            else st.push(stoi(s));
        }
        return (int)st.top();
    }
};