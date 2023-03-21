#include "Number.h"
#include <iostream>
#include <cstring>


Number::Number(const char* value, int base) {
    Init(value, base);
}

Number::Number(const Number& other) {
    Init(other.digits_, other.base_);
}


Number::Number(Number&& other) {
    digits_ = other.digits_;
    base_ = other.base_;
    size_ = other.size_;
    other.digits_ = nullptr;
    other.base_ = 10;
    other.size_ = 0;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] digits_;
        digits_ = other.digits_;
        base_ = other.base_;
        size_ = other.size_;
        other.digits_ = nullptr;
        other.base_ = 10;
        other.size_ = 0;
    }
    return *this;
}

Number::~Number() {
    delete[] digits_;
}


void Number::Init(const char* value, int base) {
    base_ = base;
    size_ = std::strlen(value);
    digits_ = new char[size_];
    for (int i = 0; i < size_; i++) {
        digits_[i] = value[size_ - i - 1];
        if (digits_[i] >= '0' && digits_[i] <= '9') {
            digits_[i] -= '0';
        }
        else if (digits_[i] >= 'a' && digits_[i] <= 'z') {
            digits_[i] -= 'a' - 10;
        }
        else if (digits_[i] >= 'A' && digits_[i] <= 'Z') {
            digits_[i] -= 'A' - 10;
        }

    }
    Resize(size_); 
}

void Number::Resize(int new_size) {
    int i = new_size - 1;
    while (i >= 0 && digits_[i] == 0) {
        i--;
    }
    size_ = i + 1;
    if (size_ == 0) {
        base_ = 10;
    }
    char* new_digits = new char[size_];
    std::memcpy(new_digits, digits_, size_);
    delete[] digits_;
    digits_ = new_digits;
}

Number operator+(const Number& a, const Number& b) {
    int base = std::max(a.base_, b.base_);
    Number result("", base);
    int carry = 0;
    for (int i = 0; i < std::max(a.size_, b.size_); i++) {
        int sum = carry;
        if (i < a.size_) {
            sum += a.digits_[i];
        }
        if (i < b.size_) {
            sum += b.digits_[i];
        }
        result.digits_[i] = sum % base;
        carry = sum / base;
    }
    if (carry > 0) {
        result.Resize(result.size_ + 1);
        result.digits_[result.size_ - 1] = carry;
    }
    return result;
}

Number operator-(const Number& a, const Number& b) {
    int base = std::max(a.base_, b.base_);
    Number result("", base);
    int borrow = 0;
    for (int i = 0; i < std::max(a.size_, b.size_); i++) {
        int diff = borrow;
        if (i < a.size_) {
            diff += a.digits_[i];
        }
        if (i < b.size_) {
            diff -= b.digits_[i];
        }
        if (diff < 0) {
            borrow = -1;
            diff += base;
        }
        else {
            borrow = 0;
        }
        result.digits_[i] = diff;
    }
    result.Resize(result.size_);
    while (result.size_ > 1 && result.digits_[result.size_ - 1] == 0) {
        result.Resize(result.size_ - 1);
    }
    return result;
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator-=(const Number& other) {
    *this = *this - other;
    return *this;
}

Number& Number::operator--() {
    for (int i = 0; i < size_ - 1; i++) {
        digits_[i] = digits_[i + 1];
    }
    Resize(size_ - 1);
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    --(*this);
    return temp;
}

char Number::operator[](int i) const {
    return digits_[i];
}

bool Number::operator==(const Number& other) const {
    if (size_ != other.size_ || base_ != other.base_) {
        return false;
    }
    for (int i = 0; i < size_; i++) {
        if (digits_[i] != other.digits_[i]) {
            return false;
        }
    }
    return true;
}

bool Number::operator!=(const Number& other) const {
    return !(*this == other);
}

bool Number::operator>(const Number& other) const {
    if (size_ > other.size_) {
        return true;
    }
    else if (size_ < other.size_) {
        return false;
    }
    else {
        for (int i = size_ - 1; i >= 0; i--) {
            if (digits_[i] > other.digits_[i]) {
                return true;
            }
            else if (digits_[i] < other.digits_[i]) {
                return false;
            }
        }
        return false;
    }
}

bool Number::operator<(const Number& other) const {
    return other > *this;
}

bool Number::operator>=(const Number& other) const {
    return !(*this < other);
}

bool Number::operator<=(const Number& other) const {
    return !(other < *this);
}

void Number::SwitchBase(int newBase) {
int oldBase = base_;
if (newBase == oldBase) {
return;
}

int decValue = 0;
int power = 1;
for (int i = size_ - 1; i >= 0; i--) {
int digit = (digits_[i] >= 'A') ? (digits_[i] - 'A' + 10) : (digits_[i] - '0');
decValue += digit * power;
power *= oldBase;
}

int i = 0;
while (decValue > 0) {
int digit = decValue % newBase;
if (digit >= 10) {
digits_[i] = 'A' + (digit - 10);
} else {
digits_[i] = '0' + digit;
}
i++;
decValue /= newBase;
}
size_ = i;
base_ = newBase;
digits_[i] = '\0';

std::reverse(digits_, digits_ + size_);
}

void Number::Print() const {
std::cout << digits_ << std::endl;
}

int Number::GetDigitsCount() const {
return size_;
}

int Number::GetBase() const {
return base_;
}

