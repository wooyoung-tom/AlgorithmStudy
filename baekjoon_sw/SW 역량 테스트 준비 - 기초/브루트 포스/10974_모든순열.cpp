//
// Created by djdj7 on 2020-05-24.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> permutation_v;
bool isVisited[8];

void input() {
    cin >> N;
}

void permutation() {
    if (permutation_v.size() == N) {
        for (int i = 0; i < permutation_v.size(); ++i) {
            cout << permutation_v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int j = 1; j <= N; ++j) {
        if (!isVisited[j]) {
            isVisited[j] = true;
            permutation_v.push_back(j);
            permutation();
            isVisited[j] = false;
            permutation_v.pop_back();
        }
    }
}

int main() {
    input();
    permutation();
}