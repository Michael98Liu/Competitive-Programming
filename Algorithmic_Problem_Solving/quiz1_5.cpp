#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    Node(int n, Node* p){
        num = n;
        parent = p;
    }
    int num;
    Node* parent;
    Node* left = nullptr;
    Node* right = nullptr;
};

void traverse(Node* root){
    if( root->left != nullptr ) traverse(root->left);
    if( root->right != nullptr) traverse(root->right);
    printf("%d ", root->num);
}

int main(){
    int n;
    scanf("%d\n", &n);
    std::vector<int> v;
    int num;

    for( int i = 0; i < n; i++ ){
        cin >> num;
        v.push_back(num);
    }

    Node* root = new Node(v[0], nullptr);
    Node* prev = root;
    Node* prev_root = root;
    int i =1;

    while( i < n ){
        while( v[i] < v[i-1] ){
            Node * node = new Node(v[i], prev);
            prev->left = node;
            prev = node;
            i ++;
        }
        prev = prev->parent;
        while( i < n && v[i] > v[i-1] && v[i] < prev_root->num ){
            Node * node = new Node(v[i], prev);
            prev->right = node;
            prev = prev->parent;
            i++;
        }
        if( i < n){
            Node * node = new Node(v[i], root);
            prev_root->right = node;
            prev = node;
            prev_root = node;
            i++;
        }
    }

    traverse(root);
    printf("\n" );

    //printf("%d %d %d\n", root->right->num, root->right->right->num, root->right->right->left->num);

    return 0;
}
