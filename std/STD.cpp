#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include "../enums.hpp"
#include "../addons/gzip/compress.hpp"
#include "../addons/gzip/decompress.hpp"

namespace DG2D
{
    namespace SmartTableDatabase
    {
        static const char savefile_signature[4] = { 'S','T','D','\0' };
        static std::string filename = "untitled.std";

        bool preparefile()
        {
            std::fstream file(filename, std::ios::in | std::ios::binary);
            if (file.good())
            {
                char sig[4];
                file.read(sig, 4);
                if (file.gcount() < 4 || std::memcmp(sig, savefile_signature, 4) != 0)
                {
                    file.close();
                    std::ofstream wipe(filename, std::ios::binary | std::ios::trunc);
                    wipe.write(savefile_signature, 4);
                    wipe.close();
                }
            }
            else
            {
                std::ofstream newfile(filename, std::ios::binary);
                newfile.write(savefile_signature, 4);
                newfile.close();
            }
            return true;
        }

        void writeSpecialSaveFileSymbols(std::ofstream& file, SpecialSaveFileSymbols m)
        {
            signed char mc = static_cast<signed char>(m);
            file.write(reinterpret_cast<const char*>(&mc), sizeof(mc));
        }

        void writestring(std::ofstream& file, const std::string& str)
        {
            file.write(str.data(), str.size());
        }

        bool SetValue(std::string Key, std::string Value)
{
    preparefile();

    // Step 1: Check if key already exists
    bool keyExists = HasKey(Key);

    // Open file in append mode
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    if (!file.is_open())
        return false;

    // Optional: mark old entry as deleted
    // Currently we just append new value (LoadValue can be updated to pick the last occurrence)

    writeSpecialSaveFileSymbols(file, SpecialSaveFileSymbols::Newline);
    writestring(file, Key);
    writeSpecialSaveFileSymbols(file, SpecialSaveFileSymbols::Separator);

    std::string compressed = gzip::compress(Value.data(), Value.size());

    uint32_t size = static_cast<uint32_t>(compressed.size());
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    file.write(compressed.data(), compressed.size());

    file.close();
    return true;
}

        std::string LoadValue(std::string Key)
        {
            preparefile();
            std::ifstream file(filename, std::ios::binary);
            file.seekg(4); // skip signature

            std::string buffer;
            char c;

            while (file.get(c))
            {
                if (c < 0)
                {
                    SpecialSaveFileSymbols m = static_cast<SpecialSaveFileSymbols>(c);
                    if (m == SpecialSaveFileSymbols::Newline)
                    {
                        buffer.clear();
                    }
                    else if (m == SpecialSaveFileSymbols::Separator)
                    {
                        if (buffer == Key)
                        {
                            uint32_t size = 0;
                            file.read(reinterpret_cast<char*>(&size), sizeof(size));

                            std::string compressed(size, '\0');
                            file.read(&compressed[0], size);

                            std::string value = gzip::decompress(compressed.data(), compressed.size());
                            return value;
                        }
                        buffer.clear();
                    }
                    else if (m == SpecialSaveFileSymbols::EndOfFile)
                        break;
                }
                else
                {
                    buffer.push_back(c);
                }
            }
            return nullptr;
        }

        bool HasKey(std::string Key)
        {
            return !LoadValue(Key).empty();
        }
    }
}
