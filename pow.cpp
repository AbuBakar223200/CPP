#include <iostream>

using namespace std;

int powx_y(int x, int y){
    if (y == 0) return 1;
    int p = powx_y(x, y/2);

    if(y % 2 == 0) return p*p;
    else return p*p*x;
}

int main(){
    int x,y;
    cin >> x >> y;
    cout << powx_y(x, y) << endl;
    return 0;
}

