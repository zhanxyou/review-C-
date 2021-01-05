#include<iostream>
using namespace std;

#if 0
const int aa = 100;
void test00() {
	int* p = (int*)&aa;
	//*p = 200 //�﷨ͨ�������г���

	const int bb = 100; //������ ���ű���
	int* q = (int*)&bb;
	//*q = 200 //���� ��const���� ȡ��ַ��������ڴ�

	int cc = 100;
	const int dd=cc;  //ʹ����ͨ���� ��ʼ��const ����
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
	//p.age = 10; //���� ��Ϊconst
	
	Person* ppp = (Person*)&p1; //����޸�
	(*ppp).name = "yom";
	ppp->age = 10; //����

	cout<<"name: "<<ppp->name<<" age: "<<ppp->age<<endl;

}

void test02(){
	int a = 10;
	int& b = a;	//���� &����=ԭ��	//����a //������ڴ浽ջ��
	//�����ʼ����int&b�� error!
	cout << b << endl;//10
	cout << a << endl;//10
	int c = 100;
	b = c;//��ֵ
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
	//method 2 ������������ 
	typedef int(ARRAY_TYPE)[10];
	//�����
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
	swap1(a, b); //ֵ���� == ������һ�� a b��ԭ a b ����
	cout << a << " : " << b << endl; // 10 20

#if 0
	swap2(&a, &b);//��ַ����
	cout << a << " : " << b << endl;//20 10
#endif // 0

#if 0
	swap3(a, b);//���ô���
	cout << a << " : " << b << endl;//20 10
#endif // 0

}
int& func() {
	int a = 10;
	return a; //��������
}
int& func2() {
	static int a = 10;//һֱ���ڵ���������������ͷ�
	return a;
}
void test05() {
	//���ñ�����һ��Ϸ��ڴ�ռ�
	//int b = 10; //ջ��
	//int& a = b; //�Ϸ�

	//int& a = 10; //���Ϸ�

	//��Ҫ���ؾֲ�����������
	int& res = func();//��������
	cout << res << endl;//10 ��һ�ο���
	cout << res << endl;//func() ���ͷţ�����10������

	int& res2 = func2();
	cout << res2 << endl;//10
	cout << res2 << endl;//10 func2() �����ͷ� ֱ���������

	//int&tmp =1000
	func2() = 1000;//����������ֵ�����ã���ô�������ÿ�����Ϊ��ֵ
	cout << res2 << endl;//1000

}
struct Person1 {
	int age;
};
void allocateSpace(Person1** p) {
	//pָ��ָ���ָ�� *pָ�� ָ�����person���� **p person����
	*p = (Person1*)malloc(sizeof(Person1));
	(*p)->age = 10;
}
void allocateSpace2(Person1* &pp) { //Person * &pp = p
	//pָ��ָ���ָ�� *pָ�� ָ�����person���� **p person����
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
	//a = 10000; const �����޸ĳ�����ָ��
	//������ȻҪ�޸ģ������粻��const
	cout << a << endl;
}
void test07() {
	//int& ref = 10; error

	const int& ref = 10;//����const֮��
	                    //�൱��д�� int temp = 10�� 
						//const int&ref = temp
	int* p = (int*)&ref;
	*p = 10000;//�൱���޸���temp
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
	Circle c1; //(ʵ����)���� c1
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

//��ȱ��1 ������ �� ��������
//#define MYADD(x,y) x+y; //
#define MYADD(x,y) ((x)+(y)); // 
//��ȱ��2 ������ ��Щ������Ȼ��Ԥ�ڲ���
#define MYCOMPARE(a,b) (((a) < (b))? (a) : (b))
//��ͨ�����������ȱ��
void compare(int a, int b) {
	int ret = a < b ? a : b;
	cout << a << endl; //11
}
void test09() {
	//��ȱ��1 ������ �� ��������
	int a = 10;
	int b = 20;
	int ret = MYADD(a, b); //�������� ����*2
	cout << ret << endl;
	//int ret = MYADD(a, b) * 2; //������ 600

	//��ȱ��2 ������ ��Щ������Ȼ��Ԥ�ڲ���

	int ret2 = MYCOMPARE(++a, b); //Ԥ��11  ���12 
				//��Ϊ  (((++a) < (b))? (++a) : (b))
	cout << ret2 << endl;

}
//inline function
void test10() {
	//inline void func();
	//inline void func() {}; ���� �� ���ö���Ҫ ��inline
}

#endif

#if 0
//Ĭ�ϲ��� �﷨  �β�  ���� ����  = Ĭ��ֵ
//ע������ �������һ��λ������Ĭ�ϲ�������ô�����λ���𣬴����Ҷ�������Ĭ��ֵ
int func(int a, int b = 10, int c = 10)
{
	return  a + b + c;
}


void test01()
{
	cout << func(20, 10) << endl;

}


//������������ʵ�� ֻ����һ�� �ṩĬ�ϲ�����������ͬʱ��Ĭ�ϲ���
void myFunc(int a = 10, int b = 10);
void myFunc(int a, int b) {};



//ռλ����  ֻдһ�����ͽ���ռλ������ʱ�����Ҫ����ռλֵ
//ռλ���� ��;�� Ŀǰû��
void func2(int a, int = 1)
{

}

void test02()
{
	func2(10);
}

#endif

#if 0
//������������
//1����ͬһ��������
//2������������ͬ
//3���������������͡�˳��ͬ

//class Person
//{
//public:
//	void func()   ��Ա���� ������ȫ�ֺ���
//	{
//	}
//};

void func()
{
	cout << "func()����" << endl;
}

void func(int a)
{
	cout << "func(int a)����" << endl;
}

void func(double a)
{
	cout << "func(double a)����" << endl;
}

void func(int a, double b)
{
	cout << "func(int a ,double b)����" << endl;
}

void func(double a, int b)
{
	cout << "func(double a, int b)����" << endl;
}

//����ֵ�ɲ�������Ϊ�������ص����� �𰸣�������
//int func(int a, double b)
//{
//	cout << "func(int a ,double b)����" << endl;
//}



void test01()
{
	func(1, 3.14);
}



//���������� ���������汾
//void myFunc(int a)
//{
//	cout << "myfunc(int a )����" << endl;
//}
void myFunc(int& a) // int & a  = 10;
{
	cout << "myfunc(int &a )����" << endl;
}
void myFunc(const int& a) // const int &a = 10;
{
	cout << "myfunc( const int &a )����" << endl;
}


void test02()
{
	int a = 10;
	//myFunc(a);//��Ҫ��������Գ���

}


//������������Ĭ�ϲ���  ע���������Գ���
void func2(int a, int b = 10)
{

}

void func2(int a)
{

}

void test03()
{
	//func2(10); //���ֶ�����
}

#endif // 0


#if 0
//����һ�������Ƽ�
//���߱�����  show������C���Է�ʽ ������
//extern "C" void show();

//����2
#include "test.h"

void test01()
{
	show();//_Z4showv;��C++���к������ػ����κ�����������show��c�����ļ����������ʧ��
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
	printf("%s�ڳ��˷�\n", p->name);
}

void test01()
{
	struct Person p;
	strcpy(p.name, "����");
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
	printf("%s�ڳԹ���\n", dog->name);
}

void test02()
{
	struct Dog d;
	strcpy(d.name, "����");
	d.age = 100;

	DogEat(&d);


	struct Person p;
	strcpy(p.name, "����");

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
	//����Ȩ��
public:
	char name[64];
	int age;

	void PersonEat()
	{
		printf("%s�ڳ��˷�\n", name);
	}
};

struct Dog
{
	//����Ȩ��
public:
	char name[64];
	int age;

	void DogEat()
	{
		printf("%s�ڳԹ���\n", name);
	}
};

//C++��װ ���  �����Ժ���Ϊ��Ϊһ�����壬�����������е�����

//�ڶ������ �����Ժ���Ϊ  ����Ȩ�޿���

void test01()
{
	struct Person p;
	strcpy(p.name, "����");

	p.PersonEat();

	//p.DogEat();
}


//struct��class ����
//class Ĭ��Ȩ��  ˽��Ȩ��  �� structĬ��Ȩ���� ����Ȩ��
//����Ȩ��
// public  ����Ȩ��    ��Ա ����  ���� �����Է���	 
// private ˽��Ȩ��    ��Ա ����  ���Է���  ����  �����Է���  ���Ӳ����Է��ʸ��׵�privateȨ������
// protected ����Ȩ��  ��Ա ����  ���Է���  ����  �����Է���  ���ӿ��Է��ʸ��׵�protectedȨ������

class Person2
{
public:
	string m_Name; //����Ȩ��

protected:
	string m_Car;  //����Ȩ��

private:
	int  m_pwd;  //˽��Ȩ��

public:

	void func()
	{
		m_Name = "����";
		m_Car = "������";
		m_pwd = 123456;
	}

};

void test02()
{
	Person2 p;
	p.m_Name = "����"; //����Ȩ��  ������Է���
//	p.m_Car = "��˹��˹"; //����Ȩ��  ������ʲ���
//	p.m_pwd = 123; //˽��Ȩ��  ���ⲻ���Է���
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
	//��������
	void setName(string name)
	{
		m_Name = name;
	}
	//��ȡ����
	string getName()
	{
		return m_Name;
	}

	//��ȡ����
	int getAge()
	{
		return m_Age;
	}

	//��������
	void setAge(int age)
	{
		if (age < 0 || age > 150)
		{
			cout << "�����������" << endl;
			return;
		}
		m_Age = age;
	}

	//��������
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
	string m_Name;  //����  �ɶ���д
	int m_Age = 18;      //����  �ɶ� ��д��0 ~ 150֮�䣩
	string m_Lover; //����  ֻд
};

void test01()
{
	Person p;
	//���Խ�char * ��ʽ����ת��Ϊ string
	p.setName("����");
	cout << "������ " << p.getName() << endl;

	//��ȡ����
	p.setAge(100);
	cout << "���䣺 " << p.getAge() << endl;

	//��������
	p.setLover("�Ծ�");

	//cout << "���������ǣ�"<< p.m_Lover <<endl; //������ֻдȨ��  �ⲿ���ʲ���

}

//����Ա���Զ�����Ϊ˽�кô����Լ����Կ��ƶ�дȨ��
//���Զ��������� ����Ч����֤
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
//������
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
//1����������������
void test01()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "��������ʼ�ۼ�ֵ�� " << endl;
	int num;
	cin >> num;

	for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));
	//for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}

