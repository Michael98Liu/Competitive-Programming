#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
using namespace std;

int main(){
    int n;
    string name;
    string student;

    list<string > llist;
    list<string >::iterator list_it;
    map<string, list<string>::iterator > mmap;
    map<string, int>::iterator map_it;
    scanf("%d\n", &n);
    list_it = llist.begin();

    for( int i =0; i<n; i++ ){
        cin >> name;

        list_it = llist.insert(list_it, name);
        //printf("%s\n", (*list_it).c_str() );
        mmap[name] = list_it;
        list_it = llist.end();
    }
    /*

    for( list<string >::iterator it = llist.begin(); it != llist.end(); it++ ){
        printf("%s\n", (*it).c_str());
    }
    */

    int m;
    scanf("%d\n", &m);
    char op;

    for( int i = 0; i<m; i++ ){
        cin >> op;
        if( op == 'j' ){
            cin >> name;

            list_it = llist.end();
            list_it = llist.insert(list_it, name);
            //printf("%s\n", (*list_it).c_str() );
            mmap[name] = list_it;
        }
        else if( op == 's' ){
            printf("%s\n", llist.front().c_str());
            llist.pop_front();
        }
        else if( op == 'l'){
            cin >> name;
            //printf("left %s\n", llist.front().c_str());
            list_it = mmap[name];
            llist.erase(list_it);
        }
    }

    return 0;
}
