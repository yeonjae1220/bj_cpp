#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <map>
using namespace std;

//노드 구조체 생성
typedef struct NODE
{
	int data;
	struct NODE* link;
}node;

//그래프 배열 생성
vector<node*> adjList;

map<int, int> check_virus;
int vertex_num, edge_num;
int vertex, edge;
int cnt = 0;

//노드 생성 함수
node* make_node(int edge)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = edge;
	temp->link = NULL;
	return temp;
}

//생성한 노드를 adjList에 집어넣어주는 함수
void input_list(int root, node* input)
{

	input->link = adjList[root];
	adjList[root] = input;

}

vector<int> checking;

void fuc1(node* root)
{
	while (1)
	{
		if (root == NULL)
			break;
		else
		{
			if (root->data != 1 && !(check_virus.find(root->data) != check_virus.end()))//map에 없을 때
			{
				check_virus.insert({ root->data, 1 });
			}
			
			root = root->link;
		}
	}

	for (auto iter = check_virus.begin(); iter != check_virus.end(); iter++)
	{
		int k = 1;
		for (int i = 0; i < checking.size(); i++)
		{
			if (checking[i] == iter->first)
			{
				k = 0;
				break;
			}
		}

		if (k == 1)
		{
			checking.push_back(iter->first);
			fuc1(adjList[iter->first]);
		}
		
	}


}



int main()
{

	cin >> vertex_num >> edge_num;

	//adjList원소들 NULL로 초기화
	for (int i = 0; i <= vertex_num; i++)
	{
		adjList.push_back(NULL);
		/*check_virus.push_back(0);*/
	}

	for (int i = 0; i < edge_num; i++)
	{
		cin >> vertex >> edge;
		node* temp_edge_node = make_node(edge);
		node* temp_vertex_node = make_node(vertex);
		input_list(vertex, temp_edge_node);
		input_list(edge, temp_vertex_node);
	}

	fuc1(adjList[1]);

	for (auto iter = check_virus.begin(); iter != check_virus.end(); iter++)
	{
		if (iter->second == 1)
			cnt++;
	}

	cout << cnt;


	return 0;
}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//typedef struct NODE
//{
//	int com;
//	NODE* link;
//}node;
//
//vector<node*> graph;
//
//int com_num, n, input1, input2;
//int cnt = 0;
//
//
//
//node* make_node(int data)
//{
//	node* temp = (node*)malloc(sizeof(node));
//	temp->com = data;
//	temp->link = NULL;
//	return temp;
//}
//
//void make_graph(int index, node* input)
//{
//	input->link = graph[index];
//	graph[index] = input;
//}
//
//vector<int> cnt_com;
//
//void is_linked(int n)
//{
//	//node* root = graph[0];
//	
//	while (1)
//	{
//		cnt_com[graph[n]->com] = 1;
//		graph[n] = graph[n]->link;
//		if (graph[n] == NULL)
//			break;
//		else
//			is_linked(graph[n]->com);
//	}
//
//	
//
//}
//
//
//
//
//int main()
//{
//	cin >> com_num >> n;
//
//	graph.resize(n+2);
//	cnt_com.resize(com_num+1);//0으로 초기화??
//
//	for (int i = 1; i <= com_num; i++)
//	{
//		cnt_com[i] = 0;
//	}
//
//
//	for (int i = 0; i < graph.size(); i++)
//	{
//		graph[i] = NULL;
//	}
//
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> input1 >> input2;
//		node* temp1 = make_node(input2);
//		node* temp2 = make_node(input1);
//		make_graph(input1, temp1);
//		make_graph(input2, temp2);
//
//	}
//
//
//	is_linked(1);
//
//	for (int i = 0; i < cnt_com.size(); i++)
//	{
//		if (cnt_com[i] != 0)
//			cnt++;
//	}
//
//	cout << cnt;
//
//
//
//	
//
//
//
//	return 0;
//}