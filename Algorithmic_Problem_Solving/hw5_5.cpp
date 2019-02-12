#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Node{
public:
    int height;
    int rank = 0;
    int row;
    int col;
    Node* parent;

    Node(int h, int r, int c){
        height = h;
        row = r;
        col = c;
    }
};

void initUnionFind(vector<vector<Node*> >& islands){
    for( auto it = islands.begin(); it != islands.end(); it++ ){
        for( auto iit = it->begin(); iit != it->end(); iit++ ){
            (*iit)->parent = (*iit);
        }
    }
}

Node* findRoot(Node* x){
    if( x->parent ==  x ) return x;
    return x->parent = findRoot(x->parent);
}

void findNeighbours(Node* node, set<Node*>& neighbours, vector< vector<Node*> >& islands, int n, int m, int cell_level){
    Node* root;
    root = findRoot(islands[node->row][node->col]);
    if( root->height >= cell_level) neighbours.insert(root);

    if( node->col + 1 < m){
        root = findRoot(islands[node->row][node->col + 1]);
        if( root->height >= cell_level) neighbours.insert(root);
    }
    if( node->col -1 >=0 ){
        root = findRoot(islands[node->row][node->col - 1]);
        if( root->height >= cell_level) neighbours.insert(root);
    }
    if( node->row + 1 < n){
        root = findRoot(islands[node->row + 1][node->col]);
        if( root->height >= cell_level) neighbours.insert(root);
    }
    if( node->row -1 >=0 ){
        root = findRoot(islands[node->row - 1][node->col]);
        if( root->height >= cell_level) neighbours.insert(root);
    }
}

void unionNodes(Node* x, Node* y){
    Node* xRoot = findRoot(x);
    Node* yRoot = findRoot(y);
    if( xRoot->rank > yRoot->rank ) swap(xRoot, yRoot);
    if( xRoot->rank == yRoot->rank ) yRoot->rank += 1;
    xRoot->parent = yRoot;
}


int main(){
    int n, m, q, num;
    scanf("%d %d %d\n", &n, &m, &q);
    vector<Node*> row;
    vector< vector<Node*> > islands;
    map<int, vector<Node*> > heights;
    auto hit = heights.begin();

    for( int i = 0; i < n; i++){
        islands.push_back(vector<Node*>());
        for( int j = 0; j < m; j++ ){
            cin >> num;
            Node* node = new Node(num, i, j);
            islands[i].push_back(node);
            hit = heights.find(num);
            if( hit == heights.end() ) heights[num] = vector<Node*>();
            heights[num].push_back(node);
        }
    }
    initUnionFind(islands);

    vector<int> query;
    map<int, int> result;

    for( int i = 0; i<q; i++ ){
        cin >> num;
        query.push_back(num);
        result[num] = 0;
    }

    auto mit = heights.rbegin();
    set<Node*> neighbours;
    int island_count = 0;
    int water_level = 0;

    for( auto it = result.rbegin(); it != result.rend(); it++ ){
        water_level = it->first;
        //printf("water_level: %d\n", water_level);

        while( mit->first > water_level && mit != heights.rend() ){
            // for all islands with height greater than water level
            island_count += mit->second.size();
            //printf("%d %lu\n", mit->first, mit->second.size());

            for( auto vit = mit->second.begin(); vit != mit->second.end(); vit ++ ){
                findNeighbours(*vit, neighbours, islands, n, m, (*vit)->height);
                //printf("neighbours: %lu\n", neighbours.size());
                island_count = island_count - neighbours.size()+ 1;

                for( auto sit = neighbours.begin(); sit != neighbours.end(); sit ++ ){
                    unionNodes(*vit, *sit);
                }
                neighbours.clear();
            }
            mit ++;
        }
        result[water_level] = island_count;
        //printf("count: %d\n\n", island_count);

        // count how many unique neighbours
    }

    for( auto it = query.begin(); it != query.end(); it ++ ){
        printf("%d\n", result[*it]);
    }

    return 0;
}
