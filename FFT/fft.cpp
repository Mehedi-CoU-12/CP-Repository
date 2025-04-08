#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<int>x(n),y(m),xy(n+m);

    for(auto &it:x)
    cin>>it;

    for(auto &it:y)
    cin>>it;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        xy[i+j]+= x[i] * y[j];
    }

    for(auto it:xy)
    cout<<it<<" ";
    cout<<endl;
}