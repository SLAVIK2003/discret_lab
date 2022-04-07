#include <iostream>
#include <iomanip>

using namespace std;

int fact(int x)
{
	int res = 1;
	for (int i = 1; i <= x; i++)
	{
		res = res * i;
	}
	return res;
}

int main()
{
	//TASK 1
	int n = 6;
	int r = 5;
	int first = fact(n);
	int sec = fact(n - r);
	int a = first / sec;
	cout << "Task 1: " << endl << "n = " << n << endl << "r = " << r << endl << "A = " << a << endl << endl;

	//TASK 2
	int i = 1;
	n = i + 5;
	int** F = new int* [n];
	for (int j = 0; j < n; j++)
		F[j] = new int[n];

	int* B = new int[n];

	cout << "Task 2:" << endl;

	//stirling
	for (int j = 0; j < n; j++)
	{
		F[j][0] = 1;
		F[j][j] = 1;
	}

	for (int j = 2; j < n; j++)
		for (int k = 1; k < j; k++)
		{
			F[j][k] = F[j - 1][k - 1] + (k + 1) * F[j - 1][k];
		}
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++)
			if (F[j][k] < 0)
				F[j][k] = 0;

	//BELL
	for (int j = 0; j < n; j++)
		B[j] = 0;

	for (int j = 0; j < n; j++)
		for (int k = 0; k < j; k++)
		{
			B[j] = B[j] + F[j][k];
		}


	//print
	cout << "i = " << i << endl << "n = " << n << endl;
	cout << " |";
	for (int i = 0; i < n; i++)
		cout << setw(6) << i + 1 << "|";
	cout << setw(6) << "BELL" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "|";
		for (int j = 0; j < n; j++)
		{
			if (F[i][j] == 0)
				cout << setw(6) << "" << "|";

			else cout << setw(6) << F[i][j] << "|";
		}
		cout << setw(6) << B[i];
		cout << endl;
	}
	cout << endl;
}