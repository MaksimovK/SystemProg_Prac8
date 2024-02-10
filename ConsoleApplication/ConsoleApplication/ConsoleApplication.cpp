#include <iostream>
#include <algorithm>
#define MAX_PEOPLE 100
using namespace std;

struct Man {
    bool isMilitary;
    char address[100];
};

struct Woman {
    int childrenCount;
};

union Info {
    Man manInfo;
    Woman womanInfo;
};

struct Person {
    char name[100];
    wchar_t gender;
    Info info;
};

bool CompareWomen(const Person& a, const Person& b) {
    return a.info.womanInfo.childrenCount > b.info.womanInfo.childrenCount;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Person people[MAX_PEOPLE];
    people[0] = { "Иванова Мария Кирилловна", L'ж' };
    people[0].info.womanInfo = { 3 };
    people[1] = { "Петров Иван Петрович", L'м' };
    people[1].info.manInfo = { true, "ул. Ленина, 1" };
    people[2] = { "Сидорова Елена Романовна", L'ж' };
    people[2].info.womanInfo = { 1 };
    people[3] = { "Кузнецов Алексей Дмитриевич", L'м' };
    people[3].info.manInfo = { false, "пр. Мира, 2" };
    people[4] = { "Васильева Ольга Алексеевич", L'ж' };
    people[4].info.womanInfo = { 2 };

    Person women[MAX_PEOPLE];

    int womenCount = 0;
    for (int i = 0; i < MAX_PEOPLE; ++i) {
        if (people[i].gender == L'ж') {
            women[womenCount++] = people[i];
        }
    }

    sort(women, women + womenCount, CompareWomen);

    for (int i = 0; i < womenCount; ++i) {
        cout << women[i].name << " " << women[i].info.womanInfo.childrenCount << endl;
    }

    return 0;
}
