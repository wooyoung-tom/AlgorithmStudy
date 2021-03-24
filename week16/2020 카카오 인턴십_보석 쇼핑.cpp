//
// Created by 최우영 on 2021/03/24.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    // 처음에 최대 구간으로 설정
    vector<int> answer = {1, (int) gems.size()};

    unordered_map<string, int> map;
    unordered_set<string> set;

    // 좌, 우 포인터 두 개 선언
    int left = 0, right = 0;
    int diff = gems.size();

    // map 초기화 진행, 개수를 위해 set insert
    for (auto &gem : gems) set.insert(gem);

    while (true) {
        // 모든 보석이 다 담긴 경우
        if (map.size() == set.size()) {
            if (diff > right - left) {
                diff = right - left;
                answer[0] = left + 1;
                answer[1] = right;
            }
            // 보석이 하나남았으면 제거하고 left 증가시킨다.
            if (map[gems[left]] == 1) {
                map.erase(gems[left]);
                left++;
            }
                // 같은 종류의 보석이 여러개면 1개 감소시키고
                // left 증가시킨다.
            else if (map[gems[left]] - 1 > 0) {
                map[gems[left]]--;
                left++;
            }
        }
            // 끝까지 탐색하면 종료된다.
        else if (right == gems.size()) break;
            // 보석 종류를 다 포함하지 못한 경우에는 right 증가시킨다.
        else {
            map[gems[right]]++;
            right++;
        }
    }

    return answer;
}

int main() {
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int> answer = solution(gems);

    for (int i = 0; i < answer.size(); ++i) {
        printf("%d\n", answer[i]);
    }
}