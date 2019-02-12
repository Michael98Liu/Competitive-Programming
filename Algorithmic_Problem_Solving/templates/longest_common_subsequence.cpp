int dp[MAX_LEN][MAX_LEN];
// bottom-up
void solve(string X, string Y) { // indices of X and Y are 1-based!
  for (int i = 1; i <= X.length; i++) {
    for (int j = 1; j <= Y.length; j++) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (X[i] == Y[j] ? 1 : 0));
    }
  }
}
