class Solution {
  public:
   vector<vector<int>> dp;
    
    int solve(bool last, int n)
    {
        if(n==1)
        return last ? 1 : 2;
        
        if(dp[last][n])
        return dp[last][n];
        
        return dp[last][n] = solve(false, n-1) + (last ? 0 : solve(true, n-1));
    }
    int countStrings(int n) {
        bool last = false;
        dp = vector<vector<int>>(2, vector<int>(n+1, 0));
        return (int)solve(last, n);
    }
};