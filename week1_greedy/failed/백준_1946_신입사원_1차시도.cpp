//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 테스트 케이스의 개수 T(1 ≤ T ≤ 20)
// 첫째 줄에 지원자의 숫자 N(1 ≤ N ≤ 100,000)
int T, N;

// 서류심사 성적, 면접 성적 순위를 구조화 하여 처리
struct employ_score {
    int portfolio_rank, interview_rank;
};

// 성적과 순위를 담아놓을 vector
vector<employ_score> info_v;

void solution(vector<employ_score> &info);

// 구조체의 멤버변수를 토대로 정렬하기 위한 Compare 함수 선언
bool compare(const employ_score &first, const employ_score &second) {
    return first.portfolio_rank > second.portfolio_rank;
}

void input() {
    cin >> T;

    // 테스트 케이스 수인 T 만큼 loop 순회하면서 입력받는다.
    for (int i = 0; i < T; ++i) {
        cin >> N;
        // 그 후, 지원자의 숫자 N 만큼 score, rank 입력된다.
        for (int j = 0; j < N; ++j) {
            int rank1, rank2;
            cin >> rank1 >> rank2;
            info_v.push_back(employ_score{rank1, rank2});
        }
        solution(info_v);
        info_v.clear();
    }
}

void solution(vector<employ_score> &info) {
    // 먼저 서류심사 성적 내림차순으로 정렬한다.
    sort(info.begin(), info.end(), compare);

    // 선발에서 제외되어진 사람 수
    int elimination = 0;

    // 본인 제외 모든 순위를 Check 해야 하기 때문에 이중 for loop 구성면
    // 서류 심사 성적에서 내림차순으로 정렬하였기 때문에, 면접 순위에 따라서 판별 가능하다고 생각 됨.
    for (int i = 0; i < info.size(); ++i) {
        // 사실 이전 것과 자신 비교하여서 연산하였으므로
        // 자신 다음 부터 시작하면 된다.
        // 현재 존재하는 정보 리스트 사이즈와 같다면 비교할 필요가 없게 된다.
        if (i == info.size() - 1) break;
        for (int j = i + 1; j < info.size(); ++j) {
            // 1. 본인보다 순위가 높은 사람이 존재할 때
            // 이미 서류 심사 성적이 가장 최하위이므로 자신보다 순위가 높은 사람이 존재한다면 선발에서 제외된다.
            // 선발에서 제외 한 후에는 안쪽 for 문을 벗어나 새로운 비교 대상을 선정해야 한다.
            if (info[i].interview_rank > info[j].interview_rank) {
                elimination++;
                break;
            }
        }
    }

    cout << info.size() - elimination << "\n";
}

int main() {
    input();
//    solution();
}