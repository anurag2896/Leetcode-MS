class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();

        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int mid = (n1+n2+1)/2;

        int l=0, r=n1;
        while(l<=r) {
            int m1 = l+(r-l)/2;
            int m2 = mid - m1;

            int l1 = m1-1>=0 ? nums1[m1-1] : INT_MIN;
            int l2 = m2-1>=0 ? nums2[m2-1] : INT_MIN;

            int r1 = m1 < n1 ? nums1[m1] : INT_MAX;
            int r2 = m2 < n2 ? nums2[m2] : INT_MAX;

            if(l1<=r2 && l2<=r1) {
                if((n1+n2)%2==0) {
                    return (double)(max(l1, l2) + min(r1, r2))/2;
                } else
                    return (double)(max(l1, l2));
            } else if(l1>r2) {
                r=m1-1;
            } else
                l=m1+1;
        }

        return 0;
    }
};