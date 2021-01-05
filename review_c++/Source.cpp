#include<iostream>
using namespace std;

#if 0
const int aa = 100;
void test00() {
	int* p = (int*)&aa;
	//*p = 200 //语法通过，运行出错

	const int bb = 100; //分配于 符号表中
	int* q = (int*)&bb;
	//*q = 200 //出错 对const变量 取地址，会分配内存

	int cc = 100;
	const int dd=cc;  //使用普通变量 初始化const 变量
	int* pp = (int*)&dd;
	*pp = 1000;
	cout << dd << cc<<endl; // 1000 100
}

struct Person {
	string name;
	int age;
};
void test01() {
	const Person p1;
	//p.age = 10; //出错 因为const
	
	Person* ppp = (Person*)&p1; //间接修改
	(*ppp).name = "yom";
	ppp->age = 10; //可行

	cout<<"name: "<<ppp->name<<" age: "<<ppp->age<<endl;

}

void test02(){
	int a = 10;
	int& b = a;	//类型 &别名=原名	//引用a //会分配内存到栈上
	//必须初始化，int&b； error!
	cout << b << endl;//10
	cout << a << endl;//10
	int c = 100;
	b = c;//赋值
	cout << a << endl; //100
	cout << b << endl; //100
	cout << c << endl; //100

}
void test03() {
	//method 1
	int arr[10];
	int(&pArr)[10] = arr;

	for (int i = 0; i < 5; i++)
	{
		arr[i] = 10 + i;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << pArr[i] << endl;;
	}
	//method 2 定义数组类型 
	typedef int(ARRAY_TYPE)[10];
	//起别名
	ARRAY_TYPE& pArr2 = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << pArr2[i] << endl;;
	}

}
void swap1(int a ,int b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void swap2(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap3(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void test04() {
	int a = 10;
	int b = 20;
	swap1(a, b); //值传递 == 拷贝了一份 a b，原 a b 不变
	cout << a << " : " << b << endl; // 10 20

#if 0
	swap2(&a, &b);//地址传递
	cout << a << " : " << b << endl;//20 10
#endif // 0

#if 0
	swap3(a, b);//引用传递
	cout << a << " : " << b << endl;//20 10
#endif // 0

}
int& func() {
	int a = 10;
	return a; //返回引用
}
int& func2() {
	static int a = 10;//一直存在到程序结束，不被释放
	return a;
}
void test05() {
	//引用必须引一块合法内存空间
	//int b = 10; //栈上
	//int& a = b; //合法

	//int& a = 10; //不合法

	//不要返回局部变量的引用
	int& res = func();//接收引用
	cout << res << endl;//10 第一次可行
	cout << res << endl;//func() 被释放，不等10，乱码

	int& res2 = func2();
	cout << res2 << endl;//10
	cout << res2 << endl;//10 func2() 不被释放 直到程序结束

	//int&tmp =1000
	func2() = 1000;//当函数返回值是引用，那么函数调用可以作为左值
	cout << res2 << endl;//1000

}
struct Person1 {
	int age;
};
void allocateSpace(Person1** p) {
	//p指向指针的指针 *p指针 指向的是person本体 **p person本体
	*p = (Person1*)malloc(sizeof(Person1));
	(*p)->age = 10;
}
void allocateSpace2(Person1* &pp) { //Person * &pp = p
	//p指向指针的指针 *p指针 指向的是person本体 **p person本体
	pp = (Person1*)malloc(sizeof(Person1));
	pp->age = 20;
}
void test06() {
	Person1* p = NULL;
	allocateSpace(&p);
	cout << p->age << endl;

	Person1* p2= NULL;
	allocateSpace2(p2);
	cout << p2->age << endl;
}
void showValue(const int& a) {
	//a = 10000; const 不能修改除非用指针
	//不过既然要修改，还不如不加const
	cout << a << endl;
}
void test07() {
	//int& ref = 10; error

	const int& ref = 10;//加了const之后，
	                    //相当于写成 int temp = 10， 
						//const int&ref = temp
	int* p = (int*)&ref;
	*p = 10000;//相当于修改了temp
	cout << ref << endl;//10000

	int a = 100;
	showValue(a);
}

const double PI = 3.14;

class Circle {
public:
	int r;//member 
	double calculateP() { //member function/method
		return 2 * PI * r;
	}
	void setR(int rr) {
		r = rr;
	}
	int getR() { return r; }
};
class Student {
public: 
	string name;
	int id;

	void setName(string n) { name = n; }
	void setId(int i) { id = i; }
	void showStudent() { cout <<"name:" <<name <<" id: "<< id << endl; }
};
void test08() {
	Circle c1; //(实例化)对象 c1
	//c1.r = 10;
	c1.setR(10);
	cout << c1.getR() << endl;
	cout << c1.calculateP() << endl;

	Student s1;
	s1.name = "tom";
	s1.id = 1;
	cout << s1.name <<" : "<< s1.id << endl;

	Student s2;
	s2.setName("jerry");
	s2.setId(2);
	s2.showStudent();
}

//宏缺陷1 加括号 与 不加括号
//#define MYADD(x,y) x+y; //
#define MYADD(x,y) ((x)+(y)); // 
//宏缺陷2 加括号 有些运算依然与预期不符
#define MYCOMPARE(a,b) (((a) < (b))? (a) : (b))
//普通函数不会出现缺陷
void compare(int a, int b) {
	int ret = a < b ? a : b;
	cout << a << endl; //11
}
void test09() {
	//宏缺陷1 加括号 与 不加括号
	int a = 10;
	int b = 20;
	int ret = MYADD(a, b); //不加括号 不可*2
	cout << ret << endl;
	//int ret = MYADD(a, b) * 2; //加括号 600

	//宏缺陷2 加括号 有些运算依然与预期不符

	int ret2 = MYCOMPARE(++a, b); //预期11  结果12 
				//因为  (((++a) < (b))? (++a) : (b))
	cout << ret2 << endl;

}
//inline function
void test10() {
	//inline void func();
	//inline void func() {}; 声明 与 引用都需要 加inline
}

#endif

#if 0
//默认参数 语法  形参  类型 变量  = 默认值
//注意事项 ，如果有一个位置有了默认参数，那么从这个位置起，从左到右都必须有默认值
int func(int a, int b = 10, int c = 10)
{
	return  a + b + c;
}


void test01()
{
	cout << func(20, 10) << endl;

}


//函数的声明和实现 只能有一个 提供默认参数，不可以同时加默认参数
void myFunc(int a = 10, int b = 10);
void myFunc(int a, int b) {};



//占位参数  只写一个类型进行占位，调用时候必须要传入占位值
//占位参数 用途？ 目前没用
void func2(int a, int = 1)
{

}

void test02()
{
	func2(10);
}

#endif

#if 0
//函数重载条件
//1、在同一个作用域
//2、函数名称相同
//3、参数个数、类型、顺序不同

//class Person
//{
//public:
//	void func()   成员函数 而不是全局函数
//	{
//	}
//};

void func()
{
	cout << "func()调用" << endl;
}

void func(int a)
{
	cout << "func(int a)调用" << endl;
}

void func(double a)
{
	cout << "func(double a)调用" << endl;
}

void func(int a, double b)
{
	cout << "func(int a ,double b)调用" << endl;
}

void func(double a, int b)
{
	cout << "func(double a, int b)调用" << endl;
}

//返回值可不可以作为函数重载的条件 答案：不可以
//int func(int a, double b)
//{
//	cout << "func(int a ,double b)调用" << endl;
//}



void test01()
{
	func(1, 3.14);
}



//函数重载中 引用两个版本
//void myFunc(int a)
//{
//	cout << "myfunc(int a )调用" << endl;
//}
void myFunc(int& a) // int & a  = 10;
{
	cout << "myfunc(int &a )调用" << endl;
}
void myFunc(const int& a) // const int &a = 10;
{
	cout << "myfunc( const int &a )调用" << endl;
}


void test02()
{
	int a = 10;
	//myFunc(a);//需要避免二义性出现

}


//函数重载碰到默认参数  注意避免二义性出现
void func2(int a, int b = 10)
{

}

void func2(int a)
{

}

void test03()
{
	//func2(10); //出现二义性
}

#endif // 0


#if 0
//方法一，但不推荐
//告诉编译器  show函数用C语言方式 做链接
//extern "C" void show();

//方法2
#include "test.h"

void test01()
{
	show();//_Z4showv;在C++中有函数重载会修饰函数名，但是show是c语言文件，因此链接失败
}


#endif // 0

#if 0
struct Person
{
	char  name[64];
	int age;
};

void PersonEat(struct Person* p)
{
	printf("%s在吃人饭\n", p->name);
}

void test01()
{
	struct Person p;
	strcpy(p.name, "张三");
	p.age = 10;

	PersonEat(&p);
}


struct Dog
{
	char name[64];
	int age;
};

void DogEat(struct Dog* dog)
{
	printf("%s在吃狗粮\n", dog->name);
}

void test02()
{
	struct Dog d;
	strcpy(d.name, "旺财");
	d.age = 100;

	DogEat(&d);


	struct Person p;
	strcpy(p.name, "老王");

	DogEat(&p);

}



int main() {
	//	test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}
#endif // 0

#if 0
struct  Person
{
	//公共权限
public:
	char name[64];
	int age;

	void PersonEat()
	{
		printf("%s在吃人饭\n", name);
	}
};

struct Dog
{
	//公共权限
public:
	char name[64];
	int age;

	void DogEat()
	{
		printf("%s在吃狗粮\n", name);
	}
};

//C++封装 理念：  将属性和行为作为一个整体，来表现生活中的事物

//第二次理念： 将属性和行为  加以权限控制

void test01()
{
	struct Person p;
	strcpy(p.name, "老王");

	p.PersonEat();

	//p.DogEat();
}


//struct和class 区别？
//class 默认权限  私有权限  而 struct默认权限是 公共权限
//访问权限
// public  公共权限    成员 类内  类外 都可以访问	 
// private 私有权限    成员 类内  可以访问  类外  不可以访问  儿子不可以访问父亲的private权限内容
// protected 保护权限  成员 类内  可以访问  类外  不可以访问  儿子可以访问父亲的protected权限内容

class Person2
{
public:
	string m_Name; //公共权限

protected:
	string m_Car;  //保护权限

private:
	int  m_pwd;  //私有权限

public:

	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_pwd = 123456;
	}

};

void test02()
{
	Person2 p;
	p.m_Name = "李四"; //公共权限  类外可以访问
//	p.m_Car = "劳斯莱斯"; //保护权限  类外访问不到
//	p.m_pwd = 123; //私有权限  类外不可以访问
}

int main() {
	test01();


	system("pause");
	return EXIT_SUCCESS;
}
#endif // 0

#if 0
class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		return m_Age;
	}

	//设置年龄
	void setAge(int age)
	{
		if (age < 0 || age > 150)
		{
			cout << "你这个老妖精" << endl;
			return;
		}
		m_Age = age;
	}

	//设置情人
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
	string m_Name;  //姓名  可读可写
	int m_Age = 18;      //年龄  可读 可写（0 ~ 150之间）
	string m_Lover; //情人  只写
};

void test01()
{
	Person p;
	//可以将char * 隐式类型转换为 string
	p.setName("张三");
	cout << "姓名： " << p.getName() << endl;

	//获取年龄
	p.setAge(100);
	cout << "年龄： " << p.getAge() << endl;

	//设置情人
	p.setLover("苍井");

	//cout << "张三情人是："<< p.m_Lover <<endl; //情人是只写权限  外部访问不到

}

//将成员属性都设置为私有好处：自己可以控制读写权限
//可以对设置内容 加有效性验证
int main() {
	test01();


	system("pause");
	return EXIT_SUCCESS;
}
#endif // 0

#if 0
class Chairman {
public:
	static Chairman* getInstance() {
		return singleman;
	}
private:
	Chairman() {
		cout << "default constructor is used" << endl;
	};
	Chairman(const Chairman&) {
	
	}
private:
	static Chairman* singleman;
};

Chairman* Chairman::singleman = new Chairman;

void test() {
	//private default constructor
	/*Chairman c1;
	Chairman c2;
	Chairman* c3 = new Chairman;*/

	Chairman* c1 =Chairman::getInstance();
	Chairman* c2 = Chairman::getInstance();
	
	//Chairman* c3 = new Chairman(*c1);

	if (c1 == c2) {
		cout << "c1==c2" << endl;
	}
	else {
		cout << "c1!=c2" << endl;
	}

	//Chairman::singleman = NULL; //public make it accessible
}
int main(void)
{

	return 0;
}

#endif // 0

#if 0
class Printer {
private:
	Printer() { 
		count =0;
		//cout << "default constructor is used" << endl; 
	};
	Printer(const Printer& p) {}
	static Printer* printer;

public:
	int count;
	static Printer* getInstance() {
		return printer;
	}

	void printerText(string text) {
		count++;
		cout << text << endl;
	}
}; 

Printer* Printer::printer = new Printer;

void test01() {

	Printer* p1 = Printer::getInstance();
	p1->printerText("enrollment");
	p1->printerText("resignation");
	cout << p1->count << endl;

	Printer* p2 = Printer::getInstance();
	p2->printerText("travel");
	cout << p1->count << endl;
}
#endif // 1

#if 0

class myArray {
public:
	myArray();
	myArray(int capacity);
	myArray(const myArray& arr);

	void pushBack(int val);
	void setData(int pos, int val);
	int getData(int pos);
	
	int getCapacity();
	int getSize();

	myArray operator+(myArray&);

	~myArray();
private:
	int m_Capacity;
	int m_Size;
	int *pAddress;
};

myArray operator+(myArray&, myArray&);
myArray operator+(myArray& p1, myArray&p2) {

}
myArray operator+(myArray& p, int num);
myArray operator+(myArray& p, int num) {

}

myArray::myArray() {
	this->m_Capacity = 100;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
}
myArray::myArray(int capacity) {
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];

}
myArray::myArray(const myArray& arr) {
	this->m_Capacity = arr.m_Capacity;
	this->m_Size = arr.m_Size;
	
	this->pAddress = new int[arr.m_Capacity];
	
	for (int i = 0; i < m_Size; i++)
	{
		this->pAddress[i] = arr.pAddress[i];
	}
}

