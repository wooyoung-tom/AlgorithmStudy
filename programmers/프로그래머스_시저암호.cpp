//
// Created by djdj7 on 2020-03-15.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] != ' ') {
            /* 대문자 범위내에 있지 않으면 시작 문자가 a가 되도록 함. */
            char start = ('A' <= s[i] && s[i] <= 'Z')? 'A' : 'a';
            /* s[i]를 start로 부터 0~25 하도록 함. */
            s[i] = start + (s[i] + n - start) % 26;
        }
    }

    answer = s;
    return answer;
}