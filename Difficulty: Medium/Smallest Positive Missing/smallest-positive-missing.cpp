class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int ans=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=0){
                continue;
            }
            else if(arr[i]==ans){
                ans++;
            }
            else if(arr[i]>ans){
                break;
            }
        }
        return ans;
        
    }
};