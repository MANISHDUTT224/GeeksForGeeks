// User function Template for C++

class Solution {
  public:
    int searchInsertK(vector<int> Arr, int N, int k) {
        // code here
        int i=0,j=N-1;
        int ans=N;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(Arr[mid]>=k){
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