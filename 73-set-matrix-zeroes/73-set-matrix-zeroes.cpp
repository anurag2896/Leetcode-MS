class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fr = 1, n = matrix.size(), m=matrix[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==0) {
                    if(i==0) {
                        fr=0;
                    } else {
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                } 
            }
        }
        
        // cout<<"printing"<<endl ;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        //column wise
        for(int i=1; i<m; i++) {
            if(matrix[0][i]==0) {
                for(int j=1; j<n; j++) {
                    matrix[j][i]=0;
                }
            }
        }
        
        //row wise
        for(int i=1; i<n; i++) {
            if(matrix[i][0]==0) {
                for(int j=1; j<m; j++) {
                    matrix[i][j]=0;
                }
            }
        }
        
        // cout<<"printing"<<endl ;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        if(matrix[0][0]==0) {
            for(int i=0; i<n; i++) {
                matrix[i][0]=0;
            }
        }
        
        if(fr==0) {
            for(int i=0; i<m; i++) {
                matrix[0][i]=0;
            }
        }
        
        
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
};