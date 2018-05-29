// Stack.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;


enum Error_code { success = 1, overflow = 0, underflow = 2, Range_error = 3 };


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
string compare(List a, List b)
{
	if (a.count>b.count)
	{
		return { "A不是B的子集" };
	}
	else {
		for (int c = a.count; c >= 0; c--) {
			for (int d = b.count; d >= 0; d--) {
				while (a.data[c] < b.data[d + 1] && a.data[c]>b.data[d]) {
					return { "A不是B的子集" };
				}

			}
		}
		return { "A是B的子集" };
	}
}
int main()
{
	List A, B;
	A.enter_data();
	cout << "A" << endl;
	B.enter_data();
	cout << "B" << endl;
	compare(A, B);
	string G = compare(A, B);
	cout << G;
	return 0;
}


