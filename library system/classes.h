#include<iostream>
using namespace std;
class Book{//base class
	protected://protected access specifier used for inheritance
	int bookId,rackNo;
	string bookName,author,edition,dateOfPurchase;
	float price;
	public:
		string status;
		Book(){//default constructor
			bookName="";author="";status="Available";edition="";dateOfPurchase="";price=0.0;bookId=0;rackNo=0;
		}
		Book(string a){//parameterized constructor
			status=a;
		}
		void displayBookDetails(string a){//display class data members
			status=a;
			cout<<"\n\tBook ID: "<<bookId;
			cout<<"\n\tBook Name: "<<bookName;
			cout<<"\n\tAuthor Name: "<<author;
			cout<<"\n\tStatus: "<<status;
			cout<<"\n\tEdition: "<<edition;
			cout<<"\n\tDate of Purchase: "<<dateOfPurchase;
			cout<<"\n\tRack NO#: "<<rackNo;
			cout<<"\n\tPrice: "<<price;
		}
		void updateStatus(string a){//function to updtae value
			status=a;
		}
		void bookstatus(){
			cout<<status;
		}
		void addBook(){//setter to initialize value
			cout<<"\n\tEnter Book ID: ";
			cin>>bookId;
			cout<<"\n\tEnter Book Name: ";
			cin>>bookName;
			cout<<"\n\tEnter Author Name: ";
			cin>>author;
			cout<<"\n\tEnter Edition: ";
			cin>>edition;
			cout<<"\n\tEnter Date of Purchase: ";
			cin>>dateOfPurchase;
			cout<<"\n\tEnter Rack No#: ";
			cin>>rackNo;
			cout<<"\n\tEnter Book Price: ";
			cin>>price;
		}
		//getters functions
		void bookprice(){
			cout<<price;
		}
		float getprice(){
			return price;
		}
		string bookname(){
			return bookName;
		}
		void bookid(){
			cout<<bookId;
		}
		void bookissue(string a){
			cout<<"\n\tBook Issue: "<<a;
		}
};
class Transaction:public Book{//inherited class from baseclass Book
	protected:
	int transId;
	string dateOfIssue,dueDate;
	public:
		Transaction(){//default constructor used to initialize members
			transId=0;dateOfIssue="";dueDate="";
		}
		//functions
		void addTransaction(){//setter function
			cout<<"\n\tEnter transaction id: ";
			cin>>transId;
			cout<<"\n\tEnter date Of Issue: ";
			cin>>dateOfIssue;
			cout<<"\n\tEnter dueDate: ";
			cin>>dueDate;
		}
		void createTransaction(){//function to display
			cout<<"\n\tTransaction Id: "<<transId;
			cout<<"\n\tDate of Issue: "<<dateOfIssue;
			cout<<"\n\tDue Date: "<<dueDate;
		}
		void deleteTransaction(){
			cout<<"\n\tTransaction Deleted.";
		}
};
//inheritance
class AccountBill:public Transaction{
	protected:
	int billNo;
	public:
		AccountBill(){//default constructor
			billNo=0;
		}
		void billno(int a){
		billNo=a+1;
		}
		void billCreate(){//function in function calling
			cout<<"\n\tBill No#: "<<billNo;
			 createTransaction();
			 cout<<"\n\tAmount: ";
			 bookprice();
		}
};
//inheritance
class MemberRecord:public AccountBill{
	protected:
	int memberId,noOfBookIssue,maxBookLimit;
	string dateOfMembership,memberName,adress;
	public:
		MemberRecord(){//default constructor
			maxBookLimit=1;noOfBookIssue=0;
		}
		MemberRecord(int a){//parameterized constructor
			noOfBookIssue=a;
		}
		void nobook(){
			noOfBookIssue=1;
		}
		void noBook(){
			noOfBookIssue=0;
		}
		void addMember(){//setter function
			cout<<"\n\tEnter Member Id: ";
			cin>>memberId;
			cout<<"\n\tEnter Name: ";
			cin>>memberName;
			cout<<"\n\tEnter Adress: ";
			cin>>adress;
			cout<<"\n\tEnter Date of membership: ";
			cin>>dateOfMembership;
		}
		void membername(){
			cout<<memberName;
		}
		void memberid(){
			cout<<memberId;
		}
		void dispMember(){//display function
			cout<<"\n\tMember ID: "<<memberId;
			cout<<"\n\tName: "<<memberName;
			cout<<"\n\tNO of Book Issue: "<<noOfBookIssue;
			cout<<"\n\tNo of Book Limit: "<<maxBookLimit;
			cout<<"\n\tAdress: "<<adress;
			cout<<"\n\tDate of Membership: "<<dateOfMembership;
		}
		void BookIssueLimit(){
			cout<<"\n\tEnter Book Issue Limit: ";
			cin>>maxBookLimit;
		}
};
//inheritance
class LibraryStaff:public MemberRecord{
	protected:
	string staffName,password;
	public:
		LibraryStaff(){//default constructor
			staffName="";password="library123";
		}
		//setter function
		void setStaff(){
			cout<<"\n\tEnter Staff Name: ";
			cin>>staffName;
			again:
			cout<<"\n\tEnter Password: ";
			cin>>password;
			if(password!="library123"){
				cout<<"\n\tWrong Password\n";
				goto again;
			}
		}
		friend void write(LibraryStaff (&l)[1000],int a);
		friend void read(LibraryStaff (&l)[1000]);
		friend void writemember(LibraryStaff (&l)[1000],int a,string);
};
