#pragma once
#include "marathon.h"

// ”ниверсальна€ функци€ фильтрации
// result Ч массив указателей на отобранные записи
// criterion Ч указатель на функцию-критерий отбора
int filter(MarathonRecord* records, int count,
    MarathonRecord** result,
    bool (*criterion)(const MarathonRecord*));

//  ритерий 1: участник из клуба "—партак"
bool isSpartak(const MarathonRecord* r);

//  ритерий 2: врем€ забега лучше (меньше) 2:50:00
bool isFastEnough(const MarathonRecord* r);