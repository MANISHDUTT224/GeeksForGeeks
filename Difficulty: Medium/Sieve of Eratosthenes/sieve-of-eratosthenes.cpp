class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<int>vec(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(vec[i]){
            for(int j=i*i;j<=n;j+=i){
                vec[j]=0;
            }
            }
        }
        vector<int>ans;
        for(int i=2;i<=n;i++){
            if(vec[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};