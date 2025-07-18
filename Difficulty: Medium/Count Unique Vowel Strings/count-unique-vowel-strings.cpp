class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        map<char,int>mp;
        for(char c:s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
                mp[c]++;
            }
        }
        int cnt=mp.size();
        if(!mp.size()){
            return 0;
        }
        int ans=1;
        int n=s.size();
        for(int i=1;i<=cnt;i++){
            ans*=i;
        }
        for(auto i:mp){
            ans*=i.second;
        }
        return ans;
        
    }
};