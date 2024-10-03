class Solution {

    // along main diagonal
    void transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i>j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    }

    // swap vertically
    void mirror(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        mirror(matrix);
    }
};