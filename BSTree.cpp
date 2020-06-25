#include "BSTree.h"

/* Constructors */
/* Default constructor */
BSTree::BSTree()
{
	root = 0;
}

BSTree::~BSTree()
{
	//deleteSubTree(root);
}

void BSTree::insert(const string & newString)
{
	Node* insertion;
	Node* curr;

	insertion = new Node(newString);
	curr = root;

	if (root == 0)
	{
		root = insertion;
	}
	else
	{
		while (curr != 0)
		{
			if (*curr == *insertion)
			{
				curr->increaseCount();
				return;
			
			}

			if (*curr > * insertion)
			{
				if (curr->getLeft() == 0)
				{
					curr->setLeft(insertion);
					return;
				}
				else
				{
					curr = curr->getLeft();
				}
			}
			else
			{
				if (curr->getRight() == 0)
				{
					curr->setRight(insertion);
					return;
				}
				else
				{
					curr = curr->getRight();
				}
				
			}
		}

	}

}

void BSTree::remove(const string & key)
{
	Node* curr;

	curr = root;

	if (search(key) == false)
	{
		//throw std::runtime_error("Deleting from an non-existent item from tree");
		return;
	}

	else
	{
		while (*curr != key)
		{

			if (*curr > key)
			{
				curr = curr->getLeft();
			}

			if (*curr < key)
			{
				curr = curr->getRight();
			}
		}

		if (curr->getCount() > 1)
		{
			curr->decreaseCount();
			return;
		}

		if (curr->getCount() == 1)
		{
			remove(curr, key);
		}
	}
}

bool BSTree::search(const std::string & key) const
{
	bool found;

	found = search(root, key);

	return found;
}

string BSTree::largest() const
{
	if (root == 0)
	{
		return "";
	}
	Node* curr;
	curr = root;

	while (curr->getRight() != 0)
	{
		curr = curr->getRight();
	}

	return curr->getData();
}

string BSTree::smallest() const
{
	if (root == 0)
	{
		return "";
	}

	Node* curr;
	curr = root;

	while (curr->getLeft() != 0)
	{
		curr = curr->getLeft();
	}

	return curr->getData();
}

int BSTree::height(const string & key) const
{
	int h;
	Node* curr;
	curr = root;

	if (search(key))
	{
		
		while (*curr != key)
		{
			if (*curr > key)
			{
				curr = curr->getLeft();
			}
			if (*curr < key)
			{
				curr = curr->getRight();
			}
		}
	}

	h = heightRecurs(curr, key);

	return h;
}

void BSTree::preOrder() const
{
	preOrder(root);
}
void BSTree::postOrder() const
{
	postOrder(root);
}
void BSTree::inOrder() const
{
	inOrder(root);
}

void BSTree::preOrder(Node * curr) const
{
	if (curr != 0)
	{
		curr->printNode();
		std::cout << ", ";
		preOrder(curr->getLeft());
		preOrder(curr->getRight());
	}
}

void BSTree::postOrder(Node * curr) const
{
	if (curr != 0)
	{
		postOrder(curr->getLeft());
		postOrder(curr->getRight());
		curr->printNode();
		std::cout << ", ";
	}
}

void BSTree::inOrder(Node * curr) const
{
	if (curr != 0)
	{
		inOrder(curr->getLeft());
		curr->printNode();
		std::cout << ", ";
		inOrder(curr->getRight());
	}

}

void BSTree::deleteSubTree(Node * curr)
{
	if (curr != 0)
	{
		deleteSubTree(curr->getLeft());
		deleteSubTree(curr->getRight());
		delete curr;
	}
}

bool BSTree::search(Node * curr, const std::string & key) const
{
	if (curr == 0)
		return false;
	else if (*curr == key)
	{
		return true;
	}
	else if (*curr > key)
	{
		return search(curr->getLeft(), key);
	}
	else
	{
		return search(curr->getRight(), key);
	}
}

void BSTree::remove(Node * curr, const string & key)
{
	Node* temp;
	if (leaf(curr))
	{
		removeLeaf(curr);
		delete curr;
	}
	else
	{
		if (curr->getLeft() != 0)
		{
			temp = findMax(curr->getLeft());
			curr->setData(temp->getData());
			curr->setCount(temp->getCount());
			//curr = temp;
			remove(temp, key);
		}
		else
		{
			temp = findMin(curr->getRight());
			curr->setData(temp->getData());
			curr->setCount(temp->getCount());
			//curr = temp;
			remove(temp, key);
		}
	}	
}

Node* BSTree::findMax(Node * curr)
{
	Node* max;
	Node* temp = curr;

	max = curr;

	while (temp != nullptr)
	{

		if (*temp > *max)
		{
			max = temp;
		}

		temp = temp->getRight();
	}

	return max;
}

Node* BSTree::findMin(Node * curr)
{
	Node* min;
	Node* temp = curr;

	min = curr;

	while (temp != nullptr)
	{

		if (*temp < * min)
		{
			min = temp;
		}

		temp = temp->getLeft();
	}

	return min;
}

bool BSTree::leaf(Node * curr)
{
	if (curr->getLeft() == nullptr && curr->getRight() == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BSTree::removeLeaf(Node * curr)
{
	Node* temp = root;
	Node* parent = root;

	if (curr == root)
	{
		root = nullptr;
		return;
	}

	while (temp != curr)
	{
		parent = temp;

		if ((*temp > *curr || *temp == *curr) && search(temp->getLeft(), curr->getData()))
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
		

	}
	
	if (parent->getRight() == temp)
	{
		parent->setRight(nullptr);
	}
	else
	{
		parent->setLeft(nullptr);
	}
}

int BSTree::heightRecurs(Node* curr, const std::string key) const
{
	if (!search(root, key))
	{
		return -1;
	}

	if (curr == nullptr)
	{
		return -1;
	}

	else
	{
		int left;
		int right;

		left = heightRecurs(curr->getLeft(), key);
		right = heightRecurs(curr->getRight(), key);

		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}

	
}