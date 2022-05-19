class Solution {
public:
    bool helper(vector<int> m) {
        for(auto i:m) {
            if(i>1)
                return false;
        }
        return true;
    }
    
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int n=s.size(), left=0, maxlen=0;
        for(int i=0; i<n; i++) {
            m[s[i]]++;
            while(!helper(m)) {
                m[s[left++]]--;
            }
            maxlen = max(maxlen, i+1-left);
        }
        return maxlen;
    }
};