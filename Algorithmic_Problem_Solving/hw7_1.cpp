#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    long long n, k, s, d;
    scanf("%llu %llu\n", &n, &k);
    long long sessCount = 0;
    long long sessEnd = 0;
    vector< pair<long long, long long> > students;

    for( long long i = 0; i < n; i++ ){
        scanf("%llu %llu\n", &s, &d);
        students.push_back(make_pair(s, d));
    }

    sort(students.begin(), students.end());

    sessEnd = students.begin()->first;
    for( auto it = students.begin(); it != students.end(); it ++ ){
        long long endTime = it->second + it->first;
        //printf("newstu: %llu\n", it->first);
        if( endTime > sessEnd ){
            long long sessStart = max(it->first, sessEnd);
            long long count = (long long) ceil((double)( endTime - sessStart )/ (double)k);
            sessEnd = sessStart + count * k;
            sessCount += count;
        }
        //printf("sessend: %llu studend: %llu\n", sessEnd, endTime);
    }
    printf("%llu\n", sessCount);
    return 0;
}
