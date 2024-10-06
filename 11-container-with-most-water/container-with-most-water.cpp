class Solution {
public:
    int maxArea(vector<int>& height) {
        int global=0, local=0;
        int l=0, r=height.size()-1;
        while(l<r) {
            if(height[l] < height[r]) {
                local = (r-l)*height[l];
                l++;
            } else {
                local = (r-l)*height[r];
                r--;
            }
            global = max(global, local);
        }
        return global;
    }
};