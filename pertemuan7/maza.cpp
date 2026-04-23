#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef struct{
    int i,j;
} Point;

typedef struct{
    Point p;
    int currentK, step;

    void set(Point a, int b, int c) {
        p = a;
        currentK = b;
        step = c;
    }

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

    string matrik[N];
    bool visited[N][M];

    for (ll i = 0; i < N; i++) {
        cin>>matrik[i];
    }

    queue<Status>node;

    Point start, end;
    start.i = -1; start.j = -1;
    end.i = -1; end.j = -1;


    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            visited[i][j] = false;
            if (matrik[i][j] == 'S') {
                start.i = i; start.j = j;
            }else if (matrik[i][j] == 'E') {
                end.i = i; end.j = j;
            }
        }
    }

    if (start.i == -1 || end.i == -1) {
        cout<<-1<<endl;
        return 0;
    }
    Status startPoint;
    startPoint.set(start,K,0);


    node.push(startPoint);

    while (!node.empty()) {
        Status currentNode = node.front();
        node.pop();

        char container = matrik[currentNode.p.i][currentNode.p.j];
        visited[currentNode.p.i][currentNode.p.j] = true;


        if (container == 'E') {
            cout<<currentNode.step<<endl;
            return 0;
        }

        if (container == '#') {
            if (currentNode.currentK > 0) {
                currentNode.currentK--;
            }else {
                continue;
            }
        }
        int moveI[] = {1,-1,0,0}, moveJ[] = {0,0,1,-1};
        
        for (ll i = 0; i < 4; i++) {

            Point allMove;
            allMove.i = currentNode.p.i + moveI[i];
            allMove.j = currentNode.p.j + moveJ[i];

            if (allMove.i == end.i && allMove.j == end.j) {
                cout << currentNode.step + 1<< endl;
                return 0;
            }

            if (0 <= allMove.i && allMove.i < N && 0 <= allMove.j && allMove.j < M) {
                if (!visited[allMove.i][allMove.j]) {
                    Status temp;
                    temp.set(allMove,currentNode.currentK, currentNode.step + 1);
                    node.push(temp);
                }
            }
        }
        
    }

    cout << -1 << endl;




    
    


    return 0;
}