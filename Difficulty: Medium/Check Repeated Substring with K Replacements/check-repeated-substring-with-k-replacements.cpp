class Solution {
  public:
    bool kSubstr(string &s, int k) {
       unordered_map<string,int> mp;
       int j=0;
       for(int i=0;i<s.size();i=i+k){
          int temp=k;
          string str="";
          while(temp--){
             str+=s[j++]; 
          }
          mp[str]++;
       }
       int n=s.size();
       for(auto it:mp){
         if(it.second==n/k || it.second==n/k-1){
             return true;
         }  
       }
       return false;
    }
};