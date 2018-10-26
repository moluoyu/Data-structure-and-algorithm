



/**
 * @brief 测试c++中成员变量的初始化顺序以及默认的初始值
 * 
 * @file cplussynax.cpp
 * @author Luo Yu
 * @date 2018-09-13
 */

#include<string>
#include<iostream>
using namespace std;
class test
{

public:
   // test():b(2),a(b+4)
 //   {

 //   }
   void print()
   {
        cout <<a<<endl;
        cout<<b<<endl;
        cout << c<<endl;
   }
private:
    int a;
    int b;
    int c;
};
int main()
{
    test test1;
    test1.print();
    test test2;
    cout <<"--"<<endl;
    test2.print();

    return 0;
}
/************************************************
 表明成员变量初始化时，里面存放的是随机值。
output:
0
8
0
--
81
0
4224528
***********************************************/
/************************************************
case 2 如果增加如下构造函数，由于函数初始化列表顺序是按照成员在类内初始化顺序的，所以先初始化a,再初始化b
output:a 因为b是随机值，所以a初始化为随机值。
-858993456
2
-858993460
--
-858993456
2
-858993460
***********************************************/
#include<iostream>
#include<stdlib.h>
using namespace std;
class test
{

public:
	test() :b(2), a(b + 4)
	{

	}
	void print()
	{
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
private:
	int a;
	int b;
	int c;
};
int main()
{
	test test1;
	test1.print();
	test test2;
	cout << "--" << endl;
	test2.print();
	return 0;
}
