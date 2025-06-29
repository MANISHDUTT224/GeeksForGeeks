// User function Template for C++

class Solution {
  public:
    bool canplace(vector<int>&stalls,int mid,int k){
        int cntcows=1;
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=mid){
                cntcows++;
                last=stalls[i];
            }
            if(cntcows>=k){
            return true;
        }
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size(),ans=-1;
        int i=1,j=stalls[n-1]-stalls[0];
        while(i<=j){
            int mid=(i+j)/2;
            if(canplace(stalls,mid,k)){
                ans=mid;
                i=mid+1;
            }
            else{
               
                j=mid-1;
            }
        }
        return ans;
    }
};