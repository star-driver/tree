// JosefuProblem.cpp: 定义控制台应用程序的入口点。
//

//不带头节点解决约瑟夫环


#include"stdafx.h"
#include "iostream"
#include "string"
using namespace std;


enum ErrorCode { success = 1, overflow = 0, underflow = 2, Range_error = 3 };


class List
{
public:
	typedef struct node {
		int data;
		node * next;
	}node;
	List();
	int length() const;
	bool empty() const;
	ErrorCode insert(const int, const int);
	ErrorCode DeleteElement(const int);
	ErrorCode EnterData();
	void output();
	int count;
private:
	node * g;
	node*p;
	node*k;
};
List::List() {
	count = 1;
	p = new node;
	p->next = p;
	g = p;
	k = p;
}
int List::length() const
{
	return count;
}
bool List::empty() const
{
	if (count == 0) {
		return true;
	}
	return false;
}
ErrorCode List::EnterData()
{
	node*j = g;
	int x;
	cout << "Now start enter" << endl;
	cin >> x;
	while (x != -1) {
		count++;
		j = new node;
		p->data = x;
		p->next = j;
		j->next = g;
		cin >> x;
		if (x != -1)             //当x=-1时不再使p指针指向j指针所指向的node;
			p = j;
	}
	delete j;
	p->next = g;             //此时p指向j的前一个node;回环;
	return success;
}
ErrorCode List::insert(const int i, const int x)
{
	node*o = p;
	int j = 0;
	while (j < i - 1 && o != NULL) {
		o = o->next;
		j++;
	}
	if (i<1 || i>length() + 1) {
		return Range_error;
	}
	node*s = new node;
	s->data = x;
	s->next = o->next;
	o->next = s;
	count++;
	return success;
}
ErrorCode List::DeleteElement(const int i)
{
	if (length() == 0)
		return underflow;
	if (i < 1 || i >= length())
		return Range_error;
	node*q, *L;
	int a = 0;
	while (i - 1 > a) {
		k = k->next;
		a++;
	}                     //此时k指向欲删除项的前一位;
	q = k->next->next;
	L = k->next;
	delete L;
	k->next = q;           //回环;
	return success;
}
void List::output()
{
	cout << k->data << endl;
}
List JosephProblem(List a)
{
	if (a.count <= 1)
		return a;
	int j;
	cin >> j;
	while (a.count != 1) {
		a.DeleteElement(j);
		a.count--;
	}
	return a;
}
int main()
{
	List A;
	A.EnterData();
	A = JosephProblem(A);
	A.output();
	return 0;
}


