//
// Created by djdj7 on 2020-03-15.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;

    for(int i = 0 ; i < s.size() ; i++) {
        char a = s[i];
        if(s[i] == ' ') {
            index = 0;
        } else{
            if(index % 2 == 0){
                s[i] = toupper(s[i]);
                index++;
            } else {
                s[i] = tolower(s[i]);
                index++;
            }
        }
    }

    answer = s;
    return answer;
}