class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
       map<int,int>mp;
       for(auto it:a){
           mp[it]++;
       }
      map<int,int>mp1;
       for(auto it:b){
           mp1[it]++;
       }
       for(auto it:mp1){
           if(it.second>mp[it.first]){
               return false;
           }
       }
       return true;
    }
};