class Solution {
    public int startStation(int[] gas, int[] cost) {
        // Your code here
        int n=gas.length;
        int start=0;
        int totalgain=0,curgain=0;
        for(int i=0;i<n;i++){
            int gain=gas[i]-cost[i];
            curgain+=gain;
            totalgain+=gain;
            if(curgain<0){
                curgain=0;
                start=i+1;
            }
        }
        return (totalgain<0)?-1:start;
    }
}