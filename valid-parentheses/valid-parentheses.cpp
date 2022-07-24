class Solution {
public:
    bool areSame(char open, char close) {
        if(open=='(' && close==')')
            return true;
        else if(open=='{' && close=='}')
            return true;
        else if(open=='[' && close==']')
            return true;
        else
            return false;
    }
    
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0; i<n; i++) {
           if(s[i]=='(' || s[i]=='{' || s[i]=='[')
               st.push(s[i]);
            else {
                if(st.empty())
                    return false;
                char top = st.top();
                // cout<<top<<" "<<s[i]<<endl;
                st.pop();
                if(!areSame(top, s[i]))
                    return false;
            }
        }
        // cout<<"here";
        if(!st.empty())
            return false;
        return true;
    }
};