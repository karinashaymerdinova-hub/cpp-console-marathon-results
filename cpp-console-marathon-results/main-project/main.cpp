#include <iostream>
#include "file_reader.h"
#include "filter.h"
#include "sort.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "=== Программа обработки результатов марафона ===" << endl;
    cout << "Вариант 1: Результаты марафона" << endl;
    cout << "Автор: Шаймердинова Карина" << endl;
    cout << "Группа: 25ИСиТ" << endl << endl;

    MarathonRecord records[MAX_RECORDS];
    MarathonRecord* result[MAX_RECORDS];
    int count = readData("data.txt", records);

    if (count == 0) {
        cout << "Ошибка: данные не загружены!" << endl;
        return 1;
    }
    cout << "Загружено записей: " << count << endl;
    int choice = -1;
    while (choice != 0) {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Показать всех участников" << endl;
        cout << "2. Фильтр: участники клуба \"Спартак\"" << endl;
        cout << "3. Фильтр: результат лучше 2:50:00" << endl;
        cout << "4. Сортировка" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n=== ВСЕ УЧАСТНИКИ ===" << endl;
            printHeader();
            for (int i = 0; i < count; i++) printRecord(&records[i]);
        }
        else if (choice == 2) {
            int n = filter(records, count, result, isSpartak);
            cout << "\n=== УЧАСТНИКИ КЛУБА СПАРТАК === Найдено: " << n << endl;
            printHeader();
            for (int i = 0; i < n; i++) printRecord(result[i]);
        }
        else if (choice == 3) {
            int n = filter(records, count, result, isFastEnough);
            cout << "\n=== РЕЗУЛЬТАТ ЛУЧШЕ 2:50:00 === Найдено: " << n << endl;
            printHeader();
            for (int i = 0; i < n; i++) printRecord(result[i]);
        }
        else if (choice == 4) {
            // Массив указателей для сортировки
            MarathonRecord* sorted[MAX_RECORDS];
            for (int i = 0; i < count; i++) sorted[i] = &records[i];
            SortFunc sortMethods[] = { bubbleSort, quickSort };
            cout << "\nМетод сортировки:" << endl;
            cout << "1. Пузырьком (Bubble sort)" << endl;
            cout << "2. Быстрая (Quick sort)" << endl;
            cout << "Выбор: ";
            int sm; cin >> sm;
            if (sm < 1 || sm > 2) { cout << "Неверный выбор." << endl; continue; }

            CompareFunc cmpFuncs[] = { compareByRaceTime, compareByClubAndName };
            cout << "Критерий сортировки:" << endl;
            cout << "1. По возрастанию времени забега" << endl;
            cout << "2. По клубу, внутри клуба — по фамилии" << endl;
            cout << "Выбор: ";
            int cm; cin >> cm;
            if (cm < 1 || cm > 2) { cout << "Неверный выбор." << endl; continue; }

            sortMethods[sm - 1](sorted, count, cmpFuncs[cm - 1]);

            cout << "\n=== РЕЗУЛЬТАТЫ СОРТИРОВКИ ===" << endl;
            printHeader();
            for (int i = 0; i < count; i++) printRecord(sorted[i]);
        }
    }
    return 0;
}
