//
// Created by 최우영 on 2021/02/19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str, tmp;
    vector<string> strContainer;

    getline(cin, str);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (i == 0 && str[i] == ' ') {
            // 첫 번째 자리이면서 공백일 때
            continue;
        } else if (str[i] != ' ') {
            if (i == str.length() - 1) {
                // 공백이 아닌데 문자열 끝자리라면
                strContainer.push_back(tmp);
                tmp = "";
            } else {
                // 공백이 아니면
                tmp += str[i];
            }
        } else if (str[i] == ' ') {
            strContainer.push_back(tmp);
            tmp = "";
        }
    }

    cout << strContainer.size();
}