// StackC=A+B.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include "iostream"
#include "string"
using namespace std;


enum Error_code { success = 1, overflow = 0, underflow = 2, Range_error = 3 };
int q = 0;
class List
{
public:
	List();
	int length() const;
	bool empty() const;
	bool full() const;
	Error_code insert(const int, const int);
	Error_code insert1(int);
	Error_code delete_element(const int);
	Error_code enter_data();
	int data[18];
	int count;
private:


	int j;
};
List::List() {
	count = 0;
}
int List::length() const
{
	return count;
}
bool List::empty() const
{
	if (count == 0)
		return true;
	return false;
}
bool List::full() const
{
	if (count == 17)
		return true;
	return false;
}
Error_code List::enter_data()
{
	cout << "Now start enter" << endl;
	for (j = 0; j < 18; j++) {
		cin >> data[j];
		count++;
		if (data[j] == 0) {
			break;
		}
	}
	return success;
}
Error_code List::insert(const int i, const int x)//插入表 
{
	if (full()) {
		return overflow;
	}
	if (i<1 || i>length() + 1)
		return Range_error;
	for (j = count - 1; j >= i - 1; j--)
		data[j + 1] = data[j];
	data[i - 1] = x;
	count = count + 1;
	return success;
}
Error_code List::delete_element(const int i)
{
	if (length() == 0)
		return underflow;
	if (i < 1 || i >= length())
		return Range_error;
	for (j = i + 1; j <= length(); j++)
		data[j - 2] = data[j - 1];
	count--;
	return success;
}
Error_code List::insert1(int x)
{
	int i = count - 1;
	if (i >= 17)
		return overflow;
	while (i > 0 && data[i] > x)
	{
		data[i + 1] = data[i];
		i--;
	}
	data[i + 1] = x;
	count++;
	return success;
}
List Plus(List a, List b, List c)
{
	for (int w = a.count - 1; w >= 0; w--) {
		for (int e = b.count - 1; e >= 0; e--) {
			if (a.data[w] == b.data[e]) {
				c.data[q] = a.data[w];
				q++;
				c.count++;
			}
		}
	}
	return c;
}
int main()
{
	int j = 0;
	List A, B, C;
	A.enter_data();
	B.enter_data();
	C = Plus(A, B, C);
	cout <<"C's count is :"<<C.count << endl;
	for (j = 1; j < C.count; j++) {//j从1开始,为了去掉'0'
		cout << C.data[j] << endl;
	}
	return 0;
}


