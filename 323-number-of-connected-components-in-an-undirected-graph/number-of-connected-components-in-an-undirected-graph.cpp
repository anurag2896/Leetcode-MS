class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if(parent[u]==u)
            return u;
        return parent[u]=findParent(parent[u]);
    }

    void doUnion(int u, int v) {
        int fu = findParent(u);
        int fv = findParent(v);

        if(fu==fv)
            return;
        
        if(size[fu]<size[fv]) {
            size[fv] += size[fu];
            parent[fu] = fv;
        } else {
            size[fu] += size[fv];
            parent[fv] = fu;
        }
    }

    bool areUnion(int u, int v) {
        return findParent(u) == findParent(v);
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto edge:edges) {
            if(!dsu.areUnion(edge[0], edge[1])) {
                n--;
                dsu.doUnion(edge[0], edge[1]);
            }
        }

        return n;
    }
};