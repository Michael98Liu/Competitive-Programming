// a is 1-based
int n, a[MAX_N];
// -1: not computed, 0: cannot get s, 1: can get s

int n, a[MAX_N];
bool dp[MAX_N][MAX_SUM];
bool solve(int S) {
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int s = 0; s <= S; s++) {
      dp[i][s] = dp[i-1][s];
      if (s - a[i] >= 0) dp[i][s] |= dp[i-1][s - a[i]];
    }
  }
  return dp[n][S];
}

int n, a[MAX_N];
int dp[MAX_N][MAX_SUM];
bool take[MAX_N][MAX_SUM]; // 0: not take a[i], 1: take a[i]
int solve(int i, int s) {
  if (i == 0) return s == 0;
  if (s < 0) return 0;
  if (dp[i][s] != -1) return dp[i][s];
  if (solve(i-1, s)) {
    dp[i][s] = true;
    take[i][s] = false;
  }
  if (solve(i-1, s - a[i])) {
    dp[i][s] = true;
    take[i][s] = true;
  }
  return dp[i][s];
}
// decision retrieval
vector<int> getSubset(int S) {
  solve(n, S);
  // assume dp[i][s] == 1, otherwise we have no subset to return
  vector<int> nums;
  for (int i = n; i >= 1; i--) {
    if (take[i][S]) { // check if we need to take the last element
      nums.push_back(a[i]);
      S -= a[i];
    }
  }
  return nums;
}
