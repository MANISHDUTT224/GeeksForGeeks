class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
            int ans=(n*(n-1))/2;
            int diff=0;
            for(auto i:mp){
                if(i.second>1){
                    int len=i.second;
                    diff+=(len*(len-1))/2;
                    
                }
            }
            if(diff>0){
                return ans-diff+1;
            }
            
    return ans;
    }
};
