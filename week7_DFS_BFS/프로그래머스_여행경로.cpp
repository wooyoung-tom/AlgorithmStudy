//
// Created by 최우영 on 2021/01/10.
//

#include <iostream>
#include <vector>

using namespace std;

bool isUsed[10001];

vector<vector<string>> completeRoute;
vector<string> route;

bool compare(const vector<string> &first, const vector<string> &second) {
    // 어차피 두개 사이즈는 같다.
    for (int i = 0; i < first.size(); ++i) {
        // 1. 요소가 같으면 continue
        if (first[i] == second[i]) continue;
            // 2. 다를 때 비교 (알파벳 순서)
        else return first[i] < second[i];
    }
    return false;
}

void travel(int depth, const string &departure, const vector<vector<string>> &tickets) {
    if (depth == tickets.size()) {
        // 마지막 행선지 넣고, route 에 완성된 정보 넣는다.
        route.push_back(departure);
        completeRoute.push_back(route);
        route.pop_back();
        return;
    }

    for (int i = 0; i < tickets.size(); ++i) {
        // 현재 출발지와 티켓 출발지가 같고, 티켓이 사용하지 않은 티켓일 때
        if (departure == tickets[i][0] && !isUsed[i]) {
            isUsed[i] = true;
            route.push_back(departure);
            travel(depth + 1, tickets[i][1], tickets);
            route.pop_back();
            isUsed[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    travel(0, "ICN", tickets);

    sort(completeRoute.begin(), completeRoute.end(), compare);

    answer = completeRoute[0];

    return answer;
}

int main() {

}