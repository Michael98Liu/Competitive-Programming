#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    Node* parent;
    int rank = 0;
    int member = 1;
};

void initUnionFind(vector<Node*>& groups){
    for( auto it = groups.begin(); it != groups.end(); it++ ){
        (*it)->parent = (*it);
    }
}

Node* findRoot(Node* x){
    if( x->parent ==  x ) return x;
    return x->parent = findRoot(x->parent);
}

void unionNodes(Node* x, Node* y){
    Node* xRoot = findRoot(x);
    Node* yRoot = findRoot(y);
    if( xRoot->rank > yRoot->rank ) swap(xRoot, yRoot);
    if( xRoot->rank == yRoot->rank ) yRoot->rank += 1;
    xRoot->parent = yRoot;
}

int main(){
    int n, m;
    vector<Node*> students;
    int case_count = 0;
    int reli_count = 0;
    while( scanf("%d %d\n", &n, &m) ){
        if( m == 0 && n==0) break;
        case_count += 1;
        reli_count = n;
        for( int i = 0; i < n; i++){
            Node* node = new Node();
            students.push_back(node);
        }
        initUnionFind(students);

        int stu1, stu2;
        for( int i= 0; i< m; i++){
            scanf("%d %d\n", &stu1, &stu2);
            if( findRoot(students[stu1-1]) != findRoot(students[stu2-1]) ) reli_count --;
            unionNodes(students[stu1-1], students[stu2-1]);
        }

        students.clear();
        printf("Case %d: %d\n", case_count, reli_count);
    }
    return 0;
}
