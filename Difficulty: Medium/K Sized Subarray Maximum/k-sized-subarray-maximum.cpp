class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
       vector<int> ans;
      int maxv=INT_MIN, maxi=-1;
      
      int i=0, j=0, n=arr.size();
      
      for(j=0; j<n; j++){
        if(arr[j] > maxv) { maxv=arr[j]; maxi=j; }
        
        if((j-i+1) == k){
          ans.push_back(maxv);
          if(i==maxi){
            maxv=INT_MIN;
            i++;
            for(int m=i; m<=j; m++){
              if(arr[m] > maxv) { maxv=arr[m]; maxi=m; }    
            }
          }
          else i++;
        }
      }
      
      return ans;
    }
};