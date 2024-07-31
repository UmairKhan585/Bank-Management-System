//      ------------------------------------    
//      |   Libraries To Start The Project  |
//      ------------------------------------ 

#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
int a;

//      ------------------------------------
//      |        Creating Class             |
//      ------------------------------------

class Bank
{
private:
	long long int cnic;
	int Acc_no, bal;
	char Name[100], Address[200], type;


public:
	void Create_Account();
	void Display_Acc() const;
	int deposit_bal(int add);
	int withdraw(int amount);
	void T_BalEnq();
	void Acc_list();
	void Modify_Account();
	void Close_Account();
	int returnacno() const;
	int returndeposit() const;
	char returntype() const;
	long long int returncnic() const;
	void data() const;
	int returnbal() const;
};

int Bank::returnbal()const
{
	return bal;
}

int Bank::returnacno() const
{
	return Acc_no;
}

int Bank::returndeposit() const
{
	return bal;
}

char Bank::returntype() const
{
	return type;
}

long long int Bank::returncnic() const
{
	return cnic;
}

void Bank::data() const
{
	cout << " " << Acc_no << setw(18) << setfill(' ') << " " << Name << setw(18) << setfill(' ') << " " << type << setw(18) << setfill(' ') << bal << endl;
	cout << endl;
	cout << endl;
}

//      ------------------------------------
//      |   Function To create new Account  |
//      ------------------------------------

void Bank::Create_Account()
{
	system("cls");
	system("color 0A");
	cout << "\t\t\t\t =================" << endl;
	cout << "\t\t\t\t| CREATE ACCOUNT |" << endl;
	cout << "\t\t\t\t=================" << endl << endl;
	cout << "\t\t\t\tEnter your Cnic no::"; cin >> cnic;
	cout << "\t\t\t\tEnter Your Account-Number :: "; cin >> Acc_no;

	bool found = false;
	Bank client;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "\t\t\t\tFile could not be open !! Press any Key...";
		return;
	}

	while (!File.eof() && found == false)
	{
		while (File.read(reinterpret_cast<char *> (&client), sizeof(Bank)))
		{
			if (client.returnacno() == Acc_no)
			{
				cout << endl << endl;
				cout << setw(40) << setfill(' ') << " " << setw(22) << setfill('-') << "-" << endl;
				cout << setw(40) << setfill(' ') << " " << "Account Already exists" << endl;
				cout << setw(40) << setfill(' ') << " " << setw(22) << setfill('-') << "-" << endl;
				Sleep(3000);
				a = 0;
				break;
			}

			found = true;
		}

		if (client.returnacno() != Acc_no)
		{
			cout << "\t\t\t\tEnter Name of Your Account_Holder(Customer) :: ";
			cin.ignore();
			cin.getline(Name, 100);
			cout << "\t\t\t\tEnter Your Address :: ";
			cin.ignore();
			cin.getline(Address, 200);
			cout << "\t\t\t\tWhat type of Account you want to create C or S :: ";
			cin >> type;
			if (type != 'S' && type != 'C'&&type != 's' && type != 'c')
			{
				cout << "Invalid Type Entered!" << endl;
				Sleep(2000);
				Create_Account();
			}
			else
			{
				type = toupper(type);
				cout << "\t\t\t\tEnter the Amount for deposit:: ";
				cin >> bal;
				cout << endl << endl;
				cout << "\t\t\t\t================" << endl;
				cout << "\t\t\t\tAccount Created!" << endl;
				cout << "\t\t\t\t================" << endl;
				a = 1;
			}
		}
		File.eof();
		found = true;

	}
	File.close();
}

//      ------------------------------------
//      |  Funvtion for Dispalying Account  |
//      ------------------------------------

void Bank::Display_Acc() const
{
	cout << "\t\t\t\tHolder's Name of Account :: " << Name << endl;
	cout << "\t\t\t\tCnic no:: " << cnic << endl;
	cout << "\t\t\t\tAccount Number :: " << Acc_no << endl;
	cout << "\t\t\t\tAccount Type :: " << type << endl;
	cout << "\t\t\t\tHolder's Address :: " << Address << endl;
	cout << "\t\t\t\tTotal Amount :: " << bal << endl;
}

//      -----------------------------------------------
//      |   Function for depositing Amount from user  |
//      -----------------------------------------------

int  Bank::deposit_bal(int add)
{
	bal = bal + add;
	return bal;
}

//      ----------------------------------------------
//      |   Function for withdrawing Amount from user |
//      ----------------------------------------------

int Bank::withdraw(int amount)
{
	bal -= amount;
	return bal;
}

//      ----------------------------------------------
//      |   Function for Modifying Account            |
//      ----------------------------------------------

