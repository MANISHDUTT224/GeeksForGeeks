//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int maxarea=0;
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int res=min(arr[l],arr[r])*(r-l);
            maxarea=max(maxarea,res);
            if(arr[l]<arr[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends