class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1, totwater=0, lmax=0, rmax=0;
        while(l<r) {
            if(height[l]<height[r]) {
                if(lmax>height[l])
                    totwater += lmax-height[l];
                lmax=max(height[l++], lmax);
            } else {
                if(rmax>height[r])
                    totwater += rmax-height[r];
                rmax=max(height[r--], rmax);
            }
        }
        return totwater;
    }
};