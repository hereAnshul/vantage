#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<string>
#include<windows.h>
#include<question.h>
using namespace std;
using namespace questions;
int main()
{
	ofstream fout;
	int n,i;
	a:cout<<"\t\t\t\t\t\t\t1.Hard set\n\t\t\t\t\t\t\t2.Easy set\n\t\t\t\t\t\t\t3.Set Count\n\t\t\t\t\t\t\t4.Exit\n\n\t\t\t\t\t\t\tChoice: ";
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
				cout<<"How many questions?\n";
				cin>>n;
				hard h[n];			
				fout.open("qh1.bin",ios::out|ios::binary); 
				for(i=0;i<n;i++)
				{
					h[i].seth();
				}
				for(i=0;i<n;i++)
				{
					fout.write((char*)&h[i],sizeof(question));	
				}
				
				fout.close();	
				break;
		}
	
		case 2: {
			cout<<"How many questions?\n";
				cin>>n;
				easy e[n];			
				fout.open("qe.bin",ios::out|ios::binary); 
				for(i=0;i<n;i++)
				{
					e[i].sete();
				}
				for(i=0;i<n;i++)
				{
					fout.write((char*)&e[i],sizeof(question));	
				}
				
				fout.close();	
			break;
			}
		case 3: {
					nos no;
					no.count = 0;
					fout.open("nos1.bin",ios::out|ios::binary);
					fout.write((char*)&no,sizeof(nos));
					fout.close();
					break;
				}
			
		case 4: exit(0);
	}
	cout<<"\t\t\t\t\t\t\tSaving........\n";
	Sleep(1000);
	system("CLS");
	goto a;	
	
}
