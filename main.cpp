#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>

using namespace std;

int solution(vector<string> strs, string t) {
    int answer = 0;

    int dp[t.length()];

    // string t 의 뒤에서 부터 하나씩 늘려가면서 진행한다.
    for (int i = t.length() - 1; i >= 0; i--) {
        // 하나씩 늘려준 string 저장할 변수
        string tmp = "";

    }

    return answer;
}

int main() {
    vector<string> strs = {"ba","na","n","a"};
    string t = "banana";

    solution(strs, t);
}