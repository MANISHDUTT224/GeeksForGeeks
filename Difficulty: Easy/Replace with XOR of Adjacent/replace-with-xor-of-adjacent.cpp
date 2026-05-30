class Solution {
  public:
      virtual void replaceElements(vector<int>& arr){
      int n=arr.size();
      if(n<=1) return;
      
      int prev=arr[0];
      arr[0]=prev^arr[1];
      
      for(int i=1; i<(n-1); i++){
        int tmp=arr[i];
        arr[i]=prev^arr[i+1];
        prev=tmp;
      }
      
      if(n>=2)
        arr[n-1]^=prev;
      
      return;
    }
};