// User function template for C++

class Solution {
  public:
    int lowerbound(vector<int>arr,int mi,int m){
        int i=0,j=m-1;
        int ans=m;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]>mi){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        
        return ans;
    }
    int cont(vector<vector<int>>&mat,int mid,int n,int m){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=lowerbound(mat[i],mid,m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int req=(n*m)/2;
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int se=cont(mat,mid,n,m);
            if(se<=req){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
