class Solution {
public:
    int helper(string op, int a, int b) {
        if(op=="+")
            return a+b;
        if(op=="-")
            return a-b;
        if(op=="*")
            return a*b;
        else
            return a/b;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n=tokens.size();
        
        int a, b;
        unordered_set<string> se = {"+", "-", "*", "/"};
        for(int i=0; i<n; i++) {
            if(se.find(tokens[i])==se.end()) {
                // cout<<stoi(tokens[i])<<endl;
                s.push(stoi(tokens[i]));
                // cout<<s.top()<<endl;
            } else {
                b=s.top();
                s.pop();
                a=s.top();
                s.pop();
                // cout<<"values "<<a<<" "<<b<<endl;
                s.push(helper(tokens[i], a, b));
            }
        }
        
        return s.top();
    }
};