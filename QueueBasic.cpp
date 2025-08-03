#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.empty() << endl;
    cout << st.size() << endl;
    cout << st.front() << endl;
    st.pop();
    cout << st.front() << endl;
    return 0;
}

