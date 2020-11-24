//
// Created by 최우영 on 2020/11/24.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 128 + 1

using namespace std;

// N, M은 500,000 이하의 자연수
int N, M;
// 사람 이름 넣어놓을 vector
vector<string> nonListenedVector;
vector<string> nonSeenVector;

vector<string> result;

unordered_map<string, int> map;

void input() {
    string name;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> name;
        nonListenedVector.push_back(name);
    }
    for (int i = 0; i < M; ++i) {
        cin >> name;
        nonSeenVector.push_back(name);
    }
}

void solution() {
    // 먼저 듣도 못한 사람 N 만큼 순회하면서 map value 값 변경
    for (int i = 0; i < N; ++i) {
        string currentName = nonListenedVector[i];
        map[currentName]++;
    }

    // 보도 못한 사람 M 만큼 순회하면서 map 확인
    for (int i = 0; i < M; ++i) {
        string currentName = nonSeenVector[i];
        if (map[currentName] != 0) {
            result.push_back(currentName);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << "\n";
    }
}

int main() {
    input();
    solution();
}