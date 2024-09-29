class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l=0, ans=0, max_freq=0;
        for(int i=0; i<s.size(); i++) {
            freq[s[i]-'A']++;
            max_freq = max(max_freq, freq[s[i]-'A']);
            while(l<i && i-l+1-max_freq > k) {
                freq[s[l]-'A']--;
                l++;
            }

            ans = max(ans, i-l+1);
        }
        return ans;
    }
};