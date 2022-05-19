class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;  //fruit, count
        int n=fruits.size(), left=0, maxlen=0;
        for(int i=0; i<n; i++) {
            m[fruits[i]]++;
            while(m.size()>2) {
                m[fruits[left]]--;
                if(m[fruits[left]]==0)
                    m.erase(fruits[left]);
                left++;
            }
            maxlen = max(maxlen, i-left+1);
        }
        return maxlen;
    }
};