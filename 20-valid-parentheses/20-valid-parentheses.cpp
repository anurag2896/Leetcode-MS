class Solution {
public:
    bool check(char c, char o) {
        if(c=='(' && o==')' || c=='[' && o==']' || c=='{' && o=='}')
            return true;
        return false;
            
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
                st.push(s[i]);
            } else {
                if(st.empty())
                    return false;
                if(check(st.top(), s[i]))
                    st.pop();
                else
                    return false;
            }
        }
        if(!st.empty())
            return false;
        
        return true;
    }
};