#include <iostream>
#include <set>

using namespace std;
int main(){
    set<int> st;
    cout << st.size() << endl;
    st.insert(10);
    st.insert(100);
    st.insert(102);
    st.insert(5434);
    st.erase(st.begin(),st.find(102));
    for(auto x:st) cout << x << " ";
//    for (auto i=cg_table.begin(); i!=cg_table.end(); i++){
//        cout << i->first << " "<< i->second << endl;
//    }

    return 0;
}
