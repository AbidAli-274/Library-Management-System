#include<iostream> //input/output header file
#include "classes.h"//user define header file for classes
#include "functions.h"//user define header file for functions
#include<fstream>
using namespace std;
int main(){
	//classes objects
	MemberRecord m;
	AccountBill a;
	Book b;
	Transaction t;
	LibraryStaff l[1000];
	char op;
	int i=1;
	int loop=0;
		cout<<"\n\tLibrary Staff\n";
		l[1].setStaff();//calling function
		int r=dispStaff(l,i);//calling function with int return type
		if(r==0){
			return 0;
		}
}

