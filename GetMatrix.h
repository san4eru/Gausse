#ifndef GETMATRIX_H
#define GETMATRIX_H

#include <fstream>
#include <sstream>

using namespace std;

void ShowMatrix(int n, int m, double** matrix, double* b); // Функция вывода матрицы
void ShowMatrix(int n, int m, double* x); // Перегруженная функция вывода матрицы для вывода решения
void MakeMatrix(int n, int k, char* filename, double** matrix, double* b); // Функция заполения матрицы
double Function(int n, int k, int i, int j); // Функция заполнения матрицы по формуле

// Метод Жордана решения линейной системы
void Solution(int n, double** matrix, double* b, double* x);
void Jordan(int n, double** matrix, double* b); // Приведение матрицы
void AnsJordan(int n, double** matrix, double* b, double* x); // Подстановка в матрицу

void Nevyazka(int n, double** matrix, double* b, double* x); // Функция вычисления невязок

#endif