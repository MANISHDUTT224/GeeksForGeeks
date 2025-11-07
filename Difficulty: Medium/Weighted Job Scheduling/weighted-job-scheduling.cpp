class Solution {
  public:
     int BinarySearch(vector<vector<int>> &jobs, int key, int l, int r){
        while(l<=r){
            int m = l+(r-l)/2;
            if(jobs[m][0] >= key){
                r=m-1;
            }
            else{
                l=m+1;
            }
        } 
        return l;
    }
    int rec(vector<vector<int>> &jobs, int i, int r, vector<int> &dp){
        if(i >= jobs.size())return 0;
        // 1d dp works here because element only gets picked if its lower limit is more than r
        if(dp[i] != -1){
            return dp[i];
        }
        int take = INT_MIN, not_take = INT_MIN;
        
        // take
        if(jobs[i][0]>=r){
            int idx = BinarySearch(jobs, jobs[i][1], i+1, jobs.size()-1);
            take = rec(jobs, idx, jobs[i][1], dp)+jobs[i][2];
        }
        
        // not take
        not_take = rec(jobs, i+1, r, dp);
        
        return dp[i] = max(take, not_take);
    }
    int maxProfit(vector<vector<int>> &jobs) {
        vector<int> dp(jobs.size(), -1);
        sort(jobs.begin(), jobs.end());
        return rec(jobs, 0, INT_MIN, dp);
    }
};
