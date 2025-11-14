#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int visited[MAXSIZE][MAXSIZE] = {0};
char map[MAXSIZE][MAXSIZE];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int curr = 0, best = 0;

int dfs(int i, int j, int r, int c) {
    if(i < 0 || i >= r || j < 0 || j >= c) return 0; // out of bounds
    if(map[i][j] < '0' || map[i][j] > '9') return 0; // bukan angka
    if(visited[i][j]) return 0; // sudah dikunjungi

    visited[i][j] = 1;
    int sum = map[i][j] - '0';

    for(int idx = 0; idx < 4; idx++) {
        sum += dfs(i + dr[idx], j + dc[idx], r, c);
    }
    return sum;
}

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        scanf("%s", map[i]);
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(map[i][j] >= '0' && map[i][j] <= '9' && visited[i][j] == 0) {
                int curr = dfs(i, j, r, c);
                best = MAX(curr, best);
                curr = 0;
            }
        }
    }

    printf("%d", best);
    return 0;
}