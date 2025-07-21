class Solution {
  public:
    int cntCoprime(vector<int>& nums) {
        // code here
        int m=*max_element(nums.begin(),nums.end());
        vector<int>ctr(m+1,0);
        for(int ele:nums){
            ctr[ele]++;
        }
        vector<int>mctr(m+1,0);
        for(int i=1;i<=m;i++){
            for(int mul=1;i*mul<=m;mul++){
                mctr[i]+=ctr[i*mul];
            }
        }
        vector<long>dp(m+1,0);
        for(int i=m;i>=1;i--){
            dp[i]=(long)mctr[i]*(mctr[i]-1)/2;
            for(int mul=2;i*mul<=m;mul++){
                dp[i]-=dp[i*mul];
            }
        }
        return dp[1];
    }
};
