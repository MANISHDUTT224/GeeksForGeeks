// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
       int first=-1,last=-1;
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]>=x){
                last=arr[mid];
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]<=x){
                first=arr[mid];
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return {first,last};
    }
};