#include <iostream>
#include <algorithm>

using namespace std;
typedef struct
{
    float weight, value;
}item;

bool comp(item x, item y){
    return (x.value/x.weight) > (y.value/y.weight);
}

int main(){
    item items[100];
    int n;
    float W, profit=0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> items[i].weight >> items[i].value;
    cin >> W;
    sort(items, items+n, comp);
    for(int i=0; i<n; i++){
        if(items[i].weight < W){
            W -= items[i].weight;
            profit += items[i].value;
        }
        else{
            profit +=  items[i].value/items[i].weight * W;
            break;
        }


    }
    cout << "Profit: " << profit << endl;

    return 0;
}
