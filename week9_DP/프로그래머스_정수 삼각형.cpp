//
// Created by 최우영 on 2021/01/19.
//

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> tmp = triangle;

    // 첫 번째 줄부터 이동
    for (int i = 0; i < triangle.size() - 1; ++i) {
        // 현재 벡터 순회
        for (int j = 0; j < triangle[i].size(); ++j) {
            // 현재 숫자
            int currentNum = tmp[i][j];
            // 계산할 숫자
            int targetLeftNum = triangle[i + 1][j];
            int targetRightNum = triangle[i + 1][j + 1];

            // 1. 왼쪽 아래 값 바꾸기
            if (tmp[i + 1][j] < (targetLeftNum + currentNum)) {
                tmp[i + 1][j] = targetLeftNum + currentNum;
            }
            // 2. 오른쪽 아래 값 바꾸기
            if (tmp[i + 1][j + 1] < (targetRightNum + currentNum)) {
                tmp[i + 1][j + 1] = targetRightNum + currentNum;
            }
        }
    }

    for (int i = 0; i < tmp[tmp.size() - 1].size(); ++i) {
        if (answer < tmp[tmp.size() - 1][i]) {
            answer = tmp[tmp.size() - 1][i];
        }
    }

    printf("%d", answer);
    return answer;
}

int main() {
    vector<vector<int>> triangle = {
            {7},
            {3, 8},
            {8, 1, 0},
            {2, 7, 4, 4},
            {4, 5, 2, 6, 5}
    };

    solution(triangle);
}