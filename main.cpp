#include <iostream>
#include <vector>

using namespace std;

int N, M;
int network[101][101];
bool isInfected[101];

int res;

bool isFinish(int start) {
    for (int i = 1; i <= N; ++i) {
        if (network[start][i] != 0) return false;
    }
    return true;
}

void dfs(int start) {
    if (isFinish(start)) return;

    for (int i = 1; i <= N; ++i) {
        if (network[start][i] == 1 && !isInfected[i]) {
            isInfected[i] = true;
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i < M; ++i) {
        int row, col;
        scanf("%d %d", &row, &col);

        network[row][col] = 1;
    }

    isInfected[1] = true;

    dfs(1);

    for (int i = 1; i <= N; ++i) {
        if (isInfected[i]) res++;
    }

    // 1번 컴퓨터 빼고 세야하므로 -1 해준다.
    printf("%d", res - 1);
}
