class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        // Code here
        vector<vector<int>>result;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(result.size()==0|| result.back()[1]<intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }
        }
        return result;
    }
};