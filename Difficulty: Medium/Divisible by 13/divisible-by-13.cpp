class Solution {
  public:
    bool divby13(string &s) {
        // code here
        long long su=0;
        for(int i=0;i<s.size();i++){
            su=(su*10+(s[i]-'0'))%13;
        }

        return su==0;
    }
};