#include <iostream>
#include <vector>

using namespace std;


int mov_x[4] = { 0, 1, 0, -1 };
int mov_y[4] = { -1, 0, 1, 0 };

int R, C;
//vector<vector<int>> Map(R, vector<int>(C, -1));
char Map[21][21];
int visited[26] = { 0, };

int answer = 0;

void find_answer(int x, int y, int cnt)
{
	if (answer < cnt)
		answer = cnt;

	for (int i = 0; i < 4; i++)
	{
		int x_temp = x + mov_x[i];
		int y_temp = y + mov_y[i];

		if (x_temp >= 0 && y_temp >= 0 && x_temp < C && y_temp < R && visited[Map[y_temp][x_temp] - 'A'] == 0)
		{
			visited[Map[y_temp][x_temp] - 'A'] = 1;
			find_answer(x_temp, y_temp, cnt + 1);
			visited[Map[y_temp][x_temp] - 'A'] = 0;
		}
	}
}



int main()
{
	
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> Map[i][j];
		}
	}

	visited[Map[0][0] - 'A'] = 1;
	find_answer(0, 0, 1);

	cout << answer;







	return 0;
}