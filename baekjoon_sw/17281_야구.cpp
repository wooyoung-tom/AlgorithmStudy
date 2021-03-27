//
// Created by djdj7 on 2020-05-24.
//

#include <iostream>

using namespace std;

int N;                          // 이닝 수
int player_order[10];           // 타순
int board[50][10];              // 이닝 별 결과
int position[10];               // 각 타자별 위치
int max_score;                  // 최종 최다 점수
bool isOrdered[10];             // 선수가 배치되었는지 확인

void input() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> board[i][j];
        }
    }

    /* 1번 선수는 항상 타순배치. */
    /* 1번 선수는 항상 4번타자. */
    isOrdered[1] = true;
    player_order[4] = 1;
}

int hit_and_score(int current_player, int base) {
    int score = 0;
    /* 누상에 주자가 있는지에 대한 확인 */
    for (int j = 1; j < 10; ++j) {
        /* 누상에 주자가 있거나, 타자주자 자신일 때 */
        if (position[j] != 0 || j == current_player) {
            position[j] += base;
            if (position[j] >= 4) {
                score++;
                position[j] = 0;
            }
        }
    }

    return score;
}

void baseball() {
    int score = 0;
    int current_order = 1;                                  // 현재 타순
    int current_player = player_order[current_order];       // 현재 선수

    for (int i = 0; i < N; ++i) {
        int out_count = 0;

        while (true) {
            /* 현재 선수가 현재 이닝의 결과가 아웃일 때 */
            if (board[i][current_player] == 0) {
                out_count++;                                // 아웃카운트 하나 늘림
                current_order++;                            // 다음 타순으로 감
                if (current_order == 10) {
                    current_order = 1;                      // 다음 타순이 10번이면 1번 (타자 일순)
                    current_player = player_order[current_order];
                } else {
                    current_player = player_order[current_order];
                }
                if (out_count == 3) {
                    /* 누상의 주자 비움 */
                    for (int j = 1; j < 10; ++j) {
                        position[j] = 0;
                    }
                    break;
                }
            } else {    /* 현재 선수가 현재 이닝의 결과가 아웃이 아닐 때 */

                /* 일단 누상의 주자들 움직여야 함. */

                /* 현재 타자가 1루타 쳤을 때 */
                if (board[i][current_player] == 1) score += hit_and_score(current_player, 1);
                    /* 현재 타자가 2루타 쳤을 때 */
                else if (board[i][current_player] == 2) score += hit_and_score(current_player, 2);
                    /* 현재 타자가 3루타 쳤을 때 */
                else if (board[i][current_player] == 3) score += hit_and_score(current_player, 3);
                    /* 현재 타자가 홈런 쳤을 때 */
                else score += hit_and_score(current_player, 4);

                /* 주자 모두 움직이고 난 후 */
                current_order++;                            // 다음 타순으로 감
                if (current_order == 10) {
                    current_order = 1;                      // 다음 타순이 10번이면 1번 (타자 일순)
                    current_player = player_order[current_order];
                } else {
                    current_player = player_order[current_order];
                }
            }
        }
    }
    max_score = max(max_score, score);
}

void set_order(int player) {
    int order_index = player;

    /* player > 9 이면 타순작성 완료. */
    if (player > 9) {
        baseball();
        return;
    }

    /*
     * 2번 선수부터 타순 작성 (재귀 함수).
     * i 는 선수 / player 는 타순
     */
    for (int i = 2; i <= 9; ++i) {
        if (!isOrdered[i]) {
            player_order[order_index] = i;
            isOrdered[i] = true;
            if (order_index == 3) {
                set_order(5);
            } else {
                set_order(order_index + 1);
            }
            isOrdered[i] = false;
        }
    }
}

int main() {
    input();

    /* 1번 선수부터 타순 작성 */
    set_order(1);

    cout << max_score;
}