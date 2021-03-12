//
// Created by 최우영 on 2021/03/12.
//

#include <string>
#include <vector>

using namespace std;

struct Point {
    int row, col;
};

// 왼손, 오른손 시작 위치
Point left = Point{3, 0};
Point right = Point{3, 2};

string selectHand(int key, const string &hand) {
    string result;
    int mRow;   // 어차피 col 은 1로 고정됨
    int lTmp = -1, rTmp = -1;

    switch (key) {
        case 0: {
            // 0번 버튼일 때 키패드 위치 (3, 1)
            lTmp = abs(left.row - 3) + abs(left.col - 1);
            rTmp = abs(right.row - 3) + abs(right.col - 1);
            mRow = 3;
            break;
        }
        case 2: {
            // 2번 버튼일 때 키패드 위치 (0, 1)
            lTmp = abs(left.row) + abs(left.col - 1);
            rTmp = abs(right.row) + abs(right.col - 1);
            mRow = 0;
            break;
        }
        case 5: {
            // 5번 버튼일 때 키패드 위치 (1, 1)
            lTmp = abs(left.row - 1) + abs(left.col - 1);
            rTmp = abs(right.row - 1) + abs(right.col - 1);
            mRow = 1;
            break;
        }
        case 8: {
            // 5번 버튼일 때 키패드 위치 (1, 1)
            lTmp = abs(left.row - 2) + abs(left.col - 1);
            rTmp = abs(right.row - 2) + abs(right.col - 1);
            mRow = 2;
            break;
        }
        default:
            break;
    }

    if (lTmp < rTmp) {
        result = "L";
        // 왼손 움직였으니까
        left.row = mRow;
        left.col = 1;
    } else if (lTmp > rTmp) {
        result = "R";
        // 오른손 움직였으니까
        right.row = mRow;
        right.col = 1;
    } else {
        // 둘이 거리 같을 때는 무슨 손 잡이인지 중요
        if (hand == "right") {
            result = "R";
            right.row = mRow;
            right.col = 1;
        } else if (hand == "left") {
            result = "L";
            left.row = mRow;
            left.col = 1;
        }
    }

    return result;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            // 1, 4, 7 일 때 왼손으로 눌러야 한다.
            answer += "L";
            // row 를 현재 키패드 숫자에서 3을 나누어 준다.
            left.row = numbers[i] / 3;
            left.col = 0;
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            // 3, 6, 9 일 때 오른손으로 눌러야 한다.
            answer += "R";
            // row 를 현재 키패드 숫자에서 3을 나누고 1을 빼준다.
            right.row = numbers[i] / 3 - 1;
            right.col = 2;
        } else {
            // 2, 5, 8, 0 일 때는 가까운 손으로 누른다.
            answer += selectHand(numbers[i], hand);
        }
    }

    return answer;
}

int main() {
    vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand = "left";

    printf("%s\n", solution(numbers, hand).c_str());
}