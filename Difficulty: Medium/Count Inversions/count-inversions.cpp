class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int>&arr,int l,int mid,int r){
        int i=l,j=mid+1;
        int cnt=0;
        vector<int>temp;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                cnt+=(mid-i+1);
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(arr[j]);
            j++;
        }
        int k=temp.size();
        for(int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
        return cnt;
    }
    int mergeSort(vector<int>&arr,int l,int r){
        int cnt=0;
        if(l>=r){
            return cnt;
        }
        int mid=(l+r)/2;
        cnt+=mergeSort(arr,l,mid);
        cnt+=mergeSort(arr,mid+1,r);
        cnt+=merge(arr,l,mid,r);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergeSort(arr,0,arr.size()-1);
    }
};