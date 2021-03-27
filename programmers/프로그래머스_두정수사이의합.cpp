//
// Created by djdj7 on 2020-03-13.
//

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if(a <= b) {
        for(int i = a ; i <= b ; i++){
            answer += i;
        }
    } else {
        for(int i = b ; i <= a ; i++) {
            answer += i;
        }
    }
    return answer;
}