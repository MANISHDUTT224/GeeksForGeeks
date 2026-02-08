class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        // code here
        int n=nums.size();
        int maxprd=INT_MIN,prd=1;
        for(int i=0;i<n;i++){
            prd*=nums[i];
            maxprd=max(maxprd,prd);
            if(prd==0){
                prd=1;
            }
        }
        prd=1;
        for(int i=n-1;i>=0;i--){
            prd*=nums[i];
            maxprd=max(maxprd,prd);
            if(prd==0){
                prd=1;
            }
        }
        return maxprd;
    }
};