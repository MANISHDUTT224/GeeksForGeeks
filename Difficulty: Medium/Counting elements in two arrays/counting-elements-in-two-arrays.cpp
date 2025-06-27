class Solution {
  public:
    int upperIndex(vector<int>&b,int z){
        int l=0,r=b.size()-1;
        int ans=r+1;
        
        while(l<=r){
            int mid=(l+r)/2;
            if(b[mid]<=z){
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        
        
        return ans;
    }
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(),b.end());
        vector<int>res;
        for(auto z:a){
            int t=upperIndex(b,z);
            res.push_back(t);
        }
        return res;
    }
};