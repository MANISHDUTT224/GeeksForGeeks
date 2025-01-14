//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int sum=accumulate(arr.begin(),arr.end(),0);
        right[0]=sum-arr[0];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+arr[i-1];
            right[i]=right[i-1]-arr[i];
           // cout<<left[i]<<" "<<right[i]<<endl;
            if(left[i]==right[i]){
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends