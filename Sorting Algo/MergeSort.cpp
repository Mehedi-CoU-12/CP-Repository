#include<bits/stdc++.h>
using namespace std;

void merge(int low,int mid,int high,vector<int>&v)
{
    int left=low;
    int right=mid+1;
    vector<int>temp;

    while(left<=mid and right<=high)
    {
        if(v[left]<=v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(v[left]);
        left++;
    }

    while(right<=high)
    {
        temp.push_back(v[right]);
        right++;
    }

    for(int i=low;i<=high;i++)
    v[i]=temp[i-low];

}

void mergeSort(int low,int high,vector<int>&v)
{
    if(low>=high)
    return ;

    int mid=(low+high)/2;

    mergeSort(low,mid,v);
    mergeSort(mid+1,high,v);
    
    merge(low,mid,high,v);
}

int main()
{
    int n;
    cin>>n;

    vector<int>v(n);

    for(auto &it:v)
    cin>>it;

    mergeSort(0,n-1,v);

    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;
}