class Solution {
  public:
    long findByD(vector<int>&arr,int mid){
        long total=0;
        for(int i=0;i<arr.size();i++){
            total+=ceil((double)arr[i]/(double)mid);
        }
        return total;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int i=1,j=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            long d=findByD(arr,mid);
            if(d<=k){
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
