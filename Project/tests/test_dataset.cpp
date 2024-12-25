#include "column.h"
#include "data_line.h"
#include "dataset.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(TestGroupName_txt, Subtest_1_ColumnCount)
{
    Dataset data_txt("./tests/test_data.txt", 1);
    ASSERT_EQ(data_txt.GetColumnCount(), 3);
}

TEST(TestGroupName_txt, Subtest_2_RowCount)
{
    Dataset data_txt("./tests/test_data.txt", 1);
    ASSERT_EQ(data_txt.GetRowCount(0), 3);
    ASSERT_EQ(data_txt.GetRowCount(1), 3);
    ASSERT_EQ(data_txt.GetRowCount(2), 3);
}

TEST(TestGroupName_txt, Subtest_3_ColumnTypes)
{
    Dataset data_txt("./tests/test_data.txt", 1);
    ASSERT_EQ(data_txt.GetColumnType(0), TypeData::typeInt);
    ASSERT_EQ(data_txt.GetColumnType(1), TypeData::typeString);
    ASSERT_EQ(data_txt.GetColumnType(2), TypeData::typeDouble);
}

TEST(TestGroupName_txt, Subtest_4_ColumnNames)
{
    Dataset data_txt("./tests/test_data.txt", 1);
    ASSERT_EQ(data_txt.GetColumnName(0), "col1");
    ASSERT_EQ(data_txt.GetColumnName(1), "col2");
    ASSERT_EQ(data_txt.GetColumnName(2), "col3");
}

TEST(TestGroupName_csv, Subtest_1_ColumnCount)
{
    Dataset data_csv("./tests/test_data.csv", 1);
    ASSERT_EQ(data_csv.GetColumnCount(), 3);
}

TEST(TestGroupName_csv, Subtest_2_RowCount)
{
    Dataset data_csv("./tests/test_data.csv", 1);
    ASSERT_EQ(data_csv.GetRowCount(0), 3);
    ASSERT_EQ(data_csv.GetRowCount(1), 3);
    ASSERT_EQ(data_csv.GetRowCount(2), 3);
}

TEST(TestGroupName_csv, Subtest_3_ColumnTypes)
{
    Dataset data_csv("./tests/test_data.csv", 1);
    ASSERT_EQ(data_csv.GetColumnType(0), TypeData::typeInt);
    ASSERT_EQ(data_csv.GetColumnType(1), TypeData::typeString);
    ASSERT_EQ(data_csv.GetColumnType(2), TypeData::typeDouble);
}

TEST(TestGroupName_csv, Subtest_4_ColumnNames)
{
    Dataset data_csv("./tests/test_data.csv", 1);
    ASSERT_EQ(data_csv.GetColumnName(0), "col1");
    ASSERT_EQ(data_csv.GetColumnName(1), "col2");
    ASSERT_EQ(data_csv.GetColumnName(2), "col3");
}
