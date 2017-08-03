#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* NewNode(int data);
int Lookup(int data, Node* node);
Node* Insert(int data, Node* node);
Node* Delete(int data, Node* node, Node* topNode);
int Size(Node* node);
int MaxDepth(Node* node);
int MinValue(Node* node);
int MaxValue(Node* node);
void PrintTree(Node* node);
void PrintPostorder(Node* node);
int HasPathSum(Node* node, int sum);
void PrintPaths(Node* node);
void PrintPathsRecur(Node* node, int nums[], int arrayLength);
void Mirror(Node* node);
void DoubleTree(Node* node);
int SameTree(Node* nodeA, Node* nodeB);
int CountTrees(int numKeys);
int CountTreesRecur(int currentNumber, int maxNum);
int IsBST(Node* node);
int IsBST2(Node* node);
int IsBSTRecur(Node* node, int min, int max);


int main()
{
	
	Node* node = Insert(2, NULL);
	Insert(1, node);
	Insert(3, node);
	Insert(-1, node);
	Insert(4, node);
	Insert(5, node);
	Insert(-7, node);
	Insert(4, node);
	Insert(4, node);
	Insert(-10, node);
	Insert(-15, node);
	Insert(-9, node);
	Insert(-8, node);
	Insert(15, node);
	Insert(1, node);

	//node->right->right->right->right = NewNode(1);
	//node->right->left = NewNode(10);
	//node->right->right->left->right = NewNode(1);
	//node->left->right = NewNode(3);
	//node->left->left->left->right = NewNode(15);

	Node* nodeB = Insert(2, NULL);
	Insert(1, nodeB);
	Insert(3, nodeB);
	Insert(-1, nodeB);
	Insert(4, nodeB);
	Insert(5, nodeB);
	Insert(-7, nodeB);
	Insert(4, nodeB);
	Insert(4, nodeB);
	Insert(-10, nodeB);
	Insert(-15, nodeB);
	Insert(-9, nodeB);
	Insert(-8, nodeB);

	Node* nodeC = Insert(6, NULL);
	Insert(3, nodeC);
	Insert(7, nodeC);
	Insert(4, nodeC);
	Insert(5, nodeC);
	Insert(1, nodeC);
	Insert(2, nodeC);

	//cout << "suh dood" << endl;
	/*cout << node->data << endl;
	cout << node->left->data << endl;
	cout << node->left->left->data << endl;
	cout << node->left->left->left->data << endl;
	cout << node->left->left->left->left->data << endl;
	cout << node->left->left->left->left->right->data << endl;
	cout << node->left->left->left->left->right->right->data << endl;
	cout << node->right->data << endl;
	cout << node->right->right->data << endl;
	cout << node->right->right->left->data << endl;
	cout << node->right->right->left->left->data << endl;
	cout << node->right->right->right->data << endl;*/
	cout << "\n\nSize: " << Size(node) << endl;
	cout << "Max Depth: " << MaxDepth(node) << endl;
	cout << "Min Value: " << MinValue(node) << endl;
	cout << "Max Value: " << MaxValue(node) << endl;
	PrintTree(node);
	cout << endl;
	PrintPostorder(node);
	cout << endl;
	int sum = 29;
	cout << "Contains sum of " << sum << " along any path: " << HasPathSum(node, sum) << endl;
	PrintPaths(node);
	Mirror(node);
	PrintPaths(node);
	Mirror(node);
	//DoubleTree(node);
	//PrintPaths(node);
	cout << "Trees the same: " << SameTree(node, nodeB) << endl;
	int amountOfUniqueNums = 3;
	cout << "Number of possible trees when there are " << amountOfUniqueNums << " unique numbers: " << CountTrees(amountOfUniqueNums) << endl;
	cout << "Is BST: " << IsBST2(node) << endl;
	node = Delete(2, node, node);
	PrintTree(node);
	cout << endl;
	PrintTree(nodeC);
	cout << endl;
	Delete(3, nodeC, nodeC);
	PrintTree(nodeC);
	//system("pause");
}

Node* NewNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int Lookup(int data, Node* node)
{
	if (data == node->data)
	{
		return true;
	}
	if (node == NULL)
	{
		return false;
	}
	if (data > node->data)
	{
		return Lookup(data, node->right);
	}
	else
	{
		return Lookup(data, node->left);
	}
}

Node* Insert(int data, Node* node)
{
	if (node == NULL)
	{
		return NewNode(data);
	}
	if (data > node->data)
	{
		node->right = Insert(data, node->right);
	}
	else
	{
		node->left = Insert(data, node->left);
	}
	return node;
}

Node* Delete(int data, Node* node, Node* topNode)
{
	if (node == NULL)
	{
		return topNode;
	}
	if (node->data == data && node == topNode)
	{
		if (node->left != NULL)
		{

			Node* temp = node->left;
			Node* previous = temp;
			while (temp->right != NULL)
			{
				previous = temp;
				temp = temp->right;
			}
			previous->right = NULL;
			topNode->data = temp->data;
			return topNode;
		}
		else
		{
			return node->right;
		}
	}
	if (node->left != NULL)
	{
		if (node->left->data == data)
		{
			if (node->left->left != NULL)
			{
				node->left->data = node->left->left->data;
				node->left->left = NULL;
			}
			else if (node->left->right != NULL)
			{
				node->left->data = node->left->right->data;
				node->left->right = NULL;
			}
			else
			{
				node->left = NULL;
			}
			return topNode;
		}
	}
	if (node->right != NULL)
	{
		if (node->right->data == data)
		{
			if (node->right->left != NULL)
			{
				node->right->data = node->right->left->data;
				node->right->left = NULL;
			}
			else if (node->right->right != NULL)
			{
				node->right->data = node->right->right->data;
				node->right->right = NULL;
			}
			else
			{
				node->right = NULL;
			}
			return topNode;
		}
	}
	

	Delete(data, node->left, topNode);
	Delete(data, node->right, topNode);

	return topNode;
}


