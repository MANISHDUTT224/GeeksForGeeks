class Solution {
  public:
     bool isPossible(vector<int>&arr,int k,int mid){
         int sum=0,count=1;
         for(int i=0;i<arr.size();i++){
             sum+=arr[i];
             if(sum>mid){
                 sum=arr[i];
                 count++;
             }
             
         }
         if(count<=k){
             return true;
         }
         return false;
     }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        int l=maxi,r=sum,ans=sum;
        while(l<=r){
            int mid=(l+r)/2;
            if(isPossible(arr,k,mid)){
                
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};