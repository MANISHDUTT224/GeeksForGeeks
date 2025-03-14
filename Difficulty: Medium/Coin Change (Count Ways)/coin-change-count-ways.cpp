//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int func(int i,int sum,vector<vector<int>>&dp,vector<int>&coins){
       if(i<0){
           return 0;
       }
       if(dp[i][sum]!=-1){return dp[i][sum];}
       if(sum==0){
           return 1;
           
       }
       int t=0;
       int nt=func(i-1,sum,dp,coins);
       if(sum>=coins[i]){
           t=func(i,sum-coins[i],dp,coins);
       }
       return dp[i][sum]=nt+t;
   }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return func(n-1,sum,dp,coins);
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends