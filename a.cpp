#include "GetMatrix.h"
#include <time.h>

int main(int argc, char* argv[]) //argc - ���-�� ����������; argv - ���������
{
	setlocale(LC_ALL, "Russian");

	// ��������� ������, ���� �� ������� ���������
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

	stringstream convert(argv[1]); // �������������� �� ������ � �������������
	if (!(convert >> n)) // E��� ������ �������������, �� ����������� n = -1;
		n = -1;

	stringstream convert1(argv[2]); // �������������� �� ������ � �������������
	if (!(convert1 >> m)) // E��� ������ �������������, �� ����������� m = -1;
		m = -1;

	stringstream convert2(argv[3]); // �������������� �� ������ � �������������
	if (!(convert2 >> k)) // E��� ������ �������������, �� ����������� k = -1;
		k = -1;

	if ((n == -1) || (m == -1) || (k == -1)) { // E��� n ��� m ��� k �� ���������������
		printf("������!\n"); // ������� ������
		return -1;
	}

	matrix = (double**)malloc(n * sizeof(double)); // ��������� ������ ��� �������
	b = (double*)malloc(n * sizeof(double)); // ��������� ������ ��� �������
	x = (double*)malloc(n * sizeof(double)); // ��������� ������ ��� ����������

	MakeMatrix(n, k, argv[4], matrix, b); // ������� ��������� �������

	printf("\n�������� �������:\r\n");
	ShowMatrix(n, m, matrix, b); // ������� ������ �������
	
	time_t start, stop;
	time(&start);

	Solution(n, matrix, b, x);// ����� ������� ������� �������� �������
	time(&stop);

	printf("\n��������������� �������:\r\n");
	ShowMatrix(n, m, matrix, b); // ������� ������ �������
	printf("\n");

	printf("����������:\r\n");
	ShowMatrix(n, m, x); // ������������� ������� ������ ������� ��� ������ �������
	printf("�����: %f\n", difftime(stop, start));

	printf("���������:\n");
	Nevyazka(n, matrix, b, x); // ������� ���������� �������

	free((void*)matrix); // ������������ ������
	free((void*)b);
	free((void*)x);
		
	return 0;
}