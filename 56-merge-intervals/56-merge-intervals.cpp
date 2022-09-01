class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==0)
            return ans;
        
        sort(intervals.begin(), intervals.end());
        
        for(auto i:intervals) {
            if(ans.size()==0)
                ans.push_back(i);
            else {
                int lastEnd = ans.back()[1];
                if(i[0]>lastEnd) {
                    ans.push_back(i);
                } else {
                    ans.back()[1] = max(lastEnd, i[1]);
                }
            }
        }
        
        return ans;
    }
};