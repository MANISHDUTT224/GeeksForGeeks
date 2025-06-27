// User function Template for C++

class Solution {
  public:
    void merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    int countpairs(vector<int>&arr,int low,int mid,int high){
        int j=mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++){
            while(j<=high && (long long)arr[i]>(long long)2*arr[j]){
                j++;
            }
            cnt+=(j-(mid+1));
        }
        return cnt;
    }
    int mergesort(vector<int>&arr,int low,int high){
        int cnt=0;
        if(low>=high){
            return cnt;
        }
        int mid=(low+high)/2;
        cnt+=mergesort(arr,low,mid);
        cnt+=mergesort(arr,mid+1,high);
        cnt+=countpairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return cnt;
    }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        int cnt;
        cnt+=mergesort(arr,0,n-1);
        return cnt;
    }
};