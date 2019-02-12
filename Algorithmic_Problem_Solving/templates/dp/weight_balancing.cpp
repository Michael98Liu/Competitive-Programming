// weight balancing that considers weight difference
#define MID MAX_SUM
int n, W[MAX_N];
bool dp[MAX_N][MAX_N][MAX_SUM * 2 + 1];
int solve() {
  dp[0][0][MID] = true;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= n; k++) {
      for (int d = MID - MAX_SUM; d <= MID + MAX_SUM; d++) {
        if (dp[i-1][k][d]) {
          if (k+1 <= n) dp[i][k+1][d + W[i]] = true;
          dp[i][k][d - W[i]] = true;
        }
      }
    }
  }
  // collect the answer by checking dp[n][*]
  int ans = INF;
  for (int d = MID - MAX_SUM; d <= MID + MAX_SUM; d++) {
    if (dp[n][n/2][d]) ans = min(ans, abs(d - MID));
  }
  return ans;
}

#define MID MAX_SUM
int n, W[MAX_N];
bool dp[MAX_N][MAX_SUM * 2 + 1];
int solve() {
  dp[0][MID] = true;
  for (int i = 1; i <= n; i++) {
    for (int d = MID - MAX_SUM; d <= MID + MAX_SUM; d++) {
      if (dp[i-1][d]) {
        dp[i][d + W[i]] = true;
        dp[i][d - W[i]] = true;
      }
    }
  }
  // collect the answer by checking dp[n][*]
  int ans = INF;
  for (int d = MID - MAX_SUM; d <= MID + MAX_SUM; d++) {
    if (dp[n][d]) ans = min(ans, abs(d - MID));
  }
  return ans;
}

// hw13_2
