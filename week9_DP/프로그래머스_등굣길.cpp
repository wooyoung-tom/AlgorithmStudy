//
// Created by 최우영 on 2021/01/19.
//

#include <string>
#include <utility>
#include <vector>

#define TARGET 1000000007

using namespace std;

int way[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // 1행, 1열 모두 1로 초기화
    for (int i = 1; i <= m; ++i) {
        way[1][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        way[i][1] = 1;
    }

    // 웅덩이 -1로 배열 수정
    for (int i = 0; i < puddles.size(); ++i) {
        way[puddles[i][1]][puddles[i][0]] = -1;
    }

    // (2, 2) 부터 순회 시작
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;

            if (way[i][j] == -1) way[i][j] = 0;
            else way[i][j] = (way[i][j - 1] + way[i - 1][j]) % TARGET;
        }
    }

    answer = way[n][m];

    printf("%d", answer);

    return answer;
}