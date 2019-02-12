/* not solved */

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void updateAlive(vector<bool>& alive, int ind){
    int count = 0;
    for(int i = 0; i < alive.size(); i++ ){
        if( alive[i] == true ){
            if( count == ind ) alive[ind] = false;
            count ++;
        }
    }
}

int main(){
    int n, e, d;
    scanf("%d %d %d\n", &n, &e, &d);

    vector<int> players; // how many defuses each player has
    vector<bool> alive;

    for( int i = 0; i < n; i++ ){
        players.push_back(0);
        alive.push_back(true);
    }

    int card;
    vector<int> explodes;
    vector<int> defuses;

    for( int i = 0; i< e; i ++){
        scanf("%d\n", &card);
        explodes.push_back(card);
    }

    for( int i = 0; i< d; i ++){
        scanf("%d\n", &card);
        defuses.push_back(card);
    }

    auto eit = explodes.begin();
    auto dit = defuses.begin();
    int playerInd;
    int prevex = 0; // index of last explosive card

    while( (eit!= explodes.end() || dit != defuses.end()) && players.size() > 1 ){
        printf("e: %d d: %d players: %lu\n", *eit, *dit, players.size());

        if( dit == defuses.end() || *eit < *dit ){
            playerInd = (*eit-prevex) % n;
            printf("explode %d\n", playerInd);

            if( players[playerInd] == 0 ){
                printf("deleting\n");
                players.erase(players.begin() + playerInd);
                updateAlive(alive, playerInd);//alive[playerInd] =  false;
                n -- ;
                prevex = *eit;
            }
            else{
                players[playerInd] --;
            }

            eit ++;
        }
        else if( eit == explodes.end() || *dit < *eit ){
            playerInd = (*dit-prevex) % n;
            printf("defuse %d\n", playerInd);
            players[playerInd] = min(players[playerInd] + 1, 5);
            dit ++;
        }
    }

    if( players.size() == 1 ){
        printf("here\n" );
        for( int i = 0; i < n; i++ ){
            if( alive[i] == true ){
                printf("%d\n", i);
                break;
            }
        }
    }
    else{
        printf("-1\n" );
    }
}
