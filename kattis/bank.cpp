/* Surely you want all the guys with largest sum of money to deposite. SO the question is how to arrange them.
    To serve them as late as possible, you leave as much room for other people as possible. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person{
public:

    int money;
    int time;

    Person(int m, int t){
        money = m;
        time = t;
    }
};

bool operator<(const Person& lhs, const Person &rhs){
    if( lhs.money > rhs.money ) return true;
    else return false;
}

int main(){
    int n, t;
    scanf("%d %d\n", &n, &t);
    int money, time;
    vector<Person> v;
    int* result = new int[t];
    for( int i = 0; i< t; i++){
        result[i] = 0;
    }

    for( int i = 0; i < n; i++ ){
        scanf("%d %d\n", &money, &time);
        v.push_back(Person(money, time));
    }

    sort(v.begin(), v.end());

    auto it = v.begin();
    int ans = 0;

    while( it != v.end() ){
        int serving_time = it->time;

        while( serving_time >= 0 && result[serving_time] != 0 ){
            serving_time --;
        }
        if( serving_time >= 0 ){
            //printf("%d %d\n", serving_time, it->money);
            result[serving_time] = it->money;
            v.erase(it);
        }
        else it ++;
    }

    for( int i = 0; i < t; i++){
        ans += result[i];
    }

    printf("%d\n", ans);
    return 0;

}
