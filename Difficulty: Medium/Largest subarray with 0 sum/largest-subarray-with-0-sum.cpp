/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int len=0,maxlen=0,sum=0;
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0){
                maxlen=max(maxlen,i+1);
            }
            if(mp.find(sum)!=mp.end()){
                maxlen=max(maxlen,i-mp[sum]);
            }
            else{
            mp[sum]=i;
            }
        }
        return maxlen;
    }
};