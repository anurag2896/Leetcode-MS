class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        unordered_set<int> st;
        for(auto c:s) {
            m[c]++;
        }
        int count=0;
        for(auto el:m) {
            int num_val = el.second;
            while(num_val!=0 && st.find(num_val)!=st.end()) { //found
                num_val--;
                count++;
            }
            st.insert(num_val);
        }
        return count;
    }
};