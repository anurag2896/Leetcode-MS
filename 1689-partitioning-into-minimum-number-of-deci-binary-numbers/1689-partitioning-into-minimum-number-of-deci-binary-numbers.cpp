class Solution {
public:
    int minPartitions(string n) {
        int biggest=0;
        for(auto c:n) {
            biggest = max(biggest, c-'0');
        }
        return biggest;
    }
};