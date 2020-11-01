#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>

#include "BubbleSort.hpp"

TEST(SortingAlgorithmsTests, GivenEmptyCollectionThenShouldReturnEmptyCollection)
{
    std::vector<std::int64_t> testedInput{};
    bubbleSort(testedInput);

    ASSERT_THAT(testedInput, testing::IsEmpty());
}

TEST(SortingAlgorithmsTests, GivenCollectionWithSingleElementThenShouldReturnCollectionWithThatElement)
{
    std::vector<std::int64_t> testedInput{8};
    bubbleSort(testedInput);

    ASSERT_THAT(testedInput, testing::ElementsAre(8));
}

TEST(SortingAlgorithmsTests, GivenCollectionWithTwoSortedElementsThenShouldReturnUnchangedCollection)
{
    std::vector<std::int64_t> testedInput{7, 8};
    bubbleSort(testedInput);

    ASSERT_THAT(testedInput, testing::ElementsAre(7, 8));
}

TEST(SortingAlgorithmsTests, GivenCollectionWithTwoUnsortedElementsThenShouldReturnCollectionWithChangedOrder)
{
    std::vector<std::int64_t> testedInput{8, 7};
    bubbleSort(testedInput);

    ASSERT_THAT(testedInput, testing::ElementsAre(7, 8));
}
