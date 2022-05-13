class Solution {
public:
    bool check(vector<int> ref, vector<int> m) {
        for(int i=0; i<128; i++) {
            if(m[i]<ref[i])
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        vector<int> ref(128, 0), m(128, 0);
        int n=s.size(), ts=t.size();
        if(ts>n)
            return "";
        
        for(auto c:t)
            ref[c]++;
        
        int start=0, end=0;
        string ans="";
        // cout<<"printing till here 1 "<<endl;
        while(end<n) {
            if(!check(ref, m)) {
                m[s[end]]++;
                end++;
            } else {
                if(ans=="" || end-start < ans.size())
                    ans = s.substr(start, end-start);
                m[s[start]]--;
                start++;
            }
        }
        
        // cout<<"printing till here "<<endl;
        
        while(start<end && check(ref, m)) {
            if(ans=="" || end-start < ans.size())
                ans = s.substr(start, end-start);
            m[s[start]]--;
            start++;
        }
        
        return ans;
    }
};