void myArray::pushBack(int val) {
	this->pAddress[this->m_Size] = val;
	this->m_Size++;
}
void myArray::setData(int pos, int val) {
	this->pAddress[pos] = val;
}
int myArray::getData(int pos) {
	return this->pAddress[pos];
}

int myArray::getCapacity() {
	return this->m_Capacity;
}
int myArray::getSize() {
	return this->m_Size;
}

myArray::~myArray() {
	if (this->pAddress != NULL) {
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
};
myArray myArray::operator+(myArray& p) {
	myArray tmp;
	

}

void test01() {
	myArray arr;
	for (int i = 0; i < 10; i++)
	{
		arr.pushBack(i);
	}

	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.getData(i)<<endl;
	}

	myArray arr2(arr);

	for (int i = 0; i < arr2.getSize(); i++)
	{
		cout << arr2.getData(i) << endl;
	}

	arr.setData(0, 1000);
	cout << arr.getData(0) << endl;
}
#endif // 1

#if 0
#include<vector>
#include<algorithm>
#include<deque>
class Person {
public:
	//Person() {};
	Person(string n, double s) { name = n; score = s; };
	string name;
	double score;
};

void printScore(vector<Person*>& v) {
	for (vector<Person*>::iterator it = v.begin(); it!=v.end(); it++)
	{
		cout <<"name: "<<(*it)->name<<" | score: " << (*it)->score<<endl;
	}

}
void test0() {
	vector<Person*> v;
	Person p1("tom", 0.0);
	Person p2("jerry", 0.0);
	Person p3("petter", 0.0);
	Person p4("red", 0.0);
	Person p5("blue", 0.0);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	deque<double> d;

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (int i = 0; i < 10; i++)
		{
			double points = (double)(rand()%41+60); //60 --100
			d.push_back(points);
		}
		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();
		double avg = 0;
		for (deque<double>::iterator itd = d.begin();itd !=d.end();itd++)
		{
			avg += (*itd);
		}

		avg = avg / d.size();

		(*it)->score = avg;

		d.clear();

	}


	printScore(v);
}

