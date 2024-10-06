class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner=0;
        int votes=0;
        for(auto num:nums) {
            if(votes==0)
                winner = num;

            if(winner == num) {
                votes++;
            } else {
                votes--;
            }
        }
        return winner;
    }
};