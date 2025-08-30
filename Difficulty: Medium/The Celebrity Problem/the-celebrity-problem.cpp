class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
         vector<int> knowMe(mat.size(),0),iKnow(mat.size(),0);
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(mat[i][j] == 1){
                    cnt++;
                    iKnow[i]++;
                    knowMe[j]++;
                }
            }
        }
        for(int i=0;i<mat.size();i++){
            
            if(knowMe[i]==mat.size() && iKnow[i]==1 || knowMe[i]==mat.size()-1 && iKnow[i]==0) return i;
        }
        return -1;
    }
};