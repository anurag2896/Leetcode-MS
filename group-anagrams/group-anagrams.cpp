class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for(auto s:strs) {
            string word = s;
            sort(word.begin(), word.end());
            if(m.find(word)!=m.end())
                m[word].push_back(s);
            else
                m[word] = {s};
        }
        
        vector<vector<string>> ans;
        for(auto ele:m) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};