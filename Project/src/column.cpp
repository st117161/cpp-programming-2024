#include "column.h"

Column::Column() : value(nullptr), size(0), name(""), type(TypeData::typeNotDefined)
{
}

Column::~Column()
{
    value = nullptr;
    size = 0;
    name = "";
}

std::string Column::Max() const
{
    if (size == 0)
    {
        return "column is empty";
    }
    void *result = value;
    if (type == TypeData::typeInt)
    {
        static_cast<int *>(result);
    }
    else if (type == TypeData::typeDouble)
    {
        static_cast<double *>(result);
    }
    else if (type == TypeData::typeString)
    {
        static_cast<std::string *>(result);
    }
    else
    {
        return "type not allowed";
    }
    for (size_t i = 0; i < size; ++i)
    {
        if (type == TypeData::typeInt)
        {
            result = (*(int *)result < ((int *)value)[i] ? &((int *)value)[i] : result);
        }
        else if (type == TypeData::typeDouble)
        {
            result = (*(double *)result < ((double *)value)[i] ? &((double *)value)[i] : result);
        }
        else if (type == TypeData::typeString)
        {
            result = ((*(std::string *)result).size() < ((std::string *)value)[i].size() ? &((std::string *)value)[i]
                                                                                         : result);
        }
    }
    if (type == TypeData::typeInt)
    {
        return std::to_string(*(int *)result);
    }
    else if (type == TypeData::typeDouble)
    {
        return std::to_string(*(double *)result);
    }
    else if (type == TypeData::typeString)
    {
        return *(std::string *)result;
    }
    return "error";
}

std::string Column::Min() const
{
    if (size == 0)
    {
        return "column is empty";
    }
    void *result = value;
    if (type == TypeData::typeInt)
    {
        static_cast<int *>(result);
    }
    else if (type == TypeData::typeDouble)
    {
        static_cast<double *>(result);
    }
    else if (type == TypeData::typeString)
    {
        static_cast<std::string *>(result);
    }
    else
    {
        return "type not allowed";
    }
    for (size_t i = 0; i < size; ++i)
    {
        if (type == TypeData::typeInt)
        {
            result = (*(int *)result > ((int *)value)[i] ? &((int *)value)[i] : result);
        }
        else if (type == TypeData::typeDouble)
        {
            result = (*(double *)result > ((double *)value)[i] ? &((double *)value)[i] : result);
        }
        else if (type == TypeData::typeString)
        {
            result = ((*(std::string *)result).size() > ((std::string *)value)[i].size() ? &((std::string *)value)[i]
                                                                                         : result);
        }
    }
    if (type == TypeData::typeInt)
    {
        return std::to_string(*(int *)result);
    }
    else if (type == TypeData::typeDouble)
    {
        return std::to_string(*(double *)result);
    }
    else if (type == TypeData::typeString)
    {
        return *(std::string *)result;
    }
    return "error";
}

std::string Column::Average() const
{
    if (size == 0)
    {
        return "column is empty";
    }
    if (type != TypeData::typeInt && type != TypeData::typeDouble && type != TypeData::typeString)
    {
        return "type not allowed";
    }
    long double sum = 0.0l;
    for (size_t i = 0; i < size; ++i)
    {
        if (type == TypeData::typeInt)
        {
            sum += ((int *)value)[i];
        }
        else if (type == TypeData::typeDouble)
        {
            sum += ((double *)value)[i];
        }
        else if (type == TypeData::typeString)
        {
            sum += ((std::string *)value)[i].size();
        }
    }
    sum /= size;
    return std::to_string(sum);
}

std::string Column::StandardDeviation() const
{
    if (size == 0)
    {
        return "column is empty";
    }
    if (type != TypeData::typeInt && type != TypeData::typeDouble && type != TypeData::typeString)
    {
        return "type not allowed";
    }
    long double result = 0.0l;
    long double average = 0.0l;
    average = stold(Average());
    for (size_t i = 0; i < size; ++i)
    {
        if (type == TypeData::typeInt)
        {
            result += powl(((int *)value)[i] - average, 2);
        }
        else if (type == TypeData::typeDouble)
        {
            result += powl(((double *)value)[i] - average, 2);
        }
        else if (type == TypeData::typeString)
        {
            result += powl(((std::string *)value)[i].size() - average, 2);
        }
    }
    result /= (size - 1);
    result = sqrtl(result);
    return std::to_string(result);
}
