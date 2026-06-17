#pragma once
#include "constants.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct MarathonRecord {
    int number;
    char lastName[MAX_STR];
    char firstName[MAX_STR];
    char middleName[MAX_STR];
    Time start;
    Time finish;
    char club[MAX_LINE_LENGTH];
};

// Время забега в секундах
int getRaceTimeSec(const MarathonRecord* r) {
    int s = r->start.hours * 3600 + r->start.minutes * 60 + r->start.seconds;
    int f = r->finish.hours * 3600 + r->finish.minutes * 60 + r->finish.seconds;
    return f - s;
}

void printHeader() {
    cout << left
        << setw(4) << "№"
        << setw(14) << "Фамилия"
        << setw(10) << "Имя"
        << setw(14) << "Отчество"
        << setw(10) << "Старт"
        << setw(10) << "Финиш"
        << setw(10) << "Время"
        << "Клуб" << endl;
    for (int i = 0; i < 80; i++) cout << "-";
    cout << endl;
}

void printRecord(const MarathonRecord* r) {
    int t = getRaceTimeSec(r);
    char timeStr[20], startStr[20], finishStr[20];
    // Форматируем время через строки (без printf/scanf из консоли)
    // старт
    startStr[0] = '0' + r->start.hours / 10;
    startStr[1] = '0' + r->start.hours % 10;
    startStr[2] = ':';
    startStr[3] = '0' + r->start.minutes / 10;
    startStr[4] = '0' + r->start.minutes % 10;
    startStr[5] = ':';
    startStr[6] = '0' + r->start.seconds / 10;
    startStr[7] = '0' + r->start.seconds % 10;
    startStr[8] = '\0';
    // финиш
    finishStr[0] = '0' + r->finish.hours / 10;
    finishStr[1] = '0' + r->finish.hours % 10;
    finishStr[2] = ':';
    finishStr[3] = '0' + r->finish.minutes / 10;
    finishStr[4] = '0' + r->finish.minutes % 10;
    finishStr[5] = ':';
    finishStr[6] = '0' + r->finish.seconds / 10;
    finishStr[7] = '0' + r->finish.seconds % 10;
    finishStr[8] = '\0';
    // время забега
    int th = t / 3600, tm = (t % 3600) / 60, ts = t % 60;
    timeStr[0] = '0' + th / 10; timeStr[1] = '0' + th % 10; timeStr[2] = ':';
    timeStr[3] = '0' + tm / 10; timeStr[4] = '0' + tm % 10; timeStr[5] = ':';
    timeStr[6] = '0' + ts / 10; timeStr[7] = '0' + ts % 10; timeStr[8] = '\0';

    cout << left
        << setw(4) << r->number
        << setw(14) << r->lastName
        << setw(10) << r->firstName
        << setw(14) << r->middleName
        << setw(10) << startStr
        << setw(10) << finishStr
        << setw(10) << timeStr
        << r->club << endl;
}