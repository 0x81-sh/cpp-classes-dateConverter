#pragma once

#include <ostream>

class Date {
    private:
        int year;
        int month;
        int day;
    public:
        Date(int year, int month, int day);

        [[nodiscard]] int getYear() const;
        [[nodiscard]] int getMonth() const;
        [[nodiscard]] int getDay() const;

        bool compare(const Date &ref) const;
        bool operator==(const Date &ref) const;
        friend std::ostream &operator<<(std::ostream &os, const Date &date);
};



