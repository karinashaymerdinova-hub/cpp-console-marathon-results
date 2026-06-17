#include <iostream>
#include "file_reader.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "=== Программа обработки результатов марафона ===" << endl;
    cout << "Вариант 1: Результаты марафона" << endl;
    cout << "Автор: Шаймердинова Карина" << endl;
    cout << "Группа: 25ИСиТ" << endl << endl;

    MarathonRecord records[MAX_RECORDS];
    int count = readData("data.txt", records);

    if (count == 0) {
        cout << "Ошибка: данные не загружены!" << endl;
        return 1;
    }
    cout << "Загружено записей: " << count << endl << endl;
    printHeader();
    for (int i = 0; i < count; i++)
        printRecord(&records[i]);
    return 0;
}