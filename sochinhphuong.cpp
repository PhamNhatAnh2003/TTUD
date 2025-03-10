#include<bits/stdc++.h>
using namespace std;
unsigned long long n,s=0; 
int main() { 
    cin>>n; 
    s=sqrt(n); 
    if(s*s==n) 
        cout<<"YES"; 
    else 
        cout<<"NO"; 
    return 0;

}  