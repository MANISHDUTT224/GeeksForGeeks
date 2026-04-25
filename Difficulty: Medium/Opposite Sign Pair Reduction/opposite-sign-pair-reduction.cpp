class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
             vector<int> s;

        // Traverse each element
        for (int element : arr) {

            // Process while there is a collision (opposite signs)
            while (!s.empty() && s.back() * element < 0) {

                int top = s.back();

                // Top has larger absolute value, keep top
                if (abs(top) > abs(element)) {
                    element = top;
                    s.pop_back();
                }

                // Current element has larger absolute value
                // keep current element
                else if (abs(top) < abs(element)) {
                    s.pop_back();
                }

                // Both have same absolute value, both removed
                else {
                    s.pop_back();
                    element = 0;
                    break;
                }
            }

            // If current element still exists, push into stack
            if (element != 0)
                s.push_back(element);
        }

        return s;
    
    }
};