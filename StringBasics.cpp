#include <iostream>
using namespace std;

int main(){
    string sa = "Hello";
    char tmp[] = "World";

    string sb = string(tmp);
//    cout << sa << sb << endl;
    cout << sa.size() << endl;
//    cout << sa[2] << endl;
    sa += sb + "UIU";
    cout << sa << endl;

    string sc;
//    cin >> sc ;
    getline(cin, sc);
    if(sb == sc) cout << "sb and sc are equal" <<endl;
    else cout << (sb > sc) << endl;
    cout << sa << endl;
    return 0;
}
