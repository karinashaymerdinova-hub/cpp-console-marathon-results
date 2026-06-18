#include "processing.h"

int process(const MarathonRecord* records, int count) {
    if (count == 0) return -1;

    int minTime = getRaceTimeSec(&records[0]);

    for (int i = 1; i < count; i++) {
        int t = getRaceTimeSec(&records[i]);
        if (t < minTime) {
            minTime = t;
        }
    }

    return minTime;
}