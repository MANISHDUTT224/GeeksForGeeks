class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
         int n = seats.size();

        if (k == 0) return true;

        for (int i = 0; i < n; i++) {

            if (seats[i] == 1) continue;

            bool leftEmpty = (i == 0 || seats[i - 1] == 0);

            bool rightEmpty = (i == n - 1 || seats[i + 1] == 0);

            if (leftEmpty && rightEmpty) {
                seats[i] = 1;
                k--;

                if (k == 0) return true;
            }
        }

        return false;
    }
};