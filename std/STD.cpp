#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include "../enums.hpp"

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
            signed char mc = static_cast<signed char>(m); // C++11 safe
            file.write(reinterpret_cast<const char*>(&mc), sizeof(mc));
        }

        void writestring(std::ofstream& file, const std::string& str)
        {
            file.write(str.data(), str.size());
        }

        bool SetValue(std::string Key, std::string Value)
        {
            preparefile();
            std::ofstream file(filename, std::ios::binary | std::ios::app);

            writeSpecialSaveFileSymbols(file, SpecialSaveFileSymbols::Newline);
            writestring(file, Key);
            writeSpecialSaveFileSymbols(file, SpecialSaveFileSymbols::Separator);
            writestring(file, Value);

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
                            std::string value;
                            char v;
                            while (file.get(v))
                            {
                                if (v < 0)
                                {
                                    SpecialSaveFileSymbols mv = static_cast<SpecialSaveFileSymbols>(v);
                                    if (mv == SpecialSaveFileSymbols::Newline ||
                                        mv == SpecialSaveFileSymbols::EndOfFile)
                                    {
                                        return value;
                                    }
                                }
                                value.push_back(v);
                            }
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
            return "";
        }

        bool HasKey(std::string Key)
        {
            return !LoadValue(Key).empty();
        }
    }
}
