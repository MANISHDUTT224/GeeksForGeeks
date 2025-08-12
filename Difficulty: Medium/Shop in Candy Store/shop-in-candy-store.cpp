class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int n=prices.size();
        int cand=(n+k)/(k+1);
        int min_cost=0;
        for(int i=0;i<cand;i++){
            min_cost+=prices[i];
        }
        int max_cost=0;
        for(int i=n-cand;i<n;i++){
            max_cost+=prices[i];
        }
        return {min_cost,max_cost};
    }
};