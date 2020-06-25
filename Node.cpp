#include "Node.h"

Node::Node(std::string info)
{
	data = info;
	count = 1;
	left = 0;
	right = 0;
}

std::string Node::getData()
{
	return data;
}

Node* Node::getRight()
{
	return right;
}

Node* Node::getLeft()
{
	return left;
}

int Node::getCount()
{
	return count;
}

void Node::setRight(Node * r)
{
	right = r;
}

void Node::setLeft(Node * l)
{
	left = l;
}

void Node::increaseCount()
{
	if (count >= 0)
	{
		count++;
	}
	else
	{
		//throw std::runtime_error("Adding a Node that doesnt exist.");
		return;
	}
}

void Node::decreaseCount()
{
	if (count > 0)
	{
		count--;
	}
	else
	{
		//throw std::runtime_error("Removing from a Node whose count is 0.");
		return;
	}
}

void Node::printNode()
{
	std::cout << data << "(" << count << ")";
}

bool Node::operator<(const Node & r)
{
	return data < r.data;
}
bool Node::operator>(const Node & r)
{
	return data > r.data;
}
bool Node::operator==(const Node & r)
{
	return data == r.data;
}

bool Node::operator<(const std::string r)
{
	return data < r;
}
bool Node::operator>(const std::string r)
{
	return data > r;
}
bool Node::operator==(const std::string r)
{
	return data == r;
}

bool Node::operator!=(const std::string r)
{
	return data != r;
}