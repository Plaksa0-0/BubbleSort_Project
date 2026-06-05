#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

#include "bubble_sort.h" 

using namespace std;

vector<int> generateRandomArray(int size, int min_val, int max_val) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min_val, max_val);

    for (int i = 0; i < size; ++i) {
        arr[i] = distrib(gen);
    }
    return arr;
}

void drawHistogram(const vector<int>& arr, int curr, int next) {
#ifdef _WIN32
    system("cls");  
#else
    system("clear"); 
#endif

    cout << "===========================================\n";
    cout << "   Визуализация пузырьковой сортировки     \n";
    cout << "===========================================\n\n";

    for (size_t i = 0; i < arr.size(); ++i) {
        if (i == curr || i == next) {
            cout << "\033[31m"; 
        }

        for (int j = 0; j < arr[i]; ++j) {
            cout << "|";
        }

        if (i == curr || i == next) {
            cout << "\033[0m";  
        }

        cout << " " << arr[i] << "\n";
    }

    this_thread::sleep_for(chrono::milliseconds(150));
}

void bubbleSortVisualized(vector<int>& arr) {
    int size = arr.size();
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {

            drawHistogram(arr, j, j + 1);

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;

                drawHistogram(arr, j, j + 1);
            }
        }
        if (!swapped) break;
    }
    drawHistogram(arr, -1, -1);
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Генерация случайного массива из 7 элементов...\n";
    vector<int> myArr = generateRandomArray(7, 1, 20);

    cout << "Массив успешно создан. Нажмите Enter для запуска визуализации...";
    cin.get();

    bubbleSortVisualized(myArr);

    cout << "\nСортировка завершена!\n";
    return 0;
}
