//
// Created by djdj7 on 2020-05-15.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    int map1[n][n];
    int map2[n][n];

    string sharp_row;

    for (int i = 0; i < n; ++i) {
        int current_dec1 = arr1[i];
        int current_dec2 = arr2[i];
        for (int j = n - 1; j >= 0; --j) {
            map1[i][j] = current_dec1 % 2;
            map2[i][j] = current_dec2 % 2;
            current_dec1 /= 2;
            current_dec2 /= 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map1[i][j] + map2[i][j] != 0) {
                sharp_row += '#';
            } else {
                sharp_row += ' ';
            }
        }
        answer.push_back(sharp_row);
        sharp_row.clear();
    }

    return answer;
}

int main() {
    int n = 6;
    vector<int> arr1 = {46, 33, 33 ,22, 31, 50};
    vector<int> arr2 = {27 ,56, 19, 14, 14, 10};

    solution(n, arr1, arr2);
}