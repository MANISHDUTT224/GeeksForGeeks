class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int ans=0;
        stack<int>stk;
        vector<int>nse(arr.size(),arr.size()),pse(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                pse[i]=stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            stk.pop();
        }
        for(int i=arr.size()-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()]>arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                nse[i]=stk.top();
            }
            stk.push(i);
        }
        for(int i=0;i<arr.size();i++){
            ans+=arr[i]*(nse[i]-i)*(i-pse[i]);
        }
        return ans;
    }
};