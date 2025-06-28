// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int i=0,j=nums.size()-1,ans=INT_MAX;
        int index=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[i]<=nums[j]){
                if(nums[i]<ans){
                    index=i;
                    ans=nums[i];
                }
                break;
            }
            if(nums[i]<=nums[mid]){
                if(nums[i]<ans){
                    index=i;
                    ans=nums[i];
                }
                i=mid+1;
            }
            else{
                if(nums[mid]<ans){
                    index=mid;
                    ans=nums[mid];
                }
                j=mid-1;
            }
        }
        return index;
    }
};
