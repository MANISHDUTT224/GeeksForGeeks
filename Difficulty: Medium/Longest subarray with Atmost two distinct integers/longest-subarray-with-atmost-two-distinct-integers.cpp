class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int window=0,streak=0,curr=0,prev=0,ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==curr){
                window++;
                streak++;
            }
            else if(arr[i]==prev){
                window++;
                streak=1;
                prev=curr;
            }
            else{
                window=streak+1;
                streak=1;
                prev=curr;
            }
            if(window>ans){
                ans=window;
            }
            curr=arr[i];
        }
        return ans;
        
    }
};