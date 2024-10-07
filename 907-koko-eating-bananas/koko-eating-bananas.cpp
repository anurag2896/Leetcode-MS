class Solution {

    bool canKokoEat(vector<int>& piles, int rate, int h){
        long time=0;
        for(auto pile:piles) {
            time+= (pile+rate-1)/rate;
        }

        if(time <= h)
            return true;
        
        return false;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1, r=1e9;
        int speed=-1;
        while(l<=r) {
            int m = l+(r-l)/2;
            if(canKokoEat(piles, m, h)) {
                speed = m;
                r=m-1;
            } else
                l=m+1;
        }
        return speed;
    }
};