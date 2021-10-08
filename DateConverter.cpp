#include "DateConverter.h"
#include <cmath>
#include <cstdio>

const char* lookupTable[3] = {"yyyy", "mm", "dd"};

int lengthOfNumber (int src) {
    return floor(log(src)) + 1;
}

int DateConverter::numberOfUsage = 0;

int DateConverter::getNumberOfUsage() {
    return numberOfUsage;
}

char *DateConverter::toString(Date date) {
    numberOfUsage++;

    int length = lengthOfNumber(date.getYear()) + 1 + lengthOfNumber(date.getMonth()) + 1 + lengthOfNumber(date.getDay()) + 1;
    char *str = new char[length];

    sprintf(str, "%d-%d-%d", date.getYear(), date.getMonth(), date.getDay());
    return str;
}

Date DateConverter::toDate(const char *dateString) {
    numberOfUsage++;
    return toDate("yyyy-mm-dd", dateString);
}

Date DateConverter::toDate(const char *formatString, const char *dateString) {
    numberOfUsage++;

    int data[3] = {4, 2, 2};
    for (int i = 0; i < 3; i++) {
        int index = findString(formatString, lookupTable[i]);
        int acc = 0;

        for (int j = 0; j < data[i]; j++) {
            int v = dateString[index + j];
            if (v >= 48 && v <= 57) {
                acc *= 10;
                acc += v - 48;
            }
        }

        data[i] = acc;
    }

    return {data[0], data[1], data[2]};
}

int DateConverter::findString(const char *formatString, const char *subFormat) {
    numberOfUsage++;

    int pre = 0;

    for (int i = 0; formatString[i] != '\0'; i++) {
        if (formatString[i] != subFormat[pre]) {
            pre = 0;
            continue;
        }

        pre++;
        if (subFormat[pre] == '\0') return i - pre + 1;
    }

    return -1;
}