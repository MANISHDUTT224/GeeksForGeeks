class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto num:arr){
            mp[num*num]++;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=arr[i]*arr[i],b=arr[j]*arr[j];
                if(mp.find(a+b)!=mp.end()){
                    return true;
                }
            }
        }
        return false;
        
    }
};