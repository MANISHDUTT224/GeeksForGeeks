// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        for(int i=0; i<arr[0].size(); i++){
            for(int j=0; j<arr.size(); j++){
                if(arr[j][i] == 1) return j;
            }
        }
        return -1;
    }
};