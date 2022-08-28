class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstRow=1, n=matrix.size(), m=matrix[0].size();
        // traversing all but the first column
        
        if(matrix[0][0]==0)
            firstRow = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0)
                    continue;
                if(matrix[i][j]==0) {
                    if(i==0)
                        firstRow = 0;
                    else if(i!=0 || j!=0) {
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }   
                }
            }
        }
        
        // column wise
        for(int i=1; i<m; i++) {
            // cout<<"here"<<i<<" "<<n<<" - ";
            if(matrix[0][i]==0) {
                // cout<<"inside col"<<i<<endl;
                for(int j=1; j<n; j++) {
                    matrix[j][i]=0;
                }
            }
        }
        
        // row wise
        for(int i=1; i<n; i++) {
            if(matrix[i][0]==0) {
                for(int j=1; j<m; j++) {
                    matrix[i][j]=0;
                }
            }
        }
        
        if(matrix[0][0]==0) {
            for(int i=1; i<n; i++) {
                matrix[i][0]=0;
            }
        }
        
        if(firstRow==0) {
            for(int i=0; i<m; i++) {
                matrix[0][i]=0;
            }
        }
        
    }
};