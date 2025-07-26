class Solution {
  public:
    int maxLen(string& s) {
        // code here
        int n=s.size();
        int maxlen=0;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                maxlen=max(maxlen,i-st.top());
            }
        }
        return maxlen;
    }
};