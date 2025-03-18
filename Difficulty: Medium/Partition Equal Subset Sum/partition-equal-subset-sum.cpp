//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   bool helper(int i,vector<int>&arr,vector<vector<int>>&dp,float sum){
       if(sum==0){
           return true;
       }
       if(i>=arr.size()){
           return false;
       }
       if(dp[i][sum]!=-1){
           return dp[i][sum];
       }
       bool ans=helper(i+1,arr,dp,sum);
       if(sum-arr[i]>=0){
           ans|=helper(i+1,arr,dp,sum-arr[i]);
       }
       return dp[i][sum]=ans;
   }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=0;
        
        for(int num:arr){
            sum+=num;
        }
        float half=(float)(sum);
        half/=2;
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,-1));
        return helper(0,arr,dp,half);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends