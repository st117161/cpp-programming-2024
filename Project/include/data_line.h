#ifndef DATA_LINE_H
#define DATA_LINE_H

#include <iostream>
#include <sstream>
#include <string>

struct DataLine
{
    DataLine();
    DataLine(std::string data);
    DataLine(std::string data, char delimiter, size_t size);

    std::string operator[](size_t index) const;
    friend std::ostream &operator<<(std::ostream &stream, const DataLine &data_line)
    {
        stream << data_line.data;
        return stream;
    }

    std::string data;
    char delimiter;
    size_t size;
};

#endif // DATA_LINE_H
