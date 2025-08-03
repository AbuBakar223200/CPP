#include <iostream>
#include <map>

using namespace std;
int main(){
    map <string, float> cg_table;
    cg_table["Tamim"] = 3.80;
    cg_table["Shakib"] = 2.10;
//    cg_table["Tamim"] = 1.5;
    cg_table.insert(pair<string, float>("mskdf", 1.50));
    cout << cg_table["Tamim"] << endl;

    for (auto i=cg_table.begin(); i!=cg_table.end(); i++){
        cout << i->first << " "<< i->second << endl;
    }

    return 0;
}
