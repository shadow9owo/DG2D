#include <iostream>
#include <cstring>
#include <array>
#include <limits>

namespace DG2D //chatgpt over engineering this shit could be 10 times simpler this is fucking garbage i fucking hate this fucking anyone whos reading this kill yourself you fucking nigger faggot 
{

    std::array<int, INT16_MAX> ConvertCharArrayToIntArray(const char value[INT16_MAX], size_t& outLength) {
        outLength = 0;
        while (outLength < INT16_MAX && value[outLength] != '\0') {
            ++outLength;
        }

        std::array<int, INT16_MAX> intArr{};
        for (size_t i = 0; i < outLength; ++i) {
            intArr[i] = static_cast<int>(value[i]);
        }
        return intArr;
    }


}