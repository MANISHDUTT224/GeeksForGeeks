class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n=gas.size();
        int curgain=0,totalgain=0;
        int start=0;
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
};