#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>
#include <functional>

#include "BubbleSort.hpp"

using TypeToSort = std::int64_t;
using AlgorithmInput = std::vector<TypeToSort>;
using Algorithm = std::function<void(AlgorithmInput &)>;

class SortingAlgorithmsParametrizedTestFixture : public testing::TestWithParam<Algorithm>
{
public:
    SortingAlgorithmsParametrizedTestFixture() : sortingAlgorithm{GetParam()}
    {
    }

    Algorithm sortingAlgorithm;
};

TEST_P(SortingAlgorithmsParametrizedTestFixture, GivenEmptyCollectionThenShouldReturnEmptyCollection)
{
    std::vector<TypeToSort> testedInput{};
    sortingAlgorithm(testedInput);

    ASSERT_THAT(testedInput, testing::IsEmpty());
}

TEST_P(SortingAlgorithmsParametrizedTestFixture, GivenCollectionWithSingleElementThenShouldReturnCollectionWithThatElement)
{
    std::vector<std::int64_t> testedInput{8};
    sortingAlgorithm(testedInput);

    ASSERT_THAT(testedInput, testing::ElementsAre(8));
}

TEST_P(SortingAlgorithmsParametrizedTestFixture, GivenCollectionWithTwoSortedElementsThenShouldReturnUnchangedCollection)
{
    std::vector<std::int64_t> testedInput{7, 8};
    sortingAlgorithm(testedInput);

    ASSERT_THAT(testedInput, testing::ElementsAre(7, 8));
}

TEST_P(SortingAlgorithmsParametrizedTestFixture, GivenCollectionWithTwoUnsortedElementsThenShouldReturnCollectionWithChangedOrder)
{
    std::vector<std::int64_t> testedInput{8, 7};
    sortingAlgorithm(testedInput);

    ASSERT_THAT(testedInput, testing::ElementsAre(7, 8));
}

INSTANTIATE_TEST_CASE_P(
    SortingAlgorithmsTests,
    SortingAlgorithmsParametrizedTestFixture,
    testing::Values(
        bubbleSort<TypeToSort>,
        optimizedBubbleSort<TypeToSort>,
        selectionSort<TypeToSort>,
        insertionSort<TypeToSort>));
