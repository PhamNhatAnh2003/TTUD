#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main(){
ull a,b;
cin >> a >> b;
ull A1 = a/10;
ull A2 = a%10;
ull B1 = b/10;
ull B2 = b%10;
ull C2 = A2 + B2;
ull D = C2/10;
ull R = C2%10;
ull res = a+b;
cout << res;
 return 0;
}
