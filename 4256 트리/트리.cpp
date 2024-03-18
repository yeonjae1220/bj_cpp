
/*결국 구현실패하고 구글링 함
postorder함수 이런 재귀함수 구성하는게 아직 약한듯
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> preorder;
vector<int> inorder;

int T, n, input;


void postorder(int start, int end, int index)
{
	for (int i = start; i < end; i++)
	{
		if (preorder[index] == inorder[i])
		{
			postorder(start, i, index + 1);
			//이부분이 preorder도 어차피 left쪽에 가 있는건 inorder나눈거랑 같으니 index가 이렇게 되는건가?
			//이부분 햇갈림
			postorder(i+1, end, index + 1 + i - start);
			cout << preorder[index] << " ";
		}
	}
}


int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		preorder.clear();
		inorder.clear();

		for (int j = 0; j < n; j++)
		{
			cin >> input;
			preorder.push_back(input);

		}

		for (int k = 0; k < n; k++)
		{
			cin >> input;
			inorder.push_back(input);
		}

		postorder(0, n, 0);

		cout << "\n";
	}


	return 0;
}







/*inorder 순서를 vector<int>로 받고, preorder 순서를 받은 값을 make_node 해서 
vector<node*>로 만든 다음 노드 받은 값을 중심으로 inorder에서 좌우로 vector를 쪼개서
재귀를 시키며 트리를 만들려고 하였으나 재귀함수 논리 구성 실패로 
루트기준으로 leftChild만 나오게 되었다.
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <stdlib.h>
//
//using namespace std;
//
//int T, n, input;
//
//int ptr_cnt = 1;
//
//typedef struct node
//{
//	int val;
//	node* left;
//	node* right;
//}Tnode;
//
//Tnode* root;
//Tnode* temp;
//
//vector<int> input_inorder;// 얘는 순서 받는 용으로 만들어 봄
//vector<Tnode*> input_preorder;
//
////vector<int> answer; //main 밖에서 cout이 모호합니다?
//
//
//Tnode* make_node(int a/*Tnode* new_node*/)
//{
//	Tnode* temp = (Tnode*)malloc(sizeof(Tnode));
//	temp->val = a;
//	temp->left = NULL;
//	temp->right = NULL;
//
//	return temp;
//}
//
//int findIndex(vector<int> arr, int item)
//{
//	for (auto i = 0; i < arr.size(); i++)
//	{
//		if (arr[i] == item)
//			return i;
//	}
//}
//
//void make_tree(Tnode* node, /*vector<int> input_inorder, */int pre_cnt)
//{
//	if (pre_cnt < n && node != NULL)
//	{
//		int index = findIndex(input_inorder, node->val); /*find(input_inorder.begin(), input_inorder.end(), node->val) - input_inorder.begin();*///매개변수로 주어진 node의 값에서 inorder에서의 위치 찾기
//
//		//vector<int> div_L;
//		//div_L.resize(index + 1); // copy함수가 공간을 확보해주지 않는데
//		//vector<int> div_R;
//		//div_R.resize(input_inorder.size() - index + 1);
//
//
//		//copy(input_inorder.begin(), input_inorder.begin() + index, div_L.begin());
//
//		//copy(input_inorder.begin() + index, input_inorder.end(), div_R.begin());//vector<int>가 잘 쪼개졌는지 모르겠음
//
//
//		//이부분 inorder인덱스 보고 잘라서 재귀 처럼 깔끔하게 돌려서 연결되게 만들기
//		if (find(input_inorder.begin(), input_inorder.end(), input_preorder[pre_cnt]->val) != input_inorder.end())/*(find(input_inorder.begin(), input_inorder.begin() + index, input_preorder[pre_cnt]->val) != (input_inorder.begin() + index))*///div_L에 원소가 있으면?
//		{
//			node->left = input_preorder[pre_cnt];
//			make_tree(node->left, pre_cnt + 1);
//		}
//
//		//else if (find(input_inorder.begin(), input_inorder.end(), input_preorder[pre_cnt]->val) != input_inorder.end())/*(find(input_inorder.begin() + index + 1, input_inorder.end(), input_preorder[pre_cnt]->val) != (input_inorder.end()))*/
//		//{
//			node->right = input_preorder[pre_cnt];
//			make_tree(node->right, pre_cnt + 1);
//		/*}*/
//	}
//
//}
//
//
//void postorder(node* node)
//{
//	if (node)
//	{
//		postorder(node->left);
//		postorder(node->right);
//		cout << node->val << " ";//main외부에 있어서 cout이 모호합니다? 원래 이런가
//	}
//}
//
//
//
//int main()
//{
//	cin >> T;
//
//	//여기서 preoreder 와 inorder 값을 받아서 tree의 node를 만들어 주고, 트리를 생성한다.
//	for (int i = 0; i < T; i++)
//	{
//		input_inorder.clear();
//		input_preorder.clear();
//		cin >> n;
//
//		for (int j = 0; j < n; j++)
//		{
//			cin >> input;
//			temp = make_node(input);
//			input_preorder.push_back(temp);
//
//		}
//
//		for (int k = 0; k < n; k++)
//		{
//			cin >> input;
//			/*temp = make_node(input);*/
//			input_inorder.push_back(input);
//		}
//
//
//		root = input_preorder[0];
//
//		make_tree(root, /*input_inorder,*/ ptr_cnt);
//
//
//		postorder(root);
//
//		cout << "\n";
//		ptr_cnt = 1;
//	}
//
//
//	return 0;
//}


