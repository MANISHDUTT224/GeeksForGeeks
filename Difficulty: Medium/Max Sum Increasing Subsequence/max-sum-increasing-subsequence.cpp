class Solution {
  public:
    int maxSumIS(vector<int>& nums) {
        // code here
        vector<int>list=nums;
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    list[i]=max(list[i],list[j]+nums[i]);
                }
            }
        }
        return *max_element(list.begin(),list.end());
    }
};