class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int j=i+1,k=arr.size()-1;
            while(i!=0 && arr[i]==arr[i-1]){
                i++;
            }
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==target){
                    return true;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return false;
    }
};