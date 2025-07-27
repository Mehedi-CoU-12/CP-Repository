#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

/*
🧠 Rolling Hash using Polynomial Hashing and Modular Inverse (Theory)
🔍 Problem Goal:
Efficiently compute and compare substring hashes in O(1) time after O(n) preprocessing of a string.

⚙️ Core Idea:
Use a polynomial hash function to convert a string into a number such that equal substrings will have equal hash values.

The hash of a string s of length n is computed as:

H(s) = s[0]*p^0 + s[1]*p^1 + s[2]*p^2 + ... + s[n-1]*p^(n-1)  (mod MOD)

p is a prime number (commonly 31 or 53).

MOD is a large prime number to reduce collisions and avoid overflow (1e9 + 7 is common).

Characters are converted to values like 'a' -> 1, 'b' -> 2, etc.

🚀 Precomputation:
We precompute:

dp[i]: Hash of prefix s[0..i]

inv[i]: Modular inverse of p^i under mod

This allows us to calculate substring hash from l to r in constant time.



🧮 Substring Hash Formula:
For substring s[l...r], the hash is:

Hash(l, r) = (dp[r] - dp[l-1]) * inv[l] % MOD
dp[r] is the hash up to index r

dp[l-1] is the hash up to index l-1 (which we subtract)

inv[l] is the modular inverse of p^l, to normalize the result

If l == 0, then just use dp[r].



🧠 Modular Inverse:
We need to divide by p^l, which isn't possible directly under modulo. So we multiply by the modular inverse using Fermat’s Little Theorem:

If mod is prime, then:


a^(-1) ≡ a^(mod-2) mod mod
This is implemented with binary exponentiation (a.k.a. fast power).



✅ Time and Space Complexity:
Preprocessing: O(n log mod) for modular inverses

Substring Query: O(1)

Space: O(n) for both dp and inv
*/

class StringHasher {
private:
    const int N = 1e6 + 5;
    vector<ll> inv, dp;
    ll p = 31;

    ll binaryExpo(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b % 2 == 1) {
                res = (res * a) % mod;
                b--;
            } else {
                a = (a * a) % mod;
                b /= 2;
            }
        }
        return res % mod;
    }

public:
    StringHasher() {
        inv.assign(N, 0);
        dp.assign(N, 0);
    }

    void build(const string& s) {
        ll p_power = 1;
        inv[0] = 1;
        dp[0] = (s[0] - 'a') + 1;

        for (int i = 1; i < s.size(); i++) {
            p_power = (p_power * p) % mod;
            inv[i] = binaryExpo(p_power, mod - 2);
            dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * p_power) % mod;
        }
    }

    ll getHash(int l, int r) {
        ll result = dp[r];
        if (l > 0) result -= dp[l - 1];
        result = (result * inv[l]) % mod;
        if (result < 0) result += mod;
        return result;
    }

    ll getPrefixHash(int i) {
        return dp[i];
    }

    ll getInverse(int i) {
        return inv[i];
    }
};

int main() {
    string s;
    cin >> s;

    StringHasher hasher;
    hasher.build(s);

    for (int i = 0; i < s.size(); i++) {
        cout << i + 1 << " -> " << hasher.getPrefixHash(i) << " inv: " << hasher.getInverse(i) << endl;
    }

    return 0;
}
