#include<iostream>
using namespace std;
int main(){
    int n,index;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
         
    }

    int key;
    cin>>key;
    bool c;
    
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            c=true;
            cout<<i;

        }
        else{
            c=false;
        }
    }
    if(!c) cout<<"NO";
    else if(c){
    cout<<"Yes";
    
    }

    cout<<endl;
    return 0;


}