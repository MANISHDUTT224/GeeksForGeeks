class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
         int i=0,j=arr.size()-1;
         sort(arr.begin(),arr.end());
         while(i<j){
             if(arr[i]+arr[j]==target){
                 return true;
             }
             else if(arr[i]+arr[j]<target){
                 i++;
             }
             else{
                 j--;
             }
         }
         return false;
    }
};