//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct student {
    string name;
    int korean, english, math;
};

int N;
vector<student> studentVector;

bool compare(const student &first, const student &second) {
    // 1. 국어 점수가 감소하는 순으로 정렬
    if (first.korean < second.korean) return true;
    // 2. 국어 점수가 같을 때
    else if (first.korean == second.korean) {

    }
    // 3. 국어 점수가 오를 때
    else return false;
}

void input() {
    string name;
    int korean, english, math;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> name >> korean >> english >> math;
        studentVector.push_back(student{name, korean, english, math});
    }
}

void solution() {
    // 정렬 수행
    sort(studentVector.begin(), studentVector.end(), compare);
}

int main() {
    input();
    solution();
}