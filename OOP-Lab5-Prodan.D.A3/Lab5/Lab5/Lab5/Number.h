#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdexcept>

class Number {
public:
    
    Number(const char* value, int base);
    
    Number(const Number& other);
    
    Number(Number&& other) noexcept;
    
    Number& operator=(Number&& other) noexcept;
  
    ~Number();

    
    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);
    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);
    Number& operator--(); 
    Number operator--(int); 
    char operator[](int i) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;

   
    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

private:
    char* digits_ = nullptr;
    int base_ = 10;
    int size_ = 0;

    void Init(const char* value, int base);
    void Resize(int new_size);
};