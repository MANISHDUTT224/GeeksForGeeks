// User function Template for C++

class Solution {
  public:
    int findDays(int arr[],int mid,int n){
        int load=0,days=1;
        for(int i=0;i<n;i++){
            if(load+arr[i]>mid){
                load=arr[i];
                days++;
            }
            else{
                load+=arr[i];
            }
        }
        return days;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
            sum+=arr[i];
        }
        int i=maxi,j=sum;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            int totaldays=findDays(arr,mid,n);
            if(totaldays<=d){
                ans=mid;
                j=mid-1;
            }
            else{
                
                i=mid+1;
            }
        }
        return ans;
    }
};