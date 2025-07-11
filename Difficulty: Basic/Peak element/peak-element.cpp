class Solution {
  public:
    int peakElement(vector<int> &nums) {
        // Your code here
         int i=1,j=nums.size()-2;
        int ans;
        if(nums.size()==1 || nums[0]>nums[1]){
            return 0;
        }
        int n=nums.size();
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return 0;
    }
};