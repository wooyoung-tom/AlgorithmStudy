//
// Created by 최우영 on 2020/12/06.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// n은 20보다 작거나 같은 자연수 또는 0
int n;

int fibonacci(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

void input() {
    cin >> n;
    int result = fibonacci(n);
    cout << result;
}

void solution() {

}

int main() {
    input();
//    solution();
}