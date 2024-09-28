class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int value=m[s[s.size()-1]], n=s.size();
        for(int i=n-1; i>0; i--) {
            char curr=s[i], prev=s[i-1];
            if(m[curr]<=m[prev])
                value+=m[prev];
            else
                value-=m[prev];
        }
        return value;
    }
};