class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
           if(n==1) return false;
        int cntr=1;
        int last=1;
        int t=2;
        while(n-cntr>=0){
            if((n-cntr)%t==0) return true;
            last++;
            cntr+=last;
            t++;
        }
        return false;
    }
};