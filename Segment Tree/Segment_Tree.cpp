#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
const int N = (int)1e6 + 5;
#define yes cout<<'Y'<<'E'<<'S'<<endl
#define no cout<<'N'<<'O'<<endl
#define tst int t;cin>>t;while(t--)
using namespace std;
vector<int>v(N);

class SegmentTree{
    vector<int>seg,lazy;
    public:
    SegmentTree(){
        seg.resize(4*N);
        lazy.resize(4*N);
    }

    void build(int ind,int low,int high)
    {
        if(low==high){
            seg[ind]=v[low];
            return;
        }

        int mid=(low+high)/2;

        build(2*ind+1,low,mid);
        build(2*ind+2,mid+1,high);

        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    
};

vector<int>seg(4*N),lazy(4*N);

void build(int ind,int low,int high)
{
    if(low==high){
        seg[ind]=v[low];
        return;
    }

    int mid=(low+high)/2;

    build(2*ind+1,low,mid); 
    build(2*ind+2,mid+1,high);

    //this is where we can put our condition;
    seg[ind]=(seg[2*ind+1]+seg[2*ind+2]);
}

int query(int ind,int low,int high,int l,int r)
{
    /*
        three types of overlap in segment tree's quiry 
        1.no overlap
        2.complete overlap and
        3.pertial overlap
    */

   //complete overlap
    if(l<=low and high<=r)
    return seg[ind];

    //no overlap
    if(high<l or low>r)
    return 0;

    //pertial overlap
    int mid=(low+high)/2;

    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high,l,r);

    return (left+right);
}

void pointUpdate(int ind,int low,int high,int node,int val)
{
    if(low==high)
    {
        seg[ind]+=val;
        return;
    }

    int mid=(low+high)/2;

    //goto left
    if(node<=mid and node>=low)
    pointUpdate(2*ind+1,low,mid,node,val);

    //goto right;
    else
    pointUpdate(2*ind+2,mid+1,high,node,val);

    seg[ind]=seg[2*ind+1]+seg[2*ind+2];

}

void rangeUpdate(int ind,int low,int high,int l,int r,int val)
{
    //update the node with previous value;
    if(lazy[ind]!=0)
    {
        seg[ind]+=(high-low+1)*lazy[ind];
        
        //propagate the update to it's children
        if(low!=high)
        {
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    //no overlap;
    if(r<low or l>high or low>high)
    return;

    //complete overlap
    if(low>=l and r<=high)
    {
        seg[ind]+=(high-low+1)*val;
        
        //propogate the value to it's children
        if(low!=high)
        {
            lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;
        }

        return ;
    }

    //pertial overlap
    int mid=(high+low)/2;

    rangeUpdate(2*ind+1,low,mid,l,r,val);
    rangeUpdate(2*ind+2,mid+1,high,l,r,val);

    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int querySumLazy(int ind,int low,int high,int l,int r)
{
    //upgrate the node with it's previous value;
    if(lazy[ind]!=0)
    {
        seg[ind]+=(high-low+1)*lazy[ind];

        if(low!=high)
        {
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    //no overlap
    if(r<low or l>high or low>high)
    return 0;

    //complete overlap
    if(low>=l and high<=r)
    return seg[ind];

    //pertial overlap
    int mid=(low+high)/2;

    int left=querySumLazy(2*ind+1,low,mid,l,r);
    int right=querySumLazy(2*ind+2,mid+1,high,l,r);

    return left+right;

}


int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    cin>>v[i];

    build(0,0,n-1);

    // for(int i=0;i<=14;i++)
    // cout<<seg[i]<<" ";
    // cout<<endl;
    int q;
    cin>>q;

    // find the summation of the  element in the range l to r;
    while(q--)
    {
        int p,l,r;
        cin>>p>>l>>r;
        l--,r--;

        if(p==1)
        {
            int value;
            cin>>value;
            
            rangeUpdate(0,0,n-1,l,r,value);
        }
        else
        {
            int ans=querySumLazy(0,0,n-1,l,r);
            cout<<ans<<endl;
        }

        // int ans=quiry(0,0,n-1,l,r);
        // cout<<ans<<endl;

        // cout<<";;"<<endl;
    }
}