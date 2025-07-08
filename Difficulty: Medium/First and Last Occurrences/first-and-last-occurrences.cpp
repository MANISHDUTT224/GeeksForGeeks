class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int first=-1,last=-1;
        int i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==x){
                first=mid;
            }
            if(arr[mid]>=x){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==x){
                last=mid;
            }
            if(arr[mid]<=x){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return {first,last};
    }
};