#endif // 1

#if 0
#include<map>
class Worker {
public:
	Worker(string n, int a, int t, double s):name(n),age(a),tel(t),salary(s){

	};
	string name;
	int age;
	int tel;
	double salary;
};
void hireWorker(multimap<int, Worker>& mm) {
	string w = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "Worker";
		name += w[i];
		Worker p(name, i, rand()%9999+ 10000, rand()%999+5000.0);
		mm.insert(make_pair(rand()%3, p));
	}
}
void printWorker(multimap<int, Worker>&mm) {
	for (multimap<int,Worker>::iterator it = mm.begin(); it!= mm.end(); it++)
	{
		cout << "No: " << (*it).first << " name: "<<(*it).second.name<<" age: "<<(*it).second.age<<" tel: "<< (*it).second.tel<<" salary: "<< (*it).second.salary << endl;
	}

}

void test0(){
	multimap<int, Worker> m;
	hireWorker(m);
	printWorker(m);
}
#endif // 1
#if 0
#include<vector>
#include<map>
#include<ctime>
enum {CUSTOM, IT, SALE};
class Worker {
public:
	Worker(string n, int s) : name(n), salary(s){}
	string name;
	int salary;
};
void createWorker(vector<Worker>& v) {
	string s = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "Worker";
		name += s[i];

		int salary = rand()%999 + 5000;
		v.push_back(Worker(name, salary));
	}
}
void setGroup(vector<Worker>& v, multimap<int, Worker>& m) {
	
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int department = rand() % 3;
		m.insert(make_pair(department, (*it)));
	}
}
void showGroup(multimap<int, Worker>& m) {
	for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " : " << (*it).second.name << " : " << (*it).second.salary << endl;
	}

}

