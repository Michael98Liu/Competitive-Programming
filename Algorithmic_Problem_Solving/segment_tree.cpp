#define MAXN 100001
#define MAXSEG (4*MAXN) // MAXSEG >= 4N
const int INF = (int)1e9;

int val[MAXSEG]; // maintained values, root is at 0

void build(int k, int nl, int nr) {
    if (nl == nr) {
        val[k] = arr[nl]; // arr[] is the original array
        return;
    }
    int nm = (nl+nr)/2;
    build(2*k+1, nl, nm);
    build(2*k+2, nm+1, nr);
    val[k] = min(val[2*k+1], val[2*k+2]); // range minimum
}

// Add v to arr[x]
void add(int k, int nl, int nr, int x, int v) {
	if(r < nl || l > nr) return; // x is outside the node's range
	if (nl == nr) { // on a leaf that manages a single element
		val[k] += v
		return;
	}
	int nm = (nl+nr)/2;
	add(2*k+1, nl, nm, l, r, v);
	add(2*k+2, nm+1, nr, l, r, v);
	val[k] = min(val[2*k+1], val[2*k+2]);	// update maintained minimum
}

// Get minimum in arr[l..r]
int get(int k, int nl, int nr, int l, int r) {
  // query range is outside the node's range
	if(r < nl || l > nr) return INF;
	// node's range is entirely covered by the query range
	if(l <= nl && nr <= r) return val[k];
	int nm = (nl+nr)/2;
	int ansLeft = get(2*k+1, nl, nm, l, r);
    int ansRight = get(2*k+2, nm+1, nr, l, r);
	return min(ansLeft, ansRight);
}
