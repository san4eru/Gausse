#ifndef GETMATRIX_H
#define GETMATRIX_H

#include <fstream>
#include <sstream>

using namespace std;

void ShowMatrix(int n, int m, double** matrix, double* b); // ������� ������ �������
void ShowMatrix(int n, int m, double* x); // ������������� ������� ������ ������� ��� ������ �������
void MakeMatrix(int n, int k, char* filename, double** matrix, double* b); // ������� ��������� �������
double Function(int n, int k, int i, int j); // ������� ���������� ������� �� �������

// ����� ������� ������� �������� �������
void Solution(int n, double** matrix, double* b, double* x);
void Jordan(int n, double** matrix, double* b); // ���������� �������
void AnsJordan(int n, double** matrix, double* b, double* x); // ����������� � �������

void Nevyazka(int n, double** matrix, double* b, double* x); // ������� ���������� �������

#endif