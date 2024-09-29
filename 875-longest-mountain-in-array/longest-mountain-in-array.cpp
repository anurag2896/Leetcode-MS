class Solution {
public:
    int longestMountain(vector<int>& arr) {
        // find the peak
        // then stretch and record the max

        int ans=0, n=arr.size();
        for(int i=1; i<n-1; i++) {
            if(arr[i-1]<arr[i] & arr[i]>arr[i+1]) {
                // found peak
                // int l=i-1;
                // int r=i+1;
                // Expand left
                int l = i - 1;
                while (l > 0 && arr[l - 1] < arr[l]) {
                    l--;
                }

                // Expand right
                int r = i + 1;
                while (r < n - 1 && arr[r] > arr[r + 1]) {
                    r++;
                }
                ans = max(ans, r-l+1);

                i=r;
            }
        }
        return ans >= 3 ? ans : 0;
    }
};