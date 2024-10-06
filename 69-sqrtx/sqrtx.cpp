class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;

        int l=1, r=x/2;
        int ans=0;
        while(l<=r) {
            long long m = l+(r-l)/2;
            long long guess = m*m;
            if(guess <= x) {
                ans = m;
                l=m+1;
            } else
                r=m-1;
        }
        return ans;
    }
};