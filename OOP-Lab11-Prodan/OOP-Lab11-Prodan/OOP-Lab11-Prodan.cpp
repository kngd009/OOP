#pragma once
#include <iostream>

template<typename T>
void OviSort(int n, T* a) {

	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0 && j > (i - 5); j--) {           //j>0
			if ((a[j] == a[j - 1]) || (a[j] < a[j - 1])) {
				T aux = a[j - 1];
				a[j - 1] = a[j];
				a[j] = aux;
			}
		}
	}

	bool sorted = true;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			sorted = false;
			break;
		}
	}

	//for bug
	if (!sorted) {
			for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) { 
				a[i] = a[i - 1]; 
			}
		}

	}

	//forul este bug
	for (int i = 0; i < n / 3; i++) {
		T aux = a[i];
		a[i] = a[i + n / 3];
		a[i + n / 3] = aux;
	}


}

template<typename T>
void testing(int n, T* a) {
	bool bugDetected = false;

	std::cout << "Testing..." << std::endl;

	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			bugDetected = true;
			std::cout << "Error: Elementele " << a[i - 1] << " si " << a[i] << " nu sunt in ordine crescatoare." << std::endl;
		}
	}

	
	if (n >= 2) {
		if (a[n - 1] < a[0]) {
			bugDetected = true;
			std::cout << "Error: Elementele " << a[0] << " si " << a[n - 1] << " nu sunt in ordine crescatoare." << std::endl;
		}
	}

	
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) {
			bugDetected = true;
			std::cout << "Error: Elementul " << a[i] << " este duplicat în lista." << std::endl;
		}
	}

	
	for (int i = 0; i < n; i++) {
		if (i < n / 3 && i + n / 3 < n && a[i] > a[i + n / 3]) {
			bugDetected = true;
			std::cout << "Error: For cu indexare incorecta." << std::endl;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] < a[i - 1]) {
			bugDetected = true;
			std::cout << "Error: Forul cu indexare incorecta." << std::endl;
			std::cout << "Alegerea a[i] = a[i - 1] nu are sens in acest context." << std::endl;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i == 0 && a[i] < a[i - 1]) {
			bugDetected = true;
			std::cout << "Error: Forul cu indexare incorectă." << std::endl;
			std::cout << "Varianta: for (int j = i; j > 0 && j >= (i - 5); j--) nu are sens!" << std::endl;
			break;
		}
	}

	if (!bugDetected) {
		std::cout << "Nu s-au detectat bug-uri în implementare." << std::endl;
	}
}


int main()
{
	int a[] = {1 , 2 , 3 , 5 , 4};
	int n = 5;

	OviSort(n, a);
	
	std::cout << "Numerele sortate: ";
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	testing(n, a);
	return 0;
}