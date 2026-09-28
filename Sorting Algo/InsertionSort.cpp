#include<bits/stdc++.h>
using namespace std;

/*
in insertions sort we keep swapping elements untill it find the it's positions 
from right to left.

time complexity: O(n^2)
*/

void InsertionSort(vector<int>&v,int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 and v[j-1]>v[j]){
            swap(v[j],v[j-1]);
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(auto &it:v)
    cin>>it;

    InsertionSort(v,n);

    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;

}