//
// Created by 최우영 on 2020/11/01.
//

#include <iostream>
#include <vector>

using namespace std;

// 캠핑장을 연속하는 P 일 중, L 일동안만 사용할 수 있다. 강산이는 이제 막 V 일짜리 휴가를 시작했다.
// 강산이가 캠핑장을 최대 며칠동안 사용할 수 있을까? (1 < L < P < V)
int L, P, V;

struct input_info {
    int L, P, V;
};

vector<input_info> input_v;

void input() {
    // 0 0 0 이 나올 때 까지 입력받아야 하므로 무한루프로 구현
    while (true) {
        cin >> L >> P >> V;

        // 0 0 0 나왔으니 무한루프 탈출 break;
        if (L == 0 && P == 0 && V == 0)
            break;
        else {
            struct input_info info{L, P, V};
            input_v.push_back(info);
        }
    }
}

int calculate(struct input_info info) {
    // 계속해서 계산되는 V 값 저장할 변수
    int current_V = info.V;

    // 현재 결과 저장할 변수
    int current_result = 0;

    // 계속해서 계산해야 하기 때문에 무한루프로 설정 -> 시간초과의 원인인 것으로 보임.
    // 무한루프 사용하지 않아도 나머지 사용해서 해결 가능할 듯

    // 캠핑 횟수를 정하고 L 만큼 곱한다.
    int camp_time = info.V / info.P;
    current_result = camp_time * info.L;

    // 횟수만큼 캠핑하고 남은 일 수에 대해서 생각한다.
    int remainder_day = current_V - camp_time * info.P;

    // 남은 일 수가 L 보다 크다면 -> L 일 만큼 캠핑 더 할 수 있음
    if (remainder_day > info.L) {
        current_result += info.L;
    }
    // 남은 일 수가 L 보다 작다면 -> 남은 일 수 만큼 캠핑 더 할 수 있음
    else {
        current_result += remainder_day;
    }

    return current_result;
}

void solution() {
    // 결과 저장할 변수
    int result = 0;

    // 벡터에 담아놓은 정보 하나씩 꺼내서 솔루션 수행
    for (int i = 0; i < input_v.size(); ++i) {
        struct input_info current_info = input_v[i];

        result = calculate(current_info);

        cout << "Case " << i + 1 << ": " << result << "\n";
    }
}

int main() {
    input();
    solution();
}