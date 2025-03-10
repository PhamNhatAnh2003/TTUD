#include<bits/stdc++.h>
using namespace std;


unsigned long long modExp(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long result = 1;
    a = a % mod;

    while (b > 0) {
        // If b is odd, multiply a with result
        if (b % 2 == 1)
            result = (result * a) % mod;

        // b must be even now
        b = b >> 1; // b = b/2
        a = (a * a) % mod;
    }
    return result;
}

int main() {
    unsigned long long a, b;
    unsigned long long mod = 1000000007;

    // Input a and b
    cin >> a >> b;

    // Output a^b mod (10^9 + 7)
    cout << modExp(a, b, mod);

    return 0;
}
