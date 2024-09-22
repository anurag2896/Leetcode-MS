class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(260, 0);
        int n=s.size();

        int max_freq = 0, l=0, ans=0;
        for(int i=0; i<n; i++) {
            freq[s[i]]++;
            max_freq = max(max_freq, freq[s[i]]);
            while(i-l+1 - max_freq > k) {
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};