#include <iostream>
using namespace std;

#define MAX 1000


int N, input;
int ary[MAX][MAX];

int cnt_w = 0, cnt_b = 0;

int count_paper(int ary[MAX][MAX], int n);
int check_ary(int ary[MAX][MAX], int n);

int main()
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			ary[i][j] = input;
		}
	}

	count_paper(ary, N);

	cout << cnt_w << endl;
	cout << cnt_b << endl;

	return 0;
}

int count_paper(int ary[MAX][MAX], int n)
{
	int color = check_ary(ary, n);

	if (color == 1)
	{
		cnt_w++;
		return 0;
	}
		
	else if (color == 2)
	{
		cnt_b++;
		return 0;
	}

	else
	{
		int n_div = n / 2;
		int ary1[MAX][MAX];
		int ary2[MAX][MAX];
		int ary3[MAX][MAX];
		int ary4[MAX][MAX];

		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				ary1[i][j] = ary[i][j + n / 2];
				ary2[i][j] = ary[i][j];
				ary3[i][j] = ary[i + n / 2][j];
				ary4[i][j] = ary[i + n / 2][j + n / 2];
				
			}
		}

		count_paper(ary1, n_div);
		count_paper(ary2, n_div);
		count_paper(ary3, n_div);
		count_paper(ary4, n_div);

	}

	return 0;

}

int check_ary(int ary[MAX][MAX], int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ary[0][0] != ary[i][j])
				return 0;
		}
	}

	if (ary[0][0] == 0)
		return 1;

	else
		return 2;

}

