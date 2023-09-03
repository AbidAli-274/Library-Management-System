#include<iostream>
#include<fstream>//using header file for reading and writing in files
using namespace std;
//functions for reading and writing in files
void write(LibraryStaff (&l)[1000],int a){
	ofstream write;
	write.open("data.txt");//writing in data named file
	for(int i=0;i<a;i++){
			write<<"\n\tBook ID: "<<l[i].bookId;
			write<<"\n\tBook Name: "<<l[i].bookName;
			write<<"\n\tAuthor Name: "<<l[i].author;
			write<<"\n\tStatus: "<<l[i].status;
			write<<"\n\tEdition: "<<l[i].edition;
			write<<"\n\tDate of Purchase: "<<l[i].dateOfPurchase;
			write<<"\n\tRack NO#: "<<l[i].rackNo;
			write<<"\n\tPrice: "<<l[i].price;
			write<<endl;
	}
	write.close();//closing file
}
void writemember(LibraryStaff (&l)[1000],int a,string issue){
		ofstream write;
	write.open("data1.txt");
	for(int i=0;i<a;i++){
			write<<"\n\tMember ID: "<<l[i].memberId;
			write<<"\n\tName: "<<l[i].memberName;
			write<<"\n\tNO of Book Issue: "<<l[i].noOfBookIssue;
			write<<"\n\tNo of Book Limit: "<<l[i].maxBookLimit;
			write<<"\n\tAdress: "<<l[i].adress;
			write<<"\n\tDate of Membership: "<<l[i].dateOfMembership;
			write<<"\n\tBook Issue: "<<issue;
			write<<endl;
	}
	write.close();
}
void read(LibraryStaff (&l)[1000]){
		ifstream read;
	string ch;
	char c;
	read.open("data.txt");
	if(!read){
		cout<<"file not exist";
	}else{
				while(!read.eof()){
		getline(read,ch);//getting line by line from file
		cout<<ch<<endl;
		}
		}
}
void readmember(LibraryStaff (&l)[1000]){
			ifstream read;
	string ch;
	char c;
	read.open("data1.txt");
	if(!read){
		cout<<"file not exist";
	}else{
				while(!read.eof()){
		getline(read,ch);
		cout<<ch<<endl;
		}
		}
}
int dispStaff(LibraryStaff (&l)[1000],int a){//parameterized function
	int op,x=0,book=0,member=0,q=0,temp=0;//variables
	string issue,details;
	for(int i=0;x!=1;i++){//for loop used to make task continous 
	cout<<"\n(1)\t Add Book ";//displaying options
	cout<<"\n(2)\tReturn Book";
	cout<<"\n(3)\tMembers Record";
	cout<<"\n(4)\tIssue Book";
	cout<<"\n(5)\tAdd Member";
	cout<<"\n(6)\tBooks Record";
	cout<<"\n(7)\tExit";
	again1:
	cout<<"\n\tEnter Option: ";
	cin>>op;//entering option
		if(op>=1&&op<=7){//check conditions
	if(op==1){
		l[book].addBook();//calling member functions
			
		book++;
		write(l,book);//calling file for writing in file
	}
	if(a>0){
		if(book>0){
	if(op==2){
		if(book>0){
				int n=0;
		for(int f=0;f<book;f++){
			cout<<"\n\tSr#\tName\t\tID\n";
			cout<<"\n\t"<<f+1<<"\t";
			string s=l[f].bookname();
			cout<<a;
			cout<<"\t\t";
			l[f].bookid();
		}
		again4:
			cout<<"\n\tSelect your serial number: ";
			cin>>n;
			if(n>=1&&n<=book){
				cout<<"\n\tReturning book...............\n";
				l[n-1].updateStatus("available");
				l[n-1].status="Available";
				l[n-1].noBook();
			}
			else{
				cout<<"\n\tWrong input";
				goto again4;
			}
		}
		else{
			cout<<"\n\tPlease Add Books\n";
		}
	}
}
	if(op==3){
			if(member>0){
				readmember(l);//reading members data from file
		}
		if(member==0){
			cout<<"\n\tNo members please Add members\n";
		}
	}

	if(op==4){
		if(book>0&&member>0){
		int m=0;
		float amount,price;
		cout<<"\n\t\tMembers\n";
				int d=0;
		for(int f=0;f<member;f++){
			cout<<"\n\tSr#\tName\t\tID\n";
			cout<<"\n\t"<<f+1<<"\t";
			l[f].membername();
			cout<<"\t\t";
			l[f].memberid();
		}
			againx:
			cout<<"\n\tEnter your serial# : ";
			cin>>d;
			if(d>=1&&d<=member){
				cout<<"\n\tVerified....................\n";
			}
			else{
				cout<<"\n\tWrong input";
				goto againx;
			}
		cout<<"\n\tSelect serial number to buy book: ";
				for(int f=0;f<book;f++){
			cout<<"\n\tSr#\tBook Name\tPrice\t\tStatus\n";
			cout<<"\n\t"<<f+1<<"\t";
			string t=l[f].bookname();
			cout<<t;
			cout<<"\t\t";
			l[f].bookprice();
			cout<<"\t\t";
			cout<<l[f].status;
		}
					again5:
			cout<<"\n\tEnter sr.no#: ";
			cin>>m;
			if(l[m-1].status=="Available"){
			if(m>=1&&m<=book){
				
			l[m-1].addTransaction();
			l[m-1].billno(q);
			q++;
			cout<<"\n\t******BILL*******\n";
			issue=l[m-1].bookname();
			l[m-1].bookissue(issue);
			l[m-1].billCreate();
			price=l[m-1].getprice();
			wrong:
			cout<<"\n\tEnter your amount: ";
			cin>>amount;
			if(amount>=price){
				float change=amount-price;
				cout<<"\n\tChange: "<<change;
				temp=1;
				l[m-1].status="Not Available";
				l[m-1].nobook();
				MemberRecord m(1);
				//calling functions for writing in files
				write(l,book);
				writemember(l,member,issue);
			}
			if(amount<price){
				cout<<"\n\tPlease enter full amount: ";
				goto wrong;
			}
			}
			else{
				cout<<"\n\tWrong input";
				goto again5;
			}
		}
		else{
			cout<<"\n\tBook is Busy \n";
		}
		}
		else{
			cout<<"\n\tPlease Add books and members\n";
		}
	}
	if(op==6){
		if(book>0){
			read(l);//reading from file by calling function
}
if(book==0){
	cout<<"\n\tNo Book available please Add Books\n";
}
	}

}
if(op==5){
	l[member].addMember();
	member++;
	writemember(l,member,"No Book Issue");//writing members data in file
}
if(op==7){
	return 0;
}
a++;
}
else{
	cout<<"\n\tWrong Input\n";
	goto again1;
}
system("pause");
system("cls");
}
}

