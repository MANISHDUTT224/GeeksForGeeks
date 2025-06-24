class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
       int minprice=INT_MAX,maxprofit=INT_MIN;
       for(int i=0;i<prices.size();i++){
           minprice=min(minprice,prices[i]);
           maxprofit=max(maxprofit,prices[i]-minprice);
       }
       return maxprofit;
    }
};
