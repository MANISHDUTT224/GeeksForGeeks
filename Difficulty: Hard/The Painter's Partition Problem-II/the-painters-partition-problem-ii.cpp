// User function template for C++

class Solution {
  public:
    bool Possible(vector<int>&arr,int mid,int k){
        int painters=1,sm=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid){
                return false;
            }
            if(sm+arr[i]>mid){
                sm=arr[i];
                painters++;
            }
            
            else{
                
                sm+=arr[i];
            }
        }
        return painters<=k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        long left=*max_element(arr.begin(),arr.end());
        long right=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(Possible(arr,mid,k)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
        // return minimum time
    }
};