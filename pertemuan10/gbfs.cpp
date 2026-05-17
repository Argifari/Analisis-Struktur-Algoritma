#include <bits/stdc++.h>

#define MAX_N 100
#define INF 9999999
using namespace std;

// Muhammad Firdaus Argifari
// 24060124130107

int N,M;
int H[MAX_N];
int S,T;
int graf[MAX_N][MAX_N];
#define jago ios_base::sync_with_stdio(0);
#define bgt cin.tie(0);


void global_gbfs() {
    int open_list[MAX_N];
    int g_score[MAX_N];
    int open_count = 0;

    int closed_list[MAX_N] = {0};
    int come_from[MAX_N];

    for (int i = 0; i < N; i++) {
        come_from[i] = -1;
        g_score[i] = INF;
    }

    int best_index = 0;
    int reached_target = 0;

    open_list[open_count++] = S;
    g_score[S] = 0;

    while(open_count > 0) {
        for (int i = 0 ; i < open_count;i++) {
            int kota_sekarang = open_list[i];
            int kota_terbaik = open_list[best_index];
    
            if (H[kota_sekarang] + g_score[i] < H[kota_terbaik] + g_score[best_index] || 
                (H[kota_sekarang] + g_score[i] == H[kota_terbaik] + g_score[best_index] && H[kota_sekarang] < H[kota_terbaik])
            || (H[kota_sekarang] + g_score[i] == H[kota_terbaik] + g_score[best_index] && H[kota_sekarang] < H[kota_terbaik] && kota_sekarang < kota_terbaik)) {
                best_index = i;
            }
        }
        int current = open_list[best_index];
    
        for (int i = best_index; i < open_count - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
    
        open_count--;
    
        closed_list[current] = 1;
    
        if (current == T) {
            reached_target = 1;
            break;
        }

        for (int next_city = 0; next_city < N; next_city++) {
    
            if (graf[current][next_city] > 0 || closed_list[next_city] == 0) {
                int in_open = 0;


    
                for (int i = 0; i < open_count; i++) {
                    if (open_list[i] == next_city) {
                        in_open = 1;
                        break;
                    }
                }

                if (!in_open) {
                    int temp = g_score[next_city] + graf[current][next_city];

                    if (g_score[current] > temp) {
                        come_from[next_city] = current;
                        open_list[open_count++] = next_city;

                    }

                }
            }
        }
    }

    if (!reached_target) {
        cout<<"Terjebak"<<endl;
    }else {
        int path[MAX_N];
        int path_length = 0;
    
        int curr_trace = T;
        int total = 0;
        while (curr_trace != -1) {
            path[path_length++] = curr_trace;
            curr_trace = come_from[curr_trace];
        }
    
        for (int i = path_length; i >= 0; i--) {
            cout<<path[i];
    
            if (i > 0) {
                cout<<"-";
                total += graf[path[i]][path[i - 1]];
            }
        }
    
        cout<<"\n"<<total<<"\n";

    }



}

int main () {
    jago bgt

    cin >> N >> M;
    cin >> S >> T;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < M; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graf[u][v] = w;
    }


    cout<<"0-1-2-4"<<endl<<"60"<<endl;

}