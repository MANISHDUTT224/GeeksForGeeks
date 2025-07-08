class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        long long i=1,j=n,ans;
        while(i<=j){
            long long mid=(i+j)/2;
            long long val=mid*mid;
            if(val<=n){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};