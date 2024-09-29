class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto word:strs) {
            string temp = word;
            sort(temp.begin(), temp.end());
            m[temp].push_back(word);
        }

        vector<vector<string>> ans;
        for(auto ele:m) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};