void printGroup(multimap<int, Worker>& m)
{
	cout << "IT department" << endl;
		multimap<int, Worker>::iterator pos = m.find(IT);
		int num = m.count(IT);
		int index = 0;
		for (; pos !=m.end(), index < num; pos++, index++)
		{
			cout << (*pos).first << " " << (*pos).second.name << " " << (*pos).second.salary << endl;
		}

		cout << "CUSTOM department" << endl;
		pos = m.find(CUSTOM);
		num = m.count(CUSTOM);
		index = 0;
		for (; pos != m.end(), index < num; pos++, index++)
		{
			cout << (*pos).first << " " << (*pos).second.name << " " << (*pos).second.salary << endl;
		}
		cout << "SALE department" << endl;
		pos = m.find(SALE);
		num = m.count(SALE);
		index = 0;
		for (; pos != m.end(), index < num; pos++, index++)
		{
			cout << (*pos).first << " " << (*pos).second.name << " " << (*pos).second.salary << endl;
		}
}
void test0() {
	srand(unsigned int(time(NULL)));

	vector<Worker> v;
	createWorker(v);
	multimap<int, Worker> m;
	setGroup(v, m);
	showGroup(m);

	printGroup(m);
}
#endif // 1


#if 0
//适配器
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

class MyPrint :public binary_function<int, int, void>
{
public:
	void operator()(int val, int start)const
	{
		cout << "val = " << val << " start = " << start << " sum = " << val + start << endl;
	}
};
//1、函数对象适配器
void test01()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "请输入起始累加值： " << endl;
	int num;
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));
	//for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}

