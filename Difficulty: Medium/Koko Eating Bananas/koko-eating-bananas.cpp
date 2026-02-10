class Solution {
  public:
     int findHours(vector<int>&arr,int mid){
         int total=0;
         for(int pile:arr){
             total+=ceil((double)pile/(double)mid);
         }
         return total;
     }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int i=1,j=*max_element(arr.begin(),arr.end());
        sort(arr.begin(),arr.end());
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            int tothours=findHours(arr,mid);
            if(tothours>k){
                
                i=mid+1;
            }
            else{
                ans=mid;
                j=mid-1;
            }
        }
        return ans;
        
    }
};