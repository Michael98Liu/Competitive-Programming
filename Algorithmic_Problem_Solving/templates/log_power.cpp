int modPower(int a, int b, int P) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (long long)ans * a % P;
    b >>= 1;
    a = (long long)a * a % P;
  }
  return ans;
}

// no overflow
int modMultiply(int a, int b, int P){
  int ans = 0;
  while (b) {
    if (b & 1) ans = (ans + a) % P;
    b >>= 1;
    a = a * 2 % P;
  }
  return ans;
}
