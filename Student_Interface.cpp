#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<windows.h>
#include<question.h>
using namespace std;
using namespace questions;
class student
	{
		char name[50];
		int admn,cia;
		char usn[20];
		public:
		void regist();
		int check();	
		int signin();
		friend int test();
		friend void uscore(int,int); 
		friend void score(int); 
	};
	
void student::regist()
{
	int x=0,f=0;
	cout<<"\t\t\t\t\tGive Your Admisson Number: ";
	cin>>admn;
		
	
	cout<<"\t\t\t\t\tGive Your USN: ";
	cin>>usn;
	if(admn==0||usn==0)
	{
		cout<<"\n\n\t\t\t\t\tTerminating Program.......";
		Sleep(1000);
		exit(0);
	}
	f = strlen(usn);
	while(x != f)
	{
		usn[x] = toupper(usn[x]);
		x++;
	}
	system("CLS");
}
int student::check()
{
	student *p = new student[10];
	ifstream fin;
	fin.open("admin1.bin",ios::in|ios::binary);
	for(;;)
	{
		fin.read((char*)p,sizeof(student));
		if(fin.eof())
			break;
		else if(p->admn==admn||strcmp(p->usn,usn)==0)
			return 0;
	}
	return 1;
}

int student::signin()
{
	int flag=0,x=0,f=0;
	ifstream fin;
	student obj,*p = new student[10];
	again:system("CLS");
	cout<<"\nINSTRUCTIONS:-\n";
	cout<<"1.Login id is your Admission Number.\n2.Password is your USN.\n3.To go back to main menu give '0' as your Login Id\n\n";
	cout<<"Enter your Login Id : ";
	cin>>admn;
	if(admn==0)
	{
		cout<<"\t\t\t\t\t\t.....ABORTED!!!!\n\n";
		return 0;
	}
	cout<<"Enter your Password : ";
	cin>>usn;
	x= 0;f = 0;
	f = strlen(usn);
	while(x != f)
	{
		usn[x] = toupper(usn[x]);
		x++;
	}
	fin.open("admin1.bin",ios::in|ios::binary);
	for(;;)
	{
		fin.read((char*)p,sizeof(student));
		if(fin.eof())
			break;
		else if(p->admn==admn&&strcmp(p->usn,usn)==0)
			flag=1;
	}
	if(flag==0)
	{
		cout<<"\t\t\t\t\tGive correct credentials again....\n";
		fin.close();
		Sleep(2000);
		goto again;
	}
	else
	{
		system("ClS");
		return(admn); 	
	}
}
int test()
{   
	SYSTEMTIME st,et;
	ifstream fin,finn,fi;
	ofstream fout; 
	hard h[10];
	easy e[10];
	int f,a,t=12,j,score=0,flag=0,c,k;
	fin.open("qe.bin",ios::in|ios::binary);
	finn.open("qh.bin",ios::in|ios::binary);
	system("CLS");
	cout<<"INSTRUCTIONS:\n";
	cout<<"1.For each question Max time limit is 10 seconds.\n2.You have to answer each question even if its wrong else next question will not appear.\n";
	cout<<"3.The time is calculated implicitly which means automatically your marks will be deducted after 10 seconds.\n";
	cout<<"4.Your score will be made available at the end and also will be updated\n5.If you choose to attempt the test then you can't return back until the test is completed.\n";
	cout<<"5.Marks will be updated at the end so don't try to terminate the portal else all your details will be lost.\n\n";
	cout<<"Press '1' to continue and '0' to go back to Main Menu.\n";
	cin>>c;
	if(c==0)
		return(0);
	cout<<"\n\n\n\t\t\t\t\t\tChecking Previous Activities..."<<endl;
	Sleep(2000);
	nos *ob = new nos[10],no;
	fi.open("nos1.bin",ios::in|ios::binary);
	if(!fi)
		return(-2);
	fi.read ((char*)ob, sizeof(nos));
	fi.close();
	if(ob->count>1)
	return(-1);
	no.count = ob->count;
	no.count++;
	fout.open("nos1.bin",ios::out|ios::binary);
	fout.write((char*)&no,sizeof(nos));
	fout.close();
	cout<<"\n\n\n\t\t\t\t\t\tGenerating Question Paper..."<<endl;
	Sleep(1500);
	cout<<"\n\n\n\t\t\t\t\t\t\tALL THE BEST\n";
	Sleep(1000);
	system("CLS");		
	for(j=0;j<5;j++)
	{
		if(ob->count==1)
			f = (j+1)%5;
		else
			f = (j+3)%5;
		if(t<=7&&flag==1)
		{	
			finn.seekg(f*sizeof(hard),ios::beg);
			finn.read ((char*)&h[f],sizeof(hard));		
			h[f].disph();
			cout<<"Choice: ";
			GetSystemTime(&st);
			cin>>a;
			GetSystemTime(&et);			
			t = et.wSecond-st.wSecond;
			if(t<=10&&a==h[f].answer)
			{
				score = score+1;
				flag=1;
			}
		}
		else
		{		
			fin.seekg(f*sizeof(easy),ios::beg);
			fin.read ((char*)&e[f],sizeof(easy));		
			e[f].dispe();
			cout<<"Choice: ";
			GetSystemTime(&st);
			cin>>a;
			GetSystemTime(&et);			
			t = et.wSecond-st.wSecond;
			if(t<=10&&a==e[f].answer)
			{
				score = score+1;
				flag=1;
			}
		}
	}
	cout<<"\n\t\t\t\t\t\tScore is:"<<score<<endl;	
	Sleep(2000);
	return(score);
}
void uscore(int score,int adm)
{
	student p;
	fstream fin;
	fin.open("admin1.bin",ios::in|ios::out|ios::binary);
	for(;;)
	{
		fin.read((char*)&p,sizeof(student));
		if(fin.eof())
			break;
		else if(p.admn==adm)
		{
			break;
		}
	}
	p.cia  = score;
	fin.seekp(-(sizeof(p)),ios::cur);
	fin.write((char*)&p,sizeof(student));
	fin.close();	
}
void score(int adm)
{
	student p;
	ifstream fin;
	fin.open("admin1.bin",ios::in|ios::binary);
	for(;;)
	{
		fin.read((char*)&p,sizeof(student));
		if(fin.eof())
			break;
		else if(p.admn==adm)
		{
			break;
		}
	}
	cout<<"\n\t\t\t\t\t\tYour previous score was: ";
	cout<<p.cia;
	Sleep(2000);
	fin.close();
}

