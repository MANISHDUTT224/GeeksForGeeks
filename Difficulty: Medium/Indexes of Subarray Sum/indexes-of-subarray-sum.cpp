//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int left=0,right=0,n=arr.size();
        int sum=arr[right];
        
        while(right<n){
            if(sum==target){
                vector<int>res;
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if(sum<target){
              right++;
            if(right<n){
                sum+=arr[right];
            }  
            }
            
            else{
                sum-=arr[left];
                left++;
            }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends