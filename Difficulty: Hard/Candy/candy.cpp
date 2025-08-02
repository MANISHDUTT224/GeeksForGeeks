class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int cnt=0;
        int n=arr.size();
        
        vector<int>candies(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                candies[i]=max(candies[i],candies[i-1]+1);
            }
        }
        for(int i=n-1;i>0;i--){
            if(arr[i-1]>arr[i]){
                candies[i-1]=max(candies[i]+1,candies[i-1]);
            }
            cnt+=candies[i-1];
        }
        return cnt+candies[n-1];
    }
};
