#include "Sort.h"
#include <iostream>

using namespace std;

int main() {

    cout << "String 1 with 10 random elements from 0 to 100: " << endl;
    Sort s1(10, 0, 100);
    s1.Print();

    cout << "String 2 (Existing vector): " << endl;
    int arr[] = { 5, 1, 8, 2, 6 };
    Sort s2(arr, 5);
    s2.Print();

    cout << "String 3 (initialization list): " << endl;
    Sort s3 = { 9, 3, 7, 1, 5 };
    s3.Print();

    cout << "String 4 (parametri variadici): " << endl;
    Sort s4(5, 9, 3, 7, 1, 5);
    s4.Print();
    
    cout << "String 5 (List sorted from a string): " << endl;
    Sort s5("10,40,100,5,70");
    s5.Print();
    cout << endl;

    cout << "String 1 after Insertion sort (ascedent): " << endl;
    s1.InsertSort(true);
    s1.Print();
    cout << endl;

    cout << "String 2 after Insertion sort (descedent): " << endl;
    s2.InsertSort(false);
    s2.Print();
    cout << endl;

    cout << "String 3 after QuickSort sort (ascedent): " << endl;
    s3.QuickSort(true);
    s3.Print();
    cout << endl;
  
    cout << "String 4 after QuickSort sort (descedent): " << endl;
    s4.QuickSort(false);
    s4.Print();

    cout << "String 5 after BubbleSort sort (ascedent): " << endl;
    s5.BubbleSort(true);
    s5.Print();
    cout << endl;

    cout << "String 5 after BubbleSort sort (descedent): " << endl;
    s5.BubbleSort(false);
    s5.Print();
    cout << endl;

    cout << "Number of elements in s5: " << s5.GetElementsCount() << endl;
    cout << "Element at index 3 in s5: " << s5.GetElementFromIndex(3) << endl;

    return 0;
}