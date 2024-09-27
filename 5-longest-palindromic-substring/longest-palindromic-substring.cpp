class Solution {

    string helper(string s, int l, int r) {
        int n=s.size();
        while(l>=0 && r<n && s[l]==s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }

public:
    string longestPalindrome(string s) {
        int n=s.size();
        string odd="", even="", ans="";
        for(int i=0; i<n; i++) {
            odd = helper(s, i, i);
            even = helper(s, i, i+1);

            if((odd.size() > ans.size()) || (even.size() > ans.size())) {
                if(odd.size() > even.size())
                    ans = odd;
                else
                    ans = even;
            }
        }
        return ans;
    }
};