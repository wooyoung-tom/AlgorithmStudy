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
    return first.portfolio_rank < second.portfolio_rank;
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
    // 합격자 수 저장할 변수
    int result = 0;

    // 먼저 서류심사 성적 오름차순으로 정렬한다.
    sort(info.begin(), info.end(), compare);

    // 서류심사 성적 오름차순으로 정렬하였다면 첫번째 지원자는 서류면접 1위이므로 무조건 합격하게된다.
    // (자신보다 높은 사람이 없기 때문)
    // 그 후, 자신보다 서류심사 순위가 낮은 사람과 면접심사 순위를 비교하기 위해 1위의 면접심사 성적을 저장
    result++;
    int current_interview_rank = info[0].interview_rank;

    // 두 번째 지원자부터 첫 번째 지원자의 면접 등수를 비교해간다.
    for (int i = 1; i < info.size(); ++i) {
        // 1. 현재 비교대상인 면접 순위보다 자신의 면접 순위가 높을 때
        if (current_interview_rank > info[i].interview_rank) {
            // 현재 비교대상이 합격하였기 때문에 합격한 사람보다 면접 순위가 높은 것이므로 합격
            // 현재 비교대상을 현재 지원자로 수정한다.
            result++;
            current_interview_rank = info[i].interview_rank;
        }
        // 2. 현재 비교대상인 면접 순위보다 자신의 면접 순위가 낮을 때
        // 탈락이므로 연산 필요없음.
        else continue;
    }

    cout << result << "\n";
}

int main() {
    input();
//    solution();
}