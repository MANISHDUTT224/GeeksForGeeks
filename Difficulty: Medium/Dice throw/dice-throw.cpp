class Solution {
  public:
    int countWays(int dice, int target, const int& faces, const int& totalDices, vector<vector<int>>& dp){
        if(dice == totalDices){
            return(target == 0) ? 1 : 0;
        }
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        int ways = 0;
        for(int i = 1; i <= faces; i++){
            if(i <= target){
                ways += countWays(dice+1, target - i, faces, totalDices, dp);
            }
        }
        return dp[dice][target] = ways;
    }
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n, vector<int>(x+1, -1));
        countWays(0, x, m, n, dp);
        return dp[0][x];
        // code here
        
    }
};