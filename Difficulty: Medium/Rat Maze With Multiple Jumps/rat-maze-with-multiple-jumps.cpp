using vi = vector<int>;
using vb = vector<bool>;
 
using vvi = vector<vector<int>> ;
using vvb = vector<vector<bool>> ;
int n;
class Solution {
private:
bool dfs (int r, int c, vvi& mat, vvi& ans, vvb& vis) {
if (r == n - 1 && c == n - 1) {
ans[r][c] = 1;
return true;
}
 
if (vis[r][c])
return false;
 
if (mat[r][c] == 0)
return false;
 
ans[r][c] = 1;
for (int j = 1; j < mat[r][c] + 1; j++) {
int nc = c + j;
if (nc < n && ans[r][nc] == 0) {
if (dfs (r, nc, mat, ans, vis))
return true;
}
 
int nr = r + j;
if (nr < n && ans[nr][c] == 0) {
if (dfs(nr, c, mat, ans, vis))
return true;
}
 
}
 
ans[r][c] = 0;
vis[r][c] = true;
return false;
}
 
public:
vvi shortestDist(vector<vector<int>> & mat) {
// code here
n = mat.size();
if (n == 1)
return {{1}};
 
vvi ans(n, vi(n, 0));
vvb vis(n, vb(n, false));
 
if (dfs(0, 0, mat, ans, vis))
return ans;
 
return {{-1}};
}
};
 