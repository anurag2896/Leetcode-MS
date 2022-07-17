class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        if(n==0 || l==r)
            return 0;
        int global=0, local=0;
        while(l<r) {
            local = (r-l)*min(height[l], height[r]);
            global = max(global, local);
            if(height[l]<height[r])
                l++;
            else r--;
        }
        return global;
    }
};