class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int>st;
        int maxarea=INT_MIN;
        for(int i=0;i<=n;i++){
            int ele=(i==n)?0:arr[i];
            while(!st.empty() && arr[st.top()]>ele){
                int h=arr[st.top()];
                st.pop();
                int prevless=(st.empty())?-1:st.top();
                int w=i-prevless-1;
                maxarea=max(maxarea,h*w);
            }
            st.push(i);
        }
        return maxarea;
    }
};
