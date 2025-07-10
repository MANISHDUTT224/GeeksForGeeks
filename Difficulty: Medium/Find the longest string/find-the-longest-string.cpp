class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(),words.end());
        unordered_map<string,int>mp;
        for(auto word:words){
            mp[word]++;
        }
        string s;
        int l=0;
        for(auto i:words){
            string x;
            int n=i.size();
            for(int j=0;j<n;j++){
                x+=i[j];
                
                if(!mp[x]){
                    n=0;
                    break;
                }
            }
            if(n>l){
                s=i;
                l=n;
            }
        }
        return s;
        
    }
};