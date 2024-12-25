#include "array_template.h"
#include <gtest/gtest.h>

TEST(ArrayTest, DefaultConstructor)
{
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int, 5> array(arr);
    std::ostringstream output_stream;
    std::streambuf *old_cout_streambuf = std::cout.rdbuf(output_stream.rdbuf());
    array.show();
    std::cout.rdbuf(old_cout_streambuf);
    std::string output = output_stream.str();
    ASSERT_EQ(output, "1 2 3 4 5 \n");
}

TEST(ArrayTest, MinimumValue)
{
    int arr[5] = {1, 2, 3, 0, 4};
    Array<int, 5> array(arr);
    int result = array.minimum(array);
    ASSERT_EQ(result, 0);
}

TEST(ArrayTest, MinimumNegativeValues)
{
    int arr[5] = {-1, -2, -3, -4, -5};
    Array<int, 5> array(arr);
    int result = array.minimum(array);
    ASSERT_EQ(result, -5);
}

TEST(ArrayTest, MinimumWithMixedValues)
{
    int arr[5] = {-1, 2, 3, -4, 5};
    Array<int, 5> array(arr);
    int result = array.minimum(array);
    ASSERT_EQ(result, -4);
}

TEST(ArrayTest, DefaultConstructorFloat)
{
    float arr[5] = {1.5f, 2.5f, 3.5f, 4.5f, 5.5f};
    Array<float, 5> array(arr);
    std::ostringstream output_stream;
    std::streambuf *old_cout_streambuf = std::cout.rdbuf(output_stream.rdbuf());
    array.show();
    std::cout.rdbuf(old_cout_streambuf);
    std::string output = output_stream.str();
    ASSERT_EQ(output, "1.5 2.5 3.5 4.5 5.5 \n");
}

TEST(ArrayTest, MinimumWithFloatValues)
{
    float arr[5] = {1.5f, 2.5f, 0.5f, 4.5f, 3.5f};
    Array<float, 5> array(arr);
    float result = array.minimum(array);
    ASSERT_EQ(result, 0.5f);
}
