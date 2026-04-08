class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
           int l =0 , h = arr.size() -1;
       while(l<=h ){
           if(arr[l]==0) l++;
           else{
               swap(arr[l] , arr[h]);
                h--;
           }
       }
    }
};