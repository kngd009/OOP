#pragma once
#include <initializer_list>
#include <string>

using namespace std;

class Sort
{

private:
    int* elements;
    int size;

public:

    Sort(int count, int min, int max);
    Sort(int* arr, int count);
    Sort(initializer_list <int> init_list);
    Sort(int count, ...);
    Sort(const char* str);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void QuickSortHelper(int l, int r, bool ascendent);
    void BubbleSort(bool ascendent = false);
    void Print();

    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};