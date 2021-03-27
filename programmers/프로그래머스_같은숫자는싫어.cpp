//
// Created by djdj7 on 2020-03-13.
//

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int index = 0;
    int temp = arr[0];

    while(index != arr.size()) {
        if(temp == arr[index + 1]) {
            index++;
        } else {
            answer.push_back(temp);
            temp = arr[index + 1];
            index++;
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}