int Size(Node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	int size = 1;
	size += Size(node->left);
	size += Size(node->right);

	return size;
}

int MaxDepth(Node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	int leftDepth = 1;
	leftDepth += MaxDepth(node->left);
	int rightDepth = 1;
	rightDepth += MaxDepth(node->right);
	if (leftDepth > rightDepth)
	{
		return leftDepth;
	}
	return rightDepth;
}

int MinValue(Node* node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}

	return node->data;
}

int MaxValue(Node* node)
{
	while (node->right != NULL)
	{
		node = node->right;
	}

	return node->data;
}

void PrintTree(Node* node)
{
	if (node->left != NULL)
	{
		PrintTree(node->left);
	}
	cout << node->data << " ";
	if (node->right != NULL)
	{
		PrintTree(node->right);
	}
}

void PrintPostorder(Node* node)
{
	if (node->left != NULL)
	{
		PrintPostorder(node->left);
	}
	if (node->right != NULL)
	{
		PrintPostorder(node->right);
	}

	cout << node->data << " ";
}

int HasPathSum(Node* node, int sum)
{
	int isSumZero = 0;
	if (node == NULL)
	{
		return sum == 0;
	}
	sum -= node->data;
	isSumZero = HasPathSum(node->left, sum);
	if (isSumZero == 1)
	{
		return 1;
	}
	isSumZero = HasPathSum(node->right, sum);
	return isSumZero;

	//Solution online:
	//return(HasPathSum(node->left, sum) || HasPathSum(node->right, sum));
}

void PrintPaths(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	cout << "All Possible Paths: " << endl;
	int nums[1] = { node->data };

	if (node->left != NULL)
	{
		PrintPathsRecur(node->left, nums, 1);
	}
	if (node->right != NULL)
	{
		PrintPathsRecur(node->right, nums, 1);
	}
}

void PrintPathsRecur(Node* node, int nums[], int arrayLength)
{
	int* newNums = new int[arrayLength + 1];

	for (int i = 0; i < arrayLength; i++)
	{
		newNums[i] = nums[i];
	}

	newNums[arrayLength] = node->data;
	arrayLength++;
	if (node->left != NULL)
	{
		PrintPathsRecur(node->left, newNums, arrayLength);
		//arrayLength++;
	}
	if (node->right != NULL)
	{
		PrintPathsRecur(node->right, newNums, arrayLength);
	}

	if (node->left == NULL && node->right == NULL)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			cout << newNums[i] << " ";
		}
		cout << endl;
		return;
	}
}

void Mirror(Node* node)
{
	Node* temp = node->left;
	node->left = node->right;
	node->right = temp;

	if (node->left != NULL)
	{
		Mirror(node->left);
	}
	if (node->right != NULL)
	{
		Mirror(node->right);
	}
}

void DoubleTree(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	Node* temp = node->left;
	node->left = NewNode(node->data);
	node->left->left = temp;

	if (node->left != NULL)
	{
		if (node->left->left != NULL)
		{
			DoubleTree(node->left->left);
		}
	}
	DoubleTree(node->right);
}

int SameTree(Node* nodeA, Node* nodeB)
{
	if (nodeA == NULL && nodeB == NULL)
	{
		return 1;
	}
	if (nodeA == NULL || nodeB == NULL || nodeA->data != nodeB->data)
	{
		return 0;
	}

	if (SameTree(nodeA->left, nodeB->left) && SameTree(nodeA->right, nodeB->right))
	{
		return 1;
	}
	
	return 0;
}

int CountTrees(int numKeys)
{
	int count = 0;
	for (int i = 1; i < numKeys; i++)
	{
		count += CountTreesRecur(i, numKeys);
	}
	return count;
}

int CountTreesRecur(int startingNumber, int maxNum)
{
	if (startingNumber == maxNum)
	{
		return 1;
	}
	int count = 0;
	count += maxNum - startingNumber;
	startingNumber++;

	
	count += CountTreesRecur(startingNumber, maxNum);

	return count;
}

int IsBST(Node* node)
{
	Node* currentNode = node;
	int max = node->data;
	int min = MinValue(node);                     

	while (currentNode->left != NULL)
	{
		currentNode = currentNode->left;
		if (currentNode->data > max || currentNode->data < min)
		{
			return 0;
		}
	}
	currentNode = node;
	//while(currentNode->left)
}

int IsBST2(Node* node)
{
	return IsBSTRecur(node->left, MinValue(node), node->data) ? IsBSTRecur(node->right, node->data, MaxValue(node)) : 0;
}

int IsBSTRecur(Node* node, int min, int max)
{
	if (node == NULL)
	{
		return 1;
	}
	if (node->data < min || node->data > max)
	{
		return 0;
	}
	bool isBST = 0;
	isBST = IsBSTRecur(node->left, min, node->data);
	if (!isBST)
	{
		return isBST;
	}
	isBST = IsBSTRecur(node->right, node->data, max);
	return isBST;
}

//if (node == NULL)
//{
//	return 1;
//}
//int bst = 0;
//if (node->data >= MinValue(node) && node->data <= MaxValue(node))
//{
//	bst = IsBST(node->left);
//	if (bst == 0)
//	{
//		return bst;
//	}
//	bst = IsBST(node->right);
//}
//
//return bst;