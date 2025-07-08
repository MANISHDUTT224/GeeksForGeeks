class Solution {
  public:
  int func(int mid,int n,int m){
      int ans=1;
      for(int i=1;i<=n;i++){
          ans*=mid;
          if(ans>m){
              return 2;
          }
      }
      if(ans==m){
          return 1;
      }
      return 0;
  }
    int nthRoot(int n, int m) {
        // Code here.
        int i=1,j=m;
        while(i<=j){
            int mid=(i+j)/2;
            int midN=func(mid,n,m);
            if(midN==1){
                return mid;
            }
            else if(midN==2){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return -1;
    }
};