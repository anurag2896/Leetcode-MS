class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        vector<unordered_set<char>> row(9), col(9), box(9);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                char num = board[i][j];
                if(num!='.') {
                    if(row[i].find(num)!=row[i].end())
                        return false;
                    row[i].insert(num);

                    if(col[j].find(num)!=col[j].end())
                        return false;
                    col[j].insert(num);

                    int index = (i/3)*3 + (j/3);
                    if(box[index].find(num)!=box[index].end())
                        return false;
                    box[index].insert(num);
                }
            }
        }

        return true;
    }
};