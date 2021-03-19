#include <string>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

// 보석 종류를 담을 map
unordered_map<string, int> gemMap;
unordered_map<string, bool> isGemSelected;

int length = INT_MAX;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    // 현재 골라 놓은 총 보석 종류의 갯수
    int selectedGemCnt = 0;

    // 1. 맵 자료구조에서, ‘map[보석 이름] = 빈도수’로 정의를 합니다.
    for (auto &gem : gems) {
        gemMap[gem] = 0;
        isGemSelected[gem] = false;
    }

    // 2. 왼쪽 포인터 l과 오른쪽 포인터 r을 모두 1번 진열대에 위치시킵니다.
    int left = 0, right = 0;

    while (true) {
        // 3. 양 포인터 중, 둘 중 하나라도 진열대의 범위를 벗어나면 알고리즘을 종료합니다.
        if (left > gems.size() || right > gems.size()) break;

        // 4. 양 포인터가 가리키는 범위 안에 포함된 보석 종류의 개수를 세어 봅니다.(map의 사이즈를 체크합니다)
        if (selectedGemCnt == gemMap.size()) {
            // 5-1. 범위 안에 보석 종류가 전체 보석 종류와 일치하면 더 좋은 답인지 체크한 후 l를 증가시킵니다.
            // 그리고 2로 갑니다.
            if (right - left < length) {
                length = right - left;
            }

            // 길이 교체 이후에 left 를 하나 올려줘야 한다.
            // 그 이전에, 골라놨던 보석의 개수를 하나 줄여야 한다.
            gemMap[gems[left]]--;
            // 그리고 난 후, 보석 개수가 0개면, 골랐던 보석 개수에서 하나 줄여야 한다.
            if (gemMap[gems[left]] == 0) selectedGemCnt--;
            // 그리고 나서 left 를 하나 옮긴다.
            left++;
        } else {
            // 5-2. 범위 안에 보석 종류가 전체 보석 종류보다 작다면 r를 증가시킵니다.
            // 그리고 3으로 갑니다.
            right++;

            gemMap[gems[right]]++;
            // 그리고 현재 보석이 이미 골라져있는지 확인한다.
            // 안골라져 있으면 갯수 하나 올려준다.
            if (!isGemSelected[gems[right]]) {
                selectedGemCnt++;
                isGemSelected[gems[right]] = true;
            }
        }
    }

    answer.push_back(left);
    answer.push_back(right);

    return answer;
}

int main() {
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int> answer = solution(gems);

    for (int i = 0; i < answer.size(); ++i) {
        printf("%d\n", answer[i]);
    }
}