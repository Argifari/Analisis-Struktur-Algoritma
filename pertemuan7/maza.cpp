#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Muhammad Firdaus Argifar
// 24060124130107

bool visited[1005][1005][11];

typedef struct{
    int i, j, currentK, step;
}Status;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, K;
    cin >> N >> M >> K;

    if (N == 1 && M == 1) {

        cout<<-1<<endl;
        return 0;
    }

    vector<string>matrik;


    for (ll i = 0; i < N; i++) {
        string a;
        cin >> a;
        matrik.push_back(a);
    }

    queue<Status>node;

    
    int startI = -1, startJ = -1;
    int endI = -1, endJ = -1;


    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            if (matrik[i][j] == 'S') {
                startI = i; startJ = j;
            }else if (matrik[i][j] == 'E') {
                endI = i; endJ = j;
            }
        }
    }

    if (startI == -1 || endI == -1) {
        cout<<-1<<endl;
        return 0;
    }
    Status startPoint;
    startPoint.i = startI;
    startPoint.j = startJ;
    startPoint.currentK = K;
    startPoint.step = 0;
    visited[startPoint.i][startPoint.j][startPoint.currentK] = true;


    node.push(startPoint);

    while (!node.empty()) {
        Status currentNode = node.front();
        node.pop();




        if (currentNode.i == endI && currentNode.j == endJ) {
            cout<<currentNode.step<<endl;
            return 0;
        }


        int moveI[] = {1,-1,0,0}, moveJ[] = {0,0,1,-1};
        
        for (ll i = 0; i < 4; i++) {
            
            
            ll allMoveI = currentNode.i + moveI[i];
            ll allMoveJ = currentNode.j + moveJ[i];
            int leftK = currentNode.currentK;
            


            if (0 <= allMoveI && allMoveI < N && 0 <= allMoveJ && allMoveJ < M) {
                if (matrik[allMoveI][allMoveJ] == '#') {
                    if (leftK > 0) {
                        leftK--;
                    }else {
                        continue;
                    }
                }
                if (!visited[allMoveI][allMoveJ][leftK]) {
                    visited[allMoveI][allMoveJ][leftK] = true;
                    Status temp;
                    temp.i = allMoveI;
                    temp.j = allMoveJ;
                    temp.currentK = leftK;
                    temp.step = currentNode.step + 1;
                    node.push(temp);
                }
            }
        }
        
    }

    cout << -1 << endl;




    
    


    return 0;
}