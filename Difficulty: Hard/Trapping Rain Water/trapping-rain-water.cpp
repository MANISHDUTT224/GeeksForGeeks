class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int trapped=0;
        left[0]=arr[0],right[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i]);
        }
        for(int i=0;i<n;i++){
            int waterlevel=min(left[i],right[i]);
            trapped+=(waterlevel-arr[i])*1;
        }
        return trapped;
    }
};