class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int maxlen=0,sum=0;
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int rem=sum-k;
            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            if(mp.find(rem)!=mp.end()){
                maxlen=max(maxlen,i-mp[rem]);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxlen;
    }
};