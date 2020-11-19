//
// Created by 최우영 on 2020/11/19.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define MAX 4000 + 1

using namespace std;

// 배열의 크기 n (1 ≤ n ≤ 4000)
int n;
// 숫자 담아 놓을 배열 선언 Arr: 2차원 배열 AB, CD: 합 전처리 후 담을 vector
int A[MAX], B[MAX], C[MAX], D[MAX];
vector<int> AB, CD;

void input() {
    // 배열의 크기를 입력 받음
    scanf("%d", &n);

    // n 만큼 돌면서 배열 element 하나씩 받는다.
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    }
}

void solution() {
    // 결과값 담을 변수
    long long answer = 0;

    // AB 와 CD 만들어주는 과정
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + B[j]);
        }
    }

    // AB 와 CD 배열을 오름차순으로 정렬
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    // AB 는 앞에서 부터 순회, CD 는 뒤에서 부터 순회
    int AB_index = 0;
    int CD_index = CD.size() - 1;

    // 둘 중 한 곳이라도 탐색 완료하면 종료한다.
    while (AB_index < AB.size() && CD_index >= 0) {
        // 합이 0 이 되는 경우
        if (AB[AB_index] + CD[CD_index] == 0) {
            int currentIndex = AB_index;
            long long same_AB = 0, same_CD = 0;

            while (AB[AB_index] + CD[CD_index] == 0) {
                // AB 배열에서 현재 원소와 같은 원소 count
                if (AB_index >= AB.size()) break;
                same_AB++;
                AB_index++;
            }

            while (AB[currentIndex] + CD[CD_index] == 0) {
                // CD 배열에서 현재 원소와 같은 원소 count
                if (CD_index < 0) break;
                same_CD++;
                CD_index++;
            }

            answer += (same_AB * same_CD);
        }
        else if (AB[AB_index] + CD[CD_index] < 0) AB_index++;
        else CD_index--;
    }
    cout << answer;
}

int main() {
    input();
    solution();
}