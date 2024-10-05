class Solution {

    bool isPalindrome(string word, int l, int r) {
        while(l<r) {
            if(word[l]!=word[r]) 
                return false;
            l++;
            r--;
        }
        return true;
    }

    void helper(vector<vector<string>>& ans, string s, int start, vector<string>& temp) {
        int n=s.size();

        if(start==n) {
            ans.push_back(temp);
            return;
        }

        for(int i=start; i<n; i++) {
            // for(int j=i; j<n; j++) {
                if(isPalindrome(s, start, i)) {
                    temp.push_back(s.substr(start, i-start+1));
                    helper(ans, s, i+1, temp);
                    temp.pop_back();
                }
            // }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        helper(ans, s, 0, temp);
        return ans;
    }
};