//1������bind2nd ���а�
//2���̳� public binary_function<����1 ����,����2����,����ֵ����>
//3����const


//2��ȡ��������
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

	//һԪȡ��
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), not1( GreaterThanFive()));

	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));

	if (pos != v.end())
	{
		cout << "�ҵ�С��5��ֵΪ�� " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}


	//��Ԫȡ��
	sort(v.begin(), v.end(), not2(less<int>()));
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });
}

//1������not1����ȡ��
//2���̳� public unary_function<int,bool>
//3����const


void myPrint3(int val, int start)
{
	cout << val + start << endl;
}
//3�� ����������
void test03()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//������ָ�� ����ɺ�������  ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint3), 1000));
}


//4����Ա����������
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
		cout << "��Ա����----������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
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
//	cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
//}

void test04()
{
	vector< Person > v;
	//����ʵ��
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//���� mem_fun_ref
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::addAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));


	vector< Person*> v1;
	//����ָ��
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);
	//���� mem_fun_ref
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
	//����ʵ��
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
	v3.push_back(300);//<--���ҵ����
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

	//�������������� 
	vector<int>v4;
	for (int i = 0; i < 10; i++)
	{
		v4.push_back(i);
	}
	//v.push_back(4); ���޷��ҵ�9
	//2�ֲ���
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