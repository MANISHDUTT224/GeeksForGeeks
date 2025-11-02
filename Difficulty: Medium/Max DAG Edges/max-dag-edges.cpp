class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int k=edges.size();
        int max =(V*(V-1))/2;
        return max-k;

    }
};
