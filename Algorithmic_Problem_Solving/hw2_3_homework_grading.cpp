#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct problem{
    int trial = 0;
    bool ac = false;
};

long long convert_to_sec(string date, string this_time){
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    long long sec = 0;
    for( int i = 0; i < stoi(date.substr(0,2)); i ++ ){
        sec += month[i] * 86400;
    }
    sec += (stoi(date.substr(3,5)) - 1) * 86400; // day
    if( this_time.substr(8, 10).compare("pm") == 0 ) sec += 43200; // half a day
    sec += (stoi( this_time.substr(0, 2)) % 12)* 60 *60; // hour
    sec += stoi( this_time.substr(3, 5)) * 60;
    sec += stoi(this_time.substr(6, 8));
    //printf("%lld\n", sec);

    return sec;
}

bool sortbyfirstsec(const pair<double, string> &a, const pair<double, string> &b){
    if( a.first > b.first ) return false;
    else if( a.first == b.first ){
        if( a.second > b.second ) return true;
        else return false;
    }
    else return true;
}

int main(){
    int n, k;
    scanf("%d %d\n", &n, &k);

    map<char, int> scores;
    int score;
    char letter;
    for( int i = 0; i < n; i ++ ){
        scanf("%c %d\n", &letter, &score);
        scores[letter] = score;
    }

    vector<pair<long long, vector<string> > > sorted_input; // store submission time and input
    map<string, map<char, problem*> > database; // map name to submissions
    map<string, map<char, problem*> >::iterator outer_it;
    map<char, problem*>::iterator inner_it;

    string line, name, id, status;
    string this_date, this_time, start_date, start_time;
    problem* p;

    getline(cin, line);
    istringstream ss(line);
    long long start_sec, this_sec;
    ss >> start_date >> start_time;
    start_sec = convert_to_sec(start_date, start_time);
    long long end_sec = start_sec + 604800;

    vector<string> input_line; // to be stored in sorted
    pair<long long, vector<string> > n_pair;

    while( getline(cin, line) ){
        istringstream ss(line);

        ss >> this_date >> this_time;
        this_sec = convert_to_sec(this_date, this_time);

        ss >> name >> id >> status;
        input_line.push_back(name);
        input_line.push_back(id);
        input_line.push_back(status);
        n_pair = make_pair(this_sec, input_line);

        sorted_input.push_back(n_pair);

        input_line.clear();
        //n_pair.clear();
    }

    sort(sorted_input.begin(), sorted_input.end());
    vector<pair<long long, vector<string> > >::iterator input_it;

    for( input_it = sorted_input.begin(); input_it != sorted_input.end(); input_it ++ ){
        name = input_it->second[0];
        id = input_it->second[1];
        status = input_it->second[2];

        if( input_it->first > end_sec ){
            outer_it = database.find(name);
            if( outer_it == database.end() ){
                p = new problem;
                database[name][id[0]] = p;
            }
            continue;
        }

        //printf("%s %s\n", name.c_str(), id.c_str());

        outer_it = database.find(name);
        if( outer_it == database.end() ){
            p = new problem;
            database[name][id[0]] = p;
            if( status.compare("Accepted") == 0) p->ac = true;
            else p->trial += 1;
        }
        else{
            inner_it = outer_it->second.find(id[0]);
            if( inner_it == database[name].end() ){
                p = new problem;
                database[name][id[0]] = p;
                if( status.compare("Accepted") == 0) p->ac = true;
                else p->trial += 1;
            }
            else{
                //printf("found prob\n" );
                if( status.compare("Accepted") == 0) database[name][id[0]]->ac = true;
                else if( database[name][id[0]]->ac == false){
                    database[name][id[0]]->trial += 1;
                }
            }
        }
        //printf("%d\n", database[name][id[0]]->trial);
    }

    vector<pair<double, string> > ans;
    pair<double, string> new_pair;
    double prob_score = 0, total_score = 0;
    string p_name;

    for(map<string, map<char, problem*> >::iterator it = database.begin(); it != database.end(); it ++ ){
        total_score = 0;
        p_name = it->first;
        //printf("%s\n", p_name.c_str());

        for( map<char, problem*>::iterator iit = it->second.begin(); iit != it->second.end(); iit ++ ){
            //printf("%c %d\n", iit->first, iit->second->trial);
            prob_score = 0;
            if( iit->second->ac ){
                if(iit->second->trial > k){
                    prob_score = (double)scores[iit->first] * (1- 0.1 * (iit->second->trial - k));
                    if( prob_score < (double)scores[iit->first] * 0.3 ) prob_score = (double)scores[iit->first] * 0.3;
                }
                else{
                    prob_score = scores[iit->first];
                }
                //printf("%f\n", prob_score);
                total_score += prob_score;
            }
        }
        new_pair = make_pair(total_score, p_name);
        ans.push_back(new_pair);
    }

    sort(ans.begin(), ans.end(), sortbyfirstsec);

    vector<pair<double, string> >::iterator it;

    for(it = ans.end() - 1; it != ans.begin(); it --){
        if( it->first == (int)it->first ) printf("%s %d\n", it->second.c_str(), (int)it->first);
        else printf("%s %.1f\n", it->second.c_str(), it->first);
    }
    if( it->first == (int)it->first ) printf("%s %d\n", it->second.c_str(), (int)it->first);
    else printf("%s %.1f\n", it->second.c_str(), it->first);



    return 0;
}
