/*
�ϴ� ������ ���� ����� �ʴ� ���̸� 1�� ���� ���� 0���� �ϴ� �迭�� ���� ����
���� Ǯ���� ��? ���� �Ἥ Ǯ���
*/

#include <iostream>
#include <vector>

#define MAX 102

using namespace std;

int N;
int cnt;
int x_mov[4] = { 0, 1, 0, -1 };
int y_mov[4] = { -1, 0, 1, 0 };


vector<int> answer;

void count_land(int Map[][MAX], int passed[][MAX], int w, int h);
void land_to_sea(int Map[][MAX], int passed[][MAX], int x, int y);
void arrang_map(int Map[][MAX], int Map_arrang[][MAX], int sink);

int Map[MAX][MAX] = { 0, };

int main()
{

	cin >> N;

	int max = 0;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			if (max < Map[i][j])
				max = Map[i][j];
		}
	}


	for (int sink = 0; sink <= max; sink++)//���� �κ��� 1�� ������ �κ��� 0����
	{
		cnt = 0;
		int Map_arrang[MAX][MAX] = { 0, };
		int passed[MAX][MAX] = { 0, };
		arrang_map(Map, Map_arrang, sink);



		count_land(Map_arrang, passed, N, N);

		answer.push_back(cnt);

	/*	cout << sink << " " << cnt << "\n";*/
	}

	int max_ans = -1;

	for (int i = 0; i < answer.size(); i++)
	{
		if (max_ans < answer[i])
			max_ans = answer[i];
	}

	cout << max_ans;


	return 0;
}



void count_land(int Map[][MAX], int passed[][MAX], int w, int h)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			//���� �ε����� ���̶�� �� ã��, �� �ش� �ε����� �� 0���� �����
			if (Map[i][j] == 0)
			{
				cnt++;
				Map[i][j] = 1;
				land_to_sea(Map, passed, j, i);
			}
		}
	}
}


void land_to_sea(int Map[][MAX], int passed[][MAX], int x, int y)
{

	passed[y][x] = 1;


	if (y - 1 > 0 && passed[y - 1][x] == 0 && Map[y - 1][x] == 0)//N���� �˻�
	{
		Map[y - 1][x] = 1;
		land_to_sea(Map, passed, x, y - 1);
	}
	
	if (x + 1 <= N && passed[y][x + 1] == 0 && Map[y][x + 1] == 0)//E���� �˻�
	{
		Map[y][x + 1] = 1;
		land_to_sea(Map, passed, x + 1, y);
	}
	
	if (y + 1 <= N && passed[y + 1][x] == 0 && Map[y + 1][x] == 0)//S���� �˻�
	{
		Map[y + 1][x] = 1;
		land_to_sea(Map, passed, x, y + 1);
	}
	
	if (x - 1 > 0 && passed[y][x - 1] == 0 && Map[y][x - 1] == 0)//W���� �˻�
	{
		Map[y][x - 1] = 1;
		land_to_sea(Map, passed, x - 1, y);
	}
	
}


void arrang_map(int Map[][MAX], int Map_arrang[][MAX], int sink)
{

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (sink >= Map[i][j])
				Map_arrang[i][j] = 1;
			else
				Map_arrang[i][j] = 0;
		}
	}


}