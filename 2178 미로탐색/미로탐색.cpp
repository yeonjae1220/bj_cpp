#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define WALL 0;
#define PATH 1;
#define PASSED 2;

int N, M, input_num;
vector<vector<int>> maze;
vector<vector<int>> check;
int cnt = 0;
string input;


void find_exit(int x, int y)
{
	check[x][y] = 1;


	if (x == N && y == M)
		cout << "find";

	
	if (x - 1 > 0 && maze[x - 1][y] == 1 && check[x][y-1] == 0)//W���� Ž��
		find_exit(x - 1, y);
	if (y + 1 < N && maze[x][y + 1] == 1 && check[x+1][y] == 0)//S���� Ž��
		find_exit(x, y + 1);
	if (x + 1 < M && maze[x + 1][y] == 1 && check[x][y+1] == 0)//E���� Ž��
		find_exit(x + 1, y);
	if (y - 1 > 0 && maze[x][y - 1] == 1 && check[x-1][y] == 0)//N���� Ž��
		find_exit(x, y - 1);



}


int main()
{

	cin >> N >> M;

	//string �߶� ���� �־��ش� maze 2���� �迭 �µθ��� 0 �־ �ѷ��ֱ�
	maze.resize(N+2, vector<int>(M+2, 0));
	check.resize(N + 2, vector<int>(M + 2, 0));

	for (int i = 1; i <= N; i++)
	{
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			maze[i][j+1] = input[j] - '0';
		}
	}

	for (int i = 0; i <= N+1; i++)
	{
		for (int j = 0; j <= M+1; j++)
		{
			cout << maze[i][j] << " ";
		}

		cout << "\n";
	}



	find_exit(1, 1);

	return 0;
}
















//�� ��ͷ� Ǯ��� �����Ѱ�
//int direct[4][2] = { {0, -1}, {0, 1}, {0, 1}, {-1, 0} };
//int dir = 0;
//
//void find_route(int x, int y)
//{
//
//	if (x == N && y == M)
//	{
//		cnt++;
//		cout << cnt;
//	}
//
//	for (int i = 0; i < 4; i++)
//	{
//		if (x + direct[i][0] > 0 && x + direct[i][0] <= N && y + direct[i][1] > 0 && y + direct[i][1])
//		{
//			if (maze[x + direct[i][0]][y + direct[i][1]] == 1)
//			{
//				cnt++;
//				find_route(x + direct[i][0], y + direct[i][1]);
//			}
//		}
//
//	}
//
//
//}