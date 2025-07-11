class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<mat1.size();i++){
            for(int j=0;j<mat1[0].size();j++){
               mp[mat1[i][j]]++;
            }
        }
        int count=0;
        for(int i=0;i<mat2.size();i++){
            for(int j=0;j<mat2[0].size();j++){
                int target=x-mat2[i][j];
                if(mp.find(target)!=mp.end()){
                    count+=mp[target];
                }
            }
        }
        return count;
    }
};