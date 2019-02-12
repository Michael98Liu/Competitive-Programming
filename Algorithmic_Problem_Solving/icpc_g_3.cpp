#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
public:
    int num;
    Node* next;

    Node(int n){
        num = n;
    }
};

vector<string> chop(string& s){
    vector<string> v;
    string sub_s;
    bool newString = false;
    for( int i= 0; i < s.size(); i++){
        if( s[i] == 'R' && newString ){
            v.push_back(sub_s);
            sub_s.clear();
            sub_s += s[i];
        }
        else if( s[i] == 'R') sub_s += s[i];
        else if( s[i] == 'L'){
            newString = true;
            sub_s += s[i];
        }
    }
    if( sub_s.size() != 0 ) v.push_back(sub_s);

    return v;
}

int countL(string& s){
    int counter = 0;
    for( int i=0; i < s.size(); i++){
        if ( s[i] == 'L') counter ++;
    }
    return counter;
}

int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<Node*> nodes;
    for( int i = 1; i <= n; i++ ){
        Node* node = new Node(i);
        nodes.push_back(node);
    }

    vector<string> chopped = chop(s);
    /*
    for( int i = 0; i < chopped.size(); i++ ){
        printf("%s\n", chopped[i].c_str());
    }*/

    Node* first = new Node(0);
    Node* cur = first;
    Node* tail = first;

    int next_ind = 0;

    for( int i = 0; i < chopped.size(); i++ ){
        int len = chopped[i].size();
        int len_l = count(chopped[i]);
        int len_r = chopped.size() - len_l;

        tail
        for( int j = 0; j < len_l; j++){
            nodes[j+next_ind+1]->next = nodes[j+next_ind];
        }
        next_ind += len_l + 1;

        for( int j = 0; j < len_r; j++){
            tail->next = nodes[next_ind];
            tail = tail->next;
        }

    }

    while( ind < n ){

        if( s[ind] == 'R' ){
            first = new Node(0);
            first->next = nodes[0];

            while( s[ind+1] == 'R'){
                nodes[ind]->next = nodes[ind+1];
            }

            tail = nodes[0];
        }
        else if( s[0] == 'L' ){
            while(s[ind] == 'L') ind++;
            first = nodes[ind];
            next_ind = ind+1;

            for( int j = ind; j > 0, j--){
                s[ind]->next = s[ind-1];
            }
            tail = nodes[0];
        }
    }
    */

    return 0;

}
