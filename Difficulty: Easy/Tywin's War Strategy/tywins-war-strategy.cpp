class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        vector<int>rem(k,0);
        for(auto x:arr){
            rem[x%k]++;
        }
        int n=arr.size();
        n=(n+1)/2;
        int ans=0;n -=rem[0];
        for(int i=k-1;i>0 && n>0 ;i--){
            if(n>=rem[i]){
                ans+=rem[i]*(k-i);
                n-=rem[i];
            }
            else{
                ans+=n*(k-i);
                n=0;
            }
        }
        return ans;
    }
};