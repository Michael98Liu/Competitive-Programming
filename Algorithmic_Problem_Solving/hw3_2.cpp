#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

int main(){
    int n;

    scanf("%d\n", &n);
    char event;
    int num;

    int* array = new int[(int)10e5];
    deque<int> sstack;

    //int last_s = 10e9+1;
    int* begin = array;
    int* last = array;
    int i = 0;

    map<int, int> count;
    map<int, int>::iterator it;

    while( i < n ){
        //printf("%d %d\n", i, n);
        cin >> event;
        //printf(" out %c\n", event);

        if( event == 'a' ){
            cin >> num;
            *last = num;
            it = count.find(num);

            if( it == count.end() ) count[num] = 1;
            else count[num] += 1;

            last ++;
            if( sstack.size() == 0 ){
                printf("-1\n" );
                sstack.push_back(num);
            }
            else{
                while( sstack.size() != 0 && sstack.back() >= num ){
                    sstack.pop_back();
                }

                if( sstack.size() == 0 ){
                    printf("-1\n" );
                    sstack.push_back(num);
                }
                else{
                    printf("%d\n", sstack.back() );
                    sstack.push_back(num);
                }
            }
        }
        else{
            //for( int* b = begin; b < begin + 3; b ++) printf("## %d\n", *b);
            if( begin != last ){
                printf("%d\n", *begin);
                count[*begin] --;
            }
            else printf("-1\n" );
            //printf("hre\n" );
            if( sstack.size() != 0 && *begin == sstack.front() && count[*begin] == 0) sstack.pop_front();
            if( begin != last ) begin ++;

            //if( begin == last) printf("overlap\n" );
        }

        i ++;
    }

    return 0;
}
