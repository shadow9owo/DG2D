#include "STD.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>
#include <climits>
#include "../utils/array.h"

namespace SmartTDB
{
    extern std::string GetString(std::string Name);
    extern bool SetString(std::string Name,short value);

    std::string GetString(std::string Name)
    {
        std::vector<char> a;
        if (!a.empty()) {a.clear();}
        if (!SmartTDB::Declared) { return ""; }
        if (!SmartTDB::UTILS::DoesNameExist(Name)) { return ""; }
        if (!SmartTDB::UTILS::LoadValue(Name).empty())
        {
            for (unsigned char b : SmartTDB::UTILS::LoadValue(Name))
            {
                a.push_back((char)b);
            }
        }
        std::string c(a.begin(), a.end());
        return c;
    }

    bool SetString(std::string Name, char value[UINT8_MAX]) {
        if (!SmartTDB::Declared) return false;
        if (!SmartTDB::UTILS::DoesNameExist(Name)) return false;

        size_t length = 0;
        std::array<int, INT16_MAX> intArray = DG2D::ConvertCharArrayToIntArray(value, length);

        SmartTDB::UTILS::ReplaceValue(Name, intArray.data(), length);

        return true;
    }
}