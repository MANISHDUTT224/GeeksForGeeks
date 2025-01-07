//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int i=0,j=arr.size()-1;
        int count=0;
        while(i<j){
            if(arr[i]+arr[j]==target){
                count++;
                int nexti=i+1;
                while(nexti<j && arr[nexti]==arr[nexti-1]){
                    nexti++;
                    count++;
                }
                j--;
            }
            else if(arr[i]+arr[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends