//
// Created by 최우영 on 2021/01/04.
//


#include <iostream>
#include <vector>

#define MAX 9

using namespace std;

// 좌표 구조체
struct Point {
    int row, col;
};

// 스도쿠 판
int sudoku[MAX][MAX];
bool isVisited[MAX][MAX];
// 채워 넣어야 할 좌표 담을 vector
vector<Point> pVector;

void printSudoku() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

bool isPromising(int targetNum, Point point) {
    for (int i = 0; i < MAX; ++i) {
        // 1. 같은 row 에 있으면 유망하지 않음
        if (sudoku[i][point.col] == targetNum) return false;
        // 2. 같은 col 에 있으면 유망하지 않음
        if (sudoku[point.row][i] == targetNum) return false;
    }

    // 3. 현재 좌표의 범위 내에 있는 3x3 배열에도 존재하면 안된다.
    int downSizeRow = (point.row / 3) * 3;
    int downSizeCol = (point.col / 3) * 3;
    for (int row = downSizeRow; row < downSizeRow + 3; ++row) {
        for (int col = downSizeCol; col < downSizeCol + 3; ++col) {
            // 내꺼 빼고 비교해야 함.
            if (row == point.row && col == point.col) continue;
            if (sudoku[row][col] == targetNum) return false;
        }
    }

    return true;
}

void input() {
    for (int row = 0; row < MAX; ++row) {
        for (int col = 0; col < MAX; ++col) {
            scanf("%d", &sudoku[row][col]);

            if (sudoku[row][col] == 0) {
                pVector.push_back(Point{row, col});
            }
        }
    }
}

void solveSudoKu(int depth, Point point) {
    if (depth == pVector.size()) {
        printSudoku();

        // 프로그램을 끝내야 한다.
        exit(0);
    }

    for (int i = 1; i <= MAX; ++i) {
        if (!isVisited[point.row][point.col] && isPromising(i, point)) {
            isVisited[point.row][point.col] = true;

            // 스도쿠 판 수정한다.
            sudoku[point.row][point.col] = i;

            solveSudoKu(depth + 1, pVector[depth + 1]);

            // 한 번 갔다 왔는데 해결 못했다면 0으로 초기화 시켜주어야 한다.
            sudoku[point.row][point.col] = 0;

            isVisited[point.row][point.col] = false;
        }
    }
}

int main() {
    input();

    solveSudoKu(0, pVector[0]);
}