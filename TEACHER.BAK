#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h> // printf ke liye zaruri hai
#include "markshee.cpp"

class student
{     long int Rollno;
      char phone_no[100],Aadhaar[100];
      char name[100],Fname[100],mname[100],dob[100],address[100],email[100];
      char bg[100];
      char gender[100], category[100],section;
      int SRno,clas;

public:
			//Student Data Show
void Show_studentData()
{
    student s;
    int c, found = 0;
    char sec;
    char line[400];

    ifstream fin("student.txt");

label:
    clrscr();
    cout<<"Enter Class (1-12): ";
    cin>>c;
    if(c<1 || c>12)
    {
        cout<<"Invalid Class";
        getch();
        goto label;
    }

labels:
    cout<<"Enter Section (A/B/C): ";
    cin>>sec;
    if(sec!='A' && sec!='B' && sec!='C')
    {
        cout<<"Invalid Section";
        getch();
        goto labels;
    }

    clrscr();
    cout<<"\n\n\t\t\t---- Student List: Class "<<c<<" ("<<sec<<") ----\n";
    cout<<"--------------------------------------------------------------------------------\n";
    // Table Header (Width set ki hai taaki column barabar rahein)
    // %-6s means 6 characters left-aligned
    printf("| %-5s | %-6s | %-20s | %-15s | %-10s | %-5s |\n",
           "SR", "ROLL", "NAME", "FATHER", "PHONE", "BG");
    cout<<"--------------------------------------------------------------------------------\n";
    while(fin.getline(line,400))
    {
	sscanf(line,"%d|%d|%c|%ld|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
	&s.SRno,&s.clas,&s.section,&s.Rollno,
	s.name,s.Fname,s.mname,s.dob,s.phone_no,
	s.Aadhaar,s.gender,s.category,
	s.email,s.address,s.bg);

	if(s.clas==c && s.section==sec)
	{
	    found=1;
	    // Data Row: %-15.15s ka matlab hai agar naam bada hai toh 15 characters hi dikhaye
	    printf("| %-5d | %-6ld | %-20.15s | %-15.15s | %-10.10s | %-5.5s |\n",
		   s.SRno, s.Rollno, s.name, s.Fname, s.phone_no, s.bg);
	}
    }

    if(!found)
    {
	printf("| %-71s |\n", "NO RECORD FOUND");
    }

    cout<<"--------------------------------------------------------------------------------\n";

    fin.close();
    getch();
}

				  //Student Data Search

void search_studentData()
{
    student s;
    int c, Roll, found=0;
    char sec;
    char line[400];

label:
    clrscr();
    cout<<"Enter Class: "; 
	cin>>c;
    if(c<1 || c>12) {
	 cout<<"Invalid Class";
	 getch();
	 goto label; }

labels:
    cout<<"Enter Section: "; cin>>sec;
    if(sec!='A' && sec!='B' && sec!='C') { cout<<"Invalid Section"; getch(); goto labels; }

    cout<<"Enter Roll No: "; cin>>Roll;

    ifstream fin("student.txt");
    clrscr();
    cout<<"----- Student Search Result -----\n\n";

    while(fin.getline(line,400))
    {
        sscanf(line, "%d|%d|%c|%ld|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
               &s.SRno,&s.clas,&s.section,&s.Rollno,
               s.name,s.Fname,s.mname,s.dob,s.phone_no,
               s.Aadhaar,s.gender,s.category,
               s.email,s.address,s.bg);

        if(s.clas==c && s.section==sec && s.Rollno==Roll)
        {
            found=1;

	        cout<<"SR No      : "<<s.SRno<<endl;
            cout<<"Roll No    : "<<s.Rollno<<endl;
            cout<<"Name       : "<<s.name<<endl;
            cout<<"Father     : "<<s.Fname<<endl;
            cout<<"Mother     : "<<s.mname<<endl;
            cout<<"DOB        : "<<s.dob<<endl;
            cout<<"Phone      : "<<s.phone_no<<endl;
            cout<<"Aadhaar    : "<<s.Aadhaar<<endl;
            cout<<"Gender     : "<<s.gender<<endl;
            cout<<"Category   : "<<s.category<<endl;
            cout<<"Email      : "<<s.email<<endl;
            cout<<"Address    : "<<s.address<<endl;
            cout<<"Blood Group: "<<s.bg<<endl;
            cout<<"-----------------------------\n";
            break;
        }
    }
    if(!found) cout<<"No Record Found";
    fin.close();
    getch();
}

			//Student Data Delete

void delete_studentData()
{
    student s;
    int c, Roll, found=0;
    char sec, line[400];

    clrscr();
    cout<<"Enter Class: "; cin>>c;
    cout<<"Enter Section: "; cin>>sec;
    cout<<"Enter Roll No: "; cin>>Roll;

    ifstream fin("student.txt");
    ofstream fout("temp.txt");

    while(fin.getline(line,400))
    {
        sscanf(line, "%d|%d|%c|%ld|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
               &s.SRno,&s.clas,&s.section,&s.Rollno,
               s.name,s.Fname,s.mname,s.dob,s.phone_no,
               s.Aadhaar,s.gender,s.category,
               s.email,s.address,s.bg);

        if(s.clas==c && s.section==sec && s.Rollno==Roll) found=1;
        else fout<<line<<"\n";
    }
    fin.close(); fout.close();
    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found) cout<<"\nStudent Record Deleted!";
    else cout<<"\nRecord Not Found!";
    getch();
}

			//Student Data update

