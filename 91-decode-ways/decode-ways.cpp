class Solution {

    int helper(string s, unordered_map<string, char>& m, int index, vector<int>& dp) {
        int n=s.size();

        if(index==n) {
            return 1;
        }

        if(index > n)
            return 0;

        if(dp[index]!=-1)
            return dp[index];

        int takeOne = 0;
        if(m.find(s.substr(index, 1))!=m.end()) {
            takeOne = helper(s, m, index+1, dp);
        }
        int takeTwo = 0;
        if(m.find(s.substr(index, 2))!=m.end()) {
            takeTwo = helper(s, m, index+2, dp);
        }

        return dp[index] = takeOne + takeTwo;
    }

public:
    int numDecodings(string s) {
        unordered_map<string, char> m;
        int n=s.size();

        vector<int> dp(n, -1);
        for(int i=0; i<26; i++) {
            m[to_string(i+1)] = 'A'+i;
        }

        int ans =0;
        ans = helper(s, m, 0, dp);
        return ans;
    }
};