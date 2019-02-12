#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Student{
public:
    int level;
    vector<Student*> possible;

    Student(int l){
        level = l;
    }

};

bool compareStudent(Student* a, Student* b){
    return a->possible.size() < b->possible.size();
}

int main(){
    int n, x, y, s;
    scanf("%d %d %d\n", &n, &x, &y);

    vector<Student*> a;
    vector<Student*> b;

    for( int i =0; i < n; i++){
        cin >> s;
        Student *stu = new Student(s);
        a.push_back(stu);
    }

    for( int i =0; i < n; i++){
        cin >> s;
        Student *stu = new Student(s);
        b.push_back(stu);
    }

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if( a[i]->level + b[j]->level <= y && abs(a[i]->level - b[j]->level) <= x ){
                a[i]->possible.push_back(j); // index of student b
                b[j]->possible.push_back(i); // index of student a
            }
        }
    }

    sort(a.begin(), a.end(), compareStudent);

    for( int i = 0; i < n; i++ ){
        printf("%d %lu\n", a[i]->level, a[i]->possible.size());
    }

    int count = 0;
    Student* partner;

    for( int i = 0; i < n; i++ ){
        if( a[i]->possible.size() != 0 ){
            sort(a[i]->possible.begin(), a[i]->possible.end(), compareStudent);

            int j = 0;
            while( a[i]->possible[j]->possible.size() == 0 && j < a[i]->possible.size() ){
                j ++;
            }
            if( j < a[i]->possible.size() && a[i]->possible[j]->possible.size() != 0){
                partner = a[i]->possible.back();
                partner->possible.pop_back(); // delete any element, only size matters
                count ++;
            }
        }
    }

    printf("%d\n", count);
}
