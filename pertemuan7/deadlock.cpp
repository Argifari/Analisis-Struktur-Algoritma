#include <bits/stdc++.h>

using namespace std;
#define ll long long

// Muhammad Firdaus Argifari 24060124130107

vector<ll> adj[100005];
int status[100005]; 
bool in_deadlock[100005];
vector<ll> path;

void findCycle(ll u) {
    status[u] = 1;
    path.push_back(u);

    for (ll v : adj[u]) {
        if (status[v] == 1) {
            bool startMarking = false;
            for (ll node : path) {
                if (node == v) startMarking = true;
                if (startMarking) in_deadlock[node] = true;
            }
        } else if (status[v] == 0) {
            findCycle(v);
        }
    }

    path.pop_back();
    status[u] = 2; 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    if (!(cin >> N >> M)) return 0;
    
    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (ll i = 1; i <= N; i++) {
        if (status[i] == 0) {
            path.clear();
            findCycle(i);
        }
    }
    
    vector<ll> deadlockNodes;
    for (ll i = 1; i <= N; i++) {
        if (in_deadlock[i]) {
            deadlockNodes.push_back(i);
        }
    }
    
    if (deadlockNodes.empty()) {
        cout << 0 << "\n";
        cout << "Aman\n";
    } else {
        cout << deadlockNodes.size() << "\n";
        for (int i = 0; i < deadlockNodes.size(); i++) {
            cout << deadlockNodes[i] << (i == deadlockNodes.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}