#define MAXN 100005
int fenwick[MAXN];
void add(int k, int v){
  k++;
  for(; k<MAXN;k += -k&k) fenwick[k] += v;
}
int get(int k){
  if (k < 0) return 0;
  k++;
  int ans = 0;
  for(; k; k -= -k&k) ans += fenwick[k];
  return ans;
}

/* the implementation of FenwickTree is with the help from book
    "Competitive Programming 3: the new lower bound of programming contests",
    by the Halim brothers. */
class FenwickTree{
public:
    vi ft;

    FenwickTree(int n){
        ft.assign(n+1, 0);
    }

    int rsq(int b){
        int sum = 0;
        for(; b; b -= (b & (-b)) ){
            sum += ft[b];
        }
        return sum;
    }

    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0: rsq(a-1));
    }

    void adjust(int k, int v){
        for(;k < (int)ft.size(); k += (k & (-k)) ){
            ft[k] += v;
        }
    }
};
