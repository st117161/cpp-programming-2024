#include "data_line.h"

DataLine::DataLine() : data(""), delimiter(' '), size(0)
{
}

DataLine::DataLine(std::string data) : data(data), delimiter(' '), size(0)
{
}

DataLine::DataLine(std::string line, char delimiter, size_t size) : delimiter(delimiter), size(size)
{
    if (line.at(0) == delimiter)
    {
        line.erase(line.begin());
    }
    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
    data = line;
}

std::string DataLine::operator[](size_t index) const
{
    if (index >= size || index >= data.size())
    {
        return "index out of range";
    }
    std::string output;
    std::stringstream ss(data);
    while (index != -1)
    {
        getline(ss, output, delimiter);
        --index;
    }
    return output;
}
