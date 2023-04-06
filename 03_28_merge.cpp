#include <iostream>
#include <cstdlib>
#include <ctime>
#define MIA 3
#define MIB 5
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int a[] = { 1,3,5};
	int b[] = { 0,2,3,4,5};
	int c[MIA+MIB];
	int ia=0;
	int ib=0;
	int ic=0;
	while(ia < MIA && ib < MIB) {
		if(a[ia]< b[ib]) 
			c[ic++] = a[ia++];				
		else  
			c[ic++] = b[ib++];
	}
	if(ia== MIA)
		for(int i=ib; i<MIB; i++)
			c[ic++] = b[i];
	if(ib==MIB)
	 	for(int i=ia; i<MIA; i++)
			c[ic++] = a[i];
	for(int i=0; i<MIA+MIB; i++)
	  cout << c[i] << " ";
}

		
	 
	
	
	
	
	
	
	
	
	
	
	
	

