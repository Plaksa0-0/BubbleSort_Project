#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <vector>
#include <algorithm> 

template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int size = arr.size();
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
#endif 
