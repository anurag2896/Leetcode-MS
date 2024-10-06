class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minWordLen = 1e9;
        for(auto word:strs) {
            int len = word.size();
            minWordLen = min(minWordLen, len);
        }

        string prefix = "";
        for(int i=0; i<minWordLen; i++) {
            char character = strs[0][i];
            for(int j=1; j<strs.size(); j++) {
                if(strs[j][i]!=character) {
                    return prefix;
                }
            }
            prefix += character;
        }

        return prefix;
    }
};