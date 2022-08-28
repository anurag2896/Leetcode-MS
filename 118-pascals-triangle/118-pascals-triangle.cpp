class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1; i<=numRows; i++) {
            vector<int> temp(i, 1);
            if(i>2) {
                auto last = result.back();
                int len = last.size();
                for(int i=1; i<len; i++) {
                    int sum = last[i]+last[i-1];
                    temp[i] = sum;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};