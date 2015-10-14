/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/

void bfsLinkRight(TreeLinkNode* root)
{
	if (root == NULL)
		return;
	deque<TreeLinkNode*> wait_list;

	TreeLinkNode* tempNode = NULL;
	TreeLinkNode* rightSideNode = NULL;
	TreeLinkNode* levelAnchor = NULL;

	root->next = NULL;
	if (root->right != NULL)
	{
		wait_list.push_back(root->right);
		levelAnchor = root->right;
	}
	if (root->left != NULL)
	{
		wait_list.push_back(root->left);
		if (levelAnchor == NULL)
			levelAnchor = root->left;
	}

	while (wait_list.empty() == false)
	{

		tempNode = wait_list.front();
		wait_list.pop_front();
		if (tempNode == levelAnchor)
		{
			rightSideNode = NULL;
			levelAnchor = NULL;
		}
		tempNode->next = rightSideNode;
		if (tempNode->right != NULL)
		{
			wait_list.push_back(tempNode->right);
			if (levelAnchor == NULL)
				levelAnchor = tempNode->right;
		}
		if (tempNode->left != NULL)
		{
			wait_list.push_back(tempNode->left);
			if (levelAnchor == NULL)
				levelAnchor = tempNode->left;
		}
		rightSideNode = tempNode;
	}
}

class Solution {
public:
	void connect(TreeLinkNode *root) {

		bfsLinkRight(root);

		// no return
	}
};