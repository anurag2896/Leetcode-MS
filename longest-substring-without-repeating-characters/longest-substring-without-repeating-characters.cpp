class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0, n=s.size(), l=0;
        unordered_map<char, int> m;
        
        for(int i=0; i<n; i++){
            while(m[s[i]]==1) {
                m[s[l++]]--;
            }
            m[s[i]]++;
            ans = max(ans, i-l+1);
        }
        
        return ans;
    }
};