class Solution {
  public:
      vector<int> constructList(vector<vector<int>>& queries) {
        vector<int> result;
        int current_xor = 0;
        int q = queries.size(); // Use this to get the number of queries
        
        // Process in reverse
        for (int i = q - 1; i >= 0; i--) {
            if (queries[i][0] == 1) {
                current_xor ^= queries[i][1];
            } else {
                result.push_back(queries[i][1] ^ current_xor);
            }
        }
        
        // Add the initial 0
        result.push_back(0 ^ current_xor);
        
        // Sort the result as required
        sort(result.begin(), result.end());
        
        return result;
    }
};
