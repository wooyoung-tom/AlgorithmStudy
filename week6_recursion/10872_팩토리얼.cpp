//
// Created by 최우영 on 2020/12/06.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

// 정수 N(0 ≤ N ≤ 12)
int N;

int factorial(int n) {
    if (n == 0) return 1;
    if (n == 1) return n;

    int result = n;
    return result * factorial(n - 1);
}

void input() {
    cin >> N;

    int result = factorial(N);

    cout << result;
}

void solution() {

}

int main() {
    input();
//    solution();
}