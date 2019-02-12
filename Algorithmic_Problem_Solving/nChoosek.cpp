int nChoosek( int n, int k ){

    if( k > n ){
        return 0;
    }
    if( k * 2 > n ){
        k = n-k;
    }
    if( k == 0 ){
        return 1;
    }

    int ans = n;
    for( int i = 2; i <= k; ++i ) {
        ans *= (n-i+1);
        ans /= i;
    }

    return ans;
}
