class Solution {

    bool isPossible(vector<int>& piles, int h, int speed) {
        long long time = 0;
        for(auto pile:piles) {
            time+=(pile+speed-1)/speed;
        }
        if(time<=h)
            return true;
        
        return false;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=1e9, ans=1e9;
        while(l<=r) {
            int m=l+(r-l)/2;
            if(isPossible(piles, h, m)) {
                ans=m;
                r=m-1;
            } else {
                l=m+1;
            }
        }
        return ans;
    }
};