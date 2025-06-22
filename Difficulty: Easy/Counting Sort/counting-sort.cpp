class Solution {
  public:
    // Function to arrange all letters of a string in lexicographical
    // order using Counting Sort.
    string countSort(string arr) {
        // code here
        vector<int>mp(26,0);
        for(char c:arr){
            mp[c-'a']++;
        }
        string res="";
        for(int i=0;i<26;i++){
            int cnt=mp[i];
            while(cnt){
                res+=(char)(i+'a');
                cnt--;
            }
            
        }
        return res;
        
    }
};