/*트리에서 루트 기준으로 left노드들만 출력되고 끝난다*/

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <stdlib.h>
//
//using namespace std;
//
//int T, n, input;
//
//
//
//typedef struct node
//{
//	int val;
//	node* left;
//	node* right;
//}Tnode;
//
//Tnode* root;
//Tnode* temp;
//
//vector<int> input_inorder;// 얘는 순서 받는 용으로 만들어 봄
//vector<Tnode*> input_preorder;
//
////vector<int> answer; //main 밖에서 cout이 모호합니다?
//
//
//Tnode* make_node(int a/*Tnode* new_node*/)
//{
//	Tnode* temp = (Tnode*)malloc(sizeof(Tnode));
//	temp->val = a;
//	temp->left = NULL;
//	temp->right = NULL;
//
//	return temp;
//}
//
//int findIndex(vector<int> arr, int item)
//{
//	for (auto i = 0; i < arr.size(); i++)
//	{
//		if (arr[i] == item)
//			return i;
//	}
//}
//
//void make_tree(Tnode* node, vector<int> input_inorder, int pre_cnt)
//{
//	if(pre_cnt < n && node != NULL)
//	{
//		int index = findIndex(input_inorder, node->val); /*find(input_inorder.begin(), input_inorder.end(), node->val) - input_inorder.begin();*///매개변수로 주어진 node의 값에서 inorder에서의 위치 찾기
//
//		vector<int> div_L;
//		div_L.resize(index + 1); // copy함수가 공간을 확보해주지 않는데
//		vector<int> div_R;
//		div_R.resize(input_inorder.size() - index + 1);
//
//
//		copy(input_inorder.begin(), input_inorder.begin() + index, div_L.begin());
//
//		copy(input_inorder.begin() + index, input_inorder.end(), div_R.begin());//vector<int>가 잘 쪼개졌는지 모르겠음
//
//		if (find(div_L.begin(), div_L.end(), input_preorder[pre_cnt]->val) != div_L.end())/*(find(input_inorder.begin(), input_inorder.begin() + index, input_preorder[pre_cnt]->val) != (input_inorder.begin() + index))*///div_L에 원소가 있으면?
//		{
//			node->left = input_preorder[pre_cnt];
//			make_tree(node->left, div_L, pre_cnt+1);
//		}
//
//		if (find(div_R.begin(), div_R.end(), input_preorder[pre_cnt]->val) != div_R.end())/*(find(input_inorder.begin() + index + 1, input_inorder.end(), input_preorder[pre_cnt]->val) != (input_inorder.end()))*/
//		{
//			node->right = input_preorder[pre_cnt];
//			make_tree(node->right, div_R, pre_cnt+1);
//		}
//	}
//
//}
//
//
//void postorder(node* node)
//{
//	if (node)
//	{
//		postorder(node->left);
//		postorder(node->right);
//		cout << node->val << " ";//main외부에 있어서 cout이 모호합니다? 원래 이런가
//	}
//}
//
//
//
//int main()
//{
//	cin >> T;
//	
//	//여기서 preoreder 와 inorder 값을 받아서 tree의 node를 만들어 주고, 트리를 생성한다.
//	for (int i = 0; i < T; i++)
//	{
//		input_inorder.clear();
//		input_preorder.clear();
//		cin >> n;
//
//		for (int j = 0; j < n; j++)
//		{
//			cin >> input;
//			temp = make_node(input);
//			input_preorder.push_back(temp);
//			
//		}
//
//		for (int k = 0; k < n; k++)
//		{
//			cin >> input;
//			/*temp = make_node(input);*/
//			input_inorder.push_back(input);
//		}
//
//
//		root = input_preorder[0];
//
//		make_tree(root, input_inorder, 1);
//
//
//		postorder(root);
//
//		cout << "\n";
//		
//	}
//
//
//	return 0;
//}

///////////

