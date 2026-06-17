#include "sort.h"
#include <cstring>
using namespace std;

void bubbleSort(MarathonRecord** arr, int n, CompareFunc cmp) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (cmp(arr[j], arr[j + 1]) > 0) {
                MarathonRecord* tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

static void qsHelper(MarathonRecord** arr, int lo, int hi, CompareFunc cmp) {
    if (lo >= hi) return;
    MarathonRecord* pivot = arr[(lo + hi) / 2];
    int i = lo, j = hi;
    while (i <= j) {
        while (cmp(arr[i], pivot) < 0) i++;
        while (cmp(arr[j], pivot) > 0) j--;
        if (i <= j) {
            MarathonRecord* tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
            i++; j--;
        }
    }
    qsHelper(arr, lo, j, cmp);
    qsHelper(arr, i, hi, cmp);
}

void quickSort(MarathonRecord** arr, int n, CompareFunc cmp) {
    if (n > 1) qsHelper(arr, 0, n - 1, cmp);
}

int compareByRaceTime(const MarathonRecord* a, const MarathonRecord* b) {
    return getRaceTimeSec(a) - getRaceTimeSec(b);
}

int compareByClubAndName(const MarathonRecord* a, const MarathonRecord* b) {
    int c = strcmp(a->club, b->club);
    if (c != 0) return c;
    return strcmp(a->lastName, b->lastName);
}