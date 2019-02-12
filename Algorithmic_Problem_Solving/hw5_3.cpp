#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Node{
public:
    string name;
    int age;
    Node* parent;
    int rank;
    string youngest;
    string oldest;

    Node(string s, int i){
        name = s;
        age = i;
    }
};

void initUnionFind(vector<Node*>& groups){
    for( auto it = groups.begin(); it != groups.end(); it++ ){
        (*it)->parent = (*it);
        (*it)->rank = 0;
        (*it)->youngest = (*it)->name;
        (*it)->oldest = (*it)->name;
    }
}

Node* findRoot(Node* x){
    if( x->parent ==  x ) return x;
    return x->parent = findRoot(x->parent);
}

void unionNodes(Node* x, Node* y, map<string, Node*>& address){
    Node* xRoot = findRoot(x);
    Node* yRoot = findRoot(y);
    if( xRoot->rank > yRoot->rank ) swap(xRoot, yRoot);
    if( xRoot->rank == yRoot->rank ) yRoot->rank += 1;
    xRoot->parent = yRoot;
    int y1 = address[xRoot->youngest]->age, y2 = address[yRoot->youngest]->age;
    int o1 = address[xRoot->oldest]->age, o2 = address[yRoot->oldest]->age;
    if( y1 < y2 ) yRoot->youngest = xRoot->youngest;
    else if( y1 == y2 ){
        if( xRoot->youngest < yRoot->youngest ) yRoot->youngest = xRoot->youngest;
    }
    if( o1 > o2 ) yRoot->oldest = xRoot->oldest;
    else if( o1 == o2 ){
        if( xRoot->oldest < yRoot->oldest ) yRoot->oldest = xRoot->oldest;
    }
}

int main(){
    int n, age;
    string name;
    vector<Node*> groups;
    map<string, Node*> address;
    scanf("%d\n", &n);

    for( int i = 0; i < n; i++ ){
        cin >> name >> age;
        Node* node = new Node(name, age);
        groups.push_back(node);
        address[name] = node;
    }
    initUnionFind(groups);

    scanf("%d\n", &n);
    string p1, p2;

    for( int i = 0; i < n; i++ ){
        cin >> p1 >> p2;
        unionNodes(address[p1], address[p2], address);
        Node* root = findRoot(address[p1]);
        printf("%s %s\n", root->youngest.c_str(), root->oldest.c_str());
    }


    return 0;
}
