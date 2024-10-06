class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st; //index of open brackets
        int n=s.size();

        for(int i=0; i<n; i++) {
            if(s[i]=='(') {
                st.push(i);
            } else if(s[i]==')'){
                int openIndex = st.top();
                st.pop();
                reverse(s.begin()+openIndex+1, s.begin()+i);
            }
        }

        string ans="";
        for(auto c:s) {
            if(c=='(' || c==')')
                continue;
            ans+=c;
        }
        return ans;
    }
};