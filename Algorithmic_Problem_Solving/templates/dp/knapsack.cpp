int n, V[MAX_N], S[MAX_N];
int dp[MAX_N][MAX_S];
// top-down
int solve(int i, int s) {
  if (i == 0 || s < 0) return 0;
  if (dp[i][s] != -1) return dp[i][s];
  return dp[i][s] = max(solve(i-1, s), solve(i-1, s - S[i]) + V[i]);
}
// bottom-up
int n, V[MAX_N], S[MAX_N];
int dp[MAX_N][MAX_C];
void solve(int n, int C) {
  for (int i = 1; i <= n; i++) {
    for (int s = 0; s <= C; s++) {
      dp[i][s] = max(dp[i][s], dp[i-1][s]);
      if (s + S[i] <= C) dp[i][s + S[i]] = max(dp[i][s + S[i]], dp[i-1][s] + V[i]);
      // Or you can do:
      //   dp[i][s] = dp[i-1][s];
      //   if (s - S[i] >= 0) dp[i][s] = max(dp[i][s], dp[i-1][s - S[i]] + V[i]);
    }
  }
}
