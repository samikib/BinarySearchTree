#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;

class Node
{
private:
	std::string data;
	int count;
	Node* right;
	Node* left;

public:
	Node(std::string info);
	std::string getData();
	Node* getRight();
	Node* getLeft();
	int getCount();
	void setData(std::string val) { data = val; }
	void setCount(int val) { count = val; }
	void setRight(Node* r);
	void setLeft(Node* l);
	void increaseCount();
	void decreaseCount();
	void printNode();

	bool operator<(const Node& r);
	bool operator>(const Node& r);
	bool operator==(const Node& r);
	bool operator<(const std::string r);
	bool operator>(const std::string r);
	bool operator==(const std::string r);
	bool operator!=(const std::string r);
	Node& operator=(const Node& r)
	{
		this->data = r.data;
		this->count = r.count;
		return *this;
	}
};

#endif
