class Solution(object):
    def sumSubarrayMins(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        a = sum(A) % 1000000007
        prev = A[:]

        for l in range(1, len(A)):
            # l is the length of the subarray
            new = [prev[i-l] if prev[i-l] < A[i] else A[i] for i in range(l, len(A))]
            a = (a+ sum(new)) % 1000000007
            prev = new[:]

        return a


class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int length = A.size();
        long long sum = 0;
        int modulo = 1000000007;
        int i = 0;
        int* prev = new int[length];

        for(std::vector<int>::iterator it = A.begin(); it != A.end(); ++it){
            sum += *it;
            prev[i] = *it;
            i++;
        }
        sum = sum % modulo;

        int* novel;

        for( int l = 1; l < length; l++ ){
            novel = new int[length - l];
            for( i = l; i < length; i ++){
                if( prev[i - l] < A[i] ) novel[i - l] = prev[i-l];
                else novel[i - l] = A[i];
                //printf("%d/n", novel[i - l]);
                sum += novel[i - l];
            }
            sum = sum % modulo;
            delete[] prev;
            prev = novel;
        }
        return (int)sum;


    }
};
