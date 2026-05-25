class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
         int missings = end - start + 1;
        
        for (int x: arr) {
            if (x >= start && x <= end) missings--;
        }
        
        return missings == 0;
    }
};
