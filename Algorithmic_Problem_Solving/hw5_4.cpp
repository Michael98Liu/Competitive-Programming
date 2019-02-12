#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

class Card;

class Node{
public:
    Node(){
        rank = 0;
        color = 0;
        member = 1;
    }
    Node* parent;
    Card* card;
    int rank;
    int color;// red 1, black -1
    int member;
};

class Card{
public:
    Card(int i){
        num = i;
    }
    int num;
    Node* node;
    Node* node_prime;
};

void initUnionFind(vector<Card*>& cards, int n){
    for(int i = 1; i <= n; i++){
        Card* card = new Card(i);
        card->node = new Node();
        card->node_prime = new Node();
        card->node->parent = card->node;
        card->node_prime->parent = card->node_prime;
        card->node->card = card;
        card->node_prime->card = card;
        cards.push_back(card);
    }
}

Node* findRoot(Node* x){
    if( x->parent ==  x ) return x;
    return x->parent = findRoot(x->parent);
}

Node* unionNodes(Node* x, Node* y){
    Node* xRoot = findRoot(x);
    Node* yRoot = findRoot(y);
    if( xRoot != yRoot ){
        if( xRoot->rank > yRoot->rank ) swap(xRoot, yRoot);
        if( xRoot->rank == yRoot->rank ) yRoot->rank += 1;
        xRoot->parent = yRoot;
        yRoot->member = yRoot->member + xRoot->member;
        if( xRoot->color != 0 ){
            yRoot->color = xRoot->color;
        }
    }

    return yRoot;
}

int isSameInvalid(Card* x, Card* y, int i){
    Node* xRoot = findRoot(x->node);
    Node* yRoot = findRoot(y->node);
    Node* xRoot_prime = findRoot(x->node_prime);
    Node* yRoot_prime = findRoot(y->node_prime);
    if( xRoot == yRoot_prime ){
        printf("Q%d: ?\n", i+1);
        return -1;
    }
    else if( (xRoot->color != 0 && xRoot->color == yRoot_prime->color) ||
            (yRoot->color != 0 && yRoot->color == xRoot_prime->color) ){
        printf("Q%d: ?\n", i+1);
        return -1;
    }
    return 0;
}

int isDiffInvalid(Card* x, Card* y, int i){
    Node* xRoot = findRoot(x->node);
    Node* yRoot = findRoot(y->node);
    Node* xRoot_prime = findRoot(x->node_prime);
    Node* yRoot_prime = findRoot(y->node_prime);
    if( xRoot == yRoot ){
        printf("Q%d: ?\n", i+1);
        return -1;
    }
    else if( (xRoot->color != 0 && xRoot->color == yRoot->color) ||
            (xRoot_prime->color != 0 && yRoot_prime->color == xRoot_prime->color) ){
        printf("Q%d: ?\n", i+1);
        return -1;
    }
    return 0;
}

int main(){
    int n, q;
    scanf("%d %d\n", &n, &q);
    vector<Card*> cards;
    unsigned long full = (1<<n) -1;
    initUnionFind(cards, n);

    char op;
    int c1, c2, counter = 0;

    for( int i = 0; i < q; i ++ ){
        cin >> op;
        if( op == 'd'){
            cin >> c1 >> c2;
            Node* root1 = findRoot(cards[c1-1]->node);
            Node* root2_prime = findRoot(cards[c2-1]->node_prime);

            if( isDiffInvalid(cards[c1-1], cards[c2-1], i) == 0 ){
                if( root1->color != 0 && root2_prime->color == 0 ){
                    counter += root2_prime->member;
                }
                else if( root1->color == 0 && root2_prime->color != 0 ){
                    counter += root1->member;
                }
                unionNodes(cards[c1-1]->node, cards[c2-1]->node_prime);
                unionNodes(cards[c1-1]->node_prime, cards[c2-1]->node);
            }

        }
        else if( op == 's' ){
            cin >> c1 >> c2;
            Node* root1 = findRoot(cards[c1-1]->node);
            Node* root2 = findRoot(cards[c2-1]->node);

            if( isSameInvalid(cards[c1-1], cards[c2-1], i) == 0 ){
                if( root1->color != 0 && root2->color == 0){
                    counter += root2->member;
                }
                else if( root1->color == 0 && root2->color != 0 ){
                    counter += root1->member;
                }
                unionNodes(cards[c1-1]->node, cards[c2-1]->node);
                unionNodes(cards[c1-1]->node_prime, cards[c2-1]->node_prime);
            }

        }
        else if( op == 'r'){
            cin >> c1;
            Node* root = findRoot(cards[c1-1]->node);
            Node* root_prime = findRoot(cards[c1-1]->node_prime);

            if( root->color == -1 || root_prime->color == 1 ){
                printf("Q%d: ?\n", i+1);
                continue;
            }
            else if( root->color == 0 && root_prime->color == 0){
                counter += root->member;
            }
            //root->color = 1;
            //root_prime->color = -1;

            Card* root_card = root->card;
            if( root == root_card->node ){
                root_card->node->color = 1;
                root_card->node_prime->color = -1;
            }
            else if( root == root_card->node_prime ){
                root_card->node->color = -1;
                root_card->node_prime->color = 1;
            }

            Card* root_prime_card = root_prime->card;
            if( root_prime == root_prime_card->node ){
                root_prime_card->node->color = -1;
                root_prime_card->node_prime->color = 1;
            }
            else if( root_prime == root_prime_card->node_prime ){
                root_prime_card->node_prime->color = -1;
                root_prime_card->node->color = 1;
            }

            //findRoot(root_prime->card->node)->color = 1;
        }
        else if( op == 'b'){
            cin >> c1;
            Node* root = findRoot(cards[c1-1]->node);
            Node* root_prime = findRoot(cards[c1-1]->node_prime);
            if( root->color == 1 || root_prime->color == -1 ){
                printf("Q%d: ?\n", i+1);
                continue;
            }
            else if( root->color == 0 && root_prime->color == 0){
                counter += root->member;
            }
            //root->color = -1;
            //root_prime->color = 1;

            Card* root_card = root->card;
            if( root == root_card->node ){
                root_card->node->color = -1;
                root_card->node_prime->color = 1;
            }
            else if( root == root_card->node_prime ){
                root_card->node->color = 1;
                root_card->node_prime->color = -1;
            }

            Card* root_prime_card = root_prime->card;
            if( root_prime == root_prime_card->node ){
                root_prime_card->node->color = 1;
                root_prime_card->node_prime->color = -1;
            }
            else if( root_prime == root_prime_card->node_prime ){
                root_prime_card->node->color = -1;
                root_prime_card->node_prime->color = 1;
            }
        }
        // check if found all the color
        if( counter >= n ){
            printf("Q%d: I know\n", i+1);
            break;
        }
    }

    char result[100001];
    memset(result, '\0', 100001);

    for( int i =0; i<n; i++){
        Node* root = findRoot(cards[i]->node);
        Node* root_prime = findRoot(cards[i]->node_prime);
        if( root->color == 0 && root_prime->color == 0){
            printf("I am not sure\n" );
            return 0;
        }
        else{
            if( root->color == 1 ) result[i] = 'r';
            if( root->color == -1 ) result[i] = 'b';
            else if( root_prime->color == -1) result[i] = 'r';
            else if( root_prime->color == 1) result[i] = 'b';
        }
    }
    printf("%s\n", result);
    return 0;
}
