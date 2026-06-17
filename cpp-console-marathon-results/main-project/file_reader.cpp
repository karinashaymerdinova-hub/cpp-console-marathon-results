#include "file_reader.h"
#include <fstream>
#include <cstring>
using namespace std;

static Time parseTime(const char* s) {
    Time t = { 0, 0, 0 };
    int i = 0;
    // часы
    while (s[i] >= '0' && s[i] <= '9') { t.hours = t.hours * 10 + (s[i] - '0'); i++; }
    if (s[i] == ':') i++;
    // минуты
    while (s[i] >= '0' && s[i] <= '9') { t.minutes = t.minutes * 10 + (s[i] - '0'); i++; }
    if (s[i] == ':') i++;
    // секунды
    while (s[i] >= '0' && s[i] <= '9') { t.seconds = t.seconds * 10 + (s[i] - '0'); i++; }
    return t;
}

int readData(const char* filename, MarathonRecord records[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ќшибка: не удалось открыть файл " << filename << endl;
        return 0;
    }
    int count = 0;
    while (count < MAX_RECORDS) {
        MarathonRecord& r = records[count];
        char startBuf[20], finishBuf[20];
        // „итаем пол€ через >> (без scanf)
        if (!(file >> r.number
            >> r.lastName
            >> r.firstName
            >> r.middleName
            >> startBuf
            >> finishBuf)) break;
        r.start = parseTime(startBuf);
        r.finish = parseTime(finishBuf);
        //  луб Ч остаток строки (может содержать пробелы)
        file.ignore();
        file.getline(r.club, MAX_LINE_LENGTH);
        count++;
    }
    file.close();
    return count;
}
