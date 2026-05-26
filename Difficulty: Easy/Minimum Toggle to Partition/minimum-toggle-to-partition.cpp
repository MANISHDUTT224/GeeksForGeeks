class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
         int totalone = 0;
        for(auto &num : arr) {
            if(num == 1) totalone++;
        }
        int n = arr.size();
        int totalzero = n - totalone;
        int leftone = 0 , leftzero = 0;
        int toggle = totalzero;
        for(int i = 0; i < n; i++) {
            if(arr[i]) leftone++;
            else leftzero++;
            //Ab ham har baar [0,i] tak ka partition dekh lete hai zero(0) ke liye aur [i+1,n] tak ka partition one(1) ke ilye
            int rightzero = totalzero - leftzero;
            toggle = min(toggle , leftone+rightzero);
        }
        return toggle;
    }
};