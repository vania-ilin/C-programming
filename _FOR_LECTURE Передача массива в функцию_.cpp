#include <iostream>
#include <Windows.h>
using namespace std;

void Print(int arr[], int size) // Печать массива
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int Max(int arr[], int size) // Печать массива
{
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void Sort(int A[], int N) // или так int* A
{
	int temp;
	// сортировка массива (метод пузырька)
	for (int i = 0; i < N - 1; i++)
		for (int j = N - 2; j >= i; j--)
			if (A[j] > A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
}

void Delete_Even(int*& arr, int& size) // УДАЛИТЬ четные элементы (т.е. оставить нечетные)
// int arr[] эквивалентно int* arr
// В конце функции идет перестановка ссылки, поэтому
// для явной "передачи по ссылке" нужно дополнительно в формальных параметрах поставить &
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0) // кол-во нечетных
			count++;
	}

	int* temp = new int[count];
	int j = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] % 2 != 0) // переписываем только нечетные в новый массив
		{
			temp[j] = arr[i];
			j++;
		}
	arr = temp; // переставляем ссылку на старый массив 
	size = count; // работает

	cout << "\n";
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 10;

	int* M;
	M = new int[size] { 4, 1, 0, 3, 2, 9, 7, 6, 8, 5 }; // выделение памяти и инициализация

	cout << "Исходный массив: ";
	Print(M, size);

	cout << "Наибольший элемент в массиве: " << Max(M, size) << "\n";

	Sort(M, size);
	cout << "\nОтсортированный массив: ";
	Print(M, size);

	Delete_Even(M, size);
	cout << "Массив после удаления чётных элементов:" << "\n";
	Print(M, size);
	
	delete[] M;

	cin.get();
}