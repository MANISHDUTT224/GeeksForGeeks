class Solution {
  public:
    int expand(string& s, int i, int j){
        int cnt=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            cnt++;
            i--; j++;
        }
        return cnt;
    }
    int countPS(string &s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int a1=1, a2=0;
            a1=expand(s,i,i);
            if(i+1<n) a2=expand(s,i,i+1);
            // cout<<i<<' '<<a1<<' '<<a2<<'\n';
            if(a1>1) ans+=a1-1;
            if(a2>0) ans+=a2;
        }
        return ans;
    }
};