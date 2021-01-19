#include <string>
#include <utility>
#include <vector>

#define TARGET 1000000007

using namespace std;

int way[101][101];

bool isPossible(int col, int row, int m, int n, vector<vector<int>> puddles) {
    for (int i = 0; i < puddles.size(); ++i) {
        int pCol = puddles[i][0];
        int pRow = puddles[i][1];

        if (col == pCol && row == pRow) return false;
    }

    return col <= m && row <= n;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // 집 가는 경우의 수를 1로 초기화
    way[1][1] = 1;

    // (1, 1) 부터 순회 시작
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 1. 오른쪽
            if (isPossible(j + 1, i, m, n, puddles)) {
                way[j + 1][i] = (way[j + 1][i] + way[j][i]) % TARGET;
            }
            // 2. 아래
            if (isPossible(j, i + 1, m, n, puddles)) {
                way[j][i + 1] = (way[j][i] + way[j][i + 1]) % TARGET;
            }
        }
    }

    answer = way[m][n] % TARGET;

    printf("%d", answer);

    return answer;
}