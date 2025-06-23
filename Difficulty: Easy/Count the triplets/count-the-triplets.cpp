class Solution {
  public:
    int countTriplet(vector<int>& arr) {
        // code here
        int n=arr.size(),count=0;
        sort(arr.begin(),arr.end());
    
        for(int k=n-1;k>=2;k--){
            int i=0,j=k-1;
            while(i<j){
                if(arr[i]+arr[j]==arr[k]){
                   count++;
                    i++;
                    j--;
                }
                else if(arr[i]+arr[j]<arr[k]){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return count;
    }
};