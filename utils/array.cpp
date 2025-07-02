#include <iostream>
#include <cstring>
#include <array>
#include <limits>
#include "array.hpp"
#include <vector>

namespace DG2D
{

    std::vector<int> ConvertCharArrayToIntArray(const char* value) {
        std::vector<int> intVec;
        size_t i = 0;
        while (i < INT16_MAX && value[i] != '\0') {
            intVec.push_back(static_cast<unsigned char>(value[i]));
            ++i;
        }
        return intVec;
    }
}