//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
   int func(int i,vector<int>&cost,vector<int>&dp){
       int n=cost.size();
       if(i>=n){
           return 0;
       }
       if(dp[i]!=-1){
           return dp[i];
       }
       int one=cost[i]+func(i+1,cost,dp);
       int two=cost[i]+func(i+2,cost,dp);
       return dp[i]=min(one,two);
       
   }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(func(0,cost,dp),func(1,cost,dp));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends