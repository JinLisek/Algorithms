#include <iostream>
#include <vector>

template <typename TypeToSort>
void print(const std::vector<TypeToSort> &collection);

template <typename TypeToSort>
void swap(TypeToSort &first, TypeToSort &second);

template <typename TypeToSort>
void bubbleSort(std::vector<TypeToSort> &collection);

template <typename TypeToSort>
void optimizedBubbleSort(std::vector<TypeToSort> &collection);

template <typename TypeToSort>
void selectionSort(std::vector<TypeToSort> &collection);

template <typename TypeToSort>
void insertionSort(std::vector<TypeToSort> &collection);

template <typename TypeToSort>
void print(const std::vector<TypeToSort> &collection)
{
    for (const TypeToSort &elem : collection)
    {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
}

template <typename TypeToSort>
void swap(TypeToSort &first, TypeToSort &second)
{
    TypeToSort tmp = first;
    first = second;
    second = tmp;
}

template <typename TypeToSort>
void bubbleSort(std::vector<TypeToSort> &collection)
{
    if (collection.empty())
        return;

    for (std::size_t lastIndexToCheck = collection.size() - 1; lastIndexToCheck > 0; --lastIndexToCheck)
        for (std::size_t index = 0; index < lastIndexToCheck; ++index)
            if (collection[index] > collection[index + 1])
                swap(collection[index], collection[index + 1]);
}

template <typename TypeToSort>
void optimizedBubbleSort(std::vector<TypeToSort> &collection)
{
    if (collection.empty())
        return;

    bool didSwap = false;

    for (std::size_t lastIndexToCheck = collection.size() - 1; lastIndexToCheck > 0; --lastIndexToCheck)
    {
        for (std::size_t index = 0; index < lastIndexToCheck; ++index)
        {
            if (collection[index] > collection[index + 1])
            {
                swap(collection[index], collection[index + 1]);
                didSwap = true;
            }
        }

        if (not didSwap)
            break;
    }
}

template <typename TypeToSort>
void selectionSort(std::vector<TypeToSort> &collection)
{
    if (collection.empty())
        return;

    for (auto index = 0u; index < collection.size() - 1; ++index)
    {
        auto minIndex = index;
        for (auto nextIndex = index + 1; nextIndex < collection.size(); ++nextIndex)
        {
            if (collection.at(nextIndex) < collection.at(minIndex))
                minIndex = nextIndex;
        }
        swap(collection.at(index), collection.at(minIndex));
    }
}

template <typename TypeToSort>
void insertionSort(std::vector<TypeToSort> &collection)
{
    for (auto index = 1u; index < collection.size(); ++index)
    {
        const auto currentValue = collection.at(index);
        int previousIndex = index - 1; // cannot be unsigned, because it goes -1 after previousIndex == 0
        while (previousIndex >= 0 and currentValue < collection.at(previousIndex))
        {
            collection.at(previousIndex + 1) = collection.at(previousIndex);
            --previousIndex;
        }
        collection.at(previousIndex + 1) = currentValue;
    }
}
