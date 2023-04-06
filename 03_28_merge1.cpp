#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define MIA 3
#define MIB 5
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	ofstream fout("text1.txt");
	int n;
	n = 5 + rand()%6;
	for(int i=0; i<n; i++)
		fout << i << endl;
	fout.close();
	
	ofstream fout2("text2.txt");
	n = 5 + rand()%6;
	for(int i=0; i<n; i++)
		fout2 << i << endl;
	fout2.close();
}
	 
	
	
	
	
	
	
	
	
	
	
	
	

