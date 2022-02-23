#include <iostream>

using namespace std;

void oper_qr(int* q, int* r, int* qr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (q[i] == 1 ^ r[i] == 1)
			qr[i] = 1;
		else qr[i] = 0;
	}
}
void oper_pqr(int* qr, int* p, int* pqr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i] == 1 && qr[i] == 1)
		{
			pqr[i] = 1;
		}
		else
		{
			pqr[i] = 0;
		}
	}
}
int main()
{
	const int n = 8;
	int p[n] = { 0,0,0,0,1,1,1,1 };
	int q[n] = { 0,0,1,1,0,0,1,1 };
	int r[n] = { 0,1,0,1,0,1,0,1 };
	int qr[n];
	int pqr[n];
	oper_qr(q, r, qr, n);
	oper_pqr(qr, p, pqr, n);
	cout << "           p ^ (q xor r)" << endl << endl;;
	cout << "---------------------------------------" << endl;
	cout << "| p | q | r | q xor r | p ^ (q xor r) |" << endl;
	cout << "---------------------------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "| " << p[i] << " | " << q[i] << " | " << r[i] << " |    " << qr[i] << "    |       " << pqr[i] << "       |" << endl;
	}
	cout << "---------------------------------------" << endl;
}