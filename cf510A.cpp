#include<bits/stdc++.h>




using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvl = vector<vector<ll>>;

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

bool equal_ignore_case(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    for (int i = 0; i < s2.size(); i++) {
        if (tolower(s1[i]) != tolower(s2[i])) {
            return false;
        }
    }
    return true;
}

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
vector<int> sieve(int n) {
    vector<int> arr;
    int i = 0;
    while (arr.size() < n) {
        if (is_prime(i)) {
            arr.push_back(i);
        }
        i++;
    }
    return arr;
}

bool equal_double(double a, double b) {
    return abs(a - b) <= 1e-3;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int index = m - 1;
    bool printed = false;
    for (int i = 0; i < n; i++) {
        printed = false;
        for (int j = 0; j < m; j++) {
            if (i % 2 == 0) {
                printf("#");
            } else if (j == index and printed == false) {
                printf("#");
                index = (m - 1 - index);
                printed = true;
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}