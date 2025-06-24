class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int xr=0;
        map<int,int>mp;
        mp[xr]++;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            xr^=arr[i];
            int x=xr^k;
            cnt+=mp[x];
            mp[xr]++;
            
        }
        return cnt;
    }
};