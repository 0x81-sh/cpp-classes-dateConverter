#include "Date.h"

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "[" << date.year << "/" << date.month << "/" << date.day << "]";
    return os;
}

bool Date::compare(const Date &ref) const {
    return year == ref.year && month == ref.month && day == ref.day;
}

bool Date::operator==(const Date &ref) const {
    return compare(ref);
}
