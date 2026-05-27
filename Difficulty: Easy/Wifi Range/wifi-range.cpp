class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
         int n = s.size();

        int first = -1, prev = -1, last = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (first == -1) first = i;

                if (prev != -1 && i - prev > 2 * x + 1) {
                    return false;
                }

                prev = i;

                last = i;
            }
        }

        if (first == -1) return false;

        if (first > x) return false;

        if (n - 1 - last > x) return false;

        return true;
    }
};