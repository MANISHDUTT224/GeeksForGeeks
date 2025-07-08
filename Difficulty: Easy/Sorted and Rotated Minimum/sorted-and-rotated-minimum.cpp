class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n=arr.size(),ans=INT_MAX;
        int i=0,j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[i]<=arr[j]){
                ans=min(ans,arr[i]);
            }
            if(arr[i]<=arr[mid]){
                ans=min(ans,arr[i]);
                i=mid+1;
            }
            else{
                ans=min(ans,arr[mid]);
                j=mid-1;
            }
        }
        return ans;
    }
};