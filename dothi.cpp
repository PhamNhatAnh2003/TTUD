#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MaxN = 1 + 1e2;
const ll INF = 1e18;

int n, m, s;
bool mark[MaxN];
ll dist[MaxN];
vector<pair<int, int>> adj[MaxN];

void Dijkstra(int s){
    fill(dist + 1, dist + n + 1, INF);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(mark[u]) continue;
        mark[u] = true;
        for(auto e : adj[u]){
            int v = e.first;
            ll w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    freopen("CTDL.inp","r",stdin);
    freopen("CTDL.out","w",stdout);
    cin >> n >> m >> s;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    Dijkstra(s);
    for(int i = 1 ; i <= n ; ++i){
        if(dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}
