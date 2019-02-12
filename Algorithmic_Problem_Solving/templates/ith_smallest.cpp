int get_ith(int i) {
  int l = 1, r = 1000000;
  while (l <= r) {
    int m = (l + r) / 2;
    if (getPrefixSum(m) < i) l = m + 1; // getPrefixSum is supported by Fenwick
    else r = m - 1;
  }
  return l; // smallest number that satisfies condition getPrefixSum(m) >= i
}


// optimized
int get_ith(int i){
  // Here we find the largest "val" where the sum of values between [1, val]
  // is smaller than i. So the i-th smallest position is at "val+1".
  // Since in Fenwick tree we offset the positions by one ("k++"),
  // we shall deduct one from the reported number, so we just return (val+1)-1 = val
  int val = 0, count = 0;
  for(int p = LOGN; p >= 0; p--){
    int stepSize = 1<<p, jumpTo = val+stepSize;
    if(jumpTo >= MAXN || count + fenwick[jumpTo] >= i) continue;
    val = jumpTo;
    count += fenwick[val];
  }
  return val;
}
