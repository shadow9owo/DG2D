#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>
#include <climits>
/*
    NOTES: 
        UNSIGNED CHAR - 0 - 255 (basically a byte)

    Design ;;; NAME || VALUE
*/

namespace SmartTDB
{
    extern bool Declared;
    extern std::string FILENAME;
    extern bool DeclareDBname(std::string filename);

    namespace UTILS
    {
        namespace Bytes
        {
            extern std::vector<uint8_t> IntToBytes(uint32_t value);
            extern uint32_t BytesToInt(const std::vector<uint8_t>& bytes);
        }
        extern bool DoesNameExist(std::string Name);
        extern void ReplaceValue(std::string Name, int value,size_t count = 1);
        extern std::vector<int> LoadValue(std::string Name);
    }
}

