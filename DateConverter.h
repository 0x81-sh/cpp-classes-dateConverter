#pragma once
#include "Date.h"

class DateConverter {
    private:
        static int numberOfUsage;
        DateConverter();
        static int findString(const char *formatString, const char *subFormat);
    public:
        static int getNumberOfUsage();
        static char* toString(Date date);
        static Date toDate(const char* dateString);
        static Date toDate(const char *formatString, const char *dateString);
};



