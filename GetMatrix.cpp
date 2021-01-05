#include "GetMatrix.h"

// ������� ���������� ������� �� �������
double Function(int n, int k, int i, int j) {
	double x = 0;

	if (k == 1) { // ���� k = 1
		if (i > j)
			x = n - i + 1;
		else
			x = n - j + 1;
	} 
	else if (k == 2) { // ���� k = 2
		if (i > j)
			x = i;
		else
			x = j;
	} 
	else if (k == 3) { // ���� k = 3
		x = fabs(i - j);
	} 
	else if (k == 4) { // ���� k = 4
		x = 1 / (i + j - 1);
	}

	return x;
}

// ������� ��������� �������
void MakeMatrix(int n, int k, char* filename, double** matrix, double* b) {

	if (k == 0) { // ���� k = 0, �� ��������� ������� �� �����
		ifstream file(filename);

		if (file.is_open()) // �������� �� �������� �����
			printf("��� ��! ���� ������!\n\n");
		else {
			printf("���� �� ������!\n\n");
			exit(0);
		}

		for (int i = 0; i < n; i++) { // ���������� ������� �������� �� �����
			matrix[i] = (double*)malloc(n * sizeof(double));
			for (int j = 0; j < n; j++) {
				file >> matrix[i][j];
			}
		}
	}
	else { // ���� k �� ����� 0, �� ����������� ������� �� �������
		for (int i = 0; i < n; i++) {
			matrix[i] = (double*)malloc(n * sizeof(double));
			for (int j = 0; j < n; j++) {
				matrix[i][j] = Function(n, k, i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) { // ��������� ������ ����� (�������) �� �������
		b[i] = 0;
		for (int j = 0; j <= ((n + 1) / 2); j++) {
			b[i] = b[i] + matrix[i][2*j] + 1;
		}
	}
}

// ������� ������ �������
void ShowMatrix(int n, int m, double** matrix, double* b)
{
	for (int i = 0; (i < n) && (i < m); i++)
	{
		for (int j = 0; (j < n + 1) && (j < m + 1); j++)
		{
			if ((j == n) || (j == m))
				printf(" %10.3e", b[i]); // ��������������� �����
			else
				printf(" %10.3e", matrix[i][j]); // ��������������� �����
		}
		printf("\n");
	}
	printf("\r\n");
}
// ������������� ������� ������ ������� ��� ������ �������
void ShowMatrix(int n, int m, double* x)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %10.3e", x[i]); // ��������������� �����
	}
	printf("\n");
} 

// ����� ������� ������� �������� �������
void Solution(int n, double** matrix, double* b, double* x) {
	Jordan(n, matrix, b); // ���������� �������
	AnsJordan(n, matrix, b, x); // ����������� � �������
}

// ���������� �������
void Jordan(int n, double** matrix, double* b)
{
	double v;
	for (int k = 0, i, j, im; k < n - 1; k++)
	{
		im = k;
		for (i = k + 1; i < n; i++)
		{
			if (fabs(matrix[im][k]) < fabs(matrix[i][k]))
			{
				im = i;
			}
		}
		if (im != k)
		{
			for (j = 0; j < n; j++)
			{
				v = matrix[im][j];
				matrix[im][j] = matrix[k][j];
				matrix[k][j] = v;
			}
			v = b[im];
			b[im] = b[k];
			b[k] = v;
		}
		for (i = k + 1; i < n; i++)
		{
			v = 1.0 * matrix[i][k] / matrix[k][k];
			matrix[i][k] = 0;
			b[i] = b[i] - v * b[k];
			if (v != 0)
				for (j = k + 1; j < n; j++)
				{
					matrix[i][j] = matrix[i][j] - v * matrix[k][j];
				}
		}
	}
}
// ����������� � �������
void AnsJordan(int n, double** matrix, double* b, double* x)
{
	double s = 0;
	x[n - 1] = 1.0 * b[n - 1] / matrix[n - 1][n - 1];
	for (int i = n - 2, j; 0 <= i; i--)
	{
		s = 0;
		for (j = i + 1; j < n; j++)
		{
			s = s + matrix[i][j] * x[j];
		}
		x[i] = 1.0 * (b[i] - s) / matrix[i][i];
	}
}

// ������� ���������� �������
void Nevyazka(int n, double** matrix, double* b, double* x) {

	double* e = (double*)malloc(n * sizeof(double));

	for (int i = 0; i < n; i++) {
		e[i] = 0;
		for (int j = 0; j < n; j++) {
			e[i] = e[i] + matrix[i][j] * x[j];
		}
	}

	for (int i = 0; i < n; i++) {
		e[i] = e[i] - b[i];
		e[i] = e[i] / b[i];
	}
	
	// ����� �������
	printf("�������: ");
	for (int i = 0; i < n; i++) {
		if (i % 2 != 0)
			printf(" %10.3e", e[i] - 1);
		else
			printf(" %10.3e", e[i]);
	}
}