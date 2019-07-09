#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
typedef struct nos{
	int cs;
}nos;
typedef struct Quest{
 	
 	char t[200];
 	char a[100],b[100],c[100],d[100];
 	int answer;
 	
}quest;
typedef struct Data{
	char name[50];
	int admn,cia;
	char usn[20];
    }data;
	
void registration()
{	
	data *m,*c;
	FILE *p;
	p = fopen("admin.bin","ab+");
	if(p == NULL)
	{
		printf("\t\t\t\tFILE MISSING TERMINATING....");
		exit(0);
	}
	c = (data*)malloc(sizeof(data));
	m = (data*)malloc(sizeof(data));
	printf("\nINSTRUCTIONS\n");
	printf("1.To go back to main menu press '0'.\n\n");
	printf("\n");
		
			a:printf("Enter the student's Admission Number and USN -\n");
			scanf("%d",&m->admn);
			if(m->admn==0)
			{
				printf("\t\t\t\t.....ABORTED!!!!\n\n");
				Sleep(1000);
				system("cls");
				return;
				
			}
			fflush(stdin);
			scanf("%s",m->usn);
			rewind(p);
			for(;;)
			{
				fread(c,sizeof(data),1,p);
				if(feof(p))
				break;
			 	else if((m->admn==c->admn)||(strcmp(m->usn,c->usn)==0))
				{
				printf("\t\t\t\t\tALREADY REGISTERED..\n\n");
				goto a;
				}
			}
			printf("Enter student's name\n");
			fflush(stdin);
			gets(m->name);
			fwrite(m,sizeof(data),1,p);

		fclose(p);
		printf("\n\t\t\t\t\t...DATABASE UPDATED SUCCESSFULLY...\n\n");
}

int signin()
{
	FILE *p;
	p = fopen("admin.bin","ab+");
	if(p==NULL)
	{
		printf("\t\t\t\tFILE MISSING TERMINATED.....");
		exit(0);
	}
	int flag=0;
	data *m,*c;
	m = (data*)malloc(sizeof(data));
	c = (data*)malloc(sizeof(data));
	printf("\nINSTRUCTIONS:\n");
	printf("1.Login id is your Admission Number.\n2.Password is your USN.\n3.To go back to main menu give '0' as your Login Id\n\n");
	
	again:printf("Enter your Login Id : ");
		scanf("%d",&m->admn);
	if(m->admn==0)
			{
				printf("\t\t\t\t.....ABORTED!!!!\n\n");
				Sleep(1000);
				system("cls");
				main();
			}
		
	printf("Enter your Password : ");
	scanf("%s",m->usn);
	rewind(p);
	for(;;)
			{
				fread(c,sizeof(data),1,p);
				if(feof(p))
				break;
				
				else if((strcmp(m->usn,c->usn)!=0)||(m->admn!=c->admn))
				flag=1;
				else
				return(c->admn);
			}	
	if(flag==1)
	{
	printf("\t\t\t\t\tGive correct credentials again....\n");
	goto again;
	}
}

