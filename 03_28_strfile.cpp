#include <iostream>
#include <fstream>
using namespace std;
struct info {
	int num;
	string name;
	int mid;
	int fin;
	int sum;
	float average;
};
int main()
{
	struct info In={1,"ȫ�浿", 100, 100 };
	ofstream fout("result.txt");
	fout << In.num <<" "<< In.name << " " << In.mid << " " << In.fin<< endl;
	fout.close();
}