//1、利用bind2nd 进行绑定
//2、继承 public binary_function<参数1 类型,参数2类型,返回值类型>
//3、加const


//2、取反适配器
class GreaterThanFive :public unary_function<int, bool>
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//一元取反
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( GreaterThanFive()));

	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));

	if (pos != v.end())
	{
		cout << "找到小于5的值为： " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}


	//二元取反
	sort(v.begin(), v.end(), not2(less<int>()));
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}

//1、利用not1进行取反
//2、继承 public unary_function<int,bool>
//3、加const


void myPrint3(int val, int start)
{
	cout << val + start << endl;
}
//3、 函数适配器
void test03()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//将函数指针 适配成函数对象  ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint3), 1000));
}


//4、成员函数适配器
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "成员函数----姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
	}

	void addAge()
	{
		this->m_Age += 100;
	}

	string m_Name;
	int m_Age;
};

//void myPrint4( Person & p)
//{
//	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
//}

void test04()
{
	vector< Person > v;
	//对象实体
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//利用 mem_fun_ref
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));


	vector< Person*> v1;
	//对象指针
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);
	//利用 mem_fun_ref
	for_each(v1.begin(), v1.end(), mem_fun(&Person::showPerson));
	for_each(v1.begin(), v1.end(), mem_fun(&Person::addAge));
	for_each(v1.begin(), v1.end(), mem_fun(&Person::showPerson));


}

