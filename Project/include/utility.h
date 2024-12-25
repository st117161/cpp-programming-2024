#ifndef UTILITY_H
#define UTILITY_H

#include "enums.h"
#include <string>

TypeFile TypeOfFile(const std::string FilePath)
{
    std::string str = "";
    for (size_t i = FilePath.size() - 1; i != 0; --i)
    {
        if (FilePath[i] == '.')
        {
            break;
        }
        str = FilePath[i] + str;
    }
    if (str == "txt")
    {
        return TypeFile::typeTxt;
    }
    if (str == "csv")
    {
        return TypeFile::typeCsv;
    }
    return TypeFile::typeNotDefined;
}

size_t CountOfColumns(char delimiter, std::string line)
{
    size_t sum = 1;
    for (std::string::iterator it = line.begin(); it != line.end(); ++it)
    {
        if (*it == delimiter)
        {
            ++sum;
        }
    }
    return sum;
}

TypeData TypeOfVariable(std::string str)
{
    for (char i : str)
    {
        if (i == '.')
        {
            return TypeData::typeDouble;
        }
        if (!(i >= '0' && i <= '9'))
        {
            return TypeData::typeString;
        }
    }
    return TypeData::typeInt;
}

char DelimiterSymbol(TypeFile typef)
{
    if (typef == TypeFile::typeCsv)
    {
        return ',';
    }
    if (typef == TypeFile::typeTxt)
    {
        return ' ';
    }
    return ' ';
}

#endif // UTILITY_H
