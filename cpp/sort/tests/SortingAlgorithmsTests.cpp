#include <vector>

#include "gtest/gtest.h"

#include "BubbleSort.hpp"

TEST(blax, a)
{
    std::vector<std::int64_t> testedInput{3, 2, 5, 1, 6, 9, 1, 2, 7};
    bubbleSort(testedInput);
}
