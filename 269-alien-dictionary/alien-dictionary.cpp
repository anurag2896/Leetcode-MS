class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indeg;

        for(auto word:words) {
            for(auto ch:word) {
                indeg[ch] = 0;
                adjList[ch] = {};
            }
        }

        int total_words = words.size();
        for(int i=0; i<total_words-1; i++) {
            bool foundMismatch = false;
            int min_len = min(words[i].size(), words[i+1].size());
            for(int j=0; j<min_len; j++) {
                if(words[i][j]!=words[i+1][j]) {
                    foundMismatch = true;
                    indeg[words[i+1][j]]++;
                    adjList[words[i][j]].push_back(words[i+1][j]);
                    break;
                }
            }

            if(!foundMismatch && words[i].size() > words[i+1].size())
                return "";
        }

        queue<char> q;
        for(auto ele:indeg) {
            if(ele.second==0) {
                q.push(ele.first);
            }
        }

        string topo;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            topo+=top;

            for(auto neighbor:adjList[top]) {
                indeg[neighbor]--;
                if(indeg[neighbor]==0) {
                    q.push(neighbor);
                }
            }
        }

        if(topo.size()!=adjList.size())
            return "";
        
        return topo;
    }
};