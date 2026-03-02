class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left=0,right=arr.size()-1;
        int leftMax=arr[left],rightMax=arr[right];
        int water=0;
        while(left<right){
            if(leftMax<rightMax){
                left++;
                leftMax=max(leftMax,arr[left]);
                water+=leftMax-arr[left];
                
            }
            else{
                right--;
                rightMax=max(rightMax,arr[right]);
                water+=rightMax-arr[right];
                
            }
        }
        return water;
    }
};