#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, int> map;
unordered_set<string> set;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    // 좌, 우 포인터 두 개 선언
    int left = 0, right = 0;

    // map 초기화 진행, 개수를 위해 set insert
    for (auto &gem : gems) {
        map[gem] = 0;
        set.insert(gem);
    }

    // 전체 보석의 개수
    int totalGemsCount = set.size();
    // 현재 골라놓은 보석의 개수
    int currentGemsCount = 0;

    int tLeft = 0, tRight = 0;

    while (true) {
        // left, right 가 범위를 벗어나게되면 종료한다.
        if (left > gems.size() || right > gems.size()) break;

        // 현재 골라놓은 보석의 개수가 전체 보석의 개수와 같은지 비교한다.
        if (totalGemsCount == currentGemsCount) {
            // 같을 때
            // 현재 좌, 우 포인터 두개의 길이가 이전에 저장했던 길이와 같으면
            // 이전에 저장했던 두 포인터를 그대로 가져가야 한다.
            if (right - left != tRight - tLeft) {
                tLeft = left;
                tRight = right;
            }

            // left 를 한 칸 앞으로 옮기는 작업을 수행해야 한다.
            left++;

            // left 에 있는 해당 보석의 빈도 수를 하나 뺀다.
            map[gems[left - 1]]--;

            // 그러고 나서 해당 보석 빈도 수가 0이 된다면 골라 놓은 보석의 개수를 하나 줄여야 한다.
            if (map[gems[left - 1]] == 0) currentGemsCount--;
        } else {
            // 다를 때
            // right 를 한 칸 앞으로 옮기는 작업을 수행해야 한다.
            right++;

            // right 한 칸 앞으로 옮겼는데 범위를 벗어났다면 종료
            if (right > gems.size()) break;

            // 만약에 한번도 고른적이 없는 보석이라면 현재 골라놓은 보석의 개수 하나 올려준다.
            if (map[gems[right - 1]] == 0) currentGemsCount++;

            // right 를 한 칸 앞으로 옮긴 후, map 에 해당 보석의 빈도 수를 하나 올려준다.
            map[gems[right - 1]]++;
        }
    }

    answer.push_back(tLeft + 1);
    answer.push_back(tRight);

    return answer;
}

int main() {
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int> answer = solution(gems);

    for (int i = 0; i < answer.size(); ++i) {
        printf("%d\n", answer[i]);
    }
}