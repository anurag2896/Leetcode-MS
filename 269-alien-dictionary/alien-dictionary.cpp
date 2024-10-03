class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n=words.size();
        string ans="";

        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indeg;
        for(auto word:words) {
            for(auto c:word) {
                if(adjList.find(c)==adjList.end()) {
                    adjList[c] = {};
                    indeg[c] = 0;
                }
            }
        }

        for(int i=0; i<n-1; i++) {
            string curr = words[i];
            string next = words[i+1];

            int len = min(curr.size(), next.size());
            bool foundMismatch = false;
            for(int j=0; j<len; j++) {
                if(curr[j] != next[j]) {
                    foundMismatch = true;
                    adjList[curr[j]].push_back(next[j]);
                    indeg[next[j]]++;
                    break;
                }
            }

            if(!foundMismatch && curr.size() > next.size())
                return "";
        }

        queue<char> q;
        for(auto ele:indeg) {
            if(ele.second==0) {
                q.push(ele.first);
            }
        }

        while(!q.empty()) {
            char node = q.front();
            ans+=node;
            q.pop();

            for(auto neighbor:adjList[node]) {
                indeg[neighbor]--;
                if(indeg[neighbor]==0) {
                    q.push(neighbor);
                }
            }
        }

        if(indeg.size() != ans.size())
            return "";
        
        return ans;
    }
};