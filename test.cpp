#include<bits/stdc++.h>
using namespace std;
#define N 100
int c[N][N];
int x[N];
int n;
bool visited[N];
int f,f_min;
int Cmin;
void input(){
	scanf("%d",&n);
	for(int i =1; i<=n;i++)
	  for(int j = 1; j<= n;j++){
	    scanf("%d",&c[i][j]);
	    if(i!= j && Cmin > c[i][j])
	    Cmin = c[i][j];
	}

}
bool check( int v,int k){
	return visited[v]==false;
}
void solution(){
	if(f+c[x[n]][x[1]] < f_min) f_min = f + c[x[n]][x[1]];
}
void Try(int k){
	for( int v=1;v<= n;v++){
		if(check(v,k)){
			x[k]=v;
			visited[v] = true;
			f=f+c[x[k-1]][x[k]];
			if(k==n) solution();
			else{
				if(f + Cmin*(n-k+1) < f_min)
				Try(k+1);
			}
			visited[v]=false;
			f=f-c[x[k-1]][x[k]];
		}
	}
}

int main(){
	input();
	f=0;
	f_min=1e9;
	Try(1);
	cout << f_min;
	getchar();
	return 0;
}
