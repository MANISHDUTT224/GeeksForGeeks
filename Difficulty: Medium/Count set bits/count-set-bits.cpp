class Solution {
  public:
    int countSetBits(int n) {
        // code here
        int count=0;
        for(int i=0;(1<<i)<=n;i++){
            int cycle=1<<(i+1);
            int full=n/cycle;
            int rem=n%cycle;
            count+=full*(1<<i)+max(0,rem-(1<<i)+1);
        }
        return count;
    }
};