int main() {

	//	test01();
	//	test02();
	//	test03();
	test04();

	system("pause");
	return EXIT_SUCCESS;
}
#endif // 0

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	bool operator==(Person &p) {
		
		return this->name == p.name && this->age == p.age;
	}
	string name;
	int age;

};

class MyComparePerson : public binary_function<Person*,Person*, bool>{
public:
	bool operator()(Person* p1, Person* p2)const {
		return p1->name == p2->name && p1->age == p2->age;
	}

};
class GreatnEqual {
public:
	bool operator()(int val) {
		return val >= 3;
	}
};

class myTransform {
public:
	int operator()(int val) {
		return val;
	}
};
void test02()
{
#if 0
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end()) {
		cout << "find it" << *pos << endl;
	}
	else {
		cout << "not find it" << endl;
	}

#endif // 0


#if 0
	vector<Person> v1;
	//对象实体
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	vector<Person>::iterator it1 = find(v1.begin(), v1.end(), p2);
	if (it1 != v1.end()) {
		cout << "find it " << (*it1).name << " " << (*it1).age << endl;
	}
	else {
		cout << "not find it" << endl;
	}
#endif // 0

#if 0
	vector<Person*> v2;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);
	v2.push_back(&p4);

	Person* p = new Person("bbb", 20);

	vector<Person*>::iterator it2 = find_if(v2.begin(), v2.end(), bind2nd(MyComparePerson(), p));
	if (it2 != v2.end()) {
		cout << "find it " << (*it2)->name << " " << (*it2)->age << endl;
	}
	else {
		cout << "not find it" << endl;
	}
#endif // 0



#if 0
	vector<int> v3;

	v3.push_back(3);
	v3.push_back(2);
	v3.push_back(300);//<--先找到这个
	v3.push_back(300);//<--
	v3.push_back(6);
	v3.push_back(3);

	vector<int>::iterator it3 = adjacent_find(v3.begin(), v3.end());

	if (it3 != v3.end()) {
		cout << "found it" << *it3 << endl;
	}
	else {
		cout << "not found it" << endl;
	}
#endif // 0


#if 0

	//必须是有序序列 
	vector<int>v4;
	for (int i = 0; i < 10; i++)
	{
		v4.push_back(i);
	}
	//v.push_back(4); 后无法找到9
	//2分查找
	bool ret = binary_search(v4.begin(), v4.end(), 2);

	if (ret) {
		cout << "fount it" << endl;
	}
	else {
		cout << "not found it" << endl;
	}

	v4.push_back(3);
	v4.push_back(3);
	v4.push_back(3);

	int num = count(v4.begin(), v4.end(), 3); //4

	int num1 = count_if(v4.begin(), v4.end(), bind2nd(greater_equal<int>(), 3));
	int num2 = count_if(v4.begin(), v4.end(), GreatnEqual());

	cout << num << endl;
	cout << num1 << endl;
	cout << num2 << endl;
#endif // 0

#if 0
	//merger for orderd container
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);

	}

	vector<int> v3;
	v3.resize(v1.size() + v2.size()); //*important*
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	for_each(v3.begin(), v3.end(), [](int val) {cout << val << " "; });

	cout << endl;
	vector<int> v4;
	v4.resize(v1.size());
	transform(v1.begin(), v1.end(), v4.begin(), myTransform());
	for_each(v4.begin(), v4.end(), [](int val) {cout << val << " "; });


#endif // 1


}
#endif // 1


#if 0
int main()
{
	test00();
	return 0;
}
#endif