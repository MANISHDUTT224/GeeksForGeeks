class Solution {
  public:
       vector<vector<int>>dp;
    int recur(vector<int>&arr, int idx, int buy, int fee) {
        if(idx>=arr.size()) {
            return 0;
        }
        
        if(dp[idx][buy]!=-1) {
            return dp[idx][buy];
        }
        if(buy) {
            int take=recur(arr,idx+1,0,fee)-arr[idx];
            int didnot=recur(arr,idx+1,buy,fee);
            return dp[idx][buy] = max(take,didnot);
        } else {
            int sell=recur(arr,idx+1,1,fee)+arr[idx]-fee;
            int didnot=recur(arr,idx+1,buy,fee);
            return dp[idx][buy] = max(sell,didnot);
        }
    }
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        dp=vector<vector<int>>(arr.size()+1,vector<int>(2,-1));
        return recur(arr,0,1,k);
    }
};