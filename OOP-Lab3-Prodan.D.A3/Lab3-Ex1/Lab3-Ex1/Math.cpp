#include "Math.h"
#include <stdarg.h>

int Math::Add(int a, int b)
{
	a = a + b;
	return a;
}

int Math::Add(int a, int b, int c)
{
	a = a + b + c;
	return a;
}

int Math::Add(double a, double b)
{
	a = a + b;
	return a;
}

int Math::Add(double a, double b, double c)
{
	a = a + b + c;
	return a;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	va_list arg;

	va_start(arg, count);

	int suma = 0;
	for (int i = 0; i < count; i++) {
		suma += va_arg(arg, int);
	}
	va_end(arg);

	return suma;
}

char* Math::Add(const char* str1, const char* str2)
{
    if (str1 == nullptr || str2 == nullptr) {
        return nullptr;
    }

    // lungimea sirurilor
    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    int len2 = 0;
    while (str2[len2] != '\0') {
        len2++;
    }

    // Alocam memorie pentru rezultat

    int len = len1 + len2 + 1;
    char* rezultat = new char[len];


    for (int i = 0; i < len1; i++) {
        rezultat[i] = str1[i];
    }

    for (int i = 0; i < len2; i++) {
        rezultat[len1 + i] = str2[i];
    }
    rezultat[len - 1] = '\0';

    return rezultat;
}