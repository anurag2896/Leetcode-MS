class Solution {

    bool helper(string s, unordered_set<string>& st, int index, vector<int>& dp) {
        int n=s.size();

        if(index==s.size())
            return true;

        if(dp[index]!=-1)
            return dp[index];
        
        for(int i=index; i<s.size(); i++) {
            if(st.find(s.substr(index, i-index+1))!=st.end() && helper(s, st, i+1, dp))
                return dp[index] = true;
        }
        return dp[index] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return helper(s, st, 0, dp);
    }
};