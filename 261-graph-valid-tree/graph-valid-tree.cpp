class Solution {

    bool isCyclic(vector<vector<int>>& adjList, int node, int parent, vector<bool>& vis) {
        vis[node] = true;
    
        for(auto neighbor:adjList[node]) {
            if(!vis[neighbor]) {
                if(isCyclic(adjList, neighbor, node, vis))
                    return true;
            } else {
                if(neighbor!=parent)
                    return true;
            }
        }
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int components=0;
        vector<vector<int>> adjList(n);
        vector<bool> vis(n, false);

        for(auto e:edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                components++;
                if(components > 1)
                    return false;
                
                if(isCyclic(adjList, i, -1, vis))
                    return false;
            }
        }
        return true;
    }
};