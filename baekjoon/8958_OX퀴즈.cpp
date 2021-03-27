//
// Created by 최우영 on 2021/01/03.
//

#include <iostream>

using namespace std;

int main() {
    int T;
    char ox[81];

    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        int cScore = 0;
        int correct = 0;

        scanf("%s", ox);

        for (int j = 0; ox[j] != '\0' ; ++j) {
            // 정답일 때
            if (ox[j] == 'O') {
                correct++;

                cScore += (1 * correct);
            } else correct = 0;
        }

        printf("%d\n", cScore);
    }
}