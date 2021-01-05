#include "GetMatrix.h"
#include <time.h>

int main(int argc, char* argv[]) //argc - кол-во аргументов; argv - аргументы
{
	setlocale(LC_ALL, "Russian");

	// Обработка ошибки, если не введены аргументы
	if (argc <= 1)
	{
		if (argv[0])
			printf("Usage: %c <number>\n", argv[0]);
		else
			printf("Usage: <program name> <number>\n");

		exit(1);
	}

	int n, m, k;
	double** matrix, * b, * x;

	stringstream convert(argv[1]); // Преобразование из строки в целочисленное
	if (!(convert >> n)) // Eсли нельзя преобразовать, то становиться n = -1;
		n = -1;

	stringstream convert1(argv[2]); // Преобразование из строки в целочисленное
	if (!(convert1 >> m)) // Eсли нельзя преобразовать, то становиться m = -1;
		m = -1;

	stringstream convert2(argv[3]); // Преобразование из строки в целочисленное
	if (!(convert2 >> k)) // Eсли нельзя преобразовать, то становиться k = -1;
		k = -1;

	if ((n == -1) || (m == -1) || (k == -1)) { // Eсли n или m или k не преобразовались
		printf("Ошибка!\n"); // Вывести ошибку
		return -1;
	}

	matrix = (double**)malloc(n * sizeof(double)); // Выделение памяти для матрицы
	b = (double*)malloc(n * sizeof(double)); // Выделение памяти для вектора
	x = (double*)malloc(n * sizeof(double)); // Выделение памяти для переменных

	MakeMatrix(n, k, argv[4], matrix, b); // Функция заполения матрицы

	printf("\nИсходная матрица:\r\n");
	ShowMatrix(n, m, matrix, b); // Функция вывода матрицы
	
	time_t start, stop;
	time(&start);

	Solution(n, matrix, b, x);// Метод Жордана решения линейной системы
	time(&stop);

	printf("\nПреобразованная матрица:\r\n");
	ShowMatrix(n, m, matrix, b); // Функция вывода матрицы
	printf("\n");

	printf("Переменные:\r\n");
	ShowMatrix(n, m, x); // Перегруженная функция вывода матрицы для вывода решения
	printf("Время: %f\n", difftime(stop, start));

	printf("Сравнение:\n");
	Nevyazka(n, matrix, b, x); // Функция вычисления невязок

	free((void*)matrix); // Освобождение памяти
	free((void*)b);
	free((void*)x);
		
	return 0;
}