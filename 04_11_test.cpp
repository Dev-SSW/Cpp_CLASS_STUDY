//#include <iostream>
//#include <string>
//using namespace std;
//class ex //default : private
//{
//	int no;
//	string name;
//	int age;
//public :
//	explicit ex() { no = 0; name = ""; age = 0; }
//	//생성자함수 constructor
//	ex(int n , string temp , int c) { no = n; name = temp; age = c; }
//	//생성자함수 중복 (overLoad)
//
//	void SetName(string temp) {
//		name = temp;
//	}
//
//	string GetName() {
//		return name;
//	}
//
//	void GetInfo(int& n, string& str)
//	{
//		n = no;
//		str = name;
//	}
//
//	void show()
//	{
//		cout << no << endl;
//	}
//};								   
//int main()
//{
//	ex n1, n2(); // object
//	n2.SetName("홍길동");
//	int num; string irum;
//	n2.GetInfo(num, irum);
//	cout << num << " : " << irum << endl;
//
//	/*void f(int c[], int size);
//	int i;
//	int* a;
//	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	a = new int[10] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//	cout << a << " " << b << endl;
//	f(a, 10);
//	f(b, 10);
//	delete[] a;*/
//
//}
////void f(int c[], int size)
////{
////	cout << endl << c << endl;
////	for (int i = 0; i < size; i++) {
////		cout << c[i] << endl;
////	}
////}