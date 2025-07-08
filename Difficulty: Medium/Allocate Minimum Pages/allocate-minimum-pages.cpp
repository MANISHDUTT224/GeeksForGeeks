class Solution {
  public:
    long findPages(vector<int>&arr,int mid,int k){
        long pages=0,student=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+pages>mid){
                pages=arr[i];
                student++;
            }
            else{
                pages+=arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int i=*max_element(arr.begin(),arr.end()),j=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        if(k>arr.size()){
            return -1;
        }
        while(i<=j){
            int mid=(i+j)/2;
            long total=findPages(arr,mid,k);
            if(total>k){
                i=mid+1;
            }
            else{
                ans=mid;
                j=mid-1;
            }
            
        }
        return ans;
    }
};