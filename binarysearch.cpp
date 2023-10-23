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
    bool found;

    int s=0;
    int e=n;
    while(s<=e){
        int mid =(s+e)/2;
        if(arr[mid]==key){
                cout<<"found at "<<mid<<endl;
                found=true;
                break;
        }
        if(arr[mid]>key){
            e=mid-1;

        }
        if(arr[mid]<key){
            s=mid +1 ;
        }
        else{
            found=false;
        }


    }
    if(!found)cout <<"not found";
    

    cout<<endl;
    return 0;


}