void display()
{
	
	FILE *p;
	p = fopen("admin.bin","rb");
	
	data *w;
	w = (data*)malloc(sizeof(data));
	
	for(;;)
	{
		fread(w,sizeof(data),1,p);
		if(feof(p))
		break;
		else
		printf("%s\t%d\t%s\t%d\n\n",w->name,w->admn,w->usn,w->cia);
	}
}
void updatescore(int admn,int score)
{
	FILE *p;
	p = fopen("admin.bin","rb+");
	if(p==NULL)
	{
		printf("\t\t\t\tFILE MISSING TERMINATED.....");
		exit(0);
	}
	data *m;
	m = (data*)malloc(sizeof(data));
	for(;;)
	{
		fread(m,sizeof(data),1,p);
		if(feof(p))
		break;
		else if(m->admn==admn)
		{
			m->cia = score+m->cia;
			fseek(p,-(sizeof(data)),SEEK_CUR);
			fwrite(m,sizeof(data),1,p);
			fseek(p,sizeof(data),SEEK_CUR);
		}
	}
}

	
int test()
{
FILE *p,*q,*v;
	v = fopen("nos.bin","rb+");
	if(v==NULL)
	return(-2);
	
	p = fopen("qh.bin","rb");
	if(p == NULL)
	{
		printf("\t\t\t\tFILE MISSING TERMINATING....");
		exit(0);
	}
	q = fopen("qe.bin","rb");
	if(q == NULL)
	{
		printf("\t\t\t\tFILE MISSING TERMINATING....");
		exit(0);
	}
	int a=0,i,j,score=0,t=12,flag=0,c;
	SYSTEMTIME st,et;

	nos *s;
	s = (nos*)malloc(sizeof(nos));
	quest *e[5],*h[5];
	for(i=0;i<5;i++)
		e[i] = (quest*)malloc(sizeof(quest));
	for(i=0;i<5;i++)
		h[i] = (quest*)malloc(sizeof(quest));
	
	printf("INSTRUCTIONS:\n");
	printf("1.For each question Max time limit is 10 seconds.\n2.You have to answer each question even if its wrong else next question will not appear.\n");
	printf("3.The time is calculated implicitly which means automatically your marks will be deducted after 10 seconds\n");
	printf("4.Your score will be made available at the end and also will be updated\n5.If you choose to attempt the test then you can't return back until the test is completed\n");
	printf("5.Marks will be updated at the end so don't try to terminate the portal else all your details will be lost\n\n");
	printf("Press '1' to continue and '0' to go back to Main Menu\n");
	scanf("%d",&c);
fread(s,sizeof(nos),1,v);
if(s->cs > 1)
return(-1);

else
{
if(c==1)
{
	s->cs++;
	fseek(v,-(sizeof(nos)),SEEK_CUR);
	fwrite(s,sizeof(nos),1,v);
	fseek(v,sizeof(nos),SEEK_CUR);
	fclose(v);
	printf("\t\t\t\t\tRedirecting you to new page....");
	Sleep(2000);
	system("cls");
	v = fopen("nos.bin","rb");    
	fread(s,sizeof(nos),1,v);	
	for(j=0;j<5;j++)
	{		
		if(s->cs == 1)		
		i = (j+1)%5;
		else
		i  = (j+3)%5;
			
			if(t<=7&&flag==1)
				{
					fseek(q,i*sizeof(quest),SEEK_SET);	
					fread(h[i],sizeof(quest),1,p);
					printf("Question %d: ", j+1);
					puts(h[i]->t);
					printf("1:");
					puts(h[i]->a);
					printf("2:");
					puts(h[i]->b);
					printf("3:");
					puts(h[i]->c);
					printf("4:");
					puts(h[i]->d);
					printf("choice: ");
					GetSystemTime(&st);
					scanf("%d",&a);
					GetSystemTime(&et);
					t = et.wSecond-st.wSecond;
					if(t<=10&&a==h[i]->answer)
					{
						score = score+1;
						flag=1;
					}
					else
					flag=0;
					printf("\n");
				}
				else
				{	
					fseek(q,i*sizeof(quest),SEEK_SET);	
					fread(e[i],sizeof(quest),1,q);
					printf("Question %d: ",j+1);
					puts(e[i]->t);
					printf("1:");
					puts(e[i]->a);
					printf("2:");
					puts(e[i]->b);
					printf("3:");
					puts(e[i]->c);
					printf("4:");
					puts(e[i]->d);
					printf("choice: ");
					GetSystemTime(&st);
					scanf("%d",&a);
					GetSystemTime(&et);
					t = et.wSecond-st.wSecond;
					if(t<=10&&a==e[i]->answer)
					{
						score = score+1;
						flag=1;
					}
					else
					flag=0;
					printf("\n");
				}
	}
fclose(p);
fclose(q);
}

else
return(0);	
printf("You scored %d",score);
return(score);
}
}
main()
{
	int choice, choose, w,score;
	a:printf("Welcome To Student Portal\n\n");
	printf("1.Registration\n2.Sign In\n3.Display\n4.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{

		case 1:registration();
		sleep(1000);
		break;
		
		case 2: w = signin();
					printf("\n\t\t\t\t\tDirecting......");
					Sleep(2000);
					system("cls");
					
					printf("1.Tests\n2.Scores\n");
					scanf("%d",&choose);
				switch(choose)
				{
					case 1:score=test(w);
					if(score==0)
					system("cls");
					else if(score == -1)
					{
						printf("You have already attempted the test or you have directly closed the portal more than one time......");
						Sleep(4000);
						system("cls");
					}
					else if(score == -2)
					{
						printf("\t\t\t\t\tFILE MISSING TERMINATED......");
						exit(0);
					}
					else
					{
						updatescore(w,score);
						printf("\nYour score is updated successfully.....");
						Sleep(2000);
						system("cls");	
						break;
					}
					
				
				//case 2: display(w);
				//	break;
					
				}		
		break;
		
		case 3:display();
			break;
		case 4: 
		printf("Bye!\n");
		Sleep(1000);
		exit(0);
	}
//	system("cls");
goto a;
}  	
