class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n=a1.size();
        int maxlen=0;
        unordered_map<int,int>mp;
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            s1+=a1[i];
            s2+=a2[i];
            if(s1==s2){
                maxlen=max(maxlen,i+1);
            }
            else{
            int diff=s1-s2;
            if(mp.count(diff)){
                maxlen=max(maxlen,i-mp[diff]);
            }
            else{
                mp[diff]=i;
            }
            }
        }
        return maxlen;
    }
};