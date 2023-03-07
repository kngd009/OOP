#include <iostream>
#include "Math.h"

using namespace std;

int main()
{

    cout << "180 + 34 = " << Math::Add(180, 34) << endl;
	cout << "180 + 34 + 36 = " << Math::Add(180, 34, 36) << endl;
	cout << "120.5 + 16.5 = " << Math::Add(120.5, 16.5);
	cout << "115.4 + 34.8 + 36.7 = " << Math::Add(115.4, 34.8, 36.7) << endl;

	cout << "12 * 12 = " << Math::Mul(12, 12) << endl;
	cout << "12 * 12 * 12= " << Math::Mul(12, 12, 12) << endl;
	cout << "10.3 * 10.6 = " << Math::Mul(10.3, 10.6) << endl;
	cout << "12.7 * 12.8 * 12.9= " << Math::Mul(12.7, 12.8, 12.9) << endl;

    cout << "1 + 2 + 3 + 4 + 5 = " << Math::Add(5, 1, 2, 3, 4, 5) << endl;

    const char* sir1 = "Salut, ";
    const char* sir2 = "Daniel!";

    char* sir3 = Math::Add(sir1, sir2);
    if (sir3 != nullptr) {
        cout << sir3 << endl;
        delete[] sir3;
    }
    char* sir4 = nullptr;
    char* sir5 = Math::Add(sir1, sir4);
    if (sir5 == nullptr) {
        cout << "Unul dintre siruri este null." << endl;
    }
    return 0;

	
}