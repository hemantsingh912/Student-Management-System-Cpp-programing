#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h>
#include "teachers.cpp"
#include "ATC.cpp"

class Student{
      long int Rollno;
      char phone_no[100],Aadhaar[100];
      char name[100],Fname[100],mname[100],dob[100],address[100],email[100];
      char bg[100];
      char gender[100], category[100],section;
      int SRno,clas;

public:
			//Student Data Show
void Show_studentData()
{
    Student s;
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
    cout<<"---- Student List: Class "<<c<<" ("<<sec<<") ----\n\n";


    cout<<"-----------------------------------------------------------------------------\n";
    // Table Header (Width set ki hai taaki column barabar rahein)
    // %-6s means 6 characters left-aligned
    printf("| %-5s | %-6s | %-15s | %-15s | %-10s | %-5s |\n", 
           "SR", "ROLL", "NAME", "FATHER", "PHONE", "BG");
    cout<<"-----------------------------------------------------------------------------\n";

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
            printf("| %-5d | %-6ld | %-15.15s | %-15.15s | %-10.10s | %-5.5s |\n", 
                   s.SRno, s.Rollno, s.name, s.Fname, s.phone_no, s.bg);
        }
    }

    if(!found)
    {
        printf("| %-71s |\n", "NO RECORD FOUND");
    }

    // Table Bottom Border
    cout<<"-----------------------------------------------------------------------------\n";

    fin.close();
    getch();
}

				  //Student Data Search

void search_studentData()
{
    Student s;
    int c, Roll, found=0;
    char sec;
    char line[400];
    int marsr=0;
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
		  marsr=s.SRno;
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
   // cout<<endl<<marsr;
    if(!found)
    {
     cout<<"No Record Found";
     return;
    }
    fin.close();
    getch();
    showMarksheet(marsr);
}

void showMarksheet(int x)
{
     Student s;
    int sr, foundS = 0, foundM = 0;
    char line[400];

    float marks[5], total, per;
    int clas, i;

    clrscr();
    cout<<"Enter SR No: ";
    sr=x;

    /* -------- STUDENT FILE -------- */
    ifstream fs("student.txt");

    while(fs.getline(line,400))
    {
	sscanf(line,
	"%d|%d|%c|%ld|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
	&s.SRno,&s.clas,&s.section,&s.Rollno,
	s.name,s.Fname,s.mname,s.dob,s.phone_no,
	s.Aadhaar,s.gender,s.category,
	s.email,s.address,s.bg);

	if(s.SRno == sr)
	{
	    foundS = 1;
	    clas = s.clas;
	    break;
	}
    }
    fs.close();

    if(!foundS)
    {
	cout<<"Student Record Not Found!";
	getch();
	return;
    }

    /* -------- MARKSHEET FILE -------- */
    ifstream fm("marksheet.txt");

    while(fm.getline(line,400))
    {
	sscanf(line,"%d|%d|%f|%f|%f|%f|%f|%f|%f",
	&sr,&clas,
	&marks[0],&marks[1],&marks[2],&marks[3],&marks[4],
	&total,&per);

	if(sr == s.SRno)
	{
	    foundM = 1;
	    break;
	}
    }
    fm.close();

    if(!foundM)
    {
	cout<<"Marksheet Not Found!";
	getch();
	return;
    }


    clrscr();


	       clrscr();
	       printf("\n\n\n\n\n\n\n");
	       printf("                *************************************************\n");
	       printf("               (<-------------STAR INFOTECH COLLEGE------------->)\n");
	       printf("                *************************************************\n");
	       printf("                |       SR No   : %-10d                    |\n", s.SRno);
	       printf("                |       Name    : %-20s          |\n", s.name);
	       printf("                |       Father  : %-20s          |\n", s.Fname);
	       printf("                |       Mother  : %-20s          |\n", s.mname);
	       printf("               (<---------------Subjects Marks------------------>)\n");

	       for (i = 0; i < 5; i++) {
	       printf("                |        Subject %d: %.2f                       |\n", i + 1, marks[i]);
	       total += marks[i];
	       }

	       per = total / 5;
	       printf("                |          TOTAL  : %.2f                      |\n", total);
	       printf("                -------------------------------------------------\n");
	       printf("                |        Percentage: %.2f%%                     |\n", per);
	       if (per >= 33)
	       printf("                |        RESULT :PASS                           |\n");
	       else
	       printf("                |        RESULT :FAIL                           |\n");
	       printf("                -------------------------------------------------\n");



    getch();
}

};


class TC{

};


void admin()
{
   Student k;
    while(1)
    {   int i;
  //  getch();
    clrscr();
clrscr();
cout<<"\t***************************************************************\n";
cout<<"\t*                                                             *\n";
cout<<"\t*                   ADMIN CONTROL PANEL                       *\n";
cout<<"\t*                                                             *\n";
cout<<"\t***************************************************************\n\n\n\n";


       cout<<"\t\t1. Student Managment\n";
       cout<<"\t\t2. Teacher Managment\n";
       cout<<"\t\t3. Transfer Certificates\n";
       cout<<"\t\t4. Back\n\n";
       cout<<"\t\t Select an Action:- ";
       cin>>i;
       if(i==4)
       {
	 return;
       }
       switch(i)
       {
	       case 1:
	       while(1){
	       int y;
		       clrscr();
	       cout<<"\t===============================================================\n";
	       cout<<"\t<-------------------STUDENT MANAGEMENT (ADMIN)---------------->\n";
	       cout<<"\t===============================================================\n\n\n\n\n";
		     cout<<"\n\t\t1. Show Student Data\n";
		     cout<<"\t\t2. Search Student Data(with Marksheet)\n";
		     cout<<"\t\t3.Back\n";
		     cout<<"\t\tSelect an Action:- ";
		     cin>>y;
		     if(y==3)
			break;
		       switch(y)
		       {
			     case 1:
			     k.Show_studentData();
			     break;
			     case 2:
			     k.search_studentData();
			     break;
			     default:
			     cout<<"INvalid Value";
			     break;
		       }
		       }
	       break;
	       case 2:
	     //  cout<<"2";
		   teachers();
		   break;
	       case 3:
		      AdminTc();

	       break;
	       default:
	       cout<<"INvalid value";
	       break;
       }
       getch();
    }

}