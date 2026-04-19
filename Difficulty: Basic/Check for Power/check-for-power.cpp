class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
         for(int i=0;i<=sqrt(y);i++){
            if(pow(x,i)==y){
                return true;
            }
        }
        return false;
    }
};