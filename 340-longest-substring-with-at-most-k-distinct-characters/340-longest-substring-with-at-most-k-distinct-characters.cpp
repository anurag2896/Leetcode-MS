class Solution {
public:
    int helper(vector<int> m) {
        int ans=0;
        for(auto i:m) {
            if(i>0)
                ans++;
        }
        return ans;
    }
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> m(128, 0);
        int left=0, n=s.size(), maxlen=0;
        for(int i=0; i<n; i++) {
            m[s[i]]++;
            while(helper(m)>k) {
                m[s[left]]--;
                left++; 
            }
            maxlen = max(i-left+1, maxlen);
        }
        return maxlen;
    }
};