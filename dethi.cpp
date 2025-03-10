#include <iostream>
using namespace std;

unsigned long long modExp(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long result = 1;
    a = a % mod;

    while (b > 0) {
        // Nếu b là số lẻ, nhân a với result
        if (b % 2 == 1)
            result = (result * a) % mod;

        // b phải là số chẵn bây giờ
        b = b >> 1; // b = b / 2
        a = (a * a) % mod;
    }
    return result;
}

int main() {
    unsigned long long a, b;
    unsigned long long mod = 1000000007;

    // Nhập a và b
    cin >> a >> b;

    // Xuất kết quả a^b mod (10^9 + 7)
    cout << modExp(a, b, mod) << endl;

    return 0;
}