int main()
{
	student obj,*p = new student[10];
	ofstream fout;
	int check,choice,adm=0,choose,ret;
	again:cout<<"\n\t\t\t\t\t\t1.Registration\n\t\t\t\t\t\t2.Sign In\n\t\t\t\t\t\t3.Exit\n\n\t\t\t\t\t\tChoice:-";
	cin>>choice;
	switch(choice)
	{
		case 1:{
			fout.open("admin1.bin",ios::out|ios::app|ios::binary);
			if(!fout)
			{
				cout<<"\t\t\t\t\tFile Missing...Terminated\n";
				exit(0);
			}
			a:obj.regist();
			check = obj.check();
			if(check==1)
			{
				fout.write((char*)&obj,sizeof(student));
				fout.close();
			}
			else
			{
				printf("\t\t\t\tAlready registered give the correct details\n");
				goto a;
			}			
			break;
		}
		case 2: 
			adm = obj.signin();
			if(adm!=0)
			{
				cout<<"\n\t\t\t\t\t\t\t1.Tests\n\t\t\t\t\t\t\t2.Scores\n\n\t\t\t\t\t\t\tChoice:-";
				cin>>choose;
				switch(choose)
				{
					case 1:{
						ret = test(); 
						if(ret == -1)
						{
							cout<<"\n\n\tYou have already attempted the test or you have directly closed the portal more than one time......";
							Sleep(1500);
						}
						else if(ret==0)
						{
							break;
						}
						else if(ret== -2)
						{
							cout<<"\t\t\t\t\tFile Missing...Terminated\n";
							exit(0);
						}
						else
						{
							uscore(ret,adm);
						}
						break;
					} 
					case 2: 
						score(adm);
							break;	
				}			
			}
		case 3: 
			system("CLS");
			cout<<"\n\t\t\t\t\t\tSaving Data and Closing.\n";
			Sleep(1000);
			exit(0);
			break;
		default:
			system("CLS");
			main();
			break;		
	}
	goto again;
} 	
