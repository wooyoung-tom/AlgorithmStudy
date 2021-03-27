//
// Created by 최우영 on 2021/03/02.
//

#include <iostream>

using namespace std;

// 자연수를 입력받아 뒤집어서 리턴하는 함수
int reverse(int x) {
    int res = 0;

    while (x > 0) {
        int tmp = x % 10;
        res = res * 10 + tmp;
        x /= 10;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int num = 0;
        cin >> num;

        // 입력 받은 수가 0일 때 끝
        if (num == 0) break;

        int rNum = reverse(num);

        if (num == rNum) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}