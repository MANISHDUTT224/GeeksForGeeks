class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        set<array<int,2>>st;
        map<int,vector<array<int,2>>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]){
                    mp[i].push_back({i,j});
                    st.insert({i,j});
                }
            }
        }
        for(auto &i:mp){
            for(int j=0;j<i.second.size();j++){
                for(int k=j+1;k<i.second.size();k++){
                    for(int row=i.first+1;row<=200;row++){
                        if(st.count({row,i.second[j][1]}) && st.count({row,i.second[k][1]})){
                            return 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};