#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N,M;
    cin >> N >> M;

    ll edge[M][2];
    ll matrix[N + 1][N + 1];
    int visited[N + 1][N + 1];



    for (ll i = 0; i < M; i++) {
        cin >> edge[i][0] >> edge[i][1];
    }
    
    for (ll i = 0; i <= N; i++) {
        for (ll j = 0; j <= N; j++) {
            matrix[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    
    for (ll i = 0; i < M; i++) {
        matrix[edge[i][0]][edge[i][1]] = 1;
    }

    queue <ll> node;

    
    node.push(1);

    while (!node.empty()) {
        ll currentNode = node.front();
        node.pop();
        

        for (ll j = 1; j <= N; j++) {
            if (matrix[currentNode][j] == 1) {
                if (visited[currentNode][j] == 0) {
                    visited[currentNode][j] = 1;
                    node.push(j);
                }else if (visited[currentNode][j] == 1) {
                    
                }
            }
        }
        


    }
    
    

    return 0;
}