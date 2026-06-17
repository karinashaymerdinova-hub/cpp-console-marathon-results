#include "filter.h"
#include <cstring>
using namespace std;

int filter(MarathonRecord* records, int count,
    MarathonRecord** result,
    bool (*criterion)(const MarathonRecord*)) {
    int n = 0;
    for (int i = 0; i < count; i++)
        if (criterion(&records[i]))
            result[n++] = &records[i];
    return n;
}

bool isSpartak(const MarathonRecord* r) {
    return strcmp(r->club, "Спартак") == 0;
}

bool isFastEnough(const MarathonRecord* r) {
    int t = getRaceTimeSec(r);
    int limit = 2 * 3600 + 50 * 60; // 2:50:00 = 10200 сек
    return t < limit;
}