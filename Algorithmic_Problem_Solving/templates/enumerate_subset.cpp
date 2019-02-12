bool chosen[N];
void enumerateSubset(int i) {
  if (i == N) {
    // Elements that has chosen flag is in the subset.
    return;
  }
  chosen[i] = true;
  enumerateSubset(i + 1); // pick the i-th element
  chosen[i] = false;
  enumerateSubset(i + 1); // do not pick the i-th element
}

// each element is either in the set or not
for (int m = 0; m < (1<<N); m++) {
  for (int i = 0; i < N; i++) {
    if ((m >> i) & 1) {
      // element i is in the subset
    }
  }
}
