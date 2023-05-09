#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class IndexOutOfBoundsException : public exception {
public:
    const char* what() const throw() {
        return "Indexul este prea mare";
    }
};

class ElementNotFoundException : public exception {
public:
    const char* what() const throw() {
        return "Elementul nu a fost gasit";
    }
};

class Compare {
public:
    virtual int CompareElements(void*  e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
    int Current;

public:
    ArrayIterator() : Current(0) {}

    ArrayIterator& operator++() {
        ++Current;
        return *this;
    }

    ArrayIterator& operator--() {
        --Current;
        return *this;
    }

    bool operator==(ArrayIterator<T>& other) {
        return Current == other.Current;
    }

    bool operator!=(const ArrayIterator<T>& other) {
        return Current != other.Current;
    }

    T* GetElement() {
        if (Current < 0 || Current >= Size) {
            throw IndexOutOfBoundsException();
        }
        return List[Current];
    }
};

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

public:

    friend class ArrayIterator<T>;
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array() {
        if (List != nullptr) {
            for (int i = 0; i < Size; ++i) {
                delete List[i];
            }
            delete[] List;
        }
    }

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size) {
        List = new T * [Capacity];
        for (int i = 0; i < Size; ++i) {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) {
            throw out_of_range("Index out of range");
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size == Capacity) {
            int newCapacity = Capacity == 0 ? 1 : Capacity * 2;
            T** newList = new T * [newCapacity];
            for (int i = 0; i < Size; ++i) {
                newList[i] = List[i];
            }
            delete[] List;
            List = newList;
            Capacity = newCapacity;
        }
        List[Size] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) {
            throw out_of_range("Invalid index");
        }
        if (Size == Capacity) {
            int newCapacity = Capacity == 0 ? 1 : Capacity * 2;
            T** newList = new T * [newCapacity];
            for (int i = 0; i < index; ++i) {
                newList[i] = List[i];
            }
            newList[index] = new T(newElem);
            for (int i = index; i < Size; ++i) {
                newList[i + 1] = List[i];
            }
            delete[] List;
            List = newList;
            Capacity = newCapacity;
            ++Size;
        }
        else {
            for (int i = Size - 1; i >= index; --i) {
                List[i + 1] = List[i];
            }
            List[index] = new T(newElem);
            ++Size;
        }
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T>& otherArray) {
        if (index < 0 || index > Size) {
            throw out_of_range("Invalid index");
        }
        int otherSize = otherArray.Size;
        if (Size + otherSize > Capacity) {
            int newCapacity = Capacity == 0 ? otherSize : Capacity + otherSize;
            T** newList = new T * [newCapacity];
            for (int i = 0; i < index; ++i) {
                newList[i] = List[i];
            }
            for (int i = 0; i < otherSize; ++i) {
                newList[index + i] = new T(*otherArray.List[i]);
            }
            for (int i = index; i < Size; ++i) {
                newList[i + otherSize] = List[i];
            }
            delete[] List;
            List = newList;
            Capacity = newCapacity;
            Size += otherSize;
        }
        else {
            for (int i = Size - 1; i >= index; --i) {
                List[i + otherSize] = List[i];
            }
            for (int i = 0; i < otherSize; ++i) {
                List[index + i] = new T(*otherArray.List[i]);
            }
            Size += otherSize;
        }
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) {
            throw out_of_range("Invalid index");
        }
        delete List[index];
        for (int i = index; i < Size - 1; ++i) {
            List[i] = List[i + 1];
        }
        --Size;
        return *this;
    }

    bool operator==(const Array<T>& otherArray) {
        if (this != &otherArray) {
            if (List != nullptr) {
                for (int i = 0; i < Size; ++i) {
                    delete List[i];
                }
                delete[] List;
            }
            Capacity = otherArray.Capacity;
            Size = otherArray.Size;
            List = new T * [Capacity];
            for (int i = 0; i < Size; ++i) {
                List[i] = new T(*otherArray.List[i]);
            }
        }
        return *this;
    }

    template<class T>
    void Array<T>::Sort() {
            std::sort(List, List + Size, [](const T* a, const T* b) {
            return *a < *b;
            });
    }   

    template<class T>
    void Array<T>::Sort(int(*compare)(const T&, const T&)) {
              std::sort(List, List + Size, compare);
    }

    template<class T>
        void Array<T>::Sort(Compare* comparator) {
    
        std::sort(List, List + Size, [comparator](const T* a, const T* b) {
            return comparator->CompareElements(a, b) < 0;
            });
    }

    template<class T>
    int Array<T>::BinarySearch(const T& elem) {
  
        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (*List[mid] == elem) {
                return mid; 
            }
            else if (*List[mid] < elem) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
    template<class T>
    int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
      
        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int compResult = compare(*List[mid], elem);

            if (compResult == 0) {
                return mid;
            }
            else if (compResult < 0) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        throw ElementNotFoundException();;
    }

    template<class T>
    int Array<T>::BinarySearch(const T& elem, Compare* comparator) {
        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int compResult = comparator->CompareElements(List[mid], &elem);

            if (compResult == 0) {
                return mid;
            }
            else if (compResult < 0) {
                left = mid + 1;
            else {
                right = mid - 1;
            }
            }

            throw ElementNotFoundException();
        }
    }


        template<class T>
        int Find(const T& elem) {
            for (int i = 0; i < Size; ++i) {
                if (*List[i] == elem) {
                    return i;
                }
            }
            throw ElementNotFoundException();
        }

        template<class T>
        int Array<T>::Find(const T & elem, int(*compare)(const T&, const T&)) {

            for (int i = 0; i < Size; ++i) {
                if (compare(*List[i], elem) == 0) {
                    return i;
                }
            }

            throw ElementNotFoundException();
        }

        template<class T>
        int Array<T>::Find(const T & elem, Compare * comparator) {

            for (int i = 0; i < Size; ++i) {
                if (comparator->CompareElements(List[i], &elem) == 0) {
                    return i;
                }
            }

            return -1;
        }

        template<class T>
        int Array<T>::GetSize() {
            return Size;
        }

        template<class T>
        int Array<T>::GetCapacity() {
            return Capacity;
        }

        template<class T>
        ArrayIterator<T> Array<T>:: GetBeginIterator() {
            return ArrayIterator<T>();
        }

        template<class T>
        ArrayIterator<T> Array<T>::GetEndIterator() {
            ArrayIterator<T> it;
            it.Current = Size;
            return it;
        }
    };

    int main() {
        
        try {

            Array<int> arr(5);

            arr += 10;
            arr += 20;
            arr += 30;
            arr += 40;
            arr += 50;

            cout << "Element at index 3: " << arr[3] << endl;
              arr[3] = 35;
              cout << "Modified element at index 3: " << arr[3] << endl;
              
              ArrayIterator<int> it = arr.GetBeginIterator();
              ArrayIterator<int> end = arr.GetEndIterator();
              while (it != end) {
                  cout << *it.GetElement() << " ";
                  ++it;
              }
              cout << endl;

              int index = arr.BinarySearch(35);
              cout << "Element 35 found at index: " << index << endl;

              index = arr.BinarySearch(100);
              cout << "Element 100 found at index: " << index << endl;
        }
        catch (const exception& e) {
            cout << "Exception occurred: " << e.what() << endl;
        }

        return 0;
    }