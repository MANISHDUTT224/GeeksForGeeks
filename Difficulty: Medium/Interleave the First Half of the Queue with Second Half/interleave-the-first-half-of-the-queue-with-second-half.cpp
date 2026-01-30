class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
         int n=q.size();
        int mid = n/2;
        stack<int>st;
        for(int i = 0; i<mid; i++)
        {
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        for(int i = 0; i < mid; i++) {
            q.push(q.front());
            q.pop();
        }

        for(int i = 0; i < mid; i++) {
            st.push(q.front());
            q.pop();
        }

        while(!st.empty()) {
            q.push(st.top());
            st.pop();

            q.push(q.front());
            q.pop();
        }
    }
};