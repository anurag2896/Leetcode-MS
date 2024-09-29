class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> smap(26, 0), tmap(26, 0);

        for(int i=0; i<s.size(); i++) {
            smap[s[i]-'a']++;
            tmap[t[i]-'a']++;
        }

        int count=0;
        for(int i=0; i<26; i++) {
            if(tmap[i] < smap[i]) {
                count+=smap[i] - tmap[i];
            }
            // }else if()
        }
        return count;
    }
};