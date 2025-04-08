#include<bits/stdc++.h>
using  namespace std;
int main(){
    int x=10;
    int *ptr=&x;

    cout<<x<<" address->"<<ptr<<endl;



    int a[]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<" "<<(*(a+i))<<endl;
    }
}