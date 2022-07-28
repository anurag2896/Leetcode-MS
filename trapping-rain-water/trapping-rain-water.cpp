class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int> l(n, 0), r(n, 0);
        int lmax=0, rmax=0;
        for(int i=1; i<n; i++) {
            l[i] = max(lmax, height[i-1]);
            lmax=l[i];
        }
        for(int i=n-2; i>=0; i--) {
            r[i] = max(rmax, height[i+1]);
            rmax=r[i];
        }
        
//         for(auto a:l)
//             cout<<a<<" ";
        
//         cout<<endl;
//         for(auto a:r)
//             cout<<a<<" ";
        
        for(int i=0; i<n; i++) {
            ans+=(min(l[i], r[i]) - height[i] > 0) ? min(l[i], r[i]) - height[i] : 0;
        }
        
        return ans;
    }
};