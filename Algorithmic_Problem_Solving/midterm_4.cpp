#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>

using namespace std;

class Node{
public:
    Node* parent;
    int rank;
    int member;
    bool isInfected;

    Node(){
        rank = 0;
        member = 1;
        isInfected = false;
    }
};

void initUnionFind(vector<Node*>& Nodes){
    for( auto it = Nodes.begin(); it != Nodes.end(); it++ ){
        (*it)->parent = (*it);
        (*it)->rank = 0;
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
    if( xRoot != yRoot ){
        yRoot->member = yRoot->member + xRoot->member;
        if( xRoot->isInfected ) yRoot->isInfected = true;
    }
    xRoot->parent = yRoot;

}

int main(){
    int n, q;
    scanf("%d %d\n", &n, &q);
    map<int, Node*> nodes;
    char op;
    int x, y;

    int infected = 0;

    for( int i = 0; i < q; i++ ){
        cin >> op;
        //printf("%c ", op);

        if( op == 'c' ){
            cin >> x >> y;
            //#printf("%d %d\n", x, y);

            auto it = nodes.find(x);
            if( it == nodes.end() ){
                Node* node = new Node();
                node->parent = node;
                nodes[x] = node;
            }

            it = nodes.find(y);
            if( it == nodes.end() ){
                Node* node = new Node();
                node->parent = node;
                nodes[y] = node;
            }

            Node* xroot = findRoot(nodes[x]);
            Node* yroot = findRoot(nodes[y]);

            if( xroot != yroot ){

                if( xroot->isInfected && !yroot->isInfected ) infected += yroot->member;
                if( !xroot->isInfected && yroot->isInfected ) infected += xroot->member;
                unionNodes(nodes[x], nodes[y]);

            }


            printf("%d\n", infected);
        }

        else if( op == 'v' ){
            cin >> x;
            //#printf("%d\n", x);

            auto it = nodes.find(x);
            if( it == nodes.end() ){
                Node* node = new Node();
                node->parent = node;
                nodes[x] = node;
            }

            Node* root = findRoot(nodes[x]);
            if(!root->isInfected) infected += root->member;
            root->isInfected = true;


            printf("%d\n", infected);
        }

        else if( op == 'p' ){
            cin >> x;
            //printf("%d\n", x);
            auto it = nodes.find(x);
            if( it == nodes.end() ){
                Node* node = new Node();
                node->parent = node;
                nodes[x] = node;
            }

            Node* root = findRoot(nodes[x]);
            if( root->isInfected ) infected -= root->member;
            root->isInfected = false;
            printf("%d\n", infected);
        }
    }



    return 0;
}
