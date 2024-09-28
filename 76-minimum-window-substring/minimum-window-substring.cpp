class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        
        int count=t.size();
        unordered_map<char, int> m;
        for(auto c:t) {
            m[c]++;
        }

        int index=-1, min_len=s.size(), l=0;
        for(int i=0; i<s.size(); i++) {
            if(m[s[i]] > 0) {
                count--;
            }
            m[s[i]]--;

            while(count==0) {
                m[s[l]]++;
                if(m[s[l]] > 0) {
                    count++;
                    if(i-l+1 <= min_len) {
                        index = l;
                        min_len = i-l+1;
                    }
                }
                l++;
            }
        }

        if(index==-1)
            return "";
        return s.substr(index, min_len);
    }
};