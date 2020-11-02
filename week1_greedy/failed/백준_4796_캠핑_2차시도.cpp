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

    // 계속해서 계산해야 하기 때문에 무한루프로 설정
    while (true) {
        // Case 를 나누어서 생각해야 한다.
        // 1. 남은 일 수가 P 보다 크거나 같을 때 -> L 일 동안은 무조건 사용가능
        // 하지만 남은 일 수는 P 만큼 빼주어야 함. 남은 일은 사용 못하고 그냥 지나가기 때문
        if (current_V >= info.P) {
            current_V -= info.P;
            current_result += info.L;
        }
            // 2. 남은 일 수가 P 보다 작을 때
            // 2.1 그 남은 일 수가 L 보다 클 때
        else if (current_V < info.V && current_V > info.L){
            current_result += info.L;
            break;
        }
            // 2.2 남은 일 수가 L 보다 작을 때
        else if (current_V < info.V && current_V < info.L) {
            current_result += current_V;
            break;
        }
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