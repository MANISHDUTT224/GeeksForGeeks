class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res=0;
        for(int i=0;i<s.size();i++){
            int cur=mp[s[i]];
            int next=(i+1<s.size())?mp[s[i+1]]:0;
            if(cur<next){
                res-=cur;
            }
            else{
                res+=cur;
            }
        }
        return res;
    }
};