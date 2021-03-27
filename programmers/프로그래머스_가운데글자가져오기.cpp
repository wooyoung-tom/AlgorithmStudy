//
// Created by djdj7 on 2020-03-12.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    if(s.size() % 2 == 0) {
        /* TODO substr에서 두번째 Parameter는 첫번째 Parameter에서부터 몇번째 뒤까지 자를것인지 */
        answer = s.substr(s.size() / 2 - 1, 2);
    } else {
        answer = s[s.size() / 2];
    }
    return answer;
}