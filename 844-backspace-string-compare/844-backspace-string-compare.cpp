class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string ns="", nt="";
        for(auto c:s) {
            if(c=='#') {
                if(!st.empty())
                    st.pop();
            }
            else {
                st.push(c);
            }
        }
        
        while(!st.empty()) {
            ns+=st.top();
            st.pop();
        }
        
        for(auto c:t) {
            if(c=='#') {
                if(!st.empty())
                    st.pop();
            }
            else {
                st.push(c);
            }
        }
        
        while(!st.empty()) {
            nt+=st.top();
            st.pop();
        }
        
        if(ns.compare(nt)==0)
            return true;
        return false;
    }
};