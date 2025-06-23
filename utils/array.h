#include <iostream>
#include <cstring>
#include <array>

namespace DG2D //chatgpt over engineering this shit could be 10 times simpler this is fucking garbage i fucking hate this fucking anyone whos reading this kill yourself you fucking nigger faggot 
{

    std::array<int, MAX_SIZE> ConvertCharArrayToIntArray(const char value[MAX_SIZE], size_t& outLength) {
        outLength = 0;
        while (outLength < MAX_SIZE && value[outLength] != '\0') {
            ++outLength;
        }

        std::array<int, MAX_SIZE> intArr{};
        for (size_t i = 0; i < outLength; ++i) {
            intArr[i] = static_cast<int>(value[i]);
        }
        return intArr;
    }


}