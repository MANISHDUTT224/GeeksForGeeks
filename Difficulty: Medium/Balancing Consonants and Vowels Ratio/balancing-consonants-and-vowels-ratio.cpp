class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
        unordered_map<int,int>mp;
        int v=0,c=0;
        mp[0]=1;
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            string s=arr[i];
            for(int j=0;j<s.size();j++){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    v++;
                }
                else{
                    c++;
                }
            }
            int diff=v-c;
            cnt+=mp[diff];
            mp[diff]++;
        }
        return cnt;
    }
};