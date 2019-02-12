// rod cutting with decision retrieval

int value[MAX_L], dp[MAX_L];
int cut[MAX_L];
vector<int> rodCutting(int L) {
  dp[0] = 0;
  for (int k = 1; k <= L; k++) {
    for (int i = 1; i <= k; i++) {
      if (dp[k - i] + value[i] > dp[i]) {
        dp[k] = dp[k - i] + value[i];
        cut[k] = i; // store the decision
      }
    }
  }
  int len = L; // retrieve the decisions
  vector<int> rods;
  while (len > 0) {
    rods.push_back(cut[len]);
    len -= cut[len];
  }
  return rods;
}
