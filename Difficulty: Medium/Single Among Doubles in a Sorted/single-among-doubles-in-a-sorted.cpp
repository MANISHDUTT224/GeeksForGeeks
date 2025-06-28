class Solution {
  public:
    int findOnce(vector<int>& nums) {
        // code here.
        int i=0,j=nums.size()-1;
        while(i<j){
            int mid=(i+j)/2;
            int num=(mid%2==0)?mid+1:mid-1;
            if(nums[mid]==nums[num]){
        
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        return nums[i];
    }
};