void Bank::Modify_Account()
{
	cout << "\nAccount No. : " << Acc_no;
	cout << "\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(Name, 100);
	cout << "\nModify Type of Account : ";
	cin >> type;
	type = toupper(type);
	cout << "\nModify Balance amount : ";
	cin >> bal;
}
void file_account();
void displayaccount(long long int search);
void record_edit(long long int search1);
void deleteAccount(long long int search2);
void displayAllAccount(string pswrd);
void deposit_withdraw(long long int n, int option);

//      -----------------------------------------------
//      |          Entering Point of Project           |
//      -----------------------------------------------

int main()
{
	string pswrd;
	char b;
	char option;
	long long int c_num;
	cout << endl;
	Sleep(2000);
	cout << "\t\t\t\t\t-----WELCOME!-----" << endl;
	cout << "\t\t\t\t\t\tTO" << endl << endl;
	Sleep(1500);
	do{
		system("Color 03");
		cout << "\t\t\t\t" << setw(41) << setfill('-') << "-" << endl;
		cout << "\t\t\t\t" << "|" << "\tBAHRIA BANK  LIMITED" << "\t\t|" << endl;
		cout << "\t\t\t\t|\t'Choose your Best'\t\t|" << endl;
		cout << "\t\t\t\t" << setw(41) << setfill('-') << "-" << endl << endl;
		cout << "\t\t\t\t" << setw(41) << setfill('*') << "*" << endl;
		cout << "\t\t\t\t" << "|" << "\tMADE BY :: UMAIR MUNIR " << "\t\t|" << endl;
		cout << "\t\t\t\t" << "|" << "\t\t& " << "\t\t\t|" << endl;
		Sleep(2000);
		cout << "\t\t\t\t\t\tMain Menu" << endl;
		cout << "\t\t\t\t" << setw(41) << setfill('-') << "-" << endl << endl;
		cout << "\t\t\t\t\t1. Create New Account" << endl;
		cout << "\t\t\t\t\t2. Deposit an Amount" << endl;

		cout << "\t\t\t\t\t3. Withdraw an Amount" << endl;

		cout << "\t\t\t\t\t4. Total Balance Enquiry" << endl;

		cout << "\t\t\t\t\t5. Accounts Holder List" << endl;

		cout << "\t\t\t\t\t6. Modify an Account" << endl;

		cout << "\t\t\t\t\t7. Close an Account" << endl;

		cout << "\t\t\t\t\t8. Exit" << endl << endl;
		cout << "\t\t\t\t\t->Choose your option: ";
		cin >> option;
		if (option == '1')
		{
			file_account();
		}
		else if (option == '2')
		{
			cout << "enter cnic no: "; cin >> c_num;
			deposit_withdraw(c_num, 1);
		}
		else if (option == '3')
		{
			cout << "enter cnic no: "; cin >> c_num;
			deposit_withdraw(c_num, 2);
		}
		else if (option == '4')
		{
			cout << "enter cnic no: "; cin >> c_num;
			displayaccount(c_num);
		}

		else if (option == '5')
		{
			cout << "enter password::"; cin >> pswrd;
			displayAllAccount(pswrd);
		}


		else if (option == '6')
		{
			cout << "enter cnic no: "; cin >> c_num;
			record_edit(c_num);
		}

		else if (option == '7')
		{
			cout << "enter cnic no: "; cin >> c_num;
			deleteAccount(c_num);

		}

		else if (option == '8')
		{
			cout << "\n\n\tThanks for using bank managemnt system";
		}
		else
		{
			cout << "\t\t\tWrong input" << endl;
		}
		cout << endl;
		cout << "do you want to continue(y/n)::"; cin >> b;
		system("cls");
	} while (b == 'y' || b == 'Y');
	cin.ignore();
	cin.get();

	return 0;
}

//      -----------------------------------------------
//      |              File Handling                   |
//      -----------------------------------------------

void file_account()
{

	Bank client;
	ofstream data;
	data.open("account.dat", ios::binary | ios::app);
	client.Create_Account();
	if (a == 1){
		data.write(reinterpret_cast<char *> (&client), sizeof(Bank));
		data.close();
	}
	if (a == 0){
		data.close();
	}
}
void displayaccount(long long int search)//for searching user account
{
	system("cls");
	system("color 0D");
	Bank client;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "\t\t\tUnable to open the file!!!!! Press any Key...";
		return;
	}
	cout << endl << endl;
	cout << "\t\t\t===============" << endl;
	cout << "\t\t\tBALANCE DETAILS" << endl;
	cout << "\t\t\t===============" << endl;
	while (inFile.read(reinterpret_cast<char *> (&client), sizeof(Bank)))
	{
		if (client.returncnic() == search)
		{
			client.Display_Acc();
			flag = true;
		}
	}
	if (client.returncnic() != search&&flag == false)
	{
		cout << endl << endl;
		cout << "\t\t\t==========================" << endl;
		cout << "\t\t\tAccount does not exist" << endl;
		cout << "\t\t\t==========================" << endl;
	}

	inFile.close();
}

