#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define jago ios_base::sync_with_stdio(0);
#define bgt cin.tie(0);
#define whenyah return 0;
#define MAX_INT 999999999
#define MAX_N 15

int N;
int min_out[MAX_N];
int cost[MAX_N][MAX_N];
int min_cost_hasil = MAX_INT;
int visited[MAX_N];


// Muhammad Firdaus Argifari
// 24060124130107


void dfs_bb(int curr, int count, int current_cost) {
    int expected_cost = current_cost;

    for (int i = 0; i < N;i++) {
        if (!visited[i]) {
            expected_cost += min_out[i];
        }
    }

    if (expected_cost >= min_cost_hasil) {
        return;
    }

    if (count == N) {
        if (cost[curr][0] != 0) {
            int total_cost = current_cost + cost[curr][0];
            if (total_cost < min_cost_hasil) {
                min_cost_hasil = total_cost;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[curr][i] != 0) {
            visited[i] = 1;
            dfs_bb(i, count + 1, current_cost + cost[curr][i]);
            visited[i] = 0;
        }
    }



}

int main () {
    jago bgt

    cin >> N;

    for (int i = 0; i < N; i++) {
        visited[i] = 0;
        min_out[i] = MAX_INT;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];

            if (cost[i][j] > 0 && cost[i][j] < min_out[i]) {
                min_out[i] = cost[i][j];
            }
        }
        if (min_out[i] == MAX_INT) {
            min_out[i] = 0;
        }
    }

    visited[0] = 1;

    dfs_bb(0,1,0);

    if (min_cost_hasil == MAX_INT) {
        cout<<"-1"<<endl;
    }
    else {
        cout<<min_cost_hasil<<endl;
    }


    whenyah
}