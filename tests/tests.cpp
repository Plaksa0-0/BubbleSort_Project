#include <iostream>
#include <vector>
#include <string>
#include <cassert>   
#include <cstdlib>   
#include <algorithm>  
#include <clocale>   
#include "bubble_sort.h"

template <typename T>
void printArray(const std::vector<T>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

// 1. Уже отсортирован
void testAlreadySorted() {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    std::cout << "  До:    "; printArray(arr); std::cout << "\n";
    bubbleSort(arr);
    std::cout << "  После: "; printArray(arr); std::cout << "\n";

    assert(arr == expected);
}

// 2. В обратном порядке
void testReverseOrder() {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    std::cout << "  До:    "; printArray(arr); std::cout << "\n";
    bubbleSort(arr);
    std::cout << "  После: "; printArray(arr); std::cout << "\n";

    assert(arr == expected);
}

// 3. С дубликатами
void testWithDuplicates() {
    std::vector<int> arr = { 4, 2, 2, 8, 3, 3, 1 };
    std::vector<int> expected = { 1, 2, 2, 3, 3, 4, 8 };

    std::cout << "  До:    "; printArray(arr); std::cout << "\n";
    bubbleSort(arr);
    std::cout << "  После: "; printArray(arr); std::cout << "\n";

    assert(arr == expected);
}

// 4. Пустой
void testEmptyArray() {
    std::vector<int> arr = {};
    std::vector<int> expected = {};

    std::cout << "  До:    "; printArray(arr); std::cout << "\n";
    bubbleSort(arr);
    std::cout << "  После: "; printArray(arr); std::cout << "\n";

    assert(arr == expected);
}

// 5. Один элемент
void testSingleElement() {
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };

    std::cout << "  До:    "; printArray(arr); std::cout << "\n";
    bubbleSort(arr);
    std::cout << "  После: "; printArray(arr); std::cout << "\n";

    assert(arr == expected);
}

// 6. Строки
void testStringSorting() {
    std::vector<std::string> arr = { "zebra", "apple", "mango", "banana" };
    std::vector<std::string> expected = { "apple", "banana", "mango", "zebra" };

    std::cout << "  До:    "; printArray(arr); std::cout << "\n";
    bubbleSort(arr);
    std::cout << "  После: "; printArray(arr); std::cout << "\n";

    assert(arr == expected);
}
// 7. Случайные числа
void testRandomArray() {
    std::vector<int> arr(10); 
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100; 
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    std::cout << "  До:    "; printArray(arr); std::cout << "\n";
    bubbleSort(arr);
    std::cout << "  После: "; printArray(arr); std::cout << "\n";

    assert(arr == expected);
}

// запуск тестов
int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "==================================================\n";
    std::cout << "          ЗАПУСК ЮНИТ-ТЕСТОВ АЛГОРИТМА\n";
    std::cout << "==================================================\n\n";

    std::cout << "Тест 1. Массив уже отсортирован:\n";
    testAlreadySorted();
    std::cout << "  Статус: УСПЕШНО\n\n";

    std::cout << "Тест 2. Массив в обратном порядке:\n";
    testReverseOrder();
    std::cout << "  Статус: УСПЕШНО\n\n";

    std::cout << "Тест 3. Массив с повторяющимися числами:\n";
    testWithDuplicates();
    std::cout << "  Статус: УСПЕШНО\n\n";

    std::cout << "Тест 4. Пустой массив:\n";
    testEmptyArray();
    std::cout << "  Статус: УСПЕШНО\n\n";

    std::cout << "Тест 5. Массив из одного элемента:\n";
    testSingleElement();
    std::cout << "  Статус: УСПЕШНО\n\n";

    std::cout << "Тест 6. Сортировка массива строк (шаблон):\n";
    testStringSorting();
    std::cout << "  Статус: УСПЕШНО\n\n";

    std::cout << "Тест 7. Тест случайного массива:\n";
    testRandomArray();
    std::cout << "  Статус: УСПЕШНО\n\n";

    std::cout << "==================================================\n";
    std::cout << "    Все 7 тестов успешно выполнены без ошибок!\n";
    std::cout << "==================================================\n";

    return 0;
}
