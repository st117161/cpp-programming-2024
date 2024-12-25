#ifndef ARRAY_TEMPLATE_H
#define ARRAY_TEMPLATE_H

#include <cstddef>
#include <iostream>

template <class T, size_t size> class Array
{
    T array[size];

  public:
    Array()
    {
    }

    Array(T *b)
    {
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = b[i];
        }
    }

    void show()
    {
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    T minimum(Array<T, size> &m)
    {
        T minValue = array[0];
        for (size_t i = 1; i < size; ++i)
        {
            if (array[i] < minValue)
            {
                minValue = array[i];
            }
        }
        return minValue;
    }
};

#endif // ARRAY_TEMPLATE_H
