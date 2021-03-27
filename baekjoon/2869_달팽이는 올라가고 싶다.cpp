//
// Created by 최우영 on 2021/03/05.
//

// https://peanut2016.tistory.com/39
#include <iostream>

using namespace std;

typedef long long ll;

// A, B, V가 공백으로 구분되어서 주어진다.
// (1 ≤ B < A ≤ V ≤ 1,000,000,000)
int A, B, V;
ll days;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> V;

    if ((V - A) % (A - B) == 0) days = (V - A) / (A - B);
    else days = (V - A) / (A - B) + 1;

    cout << days + 1 << "\n";
}