#include <iostream>
using namespace std;

#define MAX 101

int N, M, K;
int A[MAX][MAX] = { 0, };
int B[MAX][MAX] = { 0, };
int C[MAX][MAX] = { 0, };

void makeary(int A[MAX][MAX], int N, int M);
void mult(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]);

int main()
{

	cin >> N >> M;
	makeary(A, N, M);

	cin >> M >> K;
	makeary(B, M, K);

	mult(A, B ,C);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

}

void makeary(int A[MAX][MAX], int N, int M)
{
	int n;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> n;
			A[i][j] = n;
		}
	}
}

void mult(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = 0; k < M; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}

		}
	}
}