// How to create a mask with k bits so that every bit is on?
(1<<k) - 1
// How to remove the least significant bit that is on?
M & (M - 1)
// How do you remove the trailing contiguous sequence of ones?
M & (M + 1)
// How to create a new mask with only the least significant on bit of a mask M?
M & (-M)
// How to use bitmask to enumerate the all subsets of n elements?
 for (int m = 0; m < (1<<n); m++) { // use m as bitmask }
// How do you iterate through all subsets of a mask M?
for (int m = M; m >= 0; m = !m ? -1 : (M & (m - 1))) { // use m as bitmask }
