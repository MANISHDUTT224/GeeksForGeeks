//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int i=0,j=arr.size()-1;
        int index=0;
        int ans=INT_MAX;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[i]<=arr[j]){
                if(arr[i]<ans){
                    index=i;
                    ans=arr[i];
                }
                break;
            }
            if(arr[i]<=arr[mid]){
                if(arr[i]<ans){
                    index=i;
                    ans=arr[i];
                }
                i=mid+1;
            }
            else{
                if(arr[mid]<ans){
                    index=mid;
                    ans=arr[mid];
                }
                j=mid-1;
            }
        }
        return index;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends