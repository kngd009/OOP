#include "Sort.h"
#include <cstdarg>
#include <iostream>

using namespace std;

Sort::Sort(int count, int min, int max) {
    size = count;
    elements = new int[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        elements[i] = rand() % (max - min + 1) + min;
    }
}

Sort::Sort(int* arr, int count) {
    size = count;
    elements = new int[size];
    for (int i = 0; i < size; i++) 
    {
        elements[i] = arr[i];
    }
}

Sort::Sort(initializer_list<int> init_list) {
    size = init_list.size();
    elements = new int[size];
    copy(init_list.begin(), init_list.end(), elements);
}

Sort::Sort(int count, ...) {
    size = count;
    elements = new int[size];
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        elements[i] = va_arg(args, int);
    }
    va_end(args);
}
Sort::Sort(const char* str) {
    
    int num_commas = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            num_commas++;
        }
    }
    size = num_commas + 1;

    elements = new int[size];
        
    int num = 0;
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            elements[index] = num;
            index++;
            num = 0;
        }
        else {
            num = num * 10 + (str[i] - '0');
        }
    }
    elements[index] = num;
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascendent && elements[j] > elements[j + 1]) ||
                (!ascendent && elements[j] < elements[j + 1])) {
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
}

void Sort::InsertSort(bool ascendent) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = elements[i];
        j = i - 1;
        while (j >= 0 && (ascendent ? elements[j] > key : elements[j] < key)) {
            elements[j + 1] = elements[j];
            j = j - 1;
        }
        elements[j + 1] = key;
    }
}

void Sort::QuickSort(bool ascendent) {
    int l = 0, r = size - 1;
    int pivot = elements[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while ((ascendent ? elements[i] < pivot : elements[i] > pivot)) {
            i++;
        }
        while ((ascendent ? elements[j] > pivot : elements[j] < pivot)) {
            j--;
        }
        if (i <= j) {
            swap(elements[i], elements[j]);
            i++;
            j--;
        }
    }
    if (l < j) {
        QuickSortHelper(l, j, ascendent);
    }
    if (i < r) {
        QuickSortHelper(i, r, ascendent);
    }
}

void Sort::QuickSortHelper(int l, int r, bool ascendent) {
    int pivot = elements[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while ((ascendent ? elements[i] < pivot : elements[i] > pivot)) {
            i++;
        }
        while ((ascendent ? elements[j] > pivot : elements[j] < pivot)) {
            j--;
        }
        if (i <= j) {
            swap(elements[i], elements[j]);
            i++;
            j--;
        }
    }
    if (l < j) {
        QuickSortHelper(l, j, ascendent);
    }
    if (i < r) {
        QuickSortHelper(i, r, ascendent);
    }
}

void Sort::Print() {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << elements[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int Sort::GetElementsCount() {
    return size;
}

int Sort::GetElementFromIndex(int index) {
    if (index < 0 || index >= size) {
        return -1;
    }
    return elements[index];
}