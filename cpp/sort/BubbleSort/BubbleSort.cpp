#include <iostream>
#include <vector>

#include "BubbleSort.hpp"

void print(const std::vector<TypeToSort> &collection)
{
    for (const TypeToSort &elem : collection)
    {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
}

void swap(TypeToSort &first, TypeToSort &second)
{
    TypeToSort tmp = first;
    first = second;
    second = tmp;
}

void bubbleSort(std::vector<TypeToSort> &collection)
{
    if (collection.empty())
        return;

    for (std::size_t lastIndexToCheck = collection.size() - 1; lastIndexToCheck > 0; --lastIndexToCheck)
        for (std::size_t index = 0; index < lastIndexToCheck; ++index)
            if (collection[index] > collection[index + 1])
                swap(collection[index], collection[index + 1]);
}
