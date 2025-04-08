#include <bits/stdc++.h>
#define ll long long int
#define mod 1000003
#define yes cout << 'Y' << 'E' << 'S' << endl
#define no cout << 'N' << 'O' << endl
#define tst int t;cin>>t;while(t--)
const int N = (int)1e6 + 5;
using namespace std;
vector<int> v(N);

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * 1LL * a) % mod;

        n /= 2;
        a = (a * 1LL * a) % mod;
    }

    return res;
}

int BC(int n, int k)
{
    if (k > n)
        return 0;

    int res = v[n];

    res = (res * 1LL * power(v[k], mod - 2)) % mod;
    res = (res * 1LL * power(v[n - k], mod - 2)) % mod;

    return res;
}

int main()
{

    v[0] = v[1] = 1;

    for (int i = 2; i < N; i++)
        v[i] = (v[i - 1] * 1LL * i) % mod;

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";

        int n, k;
        cin >> n >> k;

        //nCr
        cout << BC(n, k) << endl;
    }
}