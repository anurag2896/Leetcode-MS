class Solution {

    void helper(vector<string>& ans, string temp, int open, int close) {
        if(close==0) {
            ans.push_back(temp);
            return;
        }

        if(open)
            helper(ans, temp+"(", open-1, close);
        if(close > open)
            helper(ans, temp+")", open, close-1);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", n, n);
        return ans;
    }
};