class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        for(int i=0;i<arr.size();i++){
            while(!pq.empty() && pq.top().second<=i-k){
                pq.pop();
            }
            pq.push({arr[i],i});
            if(i>=k-1){
                res.push_back(pq.top().first);
            }
        }
        return res;
        
    }
};