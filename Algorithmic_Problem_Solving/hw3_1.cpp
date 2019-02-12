#include <iostream>
#include <map>
#include <list>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int n, q;
    scanf("%d\n", &n);

    list<string > llist;
    list<string >::iterator list_it;
    map<string, list<string>::iterator > mmap;
    map<string, int>::iterator map_it;

    list_it = llist.begin();
    string mystr, name;

    getline (cin, mystr);
    istringstream ss(mystr);

    for( int i = 0; i < n; i++ ){
        ss >> name;

        list_it = llist.insert(list_it, name);
        //printf("%s\n", (*list_it).c_str() );
        mmap[name] = list_it;
    }



    scanf("%d\n", &q);

    char event;
    string student, stu2;

    for( int i = 0; i < q; i ++ ){
        cin >> event >> student;
        if( event == 'e' ){
            list_it = mmap[student];
            llist.erase(list_it);
            mmap[student] = llist.end();
        }
        else if( event == 'x'){
            cin >> stu2;
            list_it = mmap[student];
            mmap[student] = mmap[stu2];
            mmap[stu2] = list_it;
            *(mmap[student]) = student;
            *(mmap[stu2]) = stu2;
        }
        else if( event == 'r' ){
            list_it = mmap[student];
            //printf("finding left %s\n", (*list_it).c_str());
            //printf("first %s\n", (*llist.begin()).c_str());
            if( list_it != llist.begin() && list_it != llist.end() ){
                list_it --;
                printf("%s\n", (*list_it).c_str());
            }
            else{
                // if first in the row
                printf("-1\n" );
            }
        }
        else if( event == 'l' ){
            list_it = mmap[student];
            if( list_it != llist.end() ){
                list_it ++;
                if( list_it != llist.end() ) printf("%s\n", (*list_it).c_str());
                else printf("-1\n" );
            }
            else{
                printf("-1\n" );
            }
        }
    }

    return 0;

}
