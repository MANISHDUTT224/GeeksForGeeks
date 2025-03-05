//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first=-1,i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==target){
                first=mid;
                j=mid-1;
            }
            else if(arr[mid]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        int last=-1;
        i=0;
        j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==target){
                last=mid;
                i=mid+1;
            }
            else if(arr[mid]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        
        if(first!=-1 && last!=-1){
            return (last-first+1);
        }
        return 0;
        
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends