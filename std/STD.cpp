#include <iostream>

#include <fstream>

#include <string>

#include <vector>

#include <cstdint>

#include <cstring>

#include "../enums.hpp"

#include "../addons/gzip/compress.hpp"

#include "../addons/gzip/decompress.hpp"

namespace DG2D {
  namespace SmartTableDatabase {
    static
    const char savefile_signature[4] = {
      'S',
      'T',
      'D',
      '\0'
    };
    static std::string filename = "untitled.std";

    bool preparefile() {
      std::fstream file(filename, std::ios::in | std::ios::binary);
      if (file.good()) {
        char sig[4];
        file.read(sig, 4);
        if (file.gcount() < 4 || std::memcmp(sig, savefile_signature, 4) != 0) {
          file.close();
          std::ofstream wipe(filename, std::ios::binary | std::ios::trunc);
          wipe.write(savefile_signature, 4);
          wipe.close();
        }
      } else {
        std::ofstream newfile(filename, std::ios::binary);
        newfile.write(savefile_signature, 4);
        newfile.close();
      }
      return true;
    }

    void writeSpecialSaveFileSymbols(std::ofstream & file, SpecialSaveFileSymbols m) {
      signed char mc = static_cast < signed char > (m);
      file.write(reinterpret_cast <
        const char * > ( & mc), sizeof(mc));
    }

    void writestring(std::ofstream & file,
      const std::string & str) {
      file.write(str.data(), str.size());
    }

    bool SetValue(std::string Key, std::string Value) {
      preparefile();

      std::ifstream infile(filename, std::ios::binary);
      if (!infile.is_open())
        return false;

      std::vector < char > oldData((std::istreambuf_iterator < char > (infile)),
        std::istreambuf_iterator < char > ());
      infile.close();

      std::vector < char > newData;
      newData.insert(newData.end(), oldData.begin(), oldData.begin() + 4);

      std::string buffer;
      size_t i = 4;
      bool replaced = false;

      while (i < oldData.size()) {
        char c = oldData[i++];
        if (c < 0) {
          SpecialSaveFileSymbols m = static_cast < SpecialSaveFileSymbols > (c);
          if (m == SpecialSaveFileSymbols::Newline) {
            buffer.clear();
            newData.push_back(c);
          } else if (m == SpecialSaveFileSymbols::Separator) {
            if (buffer == Key && !replaced) {

              uint32_t oldSize = * reinterpret_cast < uint32_t * > ( & oldData[i]);
              i += sizeof(uint32_t) + oldSize;

              writeSpecialSaveFileSymbols( * reinterpret_cast < std::ofstream * > ( & newData), SpecialSaveFileSymbols::Separator);
              std::string compressed = gzip::compress(Value.data(), Value.size());
              uint32_t newSize = static_cast < uint32_t > (compressed.size());

              newData.insert(newData.end(),
                reinterpret_cast < char * > ( & newSize),
                reinterpret_cast < char * > ( & newSize) + sizeof(newSize));
              newData.insert(newData.end(), compressed.begin(), compressed.end());

              replaced = true;
              buffer.clear();
              continue;
            } else {
              newData.push_back(c);

              uint32_t oldSize = * reinterpret_cast < uint32_t * > ( & oldData[i]);
              newData.insert(newData.end(), &
                oldData[i], &
                oldData[i + sizeof(uint32_t) + oldSize]);
              i += sizeof(uint32_t) + oldSize;
              buffer.clear();
            }
          } else if (m == SpecialSaveFileSymbols::EndOfFile) {
            newData.push_back(c);
            break;
          }
        } else {
          buffer.push_back(c);
          newData.push_back(c);
        }
      }

      if (!replaced) {
        std::ofstream outfile(filename, std::ios::binary | std::ios::app);
        writeSpecialSaveFileSymbols(outfile, SpecialSaveFileSymbols::Newline);
        writestring(outfile, Key);
        writeSpecialSaveFileSymbols(outfile, SpecialSaveFileSymbols::Separator);
        std::string compressed = gzip::compress(Value.data(), Value.size());
        uint32_t size = static_cast < uint32_t > (compressed.size());
        outfile.write(reinterpret_cast < char * > ( & size), sizeof(size));
        outfile.write(compressed.data(), compressed.size());
        outfile.close();
        return true;
      }

      std::ofstream outfile(filename, std::ios::binary | std::ios::trunc);
      outfile.write( & newData[0], newData.size());
      outfile.close();

      return true;
    }

    std::string LoadValue(std::string Key) {
      preparefile();
      std::ifstream file(filename, std::ios::binary);
      file.seekg(4); // skip signature

      std::string buffer;
      char c;

      while (file.get(c)) {
        if (c < 0) {
          SpecialSaveFileSymbols m = static_cast < SpecialSaveFileSymbols > (c);
          if (m == SpecialSaveFileSymbols::Newline) {
            buffer.clear();
          } else if (m == SpecialSaveFileSymbols::Separator) {
            if (buffer == Key) {
              uint32_t size = 0;
              file.read(reinterpret_cast < char * > ( & size), sizeof(size));

              std::string compressed(size, '\0');
              file.read( & compressed[0], size);

              std::string value = gzip::decompress(compressed.data(), compressed.size());
              return value;
            }
            buffer.clear();
          } else if (m == SpecialSaveFileSymbols::EndOfFile)
            break;
        } else {
          buffer.push_back(c);
        }
      }
      return nullptr;
    }

    bool HasKey(std::string Key) {
      return !LoadValue(Key).empty();
    }
  }
}