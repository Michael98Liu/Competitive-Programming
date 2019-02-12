#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main(){
    string line;
    string word;
    string a, b;
    int result;
    int i = 0;
    map<string, int> sequence;

    getline(cin, line);
    istringstream ss(line);
    while(ss >> word){
        sequence[word] = i;
        i ++;
    }

    while(getline(cin, line)){
        istringstream ss(line);
        ss >> a >> b;
        if( (sequence[a] - sequence[b]) == -1 || (sequence[a] + 1) % i - (sequence[b] + 1) % i == -1 ) printf("win\n");
        else if( sequence[a] - sequence[b] == 1 || (sequence[a] + 1) % i - (sequence[b] + 1) % i == 1 ) printf("lose\n" );
        else printf("draw\n");
    }
    return 0;
}
