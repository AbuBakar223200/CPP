#include <iostream>
#include <string>

using namespace std;

int main(){
    string s = "Thank you very very much very much very much.";
    string p = "very";
    string tmp ;
    int prev_occ = s.find(p);
    int next_occ = s.find(p, prev_occ+p.size());
    int i = prev_occ+p.size();
    string res = s.substr(0, i);
//    cout << res << endl;
    while(next_occ != string::npos){
        tmp = s.substr(i, next_occ-i-1);
        res += tmp;
        prev_occ = next_occ;
        i = prev_occ+p.size();
        next_occ = s.find(p, i);
    }
    res += s.substr(i);
    cout << res << endl;
    return 0;
}
