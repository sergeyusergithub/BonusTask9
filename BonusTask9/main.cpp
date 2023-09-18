#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void new_arr(T*& arr, const int length);

template <typename T>
void fill_arr(T* arr, const int length,int left, int right);

template <typename T>
void print_arr(T* arr, const int length);

template <typename T>
void delet_arr(T*& arr,const int length);

template <typename T>
void resize_arr(T*& arr, int& length);

int main() {
	setlocale(LC_ALL, "Russian");
	int n,m;

	// Задача 1. пять функция и указатель

	double* pd = nullptr;
	std::cout << "Задача 1.\n";
	std::cout << "Введите размер массива -> ";
	std::cin >> n;

	std::cout << "Выберете необходимое действие: \n";
	std::cout << "1. Выделение памяти для массива.\n";
	std::cout << "2. Заполнение массива случайными числами.\n";
	std::cout << "3. Вывод массива в консоль.\n";
	std::cout << "4. Освобождение памяти, выделенной под массив.\n";
	std::cout << "5. Изменение размера массива.\n";
	std::cout << "6. Выход.\n";

	std::cin >> m;

	while (m - 6) {
		switch (m) {
			case 1: new_arr(pd, n);
				std::cout << "pd = " << pd << std::endl;
				break;
			case 2: fill_arr(pd, n,0,20); break;
			case 3: print_arr(pd, n); break;
			case 4: delet_arr(pd,n); break;
			case 5: resize_arr(pd, n); break;
			default:
				break;
		}
		std::cin >> m;
	}




	


	return 0;
}

template<typename T>
void new_arr(T*& arr, const int length) {
	if (arr != nullptr)
		delete arr;
	T* parr = new T[length];

	arr = parr;
	std::cout << "arr = " << arr << "\n";
	

	
	return;
}

template<typename T>
void fill_arr(T* arr, const int length,int left, int right){
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = (rand() % (right - left) + left) * 1.0;
		std::cout << arr[i] << " ";
	}
	return;
}

template<typename T>
void print_arr(T* arr, const int length){
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";

	return;
}

template<typename T>
void delet_arr(T*& arr,const int length){
	for(int i = 0; i < length; i++)
		delete (arr+i);
}

template<typename T>
void resize_arr(T*& arr, int& length){
	int n;
	std::cout << "Введите новый размер массива -> ";
	std::cin >> n;
	if (n <= 0) 
		return;

	T* tmp = new T[n];
	if (n < length) {
		for (int i = 0; i < n; i++)
			tmp[i] = arr[i];
	}
	else 
		for (int i = 0; i < n; i++)
			if (i < length) {
				tmp[i] = arr[i];
			}
			else
				tmp[i] = i - length;

	delete[] arr;
	arr = tmp;
	length = n;
		
	return;
}
