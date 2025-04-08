/*
    Problem(Guess the Number):
        there is some hidden number and you have to interactively guess it.
    the hidden number is always an integer between 1 to 1e6.you can make
    queries to the testing system. each query is one integer from 1 to 
    1e6.

    there are two different responses testing  program can provide.
    1.string "<" if the hidden number is less than the integer in your query.
    2.string ">=" if the hidden number  is greater than the integer your q
    ery.

        your program is allow to make no more than 25 queries.when your 
    program want ot print the number. print string ! then the hidden number.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    int low=1,high=1e6,ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        //asking part
        cout<<"? "<<mid<<endl;
        cout.flush();

        string s;
        cin>>s;

        if(s==">="){
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }

    cout<<"! "<<ans<<endl;
}