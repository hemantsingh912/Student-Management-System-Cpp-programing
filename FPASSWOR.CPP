#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h> // printf ke liye zaruri hai
#include "teacher.cpp"


class fpass
{
    int teacher_ID;
    char user[100], pass[100];
    char name[100], subject[100], Qualification[100], phone_no[100];
    char username[100], password[100];

public:
void password1()
{
    fpass s;
    int found = 0;
    char line[400];
    char ch, choice;
    int i;

   clrscr();
			cout<<"                ***********************************************\n";
			cout<<"               (<------------------LOGIN PANEL--------------->)\n";
			cout<<"                ***********************************************\n";
			cout<<"\n\n\n\n\n\n\n\n";
    cout << "\t\tEnter Username: ";
    fflush(stdin);
    gets(s.user);

   /* cout << "Enter Password: ";
    fflush(stdin);
    gets(s.pass);*/
    printf("\t\tEnter Password: ");
	i = 0;
	while (1) {
	    ch = getch();
	    if (ch == 13) // Enter key
		break;
	    if (ch == 8 && i > 0) { // Backspace
		i--;
		printf("\b \b");
	    } else if (i < sizeof(s.pass) - 1) {
		s.pass[i++] = ch;
		printf("*");
	    }
	}
	s.pass[i] = '\0';

    ifstream fin("teacher.txt");

    if(!fin)
    {
        cout << "File not found!";
        getch();
        return;
    }

    while(fin.getline(line, 400))
    {
        sscanf(line, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
               &s.teacher_ID,
               s.name,
               s.subject,
               s.phone_no,
               s.Qualification,
               s.username,
               s.password);

        if(strcmp(s.username, s.user) == 0 &&
           strcmp(s.password, s.pass) == 0)
        {
            found = 1;
            break;
        }
    }
    fin.close();

    if(found)
    {
        cout << "\nLogin Successful! Welcome " << s.name;
        getch();
        teacher();
    }
    else
    {
        cout << "\nInvalid Username or Password!";
        getch();
    }
}

};

void faculty()
{
	 fpass k;
	 int i;
	while(1)
	{

		 clrscr();
	       cout<<"                ******************************************************\n";
	       cout<<"               (<-----------------Faculty ACCOUNT MENU-------------->)\n";
	       cout<<"                *****************************************************\n";
	       cout<<"\n\n\n\n\n\n\n\n";
	  cout<<"1.Login a Faculty only"<<endl;
	  cout<<"2. Exit"<<endl;
	  cout<<"Select an Action:- ";
	cin>>i;

	if(i==2)
	    return;
	switch(i)
	{
	 case 1:
		k.password1();
	 break;
	 default:
		cout<<"Invalid Value";
		break;
	 }
	}

}