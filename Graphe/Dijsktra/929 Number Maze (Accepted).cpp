#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int T, N, M, maze[1000][1000];
priority_queue<iii, vector<iii>, greater<iii> > pq;
int dist[1000][1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void init() {
    for (int i=0 ; i<N ; i++)
        for (int j=0 ; j<M ; j++)
            dist[i][j] = 1e9;
}

bool bound(int x, int y) {
    return x >= 0 && x < N &&
            y >= 0 && y < M;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d\n%d", &N, &M);
        init(); // Init dist
        for (int i=0 ; i<N ; i++) {
            for (int j=0 ; j<M ; j++)
                scanf("%d", &(maze[i][j]));
        }
        pq.push(make_pair(maze[0][0], ii(0, 0)));
        dist[0][0] = maze[0][0];
        while (!pq.empty()) {
            iii front = pq.top(); pq.pop();
            int d = front.first;
            ii u = front.second;
            if (dist[u.first][u.second] == d) {
                for (int d=0 ; d<4 ; d++) {
                    int nx, ny;
                    nx = u.first + dx[d];
                    ny = u.second + dy[d];
                    if (bound(nx, ny)) {
                        if (dist[u.first][u.second] + maze[nx][ny] < dist[nx][ny]) {
                            dist[nx][ny] = dist[u.first][u.second] + maze[nx][ny];
                            pq.push(make_pair(dist[nx][ny], ii(nx, ny)));
                        }
                    }
                }
            }
        }

        printf("%d\n", dist[N-1][M-1]);
    }

}
