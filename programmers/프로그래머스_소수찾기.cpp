//
// Created by djdj7 on 2020-03-15.
//

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> numbers(n+1, 0);

    for(int i = 2 ; i <= n ; i++) {
        numbers[i] = i;
    }

    /* 2부터 시작해서 그 배수들 0으로 만든다. */
    /* 이후에는 0이면 continue한 뒤, 그 배수들을 다시 0으로 만듬 */
    for(int i = 2 ; i <= n ; i++) {
        if(numbers[i] == 0) continue;
        for(int j = 2 * i ; j <= n ; j += i) {
            numbers[j] = 0;
        }
    }

    for(int i = 0 ; i < numbers.size() ; i++) {
        if(numbers[i] != 0) {
            answer++;
        }
    }
    return answer;
}