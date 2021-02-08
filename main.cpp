/**
 * scoville [1, 2, 3, 9, 10, 12]
 * K        7
 * return   2
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    // 일단 오름차순으로 정렬
    sort(scoville.begin(), scoville.end());


    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;

    solution(scoville, K);
}