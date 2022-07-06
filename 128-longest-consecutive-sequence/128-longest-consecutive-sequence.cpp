class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num:nums)
            s.insert(num);
        
        int longestStreak=0;  //longest streak var
        for(int num:nums) {
            if(s.find(num-1)==s.end()) {
                int currentStreak=1;
                
                while(s.find(num+1)!=s.end()) {
                    num++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
            
            
        }
        
        return longestStreak;
    }
};