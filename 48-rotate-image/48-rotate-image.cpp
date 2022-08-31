class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i<j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
                // if(j<=i)
                //     swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void ultapulta(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
    
    void print(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        // print(matrix);
        ultapulta(matrix);
    }
};