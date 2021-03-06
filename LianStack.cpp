// LianStack.cpp: 定义控制台应用程序的入口点。
//实验项目链表，在递增有序链表中添加一元素仍然递增
//奇数项偶数项分开




#include"stdafx.h"
#include "iostream"
#include "string"
using namespace std;


enum Error_code { success = 1, overflow = 0, underflow = 2, Range_error = 3 };


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
	bool full() const;
	Error_code insert(const int, const int);
	Error_code insert1(int);
	Error_code delete_element(const int);
	Error_code enter_data();
	void Divided(List a, List b, List c);
	void output();
	int oops[18];
private:
	node * top;
	int count;
	int j;
};
List::List() {
	count = 0;
	top = new node;
	top->next = NULL;
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
Error_code List::enter_data()
{
	node*p,*s;
	int x;
	s = top;
	cout << "Now start enter" << endl;
	cin >> x;
	while (x != 0) {
		count++;
		p = new node;
		p->data = x;
		p->next = s->next;
		s->next = p;
		s = p;
		cin >> x;
	}
	return success;
}
Error_code List::insert(const int i, const int x)
{
	node*p = top;
	j = 0;
	while (j != i - 1 && p != NULL) {
		p = p->next;
		j++;
	}
	if (i<1 || i>length() + 1) {
		return Range_error;
	}
	node*s = new node;
	s->data = x;
	s->next = p->next;
	p->next = s;
	count++;
	return success;
}
Error_code List::delete_element(const int i)
{
	if (length() == 0)
		return underflow;
	if (i < 1 || i >= length())
		return Range_error;
	for (j = i + 1; j <= length(); j++)
		oops[j - 2] = oops[j - 1];
	count--;
	return success;
}
Error_code List::insert1(int x)
{
	int i = 0;
	node*p = top;
	node*s = new node;
	s->data = x;
	while (i!=1)
	{
		p = p->next;
		if (p->next != NULL) {
			if (p->data < s->data && p->next->data > s->data)
			{
				s->next = p->next;
				p->next = s;
				i = 1;
				count++;
			}
		}
		else return Range_error;
	}
	return success;
}
void List::output()
{
	node*o = new node;
	o = top->next;
	while (o!=NULL) {
		cout << o->data;
		o = o->next;
	}
	cout << endl;
}
void List::Divided(List a, List b, List c) {
	a.output();
	int x;
	node*p = new node;
	p = top;
	for (int i = 1; i <= a.count; i++) {
		p = p->next;
		x = p->data;
		if (i % 2 == 0) {
			c.insert(i / 2, x);
		}
		else {
			b.insert((i / 2 + 1), x);
		}
	}
	cout << "B's num:";
	b.output();
	cout << "C's num:";
	c.output();
}
int main()
{
	int i;
	List A,B,C;
	A.enter_data();
	A.Divided(A,B,C);
	cout << "which num do you want insert" << endl;
	cin >> i;
	A.insert1(i);
	cout << "this is:";
	A.output();
	return 0;
}


