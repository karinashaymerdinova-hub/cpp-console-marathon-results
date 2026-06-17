#pragma once
#include "marathon.h"

typedef int (*CompareFunc)(const MarathonRecord*, const MarathonRecord*);
typedef void (*SortFunc)(MarathonRecord**, int, CompareFunc);

// ћетоды сортировки
void bubbleSort(MarathonRecord** arr, int n, CompareFunc cmp);
void quickSort(MarathonRecord** arr, int n, CompareFunc cmp);

//  ритерии сравнени€
// 1. ѕо возрастанию времени забега (финиш - старт)
int compareByRaceTime(const MarathonRecord* a, const MarathonRecord* b);
// 2. ѕо возрастанию названи€ клуба, внутри клуба Ч по возрастанию фамилии
int compareByClubAndName(const MarathonRecord* a, const MarathonRecord* b);