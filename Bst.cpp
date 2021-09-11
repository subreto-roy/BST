#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;


};
Node* newNode(int item)
{
	Node* temp = new Node;

	temp->data = item;
	temp->left = temp->right = NULL;

	return temp;
}
void printPostorder(Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);


    cout << node->data << " ";
}


void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}


void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";

    printPreorder(node->left);
    printPreorder(node->right);
}

bool printAncestors(Node *root,int target)
{

    if (root == NULL)
        return false;
    if(root->data==target)
        return true;
    if(printAncestors(root->left,target)||printAncestors(root->right,target))
    {
        cout<<root->data<<" ";
        return true;
    }
    return false;
}
bool printDescedent(Node *root,int t)
{

   if (root == NULL)
        return false;
      printDescedent(root->left,t);

    if(root->data!=t)
        cout<<root->data<< " ";
    printDescedent(root->right,t);


}

int size(Node* Node)
{
    if(Node==NULL)
    {
        return 0;
    }
    else
    {
        return(size(Node->left)+1+size(Node->right));
    }
}

void printLeafNodes(Node *root)
{

    if(!root)
        return;

    if(!root->left && !root->right)
    {
        cout<<root->data<< " ";

        return;
    }
    if(root->left)
    {
        printLeafNodes(root->left);

    }
    if(root->right)
    {
        printLeafNodes(root->right);
    }
}


int findDepth(Node* root, int x)
{

	if (root == NULL)
		return -1;


	int dist = -1;


	if ((root->data == x)|| (dist = findDepth(root->left, x)) >= 0 || (dist = findDepth(root->right, x)) >= 0)


		return dist + 1;

	return dist;
}


int findHeightUtil(Node* root, int x,int& height)
{

	if (root == NULL) {
		return -1;
	}


	int leftHeight = findHeightUtil(
		root->left, x, height);

	int rightHeight
		= findHeightUtil(
			root->right, x, height);

	int ans = max(leftHeight, rightHeight) + 1;


	if (root->data == x)
		height = ans;

	return ans;
}


int findHeight(Node* root, int x)
{

	int h = -1;


	int maxHeight = findHeightUtil(root, x, h);


	return h;
}

int main()
{

	Node* root = newNode(5);
	root->left = newNode(10);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->left->right = newNode(25);
	root->left->right->right = newNode(45);
	root->right->left = newNode(30);
	root->right->right = newNode(35);

    cout << "(a) Preorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\n\n Inorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\n\n Postorder traversal of binary tree is \n";
    printPostorder(root);
    printf("\n");
	int k;
	printf("enter node\n");
	scanf("%d",&k);
    cout << "\n\n(b) Depth: "<< findDepth(root, k) << "\n";
    cout << "\n\n(c) Height: " << findHeight(root, k);
	printf("\n\n(d)Enter Ancestor node:\n");
	int l;
	scanf("%d",&l);
	printAncestors(root, l);
	printf("\n\n(e)Enter Descedent node\n");
	int m;
	scanf("%d",&m);
    printDescedent(root,m);

    cout<<"\n\n(f) size of the tree is " << size(root);
    printf("\n\n(g) LeafNode: \n");

    printLeafNodes(root);
	return 0;
}
