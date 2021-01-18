#include <iostream>
#include <vector>

using namespace std;

vector<int> memo[10];

bool isContains(const vector<int>& targetVector, int number) {
    for (int i = 0; i < targetVector.size(); ++i) {
        if (targetVector[i] == number) return true;
    }
    return false;
}

int solution(int N, int number) {
    int answer = 0;

    // N을 8번까지 사용할 수 있다.
    while (answer < 8) {
        // 해당 number 에 답이 있다면 break
        if (isContains(memo[answer], number)) break;
        answer++;

        vector<int> tmp;


    }

    return answer;
}

int main() {

}