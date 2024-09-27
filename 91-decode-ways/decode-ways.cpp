class Solution {

    int dfs(string s, int i, vector<int>& dp) {
        int n=s.size();

        if(i==n) {
            return 1;
        }
        if(s[i]=='0')
            return 0;

        if(dp[i]!=-1)
            return dp[i];


        int takeOne = dfs(s, i+1, dp);
        int takeTwo = 0;
        if(i+2 <= n && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
            takeTwo = dfs(s, i+2, dp);

        return dp[i] = takeOne + takeTwo;
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return dfs(s, 0, dp);
    }
};