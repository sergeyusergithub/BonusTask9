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
void delet_arr(T*& arr);

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
			case 1: new_arr(pd, n);	break;
			case 2: fill_arr(pd, n,0,20); break;
			case 3: print_arr(pd, n); break;
			case 4: delet_arr(pd); break;
			case 5: resize_arr(pd, n); break;
			default:
				break;
		}
		std::cin >> m;
		if (m == 6 && pd != nullptr) {
			delete[] pd;
			pd = nullptr;
			std::cout << "Память освобождена!\n";
		}
			
	}

	std::cout << "\n\n";

	// Задача 2. Двумерный и одномерный динамические массивы

	std::cout << "Задача 2.\nВведите rows и cols двумерного массива -> ";
	int rows, cols;
	std::cin >> rows >> cols;

	int** ppmx = nullptr;

	ppmx = new int* [rows];

	for (int i = 0; i < rows; i++)
		ppmx[i] = new int[cols];


	bool* parr = new bool[cols];

	std::cout << "Заполните массив " << rows << "x" << cols << ":\n";

	
	for(int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			std::cin >> ppmx[i][j];
		}

	std::cout << "Двумерный массив:\n";

	for (int i = 0; i < rows; i++) {
		print_arr(*(ppmx+i), cols);
	}

	bool state = true;

	for(int i = 0; i < cols; i++){
		for (int j = 0; j < rows/2; j++) {
			if (ppmx[j][i] != ppmx[rows - 1 - j][i])
				state = false;
		}
		parr[i] = state;
		state = true;
	}

	std::cout << "Логический массив:\n";

	for (int i = 0; i < cols; i++)
		if (parr[i] == 0)
			std::cout << "false ";
		else
			std::cout << "true ";

	std::cout << "\n\n";

	for (int i = 0; i < rows; i++)
		delete[] ppmx[i];
	
	delete[] ppmx;

	return 0;
}

template<typename T>
void new_arr(T*& arr, const int length) {
	if (arr != nullptr)
		delete arr;

	T* parr = new T[length];

	arr = parr;
	std::cout << "Память выделена!\n";
	return;
}

template<typename T>
void fill_arr(T* arr, const int length,int left, int right){
	if (arr == nullptr) {
		std::cout << "ОШИБКА! Память не выделена!\n";
		return;
	}
	double tmp;
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		arr[i] = (rand()*1.0/32767)*(right - left) + left*1.0;
		
	}
	std::cout << std::endl;
	std::cout << "Массив заполнен случайными числами!\n";
	return;
}

template<typename T>
void print_arr(T* arr, const int length){
	if (arr == nullptr) {
		std::cout << "ОШИБКА! Память не выделена!\n";
		return;
	}
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";

	return;
}

template<typename T>
void delet_arr(T*& arr){
	if (arr == nullptr) {
		std::cout << "Память пуста!\n";
		return;
	}
	else {
		delete[] arr;
		std::cout << "Память освобождена!\n";
		arr = nullptr;
	}
}

template<typename T>
void resize_arr(T*& arr, int& length){
	if (arr == nullptr) {
		std::cout << "ОШИБКА! Память не выделена!\n";
		return;
	}
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
	std::cout << "Размер массива изменен: " << length << "\n";
	return;
}
