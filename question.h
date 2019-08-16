using namespace std;
namespace questions
{
class nos{
	public:
	int count;
}; 
class question
{
	char t[200];
 	char a[100],b[100],c[100],d[100];
 	
 	public:
 	int answer;
	 friend void test();
	 setq()
	 {
	 	int n,i;
	 	        //cout<<"How many questions?\n";
	 	        //cin>>n;
				
				 	printf("Question: ");
					getchar();             //agar chaho toh question  ki do class bana skte hoh hard aur easy but zabardasti hoh jayegi so?
					gets(t);
					printf("1. ");
					gets(a);
					printf("2. ");
					gets(b);
					printf("3. ");
					gets(c);
					printf("4. ");
					gets(d);
					cin>>answer;
			
				 //key = rand()%5;
				 //nos = 0;
	}
	display()
	{
	cout<<endl;
	
			cout<<"Question: "<< t <<endl<<"1. "<<a<<endl<<"2. "<<b<<endl<<"3. "<<c<<endl<<"4. "<<d<<endl;
		}
	
};
class hard:public question
{
public:
seth()
{
	setq();
}	
	disph()
	{
		display();
	}
};
class easy:public question
{
public:
sete()
{
	setq();
	
}	
dispe()
	{
		display();
	}
	
};
	
	
}