void update_studentData()
{
    student s;
    int c, Roll, found=0, choice;
    char sec, line[400];

    clrscr();
    cout<<"Enter Class: "; cin>>c;
    cout<<"Enter Section: "; cin>>sec;
    cout<<"Enter Roll No: "; cin>>Roll;

    ifstream fin("student.txt");
    ofstream fout("temp.txt");

    while(fin.getline(line,400))
    {
	sscanf(line,"%d|%d|%c|%ld|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
        &s.SRno,&s.clas,&s.section,&s.Rollno,
        s.name,s.Fname,s.mname,s.dob,s.phone_no,
        s.Aadhaar,s.gender,s.category,
        s.email,s.address,s.bg);

        if(s.clas==c && s.section==sec && s.Rollno==Roll)
        {
            found = 1;
            clrscr();

            cout<<"What do you want to update?\n";
            cout<<"1. Name\n";
            cout<<"2. Father Name\n";
            cout<<"3. Mother Name\n";
            cout<<"4. Phone Number\n";
            cout<<"5. Email\n";
            cout<<"6. Address\n";
            cout<<"7. Blood Group\n";
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
                    cout<<"Enter New Father Name: ";
                    fflush(stdin);
                     gets(s.Fname);
                    break;

                case 3:
                    cout<<"Enter New Mother Name: ";
                    fflush(stdin);
                     gets(s.mname);
                    break;

                case 4:
                    cout<<"Enter New Phone Number: ";
                    cin>>s.phone_no;
                    break;

                case 5:
                    cout<<"Enter New Email: ";
                    cin>>s.email;
                    break;

                case 6:
                    cout<<"Enter New Address: ";
                    fflush(stdin);
                    gets(s.address);

                    break;

                case 7:
                    cout<<"Enter New Blood Group: ";
                    cin>>s.bg;
                    break;

                default:
                    cout<<"Invalid Choice!";
                    getch();
            }

            // Updated record write
            fout<<s.SRno<<"|"<<s.clas<<"|"<<s.section<<"|"<<s.Rollno<<"|"
                <<s.name<<"|"<<s.Fname<<"|"<<s.mname<<"|"<<s.dob<<"|"
                <<s.phone_no<<"|"<<s.Aadhaar<<"|"<<s.gender<<"|"
                <<s.category<<"|"<<s.email<<"|"<<s.address<<"|"<<s.bg<<"\n";
        }
        else
        {
            fout<<line<<"\n";
        }
    }

    fin.close();
    fout.close();

    remove("student.txt");
    rename("temp.txt","student.txt");

    if(found)
        cout<<"\nRecord Updated Successfully!";
    else
        cout<<"\nUpdated Field Successfully!";


    getch();
}


};




void teacher()
{
student f;
    while(1)
    {
	int i;
	clrscr();
cout<<"\t***************************************************************\n";
cout<<"\t*                                                             *\n";
cout<<"\t*                    FACULTY DASHBOARD                        *\n";
cout<<"\t*                                                             *\n";
cout<<"\t***************************************************************\n\n\n\n";


	cout<<"\t\t1. Student Data\n";
	cout<<"\t\t2. Marksheet\n";
	cout<<"\t\t3. Back\n\n";
	cout<<"\t\tSelect an Action:- ";
	cin>>i;

	if(i==3)
	    return;

	switch(i)
	{
	    case 1:

	     while(1)
	     {
		int y;
		clrscr();
	       cout<<"                ******************************************************\n";
	       cout<<"               (<-----------------Student Management Menu------------>)\n";
	       cout<<"                *****************************************************\n";
	       cout<<"\n\n\n\n\n\n\n\n";
		cout<<"\t\t1. Show Student Data\n";
		cout<<"\t\t2. Search Student Data\n";
		cout<<"\t\t3. Update Student Data\n";
	       //	cout<<"4. Delete Student Data\n";
		cout<<"\t\t4. Back\n\n";
		cout<<"\t\tSelect an Action:- ";
		cin>>y;
		       if(y==4)
			  break;
		switch(y)
		{
		    case 1:
			   f.Show_studentData();
		     break;
		    case 2:
			  f.search_studentData();
		     break;
		    case 3:
			   f.update_studentData() ;
		      break;
		/*    case 4:
			    f.delete_studentData();
		     break;   */
		    default: cout<<"Invalid Value"; break;
		}
		}

	    break;

	    case 2:
	    marks();
	    break;

	    default:
		cout<<"INVALID VALUE";
		break;
	}
    }
}
