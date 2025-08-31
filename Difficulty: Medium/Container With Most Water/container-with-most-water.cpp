class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int maxarea=0;
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int res=min(arr[l],arr[r])*(r-l);
            maxarea=max(maxarea,res);
            if(arr[l]<arr[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};
