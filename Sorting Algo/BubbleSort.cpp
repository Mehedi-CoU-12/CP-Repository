#include<bits/stdc++.h>
using namespace std;

/*
in bubble sort we compare two value and swap if the left value is greater than the 
right one. our goal is the move the largest value to the right and continue this 
process.
*/


void bubbleSort(vector<int>&v,int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

            if(v[j]>v[j+1])
            swap(v[j],v[j+1]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

    bubbleSort(v,n);

    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}