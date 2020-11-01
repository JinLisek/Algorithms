#include <iostream>
#include <vector>

using TypeToSort = std::int64_t;

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
    for (std::size_t lastIndexToCheck = collection.size() - 1; lastIndexToCheck > 0; --lastIndexToCheck)
        for (std::size_t index = 0; index < lastIndexToCheck; ++index)
            if (collection[index] > collection[index + 1])
                swap(collection[index], collection[index + 1]);
}

int main()
{
    std::vector<TypeToSort> input{5, 9, 6, 2, 3, 5, 6, 1, 2, 3, 5, 4, 5, 3, 9, 8, 1};

    std::cout << "BEFORE SORT:" << std::endl;
    print(input);

    bubbleSort(input);

    std::cout << "AFTER SORT:" << std::endl;
    print(input);

    return 0;
}