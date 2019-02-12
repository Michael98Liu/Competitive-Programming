#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Job{
public:
    int job_time;
    int job_fine;
    int ind;

    Job(int t, int f, int i){
        job_time = t;
        job_fine = f;
        ind  = i;
    }
};

bool operator< (const Job& lhs, const Job& rhs){
    return lhs.job_time * rhs.job_fine < rhs.job_time * lhs.job_fine;
}

int main(){
    int t;
    int n;
    scanf("%d\n", &t);

    for( int i =0; i< t; i++ ){
        scanf("\n" );
        scanf("%d\n", &n);

        vector<Job> jobs;
        int j_time, f;

        for( int j = 0; j< n; j++ ){
            scanf("%d %d\n", &j_time, &f);
            jobs.push_back(Job(j_time, f, j));
        }

        sort(jobs.begin(), jobs.end());
        int ind = 0;

        for( auto it = jobs.begin(); it != jobs.end(); it ++ ){
            printf("%d", it->ind + 1);
            if( ind != n-1 ) printf(" ");
            ind ++;
        }
        printf("\n" );
        if( i != t-1) printf("\n" );
    }

    return 0;
}
