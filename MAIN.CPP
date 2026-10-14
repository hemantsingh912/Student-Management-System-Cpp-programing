#include<iostream.h>
#include<conio.h>
#include<string.h>
#include "admin.cpp"
#include "fpasswor.cpp"
#include "password.cpp"

void main()
{            int i;
    while(1)
    {

	clrscr();
cout<<"\n\t***************************************************************\n";
cout<<"\t*                                                             *\n";
cout<<"\t*           WELCOME TO STUDENT MANAGEMENT SYSTEM              *\n";
cout<<"\t*                                                             *\n";
cout<<"\t***************************************************************\n\n\n\n\n\n";

	cout<<"\t\t1. School Admin Login"<<endl;
	cout<<"\t\t2. Faculty Login"<<endl;
	cout<<"\t\t3. Student Portal"<<endl;
	cout<<"\t\t4. Exit\n"<<endl;
	cout<<"\t\tSelect an Action:- ";
	cin>>i;

	if(i==4)
	    break;

	switch(i)
	{
	    case 1:
		{
			char user[100];
			char pass[100];

			char ch;
			 int i;
			login_again:
			clrscr();
			cout<<"                ***********************************************\n";
			cout<<"               (<------------------LOGIN PANEL--------------->)\n";
			cout<<"                ***********************************************\n";
			cout<<"\n\n\n\n\n\n\n\n";
			cout<<"\t\t\tEnter a Username:- ";
			cin>>user;

			cout<<"\t\t\tEnter a Password:- ";
			i = 0;
			while (1) {
			  ch = getch();
			    if (ch == 13) // Enter key
				break;
			    if (ch == 8 && i > 0) { // Backspace
				i--;
				printf("\b \b");
			    } else if (i < sizeof(pass) - 1) {
				pass[i++] = ch;
				printf("*");
			    }
			}
			pass[i] = '\0';

		if(strcmp(user,"Hemant")==0 && strcmp(pass,"12345")==0)
		{
			admin();
		}
		else
		{
			char l[10];
			cout<<"\nWrong Username or Password!\n";
			cout<<"Try again (yes/no):- ";
			cin>>l;

		if(strcmp(l,"YES")==0 || strcmp(l,"yes")==0)
			goto login_again;
		}
	    }
	    break;


	    case 2:
		faculty();
		break;

	    case 3:
		   passwords();
		break;

	    default:
		cout<<"\n\nInvalid Value";
		getch();
		break;

	}

    }

    getch();
}
