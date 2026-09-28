#include<bits/stdc++.h>
using namespace std;

/*
in selection sort we try to move the smallest element to the left side of the array

*/


void selectionSort(vector<int>&v,int n){

    for(int i=0;i<n-1;i++){
        int smallestIdx=i;

        for(int j=i+1;j<n;j++){
            if(v[j]<v[smallestIdx])
            smallestIdx=j;
        }

        swap(v[i],v[smallestIdx]);
   }
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

    selectionSort(v,n);

    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}