#include<iostream>
#include<vector>
using namespace std;
class bankaccount {
	private:
		string name;
		int accountnum;
		double balance;
	public:
		bankaccount(string n,int ac,double bal)
		{
			name =n;
			accountnum=ac;
			balance=bal;
		}	
		string getname()
		{
			return name;
		}
		int getaccountnum()
		{
			return accountnum;
		}
		double getbalance()
		{
			return balance;
		}
		void deposite(double amount)
		{
			balance=balance+amount;
		}
		void withdraw(double amount)
		{
			if(balance>=amount)
			{
				balance=balance-amount;
				cout<<"\n\t\tWithdrow succeesfully....."<<endl;
				
			}
			else
			{
				cout<<"\n\t\tsufficient balance\n";
			}
		}
};
class bankmanagement{
	private:
		vector<bankaccount> accounts;
    public:
    	void addaccount(string name,int accountname,double balance)
    	{
    		accounts.push_back(bankaccount(name,accountname,balance));
		}
		void showallaccount()
		{
			cout<<"\n\t\tAll account holder"<<endl;
			for(int i=0;i<accounts.size();i++)
			{
				cout<<"\n\t\tName :"<<accounts[i].getname()
				<<"\n\t\tAccount Number :"<<accounts[i].getaccountnum()
				<<"\n\t\tBalance :"<<accounts[i].getbalance()<<endl;
				
			}
		}
		void searchaccount(int account)
		{
			cout<<"\n\t\tAccount Holder"<<endl;
			for(int i=0;i<accounts.size();i++)
			{
				if(accounts[i].getaccountnum()==account)
				{
				   	cout<<"\n\t\tName :"<<accounts[i].getname()
				<<"\n\t\tAccount Number :"<<accounts[i].getaccountnum()
				<<"\n\t\tBalance :"<<accounts[i].getbalance()<<endl;	
				}
			}
		}
		bankaccount *findaccount(int accountnum)
		{
			for(int i=0;i<accounts.size();i++)
			{
				if(  accounts[i].getaccountnum()==accountnum)
				{
					return &accounts[i];
				}
			}
		}
};
main()
{
	bankmanagement bank;
	int choice;
	char op;
     do
	 {
    //system("cls");
    cout<<"\n\n\t\t::Bank Management System"<<endl;
	cout<<"\t\t\tMain menu"<<endl;
	cout<<"\t\t 1.create new account "<<endl
	<<"\t\t2.show all account\n"
	<<"\t\t3.srearch account\n"
	<<"\t\t4.deposite money \n"
	<<"\t\t5.withdrow money\n"
	<<"\t\t6.exit";
    cout<<"\n\t\t--------------------------\n";
    cout<<"\n\t\tenter your choice";
    cin>>choice;
    switch(choice)
    {
    	case 1:
		{
		
    		string name;
    		int accountnum;
    		double balance;
    		cout<<"\t\tenter name";
    		cin>>name;
    		cout<<"\t\tenter account number";
    		cin>>accountnum;
    		cout<<"\t\tenter initial balance";
    		cin>>balance;
    		
    		bank.addaccount(name,accountnum,balance);
    		cout<<"\t\taccount created sucseefully........";
    		break;
    	}
    		case 2:
			{
			
    			bank.showallaccount();
    			break;
    		}
    		case 3:
    			{
    				int accountnum;
    				cout<<"\n\t\tenter the account number";
    				cin>>accountnum;
    				bank.searchaccount(accountnum);
    				break;
				}
				case 4:
					{
						int accountnum;
						double amount;
						cout<<"\n\t\tEnter account number to deposite money :";
						cin>>accountnum;
						bankaccount* account=bank.findaccount(accountnum);
						if(account!=NULL)
						{
							cout<<"\n\t\tEnter ammount to deposite";
							cin>>amount;
							account->deposite(amount);
							 cout<<"\n\t\t"<<amount<<"Deposite successully......\n";
						}
					   else
					   {
							cout<<"\n\t\tacccount not found";
								 							 
															  
						}
				    
						break;
				}
					case 5:
						{
							int accountnum;
						double amount;
						cout<<"\n\t\tEnter account number to withdraw money :";
						cin>>accountnum;
						bankaccount* account=bank.findaccount(accountnum);
						if(account!=NULL)
						{
							cout<<"\n\t\tEnter ammount to withdraw";
							cin>>amount;
							account->withdraw(amount);
							 cout<<"\n\t\t"<<amount<<"withdraw successully......\n";
						}
					   else
					   {
							cout<<"\n\t\tacccount not found";
								 							 }
					   }
							break;
							
						}
	}
	
	
     while(choice!=6);
}

