class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        int longestStreak=0, currentStreak=0;
        for(int num:nums)
            s.insert(num);
        
        for(int num:nums) {
            if(s.find(num-1)==s.end()) { //not found
                currentStreak=1;
                while(s.find(++num)!=s.end())
                    currentStreak++;
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};