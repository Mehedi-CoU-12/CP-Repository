#include<bits/stdc++.h>
using namespace std;

/*
select the first element of the arrary as pivot then move the all element less than
or equal to the pivot element to the left and greater elements to the right. keep 
doing it untill the array are sorted.

time complexity: O(nlogn)
*/

int partition(vector<int>&v,int low,int high){
    int i=low,j=high;
    int pivot=v[low];

    while(i<j){
        while(v[i]<=pivot and i<high)
        i++;

        while(v[j]>pivot and j>low)
        j--;

        if(i<j)
        swap(v[i],v[j]);
    }

    swap(v[low],v[j]);
    return j;
}

void QuickSort(vector<int>&v,int low,int high){

    if(low>=high)
    return;

    int partionIndex=partition(v,low,high);
    
    QuickSort(v,low,partionIndex-1);
    QuickSort(v,partionIndex+1,high);

}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);

    for(auto &it:v)
    cin>>it;

    QuickSort(v,0,n-1);

    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;

}