void record_edit(long long int search1)
{
	system("cls");
	system("color 8F");
	bool found = false;
	Bank client;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *> (&client), sizeof(Bank));
		if (client.returncnic() == search1)
		{
			client.Display_Acc();
			cout << "\n\nEnter The New Details of account" << endl;
			client.Modify_Account();
			int pos = (-1)*static_cast<int>(sizeof(Bank));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *> (&client), sizeof(Bank));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)

		cout << "Record Not Found ";
}


void deleteAccount(long long int search2)
{
	system("cls");
	system("color 0E");
	Bank client;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char *> (&client), sizeof(Bank)))
	{
		if (client.returncnic() != search2)
		{
			outFile.write(reinterpret_cast<char *> (&client), sizeof(Bank));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\t\t\t=================" << endl;
	cout << "\t\t\tRecord Deleted .." << endl;
	cout << "\t\t\t=================" << endl;
}

void displayAllAccount(string pswrd)
{
	system("cls");
	system("color 70");
	Bank client;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	if (pswrd == "umair1234"){
		cout << "\t\t\t\t==================" << endl;
		cout << "\t\t\t\tACCESS GRANTED!!!!" << endl;
		cout << "\t\t\t\t==================" << endl;
		Sleep(1500);
		system("cls");
		cout << "\n\n\t\t\tACCOUNT HOLDER LIST\n\n";
		cout << setw(70) << setfill('=') << "=" << endl;
		cout << "A/c no" << setw(9) << setfill(' ') << " " << "NAME" << setw(15) << setfill(' ') << " " << "Type" << setw(18) << setfill(' ') << " " << " Balance\n";
		cout << setw(70) << setfill('=') << "=" << endl;
		while (inFile.read(reinterpret_cast<char *> (&client), sizeof(Bank)))
		{
			client.data();
		}
	}
	else{
		cout << "\t\t\t\t=================" << endl;
		cout << "\t\t\t\tACCESS DENIED!!!!" << endl;
		cout << "\t\t\t\t=================" << endl;
		inFile.close();
	}
}

void deposit_withdraw(long long int n, int option)
{
	int amnt;
	bool found = false;
	Bank client;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{

		while (File.read(reinterpret_cast<char *> (&client), sizeof(Bank)))
		{
			if (client.returncnic() == n)
			{
				client.Display_Acc();
				Sleep(2000);
				if (option == 1)
				{
					system("cls");
					system("color 0E");
					cout << "\t\t\t===================" << endl;
					cout << "\t\t\tTO DEPOSIT AMOUNT " << endl;
					cout << "\t\t\t===================" << endl;
					cout << "\n\n\t\tEnter The amount to be deposited::";
					cin >> amnt;
					client.deposit_bal(amnt);
					int pos1 = (-1)*static_cast<int>(sizeof(client));
					File.seekp(pos1, ios::cur);
					File.write(reinterpret_cast<char *> (&client), sizeof(Bank));
					cout << setw(40) << setfill(' ') << " " << setw(14) << setfill('-') << "-" << endl;
					cout << setw(40) << setfill(' ') << " " << "Record Updated" << endl;
					cout << setw(40) << setfill(' ') << " " << setw(14) << setfill('-') << "-" << endl;
					found = true;
				}
				else if (option == 2)
				{
					system("cls");
					system("color 0C");
					cout << "\t\t\t===================" << endl;
					cout << "\t\t\tTO WITHDRAW AMOUNT " << endl;
					cout << "\t\t\t===================" << endl;
					cout << "\n\n\t\tEnter The amount to be withdraw::";
					cin >> amnt;
					if (amnt > client.returnbal())
					{

						cout << endl << endl;
						cout << setw(40) << setfill(' ') << " " << setw(22) << setfill('-') << "-" << endl;
						cout << setw(40) << setfill(' ') << " " << "Insufficienct balance" << endl;
						cout << setw(40) << setfill(' ') << " " << setw(22) << setfill('-') << "-" << endl;
					}
					else
					{
						client.withdraw(amnt);
					}
					int pos = (-1)*static_cast<int>(sizeof(client));
					File.seekp(pos, ios::cur);
					File.write(reinterpret_cast<char *> (&client), sizeof(Bank));


					cout << setw(40) << setfill(' ') << " " << setw(14) << setfill('-') << "-" << endl;
					cout << setw(40) << setfill(' ') << " " << "Record Updated" << endl;
					cout << setw(40) << setfill(' ') << " " << setw(14) << setfill('-') << "-" << endl;
					found = true;
				}
			}
		}
		if (found == false){
			cout << endl << endl;
			cout << setw(40) << setfill(' ') << " " << setw(18) << setfill('-') << "-" << endl;
			cout << setw(40) << setfill(' ') << " " << "Record Not Found " << endl;
			cout << setw(40) << setfill(' ') << " " << setw(18) << setfill('-') << "-" << endl;
		}
		File.close();
	}
}

//      -----------------------------------------------
//      |            Project Completed                 |
//      -----------------------------------------------

    
