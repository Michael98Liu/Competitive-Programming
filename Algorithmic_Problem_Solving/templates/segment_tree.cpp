int val[MAX_NODES]; // maintained value on the tree node, MAX_NODES >= 4n
// build a segment tree for range minimum query on array arr[]
// [nl, nr] is node k's managed range
void build(int k, int nl, int nr) {
  if (nl == nr) {
    val[k] = a[nl];
    return;
  }
  int nm = (nl + nr) / 2;
  build(2*k+1, nl, nm);
  build(2*k+2, nm+1, nr);
  val[k] = min(val[2*k+1], val[2*k+2]);
}

int getMin(int k, int nl, int nr, int l, int r){
  // this node is out of the query range
  if(r < nl || l > nr) return INF;
  // this node is completely in the query range
  // return maintained minimum at this node
  if(l <= nl && nr <= r) return val[k];
  int nm = (nl + nr) / 2;
  int ansLeft = getMin(2*k+1, nl, nm, l, r);
  int ansRight = getMin(2*k+2, nm+1, nr, l, r);
  return min(ansLeft, ansRight); // combine answers of two children
}

void add(int k, int nl, int nr, int x, int v){
  // this node does not contain x
  if(x < nl || x > nr) return;
  // this node is [x, x]
  if(nl == x && nl == nr){
    val[k] += v;
    return;
  }
  int nm = (nl + nm) / 2;
  add(2*k+1, nl, nm, x, v);
  add(2*k+2, nm+1, nr, x, v);
  // Update the minimum because some descendant's value changed
  val[k] = min(val[2*k+1], val[2*k+2]);
}

// Usage: To add a value v to arr[x] inside arr[1..n]
add(0, 1, n, x, v);

// Usage: to get the minimum of arr[l..r] from arr[1..n]
getMin(0, 1, n, l, r);

// To build the tree for arr[1..n]
build(0, 1, n);
// To build the tree for arr[0..(n-1)]
build(0, 0, n-1);
