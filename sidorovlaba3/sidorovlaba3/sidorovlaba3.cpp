// sidorovlaba3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <regex>
#include <string>
#include<fstream>
#include <Windows.h>
using namespace std;

void generatetext() {
    int n;
    srand(time(0));
    const string emails[5] = { "amar@yet.com", "test@mail.su", "whoishere26@sus.this", "professor_54@stankin.ru", "github@test.sss"};
    cout << "Input number of elements\n";
    cin >> n;
    int counter = 0;
    string text = "";
    char temp;
    for (int i = 0; i < n * 100; i++) {
        temp = 'a' + rand() % 30;
        text.push_back(temp);
        if (i % 50 == 0) {
            text.push_back('\n');
        }
        if (i % 200 == 0) {
            text.push_back('\n');
            text.append(emails[counter]);
            text.push_back('\n');
            counter++;
            if (counter == 5) {
                counter = 0;
            }
        }
    }
    fstream file;
    file.open("test.txt");
    file << text;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    const regex re("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    smatch found;
    string line;
    fstream file;
    bool check;
    cout << "Print 1 if u need to create new random file\n0 if u dont\n";
    cin >> check;
    if (bool(check)) {
        generatetext();
    }
    else {
        file.open("test.txt", ios::in);
        while (getline(file, line)) {
;            if (regex_search(line, found, re)) {
                cout << line.substr(found.position(), found.position() + found.length()) << "\n";
            }
        }
    }
}

