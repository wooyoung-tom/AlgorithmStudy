//
// Created by djdj7 on 2020-03-16.
//

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string number;

    number = to_string(n);

    for(int i = 0 ; i < number.size() ; i++) {
        answer += (number[i] - '0');
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}