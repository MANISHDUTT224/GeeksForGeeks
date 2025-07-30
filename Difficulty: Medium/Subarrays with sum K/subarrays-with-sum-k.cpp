class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        map<int,int>mp;
       
        int n=arr.size();
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            int res=sum-k;
            if(sum==k){
                cnt++;
            }
            cnt+=mp[res];
            mp[sum]++;
        }
        return cnt;
    }
};