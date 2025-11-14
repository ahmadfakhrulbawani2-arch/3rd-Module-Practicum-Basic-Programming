#include <stdio.h>

#define MAX 105

int n, m;
char map[MAX][MAX];
char visited[MAX][MAX];

// Simpan posisi dan angka teleport
int rowTele[10][2];
int colTele[10][2];
int countTele[10] = {0};

// QUEUE BFS
int qRow[MAX*MAX];
int qCol[MAX*MAX];
int front = 0, back = 0;

// flag untuk telport yg sudah digunakan
char used[10];

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

// push ke queue
void push(int r, int c) {
    qRow[back] = r;
    qCol[back] = c;
    back++;
}

int empty() {
    return front == back;
}

void bfs() {
    while(!empty()) {
        int r = qRow[front];
        int c = qCol[front];
        front++;

        if(map[r][c] == 'x') {
            printf("YES\n");
            return 0;
        }

        for(int i=0; i<4; i++) {
            int nr = r + dr[i]; // neighbor vertikal
            int nc = c + dc[i]; // neighbor horizontal
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(map[nr][nc] == '#') continue;
            if(visited[nr][nc]) continue;
            visited[nr][nc] = 1;
            push(nr, nc);
        }

        char cur = map[r][c];
        if(cur >= '1' && cur <= '9') {
            int d = cur - '0';
            if(!used[d]) {
                used[d] = 1;
                for(int i=0; i < countTele[d]; i++) {
                    int tRow = rowTele[d][i];
                    int tCol = colTele[d][i];
                    if(!visited[tRow][tCol]) {
                        visited[tRow][tCol] = 1;
                        push(tRow, tCol);
                    }
                }
            }
        }
    }
    printf("NO\n");
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%s", map[i]);
    }

    if(map[0][0] == '#') {
        printf("NO\n");
        return 0;
    }
    if(map[0][0] == 'x') {
        printf("YES\n");
        return 0;
    }

    // Catat posisi dan angka teleport
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c = map[i][j];
            if(c >= '1' && c <= '9') {
                int d = c - '0';
                rowTele[d][countTele[d]] = i;
                colTele[d][countTele[d]] = j;
                countTele[d]++;
            }
        }
    }

    visited[0][0] = 1;
    push(0, 0); // start queue

    bfs();
    return 0;
}
