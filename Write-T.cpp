#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define ull unsigned long long
int main(){
    int n;
    double T = 0.0;
    cin >> n;
    for(int i = 1; i <=n; i++){
        T = T + 1.0/i;
    }
    cout << fixed << setprecision(5) << T << endl;
    return 0;
}