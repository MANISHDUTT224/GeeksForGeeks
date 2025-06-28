class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first=-1,last=-1;
        int i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==target){
                first=mid;
            }
            if(arr[mid]>=target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==target){
                last=mid;
            }
            if(arr[mid]<=target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        if(last==-1 && first==-1){
            return 0;
        }
        return (last-first+1);
    }
};
