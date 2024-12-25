#ifndef COLUMN_H
#include <string>
#define COLUMN_H

#include "enums.h"
#include <string>

struct Column
{
    Column();
    ~Column();

    std::string Max() const;
    std::string Min() const;
    std::string Average() const;
    std::string StandardDeviation() const;

    TypeData type;
    std::string name;
    size_t size;
    void *value;
};

#endif // COLUMN_H
