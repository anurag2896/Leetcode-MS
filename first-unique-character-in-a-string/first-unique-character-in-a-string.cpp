class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        int n=s.size();
        for(int i=0; i<n; i++) {
            if(m.find(s[i])==m.end()) {
                m[s[i]] = {i, 1};
            } else {
                m[s[i]].second++;
            }
        }
        
        int ans=-1;
        for(auto ele:m) {
            // cout<<ele.first<<" "<<ele.second.first<<" "<<ele.second.second<<endl;
            if(ele.second.second==1 && (ans==-1 || ele.second.first<ans))
                ans=ele.second.first;
        }
        
        return ans;
    }
};