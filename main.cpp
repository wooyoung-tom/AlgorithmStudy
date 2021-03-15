#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 보석 종류를 담을 map
unordered_map<string, int> gemMap;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    // 먼저 gems 벡터 순회하면서 map 에 보석 종류 갯수 세준다.
    for (auto & gem : gems) {
        gemMap[gem]++;
    }



    return answer;
}

int main() {
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    solution(gems);
}