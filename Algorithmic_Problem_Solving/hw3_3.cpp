// run time error: when chack the last element of a empty vector


#include <iostream>
#include <string>
#include <vector>
#define MOD (int)(1000000007)
using namespace std;

bool is_operator(string& c){
    if( (c[0] <= 43 && c[0] >= 40) || c[0] == 45 ) return true;
    else return false;
}

bool is_operand(char& c){
    if( c >= 48 && c <= 57 ) return true;
    else return false;
}

bool is_op(char& c){
    if(c == 42 || c == 43 || c == 45 ) return true;
    else return false;
}

int main(){
    string e;
    getline(cin, e);
    if( e.size() == 0 ){
        printf("invalid\n");
        return 0; // empty input
    }
    vector<string> infix;
    vector<string> postfix;
    vector<string> stack;
    int bracket_mismatch = 0;

    int i = 0;
    string operand;
    while(e[i] != '\0'){
        //printf("%c\n", e[i]);
        if( e[i] >= 48 && e[i] <= 57 ){
            operand += e[i];
        }
        else{
            if( e[i] == '(' ) bracket_mismatch += 1;
            else if( e[i] == ')' ) bracket_mismatch -= 1;
            if( bracket_mismatch < 0 ){
                printf("invalid\n");
                return 0; // more close bracket
            }
            if( operand.size() != 0 ){
                infix.push_back(operand);
                operand.clear();
            }
            infix.push_back(string(1, e[i]));
        }
        i ++;
    }
    if( operand.size() != 0 ) infix.push_back(operand);
    if( bracket_mismatch ){
        printf("invalid\n");
        return 0; // bracket_mismatch
    }
    if( is_op(infix[0][0]) || is_op(infix.back()[0]) ){
        printf("invalid\n");
        return 0; // starting or ending +-*
    }

    bool prev_op = false; // flag if the previous string is an operator
    string temp;

    //printf("here\n" );

    for( int i = 0; i < infix.size(); i ++ ){
        //printf("%d | %s %d \n", i, infix[i].c_str(), prev_op);

        if( is_operand(infix[i][0]) ){
            // a operand
            if( i > 0 && infix[i-1][0] == ')'){
                printf("invalid\n");
                return 0; // closing bracket following by a number
            }
            if( i < infix.size()-1 && infix[i+1][0] == '('){
                printf("invalid\n");
                return 0;
            }
            prev_op = false;
            postfix.push_back(infix[i]);
        }
        else if( is_operator(infix[i] )){
            // a operator
            if( infix[i][0] == '(' || infix[i][0] == ')' ){
                if( infix[i][0] == '(' ){
                    if( i > 0 ) if( infix[i-1][0] == ')'){
                        printf("invalid\n");
                        return 0; // closing bracket following by a number
                    }
                    stack.push_back(infix[i]);
                    prev_op = true; // operator cannot follow '('
                }else{
                    if( prev_op ){
                        printf("invalid\n");
                        return 0; // two consecutive operator
                    }
                    prev_op = false;
                    temp = stack.back();
                    stack.pop_back();
                    while( temp[0] != '(' ){
                        postfix.push_back(temp);
                        temp = stack.back();
                        stack.pop_back();
                    }
                }
            }
            else{
                if( prev_op ){
                    printf("invalid\n");
                    return 0; // two consecutive operator
                }
                prev_op = true;

                bool non_lower_priority = false;
                if( stack.size() != 0 ) non_lower_priority = (infix[i][0] == '*' && stack.back()[0] == '*' ) || infix[i][0] != '*';

                while( stack.size() != 0 && stack.back()[0] != '(' && non_lower_priority ){
                    //printf("here2\n" );
                    temp = stack.back();
                    stack.pop_back();
                    postfix.push_back(temp);
                    if( stack.size() != 0 ) non_lower_priority = (infix[i][0] == '*' && stack.back()[0] == '*' ) || infix[i][0] != '*';
                }

                stack.push_back(infix[i]);
            }

        }
    }

    while( stack.size() != 0 ){
        temp = stack.back();
        stack.pop_back();
        postfix.push_back(temp);
    }

    /*
    for( auto it = postfix.begin(); it != postfix.end(); it ++ ){
        printf("%c\n", (*it).c_str()[0] );
    }
    printf("\n" );
    */

    vector<long long> num_stack;
    long long num = 0, a = 0, b = 0;
    for( int i = 0; i < postfix.size(); i ++ ){
        //printf("***** %c\n", postfix[i][0]);
        if( is_operand(postfix[i][0]) ){
            num = 0;
            for( int j = 0; j < postfix[i].size(); j++ ){
                num = (num * 10) % MOD;
                //printf("%d %d\n", postfix[i][j], num);
                num = (num + (postfix[i][j] - 48)) % MOD;
            }
            num_stack.push_back(num);
        }
        else{
            a = num_stack.back();
            num_stack.pop_back();
            b = num_stack.back();
            num_stack.pop_back();


            if( postfix[i][0] == '*' ){
                num = (a * b) % MOD;
            }else if( postfix[i][0] == '+' ){
                num = (a + b) % MOD;
            }else if( postfix[i][0] == '-' ){
                num = (MOD + b - a) % MOD;
            }
            num_stack.push_back(num);
        }
    }

    printf("%lld\n", num_stack[0]);

    return 0;
}
