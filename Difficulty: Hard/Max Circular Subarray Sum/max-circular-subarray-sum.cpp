class Solution {
  public:
     int maxKadanes(vector<int>&arr){
         int sum=0,maxsum=INT_MIN;
         for(int i=0;i<arr.size();i++){
             sum+=arr[i];
             maxsum=max(maxsum,sum);
             if(sum<0){
                 sum=0;
             }
         }
         return maxsum;
     }
     
     int minKadanes(vector<int>&arr){
         int sum=0,minsum=INT_MAX;
         for(int i=0;i<arr.size();i++){
             sum+=arr[i];
             minsum=min(minsum,sum);
             if(sum>0){
                 sum=0;
             }
         }
         return minsum;
     }
    int maxCircularSum(vector<int> &arr) {
        // code here
        int maxsum=maxKadanes(arr);
        int minsum=minKadanes(arr);
        int total=accumulate(arr.begin(),arr.end(),0);
        if(maxsum<0){
            return maxsum;
        }
        return max(maxsum,total-minsum);
    }
};