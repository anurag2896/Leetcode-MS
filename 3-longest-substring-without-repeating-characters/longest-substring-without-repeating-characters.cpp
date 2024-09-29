class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int l=0, ans=0;
        for(int i=0; i<s.size(); i++) {
            freq[s[i]]++;
            while(l<i && freq[s[i]]>1) {
                freq[s[l]]--;
                l++;
            }

            ans = max(ans, i-l+1);
        }
        return ans;
    }
};