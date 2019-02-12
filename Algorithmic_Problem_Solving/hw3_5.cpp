#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <deque>
//#include <chrono>

using namespace std;

int traverse(map<int, vector<int> >& tree, vector<int>& visited, int start, int level){
    deque<int> to_visit;
    to_visit.push_back(start);
    to_visit.push_back(-1);// signify end of a layer
    int current;

    while( to_visit.size() > 1 ){
        current = to_visit.front();
        to_visit.pop_front();

        if( current == -1 ){
            level ++;
            to_visit.push_back(-1);
            continue;
        }

        visited[current] = level;
        for( auto it = tree[current].begin(); it != tree[current].end(); it ++ ){
            if( visited[*it] == -1 ) to_visit.push_back(*it);
        }
    }


    return level;
}

int find_n(int level, vector<int>& visited){
    for( int i = 0; i < visited.size() ; i ++ ){
        //printf("%d\n", it->second);
        if( visited[i+1] == level ) return i + 1;
    }
    return -1;
}

int find_ans(int level1, vector<int>& visited_old, int level2, vector<int>& visited_new){
    // need to make sure the distance to two end pointes sum to diameter
    for( int i = 0; i < visited_old.size(); i ++ ){
        if( visited_old[i+1] == level1 && visited_new[i+1] == level2 ) return i + 1;
    }
    return -1;
}

int main(){
    //using clock = std::chrono::steady_clock;
    //clock::time_point start = clock::now();

    int n, v1, v2;
    scanf("%d\n", &n);
    map<int, vector<int> > tree1;
    map<int, vector<int> > tree2;

    vector<int> visited1(n+1, -1);// store the depth of the node
    vector<int> visited_old1(n+1, -1);
    vector<int> visited_new1(n+1, -1);

    map<int, vector<int> >::iterator it;

    for( int i = 0; i < n-1; i ++ ){
        scanf("%d %d\n", &v1, &v2);

        it = tree1.find(v1);
        if( it == tree1.end() ){
            tree1[v1] = vector<int>();
        }
        tree1[v1].push_back(v2);

        it = tree1.find(v2);
        if( it == tree1.end() ){
            tree1[v2] = vector<int>();
        }
        tree1[v2].push_back(v1);
    }

    scanf("%d\n", &n);
    vector<int> visited2(n+1, -1);
    vector<int> visited_old2(n+1, -1);
    vector<int> visited_new2(n+1, -1);

    for( int i = 0; i < n-1; i ++ ){
        scanf("%d %d\n", &v1, &v2);

        it = tree2.find(v1);
        if( it == tree2.end() ){
            tree2[v1] = vector<int>();
        }
        tree2[v1].push_back(v2);

        it = tree2.find(v2);
        if( it == tree2.end() ){
            tree2[v2] = vector<int>();
        }
        tree2[v2].push_back(v1);
    }

    // find a longest distance
    int d1 = traverse(tree1, visited_old1, 1, 0);
    int d2 = traverse(tree2, visited_old2, 1, 0);

    //printf("1\n" );

    int s1 = find_n(d1, visited_old1);// one furthest point, level to 0
    int s2 = find_n(d2, visited_old2);

    d1 = traverse(tree1, visited1, s1, 0);
    d2 = traverse(tree2, visited2, s2, 0);// in visited1, s1 is 0

    int f1 = find_n(d1, visited1);
    int f2 = find_n(d2, visited2);

    //printf("2\n" );

    d1 = traverse(tree1, visited_new1, f1, 0);
    d2 = traverse(tree2, visited_new2, f2, 0);

    // traverse and return node with correct height
    int half_d1 = (d1 + 1)/2;
    int half_d2 = (d2 + 1)/2;
    int d3 = half_d1 + half_d2 + 1;

    //printf("%d %d %d\n", d1, d2, d3);
    //printf("%d %d\n", half_d1, half_d2);

    //printf("2\n" );

    int n1 = find_ans(half_d1, visited1, d1 - half_d1, visited_new1);
    int n2 = find_ans(half_d2, visited2, d2 - half_d2, visited_new2);

    printf("%d\n", max(d1, max(d2, d3)));

    printf("%d %d\n", n1, n2);

    //clock::time_point end = clock::now();
    //clock::duration execution_time = end - start;
    //cout << execution_time.count() << endl;
}
