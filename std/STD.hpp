#include <string>

namespace DG2D
{
    namespace SmartTableDatabase
    {
        extern std::string filename;
    
        extern bool SetValue(std::string Key,std::string Value);
        extern bool LoadValue(std::string Key);
        extern bool HasKey(std::string Key);
    }
}