// 2013011769_KangSeungWon_508

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int
main() {
    int N, x, y, numOfComponents = 0, i, j;
    vector<int> vertice;
    vector< vector<int> > connected;
    
    scanf("%d", &N);
    connected.resize(N + 1, vector<int>(N + 1, 0));
    vertice.resize(N + 1, 0);
    
    while (scanf("%d%d", &x, &y) != EOF) {
        connected[x][y] = connected[y][x] = 1;
    }
    
    for (i = 1; i <= N; ++i) {
        int& currentVertex = vertice[i];
        
        if (!currentVertex) {
            ++numOfComponents;
            queue<int> bfs;
            bfs.push(i);
            
            while (!bfs.empty()) {
                int bfsVertex = bfs.front();
                bfs.pop();
                vertice[bfsVertex] = numOfComponents;
                
                for (j = 1; j <= N; ++j) {
                    if (connected[bfsVertex][j] && !vertice[j]) {
                        bfs.push(j);
                    }
                }
            }
        }
    }
    
    printf("%d\n", numOfComponents);
    
    for (i = 1; i <= N; ++i) {
        printf("%d\n", vertice[i]);
    }
}
