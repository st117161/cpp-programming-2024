#ifndef DATASET_H
#define DATASET_H

#include "column.h"
#include "data_line.h"
#include "enums.h"

#include <string>

class Dataset
{
  public:
    Dataset() : data_(nullptr), size_(0), delimiter_for_print_('\t')
    {
    }
    Dataset(std::string FilePath, bool IndexColumnExistsInFile, DataLine = DataLine());
    ~Dataset();

    void PrintData() const;
    size_t GetColumnCount() const;
    size_t GetRowCount(size_t index) const;
    TypeData GetColumnType(size_t index) const;
    std::string GetColumnName(size_t index) const;

    void Remove(size_t index);
    void Insert(size_t index, DataLine data_line);
    void ChangeDelimiterForPrint(char delimiter);
    void Head(size_t n = 5) const;
    void Tail(size_t n = 5) const;
    void Describe(std::string column_name) const;

    Dataset &operator=(const Dataset &dataset);
    DataLine operator[](size_t index) const;

  private:
    void dispose();

    Column *data_;
    size_t size_;
    char delimiter_for_print_;
};

#endif // DATASET_H
