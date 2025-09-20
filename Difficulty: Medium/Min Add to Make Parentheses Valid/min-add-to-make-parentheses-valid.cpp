class Solution {
  public:
    int minParentheses(string& s) {
        // code here
         int open = 0;
        int close = 0;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                if(close >= open){
                    ans += (close - open);
                    open = 0;
                    close = 0;
                }
                open++;
            }
            else{
                close++;
            }
        }
        
        ans += abs(open - close);
        return ans;
        }
};