class Solution {
  public:
    bool isPossible(vector<int>&arr,int mid,int m,int k){
        int conlen=0,bouqets=0;
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
    int minDaysBloom(int m, int k, vector<int> &arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int i=*min_element(arr.begin(),arr.end()),j=*max_element(arr.begin(),arr.end());
        long long val=m*1LL*k*1LL;
        if(val>arr.size()){
            return -1;
        }
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(isPossible(arr,mid,m,k)){
                j=mid-1;
                ans=mid;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};