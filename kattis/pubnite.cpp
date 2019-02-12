#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int xs, ys, ss, ri, rf;
    int xa, ya, sa;
    scanf("%d %d %d %d %d\n%d %d %d\n", &xs, &ys, &ss, &ri, &rf, &xa, &ya, &sa);

    float dist = sqrt((xa-xs)*(xa-xs) + (ya-ys)*(ya-ys));
    float maxT = (dist - rf)/sa;
    float danger = 0;

    if( dist <= ri){
        // in the safty zone
        if( sa >= ss ) printf("%.6f\n", danger );
        else if( sa < ss ){
            float safeT = (ri - dist)/(ss-sa);
            float safeR = dist - safeT*sa;
            danger += (safeR - rf)/sa;

            printf("%.6f\n", danger);
        }
    }
    else if( dist > ri ){
        if( sa <= ss ){
            danger += (dist - rf)/sa;
            printf("%.6f\n", danger);
        }
        else if( sa > ss ){
            float chaseT = (dist - ri)/(sa-ss);
            danger += min(maxT, chaseT);
            printf("%.6f\n", danger);
        }
    }
}
