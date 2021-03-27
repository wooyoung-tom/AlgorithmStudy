//
// Created by djdj7 on 2020-03-16.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string number;

    number = to_string(n);

    /* string 내부에서 char형태를 내림차순으로 정렬하는 알고리즘 메소드 */
    /* 알고리즘 적으로 한번 생각해 볼 필요가 있음 */
    sort(number.begin(), number.end(), greater<char>());

    answer = stoull(number);
    return answer;
}