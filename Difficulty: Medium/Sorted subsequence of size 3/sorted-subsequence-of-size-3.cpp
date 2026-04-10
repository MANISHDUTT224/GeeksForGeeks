class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        
        if (n < 3) return {};
        
        vector<int> rightMax(n);
        rightMax[n - 1] = arr[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(arr[i], rightMax[i + 1]);
        }
        
        int leftMin = arr[0];
        
        for (int i = 1; i < n - 1; i++) {
            
            if (leftMin < arr[i] && arr[i] < rightMax[i + 1]) {
                return {leftMin, arr[i], rightMax[i + 1]};
            }
            
            leftMin = min(leftMin, arr[i]);
        }
        
        return {};
    }
};