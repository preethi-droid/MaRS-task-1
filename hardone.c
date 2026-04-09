#include <stdio.h>

#define N 11

int grid[N][N];

//directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

//queue for BFS
int qx[200], qy[200];
int front = 0, rear = 0;

//distance array
int dist[N][N];

int isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 1);
}

void bfs() {
    //initializing distance
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = -1;

    //starting from (0,0)
    qx[rear] = 0;
    qy[rear] = 0;
    rear++;

    dist[0][0] = 0;

    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        front++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                qx[rear] = nx;
                qy[rear] = ny;
                rear++;
            }
        }
    }
}

int main() {
    //initializing grid with 1
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = 1;

    //reading the obstacle file
    FILE *fp = fopen("sample.txt", "r");

    int n, e, s, w;

    while (fscanf(fp, "%d %d %d %d", &n, &e, &s, &w) != EOF) {
        //marking the obstacle positions as 0
        if (n < N) grid[n][0] = 0;
        if (e < N) grid[0][e] = 0;
        if (s < N) grid[s][N-1] = 0;
        if (w < N) grid[N-1][w] = 0;
    }

    fclose(fp);

    //printing the grid
    printf("Arena Map (1 = safe, 0 = obstacle):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    //BFS shortest path
    bfs();

    if (dist[10][10] != -1)
        printf("\nShortest path length: %d\n", dist[10][10]);
    else
        printf("\nNo path found\n");

    return 0;
}
