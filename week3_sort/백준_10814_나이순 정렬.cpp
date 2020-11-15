//
// Created by 최우영 on 2020/11/15.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// 회원수 N (1 ≤ N ≤ 100,000)
int N;
// 회원 정보 구조체
struct member {
    int order, age;
    string name;
};
// 회원 정보 담아 놓을 vector
vector<member> memberVector;


// 정렬 함수
bool compare(const member &first, const member &second) {
    // 1. 나이 순서대로 정렬
    if (first.age < second.age) return true;
        // 2. 나이 같을 때
    else if (first.age == second.age) {
        // 2-1. 가입한 순서대로 정렬
        return first.order < second.order;
    }
    else return false;
}

void input() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int age;
        string name;

        cin >> age >> name;

        // vector 에 입력
        memberVector.emplace_back(member{i, age, name});
    }
}

void solution() {
    sort(memberVector.begin(), memberVector.end(), compare);

    for (int i = 0; i < memberVector.size(); ++i) {
        member currentMember = memberVector[i];
        cout << currentMember.age << " " << currentMember.name << "\n";
    }
}

int main() {
    input();
    solution();
}