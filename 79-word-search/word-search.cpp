class Solution {

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string word, int x, int y, int index) {
        int m=board.size(), n=board[0].size();

        if(index==word.size()) {
            return true;
        }

        if(x<0 || y<0 || x>=m || y>=n || vis[x][y] || board[x][y]!=word[index]) {
            return false;
        }

        vis[x][y] = true;

        if(dfs(board, vis, word, x+1, y, index+1) ||
            dfs(board, vis, word, x-1, y, index+1) ||
            dfs(board, vis, word, x, y-1, index+1) ||
            dfs(board, vis, word, x, y+1, index+1))
            return true;
            
        vis[x][y] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]==word[0]) {
                    if(dfs(board, vis, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};