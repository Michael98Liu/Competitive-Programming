unsigned long long next_combination(unsigned long long x) {
  unsigned long long u = x & -x;
  unsigned long long v = u + x;
  return v +(((v^x)/u)>>2);
}
