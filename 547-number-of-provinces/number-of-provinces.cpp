class Solution {

    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int node) {
        vis[node] = true;
        int n=isConnected.size();

        for(int i=0; i<n; i++) {
            if(!vis[i] && isConnected[node][i]) {
                dfs(isConnected, vis, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        int n=isConnected.size();

        vector<bool> vis(n);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                provinces++;
                dfs(isConnected, vis, i);
            }
        }
        return provinces;
    }
};