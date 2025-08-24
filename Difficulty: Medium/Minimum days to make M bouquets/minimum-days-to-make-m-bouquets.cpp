class Solution {
  public:
     bool Possible(vector<int>&arr,int mid,int m,int k){
         int bouqets=0,conlen=0;
         for(int i=0;i<arr.size();i++){
             if(arr[i]<=mid){
                 conlen++;
             }
             else{
                 bouqets+=conlen/k;
                 conlen=0;
             }
         }
         bouqets+=conlen/k;
         return bouqets>=m;
     }
    int minDaysBloom( vector<int> &arr,int k,int m) {
        // Code here
        sort(arr.begin(),arr.end());
        int ans=-1;
        int i=*min_element(arr.begin(),arr.end());
        int j=*max_element(arr.begin(),arr.end());
        long long val=k*1LL*m*1LL;
        if(val>arr.size()){
            return -1;
        }
        while(i<=j){
            int mid=(i+j)/2;
            if(Possible(arr,mid,m,k)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};