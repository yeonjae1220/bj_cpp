
/*�ᱹ ���������ϰ� ���۸� ��
postorder�Լ� �̷� ����Լ� �����ϴ°� ���� ���ѵ�
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
			//�̺κ��� preorder�� ������ left�ʿ� �� �ִ°� inorder�����Ŷ� ������ index�� �̷��� �Ǵ°ǰ�?
			//�̺κ� �ް���
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







/*inorder ������ vector<int>�� �ް�, preorder ������ ���� ���� make_node �ؼ� 
vector<node*>�� ���� ���� ��� ���� ���� �߽����� inorder���� �¿�� vector�� �ɰ���
��͸� ��Ű�� Ʈ���� ������� �Ͽ����� ����Լ� �� ���� ���з� 
��Ʈ�������� leftChild�� ������ �Ǿ���.
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
//vector<int> input_inorder;// ��� ���� �޴� ������ ����� ��
//vector<Tnode*> input_preorder;
//
////vector<int> answer; //main �ۿ��� cout�� ��ȣ�մϴ�?
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
//		int index = findIndex(input_inorder, node->val); /*find(input_inorder.begin(), input_inorder.end(), node->val) - input_inorder.begin();*///�Ű������� �־��� node�� ������ inorder������ ��ġ ã��
//
//		//vector<int> div_L;
//		//div_L.resize(index + 1); // copy�Լ��� ������ Ȯ�������� �ʴµ�
//		//vector<int> div_R;
//		//div_R.resize(input_inorder.size() - index + 1);
//
//
//		//copy(input_inorder.begin(), input_inorder.begin() + index, div_L.begin());
//
//		//copy(input_inorder.begin() + index, input_inorder.end(), div_R.begin());//vector<int>�� �� �ɰ������� �𸣰���
//
//
//		//�̺κ� inorder�ε��� ���� �߶� ��� ó�� ����ϰ� ������ ����ǰ� �����
//		if (find(input_inorder.begin(), input_inorder.end(), input_preorder[pre_cnt]->val) != input_inorder.end())/*(find(input_inorder.begin(), input_inorder.begin() + index, input_preorder[pre_cnt]->val) != (input_inorder.begin() + index))*///div_L�� ���Ұ� ������?
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
//		cout << node->val << " ";//main�ܺο� �־ cout�� ��ȣ�մϴ�? ���� �̷���
//	}
//}
//
//
//
//int main()
//{
//	cin >> T;
//
//	//���⼭ preoreder �� inorder ���� �޾Ƽ� tree�� node�� ����� �ְ�, Ʈ���� �����Ѵ�.
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


/*Ʈ������ ��Ʈ �������� left���鸸 ��µǰ� ������*/

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
//vector<int> input_inorder;// ��� ���� �޴� ������ ����� ��
//vector<Tnode*> input_preorder;
//
////vector<int> answer; //main �ۿ��� cout�� ��ȣ�մϴ�?
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
//		int index = findIndex(input_inorder, node->val); /*find(input_inorder.begin(), input_inorder.end(), node->val) - input_inorder.begin();*///�Ű������� �־��� node�� ������ inorder������ ��ġ ã��
//
//		vector<int> div_L;
//		div_L.resize(index + 1); // copy�Լ��� ������ Ȯ�������� �ʴµ�
//		vector<int> div_R;
//		div_R.resize(input_inorder.size() - index + 1);
//
//
//		copy(input_inorder.begin(), input_inorder.begin() + index, div_L.begin());
//
//		copy(input_inorder.begin() + index, input_inorder.end(), div_R.begin());//vector<int>�� �� �ɰ������� �𸣰���
//
//		if (find(div_L.begin(), div_L.end(), input_preorder[pre_cnt]->val) != div_L.end())/*(find(input_inorder.begin(), input_inorder.begin() + index, input_preorder[pre_cnt]->val) != (input_inorder.begin() + index))*///div_L�� ���Ұ� ������?
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
//		cout << node->val << " ";//main�ܺο� �־ cout�� ��ȣ�մϴ�? ���� �̷���
//	}
//}
//
//
//
//int main()
//{
//	cin >> T;
//	
//	//���⼭ preoreder �� inorder ���� �޾Ƽ� tree�� node�� ����� �ְ�, Ʈ���� �����Ѵ�.
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

