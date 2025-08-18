class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
         sort(citations.begin(),citations.end());
        int i=citations.size();
        int j=0;
        while(i>citations[j]){
            i--;
            j++;
        }
        return i;
    }
};