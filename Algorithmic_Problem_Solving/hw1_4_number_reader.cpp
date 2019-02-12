#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int num;
    int thou, hun, ten, one;

    string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                        "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                        "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    vector<string> result;
    string re;

    while(scanf("%d\n", &num)){
        if( num == -1 ) break;

        thou = (num - num % 1000)/1000;
        num = num % 1000;
        hun = (num - num % 100)/100;
        num = num % 100;
        ten = (num - num%10) / 10;
        one = num % 10;

        if( thou != 0 ){
            result.push_back(ones[thou]);
            result.push_back(" ");
            result.push_back("thousand");
        }

        if( hun != 0 ){
            if( thou != 0) result.push_back(" ");
            result.push_back(ones[hun]);
            result.push_back(" ");
            result.push_back("hundred");
        }
        if((thou != 0 || hun != 0 ) && (ten != 0 || one != 0)){
            result.push_back(" ");
            result.push_back("and");
            result.push_back(" ");
        }

        if( ten == 1 ) result.push_back(ones[one+10]);
        else if( ten == 0 && one != 0 ) result.push_back(ones[one]);
        else{
            result.push_back(tens[ten - 2]);
            if( one != 0 ){
                result.push_back("-");
                result.push_back(ones[one]);
            }
        }

        if( thou == 0 and hun == 0 and ten == 0 and one == 0) result.push_back(ones[0]);

        for( vector<string>::iterator it = result.begin(); it != result.end(); it ++){
            string word(*it);
            cout << word;
        }
        cout << endl;
        result.clear();
        re.clear();
    }

}
