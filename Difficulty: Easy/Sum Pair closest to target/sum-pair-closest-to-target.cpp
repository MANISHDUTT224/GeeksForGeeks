//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        int maxi=INT_MAX,md=-1;
        vector<int>res;
        while(i<j){
           int s=arr[i]+arr[j];
           if(abs(target-s)<abs(target-maxi)|| (abs(target-s)==abs(target-maxi)&& (arr[j]-arr[i]>md))){
               maxi=s;
               md=arr[j]-arr[i];
               res={arr[i],arr[j]};
           }
           if(s<target){
               i++;
           }
           else{
               j--;
           }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends