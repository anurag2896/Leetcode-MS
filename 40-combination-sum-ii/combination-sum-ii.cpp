class Solution {

vector<vector<int>> ans;

void dfs(vector<int>& candidates, vector<int>& temp, int target, int start) {
    if(target<0)
        return;
    
    if(target==0) {
        ans.push_back(temp);
        return;
    }

    for(int i=start; i<candidates.size(); i++) {
        if(i>start && candidates[i]==candidates[i-1])
            continue;

        temp.push_back(candidates[i]);
        dfs(candidates, temp, target-candidates[i], i+1);
        temp.pop_back();
    }
}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, temp, target, 0);
        return ans;
    }
};