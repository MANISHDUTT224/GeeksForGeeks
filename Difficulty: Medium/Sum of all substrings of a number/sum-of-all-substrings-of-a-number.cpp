class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                ans += stoi(s.substr(i,j-i+1));
            }
        }
        return ans;
    }
};