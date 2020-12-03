//
// Created by 최우영 on 2020/12/02.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 50 + 1
#define CHESS_MAX 8 + 1

using namespace std;

// N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수
int N, M;

// 현재 판 상태 담을 2차원 배열 선언
vector<string> inputVector;
char originalBoard[MAX][MAX];
char chessBoard[CHESS_MAX][CHESS_MAX];

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        inputVector.push_back(row);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            // vector 는 (0, 0) 부터 시작하도록 되어있음
            originalBoard[i][j] = inputVector[i - 1][j - 1];
        }
    }
}

void initBoard(const int startRow, const int startColumn) {
    int tempRow = startRow;
    int tempColumn = startColumn;
    for (int i = 1; i < CHESS_MAX; ++i) {
        for (int j = 1; j < CHESS_MAX; ++j) {
            chessBoard[i][j] = originalBoard[tempRow][tempColumn];
            tempColumn++;
        }
        tempRow++;
        tempColumn = startColumn;
    }
}

int coloringChessBoard() {
    int result = 0;
    char firstColor = chessBoard[1][1];

    for (int i = 1; i < CHESS_MAX; ++i) {
        for (int j = 1; j < CHESS_MAX; ++j) {
            char targetColor = chessBoard[i][j];
            // 행 + 열 값의 합이 짝수이면 첫 번째 칸과 색깔이 같아야 한다.
            if ((i + j) % 2 == 0) {
                if (firstColor != targetColor) result++;
            }
                // 반대로 홀수이면 첫 번째 칸과 색깔이 달라야 한다.
            else {
                if (firstColor == targetColor) result++;
            }
        }
    }

    return result;
}

void solution() {
    // 최소 정사각형 갯수 찾기 위해서 최대로 칠해야 하는 MAX * MAX 로 갯수 설정
    int minColoredSquareCounter = 50 * 50;

    // (1, 1) 부터 시작해서 보드 초기화
    for (int i = 1; i + 7 <= N; ++i) {
        for (int j = 1; j + 7 <= M; ++j) {
            // 보드 초기화
            initBoard(i, j);

            // 8 * 8 보드내에서 몇개 색칠할 지 구한다.
            minColoredSquareCounter = min(minColoredSquareCounter, coloringChessBoard());
        }
    }

    cout << minColoredSquareCounter;
}

int main() {
    input();
    solution();
}