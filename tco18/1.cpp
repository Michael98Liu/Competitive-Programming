#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int dist = atoi(argv[1]);
    int k = atoi(argv[2]);
    int n = atoi(argv[3]);

    int rest = n / k;

    //cout << rest << " " << dist * (n - rest) << endl;

    return dist * (n - rest);
}
