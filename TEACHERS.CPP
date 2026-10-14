#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h> // printf ke liye zaruri hai

class Teacher
{
  int teacher_ID;
  char name[100],subject[100],Qualification[100],phone_no[100];
  char username[100],password[100];

  public:

int getID()
{
    ifstream fin("teacher.txt");
    Teacher s;
    int maxRoll = 10000;

   while(fin >> s.teacher_ID )
    {

	    if(s.teacher_ID > maxRoll)
		maxRoll = s.teacher_ID;

    }
    fin.close();
    return maxRoll + 1;
}
  void Add_Teacher()
  {
    Teacher s;
    s.teacher_ID=getID();
	clrscr();
    cout<<"ID:- "<<s.teacher_ID<<endl;
    cout<<"Enter a Name:- ";
    fflush(stdin);
    gets(s.name);

    cout<<"Enter a Subject:- ";
    fflush(stdin);
    gets(s.subject);

    cout<<"Enter a Qualification:- ";
    fflush(stdin);
    gets(s.Qualification);

    ph:
    cout<<"Enter Phone No: ";
    cin>>s.phone_no;
    if(strlen(s.phone_no) != 10)
{
    cout<<"INVALID Phone No";
    goto ph;
}

    cout<<"Enter a Username:- ";
    fflush(stdin);
    gets(s.username);

    cout<<"Enter a Password:- ";
    fflush(stdin);
    gets(s.password);


      ofstream fout("teacher.txt", ios::app);
	if(!fout)
	{
    cout<<"File Error!";
    getch();
    return;
	}

   fout << s.teacher_ID << "|"
	     << s.name << "|"
	     << s.subject << "|"
	     << s.phone_no << "|"
	     << s.Qualification << "|"
	     << s.username << "|"
	     << s.password << endl;

    fout.close();

    cout<<"Admission Successful!";
    getch();

  }

	// Teacher Data Show
void Show_teacherData()
{
    Teacher s;
    int found = 0;
    char line[400];

    ifstream fin("teacher.txt");
    clrscr();

    cout<<"---- Teacher List ----\n\n";

    cout<<"-----------------------------------------------------------------------------\n";
    printf("| %-7s | %-15s | %-15s | %-12s | %-15s |\n","ID", "NAME", "SUBJECT", "PHONE", "QUALIFICATION");
    cout<<"-----------------------------------------------------------------------------\n";

    while(fin.getline(line, 400))
    {
	sscanf(line, "%d|%[^|]|%[^|]|%[^|]|%[^|]",
	       &s.teacher_ID,
	       s.name,
	       s.subject,
	       s.phone_no,
	       s.Qualification);

	found = 1;

	printf("| %-7d | %-15s | %-15s | %-12s | %-15s |\n",
	       s.teacher_ID,
	       s.name,
	       s.subject,
	       s.phone_no,
	       s.Qualification);
    }

    if(!found)
    {
	printf("| %-71s |\n", "NO RECORD FOUND");
    }

    cout<<"-----------------------------------------------------------------------------\n";

    fin.close();
    getch();
}
				  //Teacher Data Search

void search_teacherData()
{
    Teacher s;
    int  found=0;
    int id;
    char line[400];

    clrscr();
    cout<<"Enter ID: ";
	cin>>id;

    ifstream fin("teacher.txt");
    clrscr();
    cout<<"----- Teacher Search Result -----\n\n";

    while(fin.getline(line,400))
    {

	       sscanf(line, "%d|%[^|]|%[^|]|%[^|]|%[^|]",
	       &s.teacher_ID,
	       s.name,
	       s.subject,
	       s.phone_no,
	       s.Qualification);

	if(s.teacher_ID==id)
	{
	    found=1;

	    cout<<"ID    	    : "<<s.teacher_ID<<endl;
	    cout<<"Name   	    : "<<s.name<<endl;
	    cout<<"Subject   	    : "<<s.subject<<endl;
	    cout<<"Phone     	    : "<<s.phone_no<<endl;
	    cout<<"Qualification    : "<<s.Qualification<<endl;
	    cout<<"-----------------------------\n";
	    break;
	}
    }
    if(!found) cout<<"No Record Found";
    fin.close();
    getch();
}

