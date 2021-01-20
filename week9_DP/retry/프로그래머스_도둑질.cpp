//
// Created by 최우영 on 2021/01/20.
//

#include <string>
#include <vector>

#define MAX 1000001

using namespace std;

int dp[MAX];

int solution(vector<int> money) {
    int answer = 0;
    int mSize = money.size();

    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);

    for (int i = 2; i < mSize - 1; ++i) {
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }

    answer = dp[mSize - 2];

    dp[0] = 0;
    dp[1] = money[1];

    for (int i = 2; i < mSize; ++i) {
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }

    answer = max(answer, dp[mSize - 1]);

    return answer;
}