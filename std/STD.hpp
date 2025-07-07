
#include <string>
#include <vector>
#include <cstdint>

namespace DG2D
{
    namespace SmartTDB
    {
        extern bool Declared;
        extern std::string FILENAME;
    
        extern bool DeclareDBname(std::string filename);
    
        extern int GetIntValue(std::string Name);
        extern unsigned char GetByteValue(std::string Name);
        extern short GetShortValue(std::string Name);
    
        extern void SetIntValue(std::string Name, const int *value);
        extern void SetByteValue(std::string Name, const unsigned char *value);
        extern void SetShortValue(std::string Name, const short *value);
    
        extern std::vector<unsigned char> GetRawBytes();
        extern bool SetRawBytes(std::vector<unsigned char> input);
    
        namespace UTILS
        {
            namespace Bytes
            {
                extern std::vector<uint8_t> IntToBytes(uint32_t value);
                extern uint32_t BytesToInt(const std::vector<uint8_t>& bytes);
            }
        
            extern bool DoesNameExist(std::string Name);
            extern void ReplaceValue(std::string Name, const int* values, size_t count);
            extern std::vector<int> LoadValue(std::string Name);
        }
    }
}