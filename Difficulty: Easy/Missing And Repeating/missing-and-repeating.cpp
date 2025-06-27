class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long s11=(n*(n+1))/2;
        long long s22=(n*(n+1)*(2*n+1))/6;
        long long s1=0,s2=0;
        for(int i=0;i<arr.size();i++){
            s1+=(long long)(arr[i]);
            s2+=(long long)arr[i]*(long long)arr[i];
        }
        int val1=s11-s1,val2=s22-s2;
        val2/=val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;
        return {(int)y,(int)x};
    }
};