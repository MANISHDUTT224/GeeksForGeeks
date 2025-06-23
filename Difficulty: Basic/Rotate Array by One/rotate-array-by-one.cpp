// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int k=1;
     reverse(arr.begin(),arr.begin()+arr.size()-k);
     reverse(arr.begin()+arr.size()-k,arr.end());
     reverse(arr.begin(),arr.end());
        
    }
};