			//Teacher Data update

void update_teacherData()
{
    Teacher s;
    int id,  found=0, choice;
    char  line[400];

    clrscr();
    cout<<"Enter ID: ";
     cin>>id;

    ifstream fin("teacher.txt");
    ofstream fout("temps.txt");

    while(fin.getline(line,400))
    {

	sscanf(line,"%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",&s.teacher_ID,s.name,s.subject,s.phone_no,s.Qualification,s.username,s.password);


	if(s.teacher_ID==id)
        {
            found = 1;
            clrscr();

            cout<<"What do you want to update?\n";
	    cout<<"1. Name\n";
	    cout<<"2. Subject\n";
	    cout<<"3. Qualification\n";
	    cout<<"4. Phone Number\n";
	    cout<<"Enter Choice: ";
	    cin>>choice;

	    switch(choice)
	    {
		case 1:
		    cout<<"Enter New Name: ";
		    fflush(stdin);
		     gets(s.name);
		    break;

		case 2:
		    cout<<"Enter New Subject: ";
		    fflush(stdin);
		     gets(s.subject);
		    break;

		case 3:
		    cout<<"Enter New Qualification: ";
		    fflush(stdin);
		     gets(s.Qualification);
		    break;

		case 4:
		    cout<<"Enter New Phone Number: ";
		    cin>>s.phone_no;
		    break;



		default:
		    cout<<"Invalid Choice!";
		    getch();
	    }
		fout << s.teacher_ID << "|"
     << s.name << "|"
     << s.subject << "|"
     << s.phone_no << "|"
     << s.Qualification << "|"
     << s.username << "|"
     << s.password << endl;

        }
        else
        {
            fout<<line<<"\n";
        }
    }

    fin.close();
    fout.close();

    remove("teacher.txt");
    rename("temps.txt","teacher.txt");

    if(found)
        cout<<"\nRecord Updated Successfully!";
    else
        cout<<"\nUpdated Field Successfully!";


    getch();
}


			//Teacher Data Delete

void delete_teacherData()
{
    Teacher s;
    int id, found=0;
    char  line[400];

    clrscr();
    cout<<"Enter ID: ";
     cin>>id;

    ifstream fin("teacher.txt");
    ofstream fout("temps.txt");

    while(fin.getline(line,400))
    {

	  sscanf(line, "%d|%[^|]|%[^|]|%[^|]|%[^|]",
	       &s.teacher_ID,
	       s.name,
	       s.subject,
	       s.phone_no,
	       s.Qualification);

	if(s.teacher_ID==id)
		found=1;
	else
	 fout<<line<<"\n";
    }
    fin.close(); fout.close();
    remove("teacher.txt");
    rename("temps.txt","teacher.txt");

    if(found) cout<<"\nTeacher Record Deleted!";
    else cout<<"\nRecord Not Found!";
    getch();
}


};

void teachers()
{
	Teacher s;
 while(1){
	       int y;
		    clrscr();
cout<<"\t===============================================================\n";
cout<<"\t<--------------------TEACHER MANAGEMENT----------------------->\n";
cout<<"\t===============================================================\n\n\n\n";

cout<<"\t\t1. Add Teacher\n";
cout<<"\t\t2. Delete Teacher\n";
cout<<"\t\t3. Show Teachers\n";
cout<<"\t\t4. Update Teacher\n";
cout<<"\t\t5. Search Teacher\n";
cout<<"\t\t6. Back\n\n";

cout<<"\t\tSelect an Option: ";
cin>>y;

		     if(y==6)
			break;
		       switch(y)
		       {
			     case 1:
				   s.Add_Teacher();
			     break;
			     case 2:
				   s.Show_teacherData();
			     break;
			     case 3:
				   s.search_teacherData();
			     break;
			     case 4:
				   s.update_teacherData();
			     break;
			     case 5:
				   s.delete_teacherData();
			     break;
			     default:
			     cout<<"INvalid Value";
			     break;
		       }
	 }
 getch();
}