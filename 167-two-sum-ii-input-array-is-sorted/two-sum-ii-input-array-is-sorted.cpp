class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0, r=n-1;
        int sum=0;
        while(l<r) {
            // while(l<r && numbers[l]==numbers[r])
            sum=numbers[l]+numbers[r];
            if(sum==target) {
                return {l+1, r+1};
            } else if(sum<target) {
                while(l<r && numbers[l]==numbers[l+1])
                    l++;
                l++;
            } else {
                while(l<r && numbers[r]==numbers[r-1])
                    r--;
                r--;
            }
        }

        return {};
    }
};