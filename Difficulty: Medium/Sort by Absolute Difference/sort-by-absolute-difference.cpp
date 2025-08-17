class Solution {
  public:
     static bool comp(pair<int,pair<int,int>>& a,pair<int,pair<int,int>> &b){
        if(a.first==b.first){
            return (a.second.second)<(b.second.second);
        }
        return a.first<b.first;
    }
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n=arr.size();
        vector<pair<int,pair<int,int>>>ans;
        for(int i=0;i<n;i++){
            int diff=abs(arr[i]-x);
            ans.push_back({diff,{arr[i],i}});
        }
        sort(ans.begin(),ans.end(),comp);
        for(int i=0;i<n;i++){
            arr[i]=ans[i].second.first;
        }
    }
};