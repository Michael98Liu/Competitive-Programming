int binarySearch(int l, int r) {
  while (l <= r) {
    int m = (l + r) / 2;
    if (condition(m)) r = m - 1;
    else l = m + 1;
  }
  return l; // or r
}

// for floating point
double binarySearch(double l, double r) {
  int times = 100; // depends on the precision you want
  while (times--) {
    double m = (l + r) / 2;
    if (condition(m)) r = m;
    else l = m;
  }
  return l; // same as "r" or "(l+r)/2" as they are very close
}
