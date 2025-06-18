#include "median.hpp"

int median(const int a, const int b, const int c) {
    if (a < b) {
        if (b < c) return b;
        else if (a < c) return c;
        else return a;
    } else {
        if (a < c) return a;
        else if (b < c) return c;
        else return b;
    }
}
