//
// Created by djdj7 on 2020-05-29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dwarf[9];
int total_height;
bool isChecked[9];
bool isPrinted;
vector<int> height_v;

void input() {
    for (int i = 0; i < 9; ++i) {
        cin >> dwarf[i];
    }
}

void calculate() {
    for (int i = 0; i < 9; ++i) {
        if (isChecked[i]) {
            total_height += dwarf[i];
            height_v.push_back(dwarf[i]);
        }
    }

    if (total_height == 100) {
        sort(height_v.begin(), height_v.end());

        if (!isPrinted) {
            for (int i = 0; i < height_v.size(); ++i) {
                cout << height_v[i] << "\n";
            }
            isPrinted = true;
        } else {
            return;
        }
    } else {
        total_height = 0;
        height_v.clear();
    }
}

void solution(int current_count, int current_index) {
    if (current_count == 7) {
        calculate();
        return;
    }
    for (int j = current_index; j < 9; ++j) {
        if (!isChecked[j]) {
            isChecked[j] = true;
            solution(current_count + 1, j);
            isChecked[j] = false;
        }
    }
}

int main() {
    input();
    solution(0, 0);
}