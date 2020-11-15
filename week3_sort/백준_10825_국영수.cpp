//
// Created by 최우영 on 2020/11/15.
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
    // 1-1. 국어 점수가 감소하는 순으로 정렬
    if (first.korean > second.korean) return true;
        // 2. 국어 점수가 같을 때
    else if (first.korean == second.korean) {
        // 2-1. 영어 점수가 증가하는 순으로 정렬
        if (first.english < second.english) return true;
            // 3. 영어 점수가 같을 때
        else if (first.english == second.english) {
            // 3-1. 수학 점수가 감소하는 순서로 정렬
            if (first.math > second.math) return true;
                // 4. 수학 점수가 같을 때
            else if (first.math == second.math) {
                // 4-1. 사전 순서로 정렬
                return first.name < second.name;
            }
                // 3-2. 수학 점수가 증가할 때
            else return false;
        }
            // 2-2. 영어 점수가 감소할 때
        else return false;
    }
        // 1-2. 국어 점수가 증가하면
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

    for (int i = 0; i < studentVector.size(); ++i) {
        student currentStudent = studentVector[i];
        cout << currentStudent.name << "\n";
    }
}

int main() {
    input();
    solution();
}