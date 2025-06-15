class Solution {
  public:
  int sumd(vector<int>&arr,int d){
      int sum=0,n=arr.size();
      for(int i=0;i<n;i++){
          sum+=ceil((double)(arr[i])/(double)(d));
      }
      return sum;
  }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int start=1,end=*max_element(arr.begin(),arr.end());
        while(start<=end){
            int mid=start+(end-start)/2;
            if(sumd(arr,mid)<=k){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
        
    }
};
