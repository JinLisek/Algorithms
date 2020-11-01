#include <vector>
#include <cstdint>

using TypeToSort = std::int64_t;

void print(const std::vector<TypeToSort> &collection);

void swap(TypeToSort &first, TypeToSort &second);

void bubbleSort(std::vector<TypeToSort> &collection);
