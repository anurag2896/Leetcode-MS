class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int i=0, j=m-1;
        while(i<n && j>=0 && matrix[i][j]!=target) {
            if(matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        if(j<0 || i>=n)
            return false;
        return true;
    }
};