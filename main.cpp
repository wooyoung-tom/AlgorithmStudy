#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    int left = 0, right = distance;

    // 바위 위치를 오름차순으로 정렬
    sort(rocks.begin(), rocks.end());

    // 이분탐색을 진행
    while (left <= right) {
        int mid = (left + right) / 2;

        for (int i = 0; i < rocks.size(); ++i) {

        }
    }
    return answer;
}