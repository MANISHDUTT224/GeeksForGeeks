class Solution {
  public:
    void pushZerosToEnd(vector<int>& nums) {
        // code here
        int n=nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};