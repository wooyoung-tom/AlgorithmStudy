//
// Created by djdj7 on 2020-03-19.
//

/*
 * recursive 사용해야하는지? ==> 다시한번 recursive 생각해서 풀어볼만 함.
 * 회전 시키기전에 1,2,3,4번 톱니바퀴 돌아야하는지 안돌아도되는지부터 체크하고
 * 마지막에 차례대로 톱니바퀴 Direction 따라서 회전시키면 됨.
 */

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int tobni_condition[4][8];
int K;

void rotate(int (&arr)[8], int direction) {
    if(direction == 1) {
        int temp = arr[7];
        for(int i = 7 ; i > 0 ; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    } else {
        int temp = arr[0];
        for(int i = 0 ; i < 7 ; i++) arr[i] = arr[i + 1];
        arr[7] = temp;
    }
}

void solve(int start, int direction) {
    if(start == 0) {
        if(tobni_condition[start][2] != tobni_condition[start+1][6]) {
            if(tobni_condition[start+1][2] != tobni_condition[start+2][6]) {
                if(tobni_condition[start+2][2] != tobni_condition[start+3][6]) {
                    rotate(tobni_condition[start], direction);
                    rotate(tobni_condition[start+1], -1 * direction);
                    rotate(tobni_condition[start+2], direction);
                    rotate(tobni_condition[start+3], -1 * direction);
                } else {
                    rotate(tobni_condition[start], direction);
                    rotate(tobni_condition[start+1], -1 * direction);
                    rotate(tobni_condition[start+2], direction);
                }
            } else {
                rotate(tobni_condition[start], direction);
                rotate(tobni_condition[start+1], -1 * direction);
            }
        } else rotate(tobni_condition[start], direction);
    } else if (start == 1) {
        if(tobni_condition[start][6] != tobni_condition[start-1][2]) rotate(tobni_condition[start-1], -1 * direction);
        if(tobni_condition[start][2] != tobni_condition[start+1][6]) {
            if(tobni_condition[start+1][2] != tobni_condition[start+2][6]) {
                rotate(tobni_condition[start], direction);
                rotate(tobni_condition[start+1], -1 * direction);
                rotate(tobni_condition[start+2], direction);
            } else {
                rotate(tobni_condition[start], direction);
                rotate(tobni_condition[start+1], -1 * direction);
            }
        } else rotate(tobni_condition[start], direction);
    } else if(start == 2) {
        if(tobni_condition[start][2] != tobni_condition[start+1][6]) rotate(tobni_condition[start+1], -1 * direction);
        if(tobni_condition[start][6] != tobni_condition[start-1][2]) {
            if(tobni_condition[start-1][6] != tobni_condition[start-2][2]) {
                rotate(tobni_condition[start], direction);
                rotate(tobni_condition[start-1], -1 * direction);
                rotate(tobni_condition[start-2], direction);
            } else {
                rotate(tobni_condition[start], direction);
                rotate(tobni_condition[start-1], -1 * direction);
            }
        } else rotate(tobni_condition[start], direction);
    } else if (start == 3) {
        if(tobni_condition[start][6] != tobni_condition[start-1][2]) {
            if(tobni_condition[start-1][6] != tobni_condition[start-2][2]) {
                if(tobni_condition[start-2][6] != tobni_condition[start-3][2]) {
                    rotate(tobni_condition[start], direction);
                    rotate(tobni_condition[start-1], -1 * direction);
                    rotate(tobni_condition[start-2], direction);
                    rotate(tobni_condition[start-3], -1 * direction);
                } else {
                    rotate(tobni_condition[start], direction);
                    rotate(tobni_condition[start-1], -1 * direction);
                    rotate(tobni_condition[start-2], direction);
                }
            } else {
                rotate(tobni_condition[start], direction);
                rotate(tobni_condition[start-1], -1 * direction);
            }
        } else rotate(tobni_condition[start], direction);
    }
}

void inputArr() {
    int a, b;
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 8 ; j++) {
            scanf("%1d", &tobni_condition[i][j]);
        }
    }
    cin >> K;

    for(int i = 0 ; i < K ; i++) {
        cin >> a >> b;
        solve(a - 1, b);
    }
}

int main() {
    int result = 0;
    inputArr();

    for(int i = 0 ; i < 4 ; i++) {
        if(tobni_condition[i][0] == 1) result += pow(2, i);
    }
    cout << result;
}