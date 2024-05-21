#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Bank
{	
private:
int accnum,id;
char name[50],city[50];

public:
void showChoice();
void addAccount();
void showAccount();
void searchAccount();
void deleteAccount();
void ExitProg();
};

void Bank::showChoice()
{
    
   	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"\t\tWelcome To The Banking Record System                "<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"Press <1> Add new account"<<endl;
	cout<<"Press <2> Show existing accounts"<<endl;
	cout<<"Press <3> Update a specific account"<<endl;
	cout<<"Press <4> Delete an account"<<endl;
	cout<<"Press <5> To terminate the program"<<endl;
	cout<<"To run the program please choice any number <1-2-3-4-5> :";
}
void Bank::addAccount()
{
	cout<<"\nEnter the Account Number  :\t";
	cin>>accnum;
	cout<<"Enter the Client Name     :\t";
	cin>>name;
	cout<<"Enter the Client ID       :\t";
	cin>>id;
	cout<<"Enter the City            :\t";
	cin>>city;
	

	ofstream sdata;
	if(!sdata)
	{
		cout<<"\nFile open failure!\n";
	}
    sdata.open("Banking record system.txt",ios::app);
    sdata<<endl;
    sdata<<accnum<<endl;
	sdata<<name<<endl;
	sdata<<id<<endl;
	sdata<<city<<endl<<endl;
    sdata.close();
    cout<<"\nAccount has been created successfully\n";
}

void Bank::showAccount()
{
	int b=0;
	ifstream tdata;
	tdata.open("Banking record system.txt");
	tdata>>accnum;
	tdata>>name;
	tdata>>id;
	tdata>>city;
	while(!tdata.eof())
	{
		b=1;
		cout<<"\nAccount_Number is :"<<accnum;
	    cout<<"\nClients_Name is   :"<<name;
	    cout<<"\nClients_ID is     :"<<id;
	    cout<<"\nCity is           :"<<city<<endl; 
		tdata>>accnum;
		tdata>>name;
		tdata>>id;
		tdata>>city;
        

    }
    if(b==0)
{
	cout<<"\nsorry ! The file is not contain the data ! \n";
}
    
	tdata.close();

}



void Bank::searchAccount()
{
int b=0;
int num;	
cout<<"\nEnter the Account Number want to update record: ";
cin>>num;

ifstream udata;
udata.open("Banking record system.txt");
    
ofstream n;
n.open("new.txt");

udata>>accnum;
udata>>name;
udata>>id;
udata>>city;

while(!udata.eof())
{
	if(accnum != num){
	 n<<endl;
	 n<<accnum<<endl;
	 n<<name<<endl;
	 n<<id<<endl;
	 n<<city<<endl<<endl;
	 
    }
    else
	{
	b=1;
	cout<<"\nThe Account number "<<num<<" has following data:";
	cout<<"\nAccount_Number is :"<<accnum;
	cout<<"\nClients_Name is   :"<<name;
	cout<<"\nClients_ID is     :"<<id;
	cout<<"\nCity is           :"<<city<<endl;
	cout<<"\nEnter the new data to Modify account: ";
	cout<<"\nEnter the Account Number  :\t";
	cin>>accnum;
	cout<<"Enter the Client Name     :\t";
	cin>>name;
	cout<<"Enter the Client ID       :\t";
	cin>>id;
	cout<<"Enter the City            :\t";
	cin>>city;
	cout<<"\nAccount has been updata successfully\n";
	
	n<<endl;
    n<<accnum<<endl;
	n<<name<<endl;
	n<<id<<endl;
	n<<city<<endl<<endl;

	}
	udata>>accnum;
    udata>>name;
    udata>>id;
    udata>>city;
	

}
if(b==0)
{
	cout<<"\nsorry ! The account number is not found\n";
}
n.close();
udata.close();

remove("Banking record system.txt");
rename("new.txt","Banking record system.txt");
   
}

void Bank::deleteAccount()
{
int b=0;
int deleteaccn;

cout<<"\nEnter the Account Number want to delete record :";
cin>>deleteaccn;

ifstream ddata;
ddata.open("Banking record system.txt");
    
ofstream n;
n.open("new.txt");

ddata>>accnum;
ddata>>name;
ddata>>id;
ddata>>city;
while(!ddata.eof())
{
	if(accnum != deleteaccn)
	{
	 n<<endl;
	 n<<accnum<<endl;
	 n<<name<<endl;
	 n<<id<<endl;
	 n<<city<<endl<<endl;
    }
    else
	{
		b=1;
		cout<<"\nAccount has been deleted successfully\n";
	}
	ddata>>accnum;
    ddata>>name;
    ddata>>id;
    ddata>>city;
	
}
if(b==0)
{
	cout<<"\nsorry ! The account number is not found\n";
}

n.close();
ddata.close();
remove("Banking record system.txt");
rename("new.txt","Banking record system.txt");
	
}


void Bank::ExitProg()
{
	exit(0);
}


int main()
{	
	Bank objb;
	int choice;
	while(true){
	    objb.showChoice();
		cin>>choice;
		cout<<"--------------------------------------------------------------------"<<endl;
		switch(choice){
			case 1:
				objb.addAccount();
				break;
			case 2:
				objb.showAccount();
				break;
			case 3:
				objb.searchAccount();
			    break;
			case 4:
				objb.deleteAccount();
				break;
			case 5:
				cout<<"\nThanks for using our system....";
				objb.ExitProg();
				break;
			default:
				cout << "Invalid choice!...press enter key to continue" <<endl;
		}
	}
	
return 0;
}
