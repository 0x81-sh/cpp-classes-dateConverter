#include <iostream>
#include "DateConverter.h"
#include <cstring>
#include <cassert>

void test_toString(const Date &ref, const char* target);
void test_toDate_standard(const char *src, const Date &target);
void test_toDate_extension(const char *src, const char *filterStr, const Date &target);

int main() {
    test_toString(Date(1984, 6, 3), "1984-6-3");
    test_toDate_standard("1684-05-01", Date(1684, 5, 1));
    test_toDate_extension("1234###06___13", "yyyy###mm___dd", Date(1234, 6, 13));

    return 0;
}

void test_toString(const Date &ref, const char* target) {
    char *ptr = DateConverter::toString(ref);
    assert(strcmp(ptr, target) == 0);

    delete[] ptr;
}

void test_toDate_standard(const char *src, const Date &target) {
    assert(target == DateConverter::toDate(src));
}

void test_toDate_extension(const char *src, const char *filterStr, const Date &target) {
    assert(target == DateConverter::toDate(filterStr, src));
}
