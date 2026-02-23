#include <iostream>
#include <cstring>  
#include <string>   

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char str1[50] = "Привет";
    char str2[50] = "Мир";
    char result[100]; 

    int len1 = strlen(str1);
    cout << "Длина строки = " << len1 << endl;

    strcpy(result, str1);
    cout << "Копия строки =  " << result << endl;


    strcat(result, " ");
    strcat(result, str2);
    cout << "Добавили в конец " << result << endl;

    string s1 = "programming";
    string s2 = " on CPP";
    string s3;

    int lenS1 = s1.length();
    cout << "Длина строки = " << lenS1 << endl;

    s1.append(s2);
    cout << "Добавили в конец = " << s1 << endl;

    s3 = s1.substr(0, 11);
    cout << "Первые 11 символов =  " << s3 << endl;

    return 0;
}