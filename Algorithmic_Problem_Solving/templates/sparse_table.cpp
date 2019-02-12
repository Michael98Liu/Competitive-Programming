// construction
for (int i = 0; i < N; i++) minVal[0][i] = i;
for (int k = 1; k < LOGN; k++) {
  for (int i = 0; i < N; i++) {
    minVal[k][i] = minVal[k - 1][i];
    int i2 = i + (1 << (k - 1));
    if (i2 < N && arr[minVal[k - 1][i2]] < arr[minVal[k][i]])
      minVal[k][i] = minVal[k - 1][i2];
  }
}

int get(int l, int r) { // l <= r
  // largestPower returns max k where 2^k <= range length.
  // It can be implemented in O(logN) time.
  // Or if we precompute largestPower for
  // every possible length (with a O(N) space tradeoff),
  // we can implement it in O(1) time.
  int k = largestPower(r - l + 1);
  return min(arr[minVal[k][l]],
             arr[minVal[k][r - (1<<k) + 1]]);
}
