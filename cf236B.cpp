#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null nullptr
const double pie = 3.1415926535897932384626;
const ll inf = INT_MAX;  // Very big number
const ll infinite = LLONG_MAX;
const ll mod = (1e+9) + 7;
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define trav(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vf vector<float>
#define vvf vector<vector<float>>
#define vd vector<double>
#define vvd vector<vd>
#define vb vector<bool>
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a % mod * b % mod) % mod) / gcd(a % mod, b % mod)
#define pii pair<int, int>
#define vs vector<string>
#define umapii unordered_map<int, int>
#define pll pair<ll, ll>
#define mpii map<int, int>
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define pqdi priority_queue<int>
#define pqii priority_queue<int, vector<int>, greater<int>>

string upper_case(string str) {
    for (auto &ch : str) {
        ch = toupper(ch);
    }
    return str;
}

string lower_case(string str) {
    for (auto &ch : str) {
        ch = tolower(ch);
    }
    return str;
}

bool is_prime(ll n) {
    if (n < 4) return true;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) return false;
        i++;
    }
    return true;
}

/*
====================================
@author Atul
*/

vector<int> umap(1e+6 + 1, 0);

ll sumMod = 1073741824;

int numberOfDivisers(int n) {
    map<int, int> mp;
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            mp[i]++;
            n /= i;
        } else {
            i++;
        }
    }
    if (n != 1) {
        mp[n]++;
    }
    int ans = 1;
    for (auto i : mp) {
        ans *= (i.second + 1);
    }
    return ans;
}

void run(int n) {
    umap[1] = 1;
    if (n == 1) {
        return;
    }
    for (int i = 2; i <= n; i++) {
        umap[i] = numberOfDivisers(i);
    }
}

void test_case() {
    int a, b, c;
    cin >> a >> b >> c;
    run(a * b * c);
    ll ans = 0;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= a; k++) {
                ans += (umap[i * j * k]) % sumMod;
                ans %= sumMod;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    test_case();
}