class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n=s.size();
        for(int i=n-2;i>=0;i--){
            if(s[i]==s[n-1]){
                string k=s.substr(0,i+1);
                string m=s.substr(n-1-i,i+1);
                if(k==m){
                    return i+1;
                }
            }
        }
        return 0;
    }
};