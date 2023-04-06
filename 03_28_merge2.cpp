#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin1("text1.txt");
	ifstream fin2("text2.txt");
	ofstream fout("text3.txt");
	int n1,n2;

	fin1 >> n1;
	fin2 >> n2;
	while(1) {
		if(fin1.eof()|| fin2.eof()) break;
		if(n1 < n2) {
			fout << n1 << endl;
			fin1 >> n1;
		}
		else {
			fout << n2 << endl;	
			fin2 >> n2;
		}
	}
	if(fin1.eof())
	   while(!fin2.eof()) {	   	
	   		fout<< n2 << endl;
   			fin2 >> n2;
	   }
	if(fin2.eof())
	   while(!fin1.eof()) {
	   		fout<< n1 << endl;
	   		fin1 >> n1;
	   }   
	fin1.close();
	fin2.close();
	fout.close();     
}
