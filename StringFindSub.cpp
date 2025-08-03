#include <iostream>
using namespace std;

int main(){
    string s, p;
    s = "Yes, we went to Gates after we left the dorm.";
    p = "we";
    cout << s << endl;
    int first_occ = s.find(p);
    int second_occ = s.find(p, first_occ+1);
    int third_occ = s.find(p, second_occ+1);
    cout << first_occ << " " << second_occ << " " << third_occ << endl;
    if(s.find(p, third_occ+1) == string::npos)
        cout << "No more occurrences.." << endl;
//    s.erase(first_occ, p.size());
    s.replace(first_occ, 10, " hello ");
    cout << s << endl;
    return 0;
}

