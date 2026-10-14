#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h>
#include "tc.cpp"

class admis
{
      long int Rollno;
      char phone_no[100],Aadhaar[100];
      char name[100],Fname[100],mname[100],dob[100],address[100],email[100];
      char bg[100];
      char gender[100], category[100],section;
      int SRno,clas;

public:
int validEmail(char email[])
{
    int at=-1, dot=-1;
    for(int i=0; email[i]!='\0'; i++)
    {
	if(email[i]=='@')
		at=i;
	if(email[i]=='.')
		dot=i;
    }
    return (at!=-1 && dot!=-1 && at<dot);
}

void showMarksheet()
{
    admis s;
    int sr, foundS = 0, foundM = 0;
    char line[400];
      char fullname[100];
    float marks[5], total, per;
    int clas, i;

    clrscr();
    cout<<"Enter SR No: ";
    cin>>sr;

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
}int getRoll(int clas, char section)
{
    ifstream fin("student.txt");
    admis s;
    int maxRoll = 1000;
    char line[400];

    if(!fin)
        return 1;

    while(fin.getline(line, 400))
    {
        sscanf(line, "%d|%d|%c|%d",
               &s.SRno, &s.clas, &s.section, &s.Rollno);

        if(s.clas == clas && s.section == section)
        {
            if(s.Rollno > maxRoll)
                maxRoll = s.Rollno;
        }
    }
    fin.close();
    return maxRoll + 1;
}

int getSR()
{
    ifstream fin("student.txt");
    admis s;
    int maxSR = 0;
    char line[400];

    if(!fin)
        return 1;

    while(fin.getline(line, 400))
    {
        sscanf(line, "%d|%d|%c|%d",
               &s.SRno, &s.clas, &s.section, &s.Rollno);

        if(s.SRno > maxSR)
            maxSR = s.SRno;
    }
    fin.close();
    return maxSR + 1;
}


void admissionStudent()
{
    admis s;
label:
    clrscr();
    cout<<"Enter Class (1-12): ";
    cin>>s.clas;

    if(s.clas < 1 || s.clas > 12)
    {
	cout<<"Invalid Class";
	getch();
	goto label;
    }

labels:
    cout<<"Enter Section (A/B/C): ";
    cin>>s.section;

    if(s.section!='A' && s.section!='B' && s.section!='C')
    {
	cout<<"Invalid Section";
	getch();
	goto labels;
    }

    //  Automatic numbers
    s.Rollno = getRoll(s.clas, s.section);
    s.SRno   = getSR();

    cout<<"Auto Roll No : "<<s.Rollno<<endl;
    cout<<"Auto SR No   : "<<s.SRno<<endl;

    cin.ignore(100,'\n');

cout<<"Enter Name: ";

fflush(stdin);
    gets(s.name);

cout<<"Enter Father Name: ";
cin.getline(s.Fname,100);

cout<<"Enter Mother Name: ";
cin.getline(s.mname,100);


    cout<<"Enter DOB( DD/MM/YYYY ): ";
    cin>>s.dob;

    //Phone NO
     ph:
    cout<<"Enter Phone No: ";
    cin>>s.phone_no;
    if(strlen(s.phone_no) != 10)
{
    cout<<"INVALID Phone No";
    goto ph;
}

			    //Aadhaar No
    ad:
cout<<"Enter Aadhaar No: ";
cin>>s.Aadhaar;
if(strlen(s.Aadhaar) != 12)
{
    cout<<"Invalid Aadhaar\n";
    goto ad;
}


    cout<<"Enter Gender: ";
    cin>>s.gender;

    cout<<"Enter Blood Group: ";
    cin>>s.bg;

		//General
	 gen:
    cout<<"Enter Category (General/OBC/SC/ST): ";
   cin >> s.category;

if(strcmp(s.category,"General")!=0 && strcmp(s.category,"OBC")!=0 && strcmp(s.category,"SC")!=0 && strcmp(s.category,"ST")!=0)
   {
	cout<<"Ivalid value";
	goto gen;
   }

em:
    cout<<"Enter Email: ";
    cin>>s.email;
	if(!validEmail(s.email))
	{
    cout<<"Invalid Email";
    goto em;
	}


    cout<<"Enter Address: ";
	cin.ignore();
	cin.getline(s.address,100);



    // save in file (TXT)
    ofstream fout("student.txt", ios::app);
	if(!fout)
	{
    cout<<"File Error!";
    getch();
    return;
	}

    fout << s.SRno << "|"
     << s.clas << "|"
     << s.section << "|"
     << s.Rollno << "|"
     << s.name << "|"
     << s.Fname << "|"
     << s.mname << "|"
     << s.dob << "|"
     << s.phone_no << "|"
     << s.Aadhaar << "|"
     << s.gender << "|"
     << s.category << "|"
     << s.email << "|"
     << s.address << "|"
     << s.bg << "\n";

    fout.close();

    cout<<"Admission Successful!";
    getch();
}

			//profile
void search_profileData()
{
    admis s;
    int c, Roll,SRn, found=0;
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
    cout<<"Enter a SRNO: ";
    cin>>SRn;

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

	if(s.clas==c && s.section==sec && s.Rollno==Roll && s.SRno==SRn)
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



};

void users()
{
admis k;
     while(1)
     {
     int y;
     clrscr();

cout<<"\t***************************************************************\n";
cout<<"\t*                                                             *\n";
cout<<"\t*                     STUDENT PORTAL                          *\n";
cout<<"\t*                                                             *\n";
cout<<"\t***************************************************************\n\n";


	 cout<<"\t\t1. New Admission\n";
	 cout<<"\t\t2. My Records\n";
	 cout<<"\t\t3. Transfer Certificate(TC)\n";
	 cout<<"\t\t4. Exit\n\n";
	 cout<<"\t\t  Select an Action:- ";
	 cin>>y;
	 if(y==4)
	    return;

	 switch(y)
	 {
	      case 1:
		      k.admissionStudent();
	      break;
	      case 2:
		      while(1)
		      {
			  int h;
			  clrscr();
	      cout<<"\t===============================================================\n";
	      cout<<"\t<--------------------STUDENT RECORDS MENU--------------------->\n";
	      cout<<"\t===============================================================\n\n";

			  cout<<"\t\t1. Student Profile\n";
			  cout<<"\t\t2. Marksheet\n";
			  cout<<"\t\t3. Back\n\n";
			  cout<<"\t\t  Select an Action:- ";
			  cin>>h;

			  if(h==3)
			      break;

			  switch(h)
			 {
			     case 1:
				    k.search_profileData();
			     break;
			     case 2:
				    k.showMarksheet();
			     break;
			     default:
			     cout<<"INVALID VALUE";
			     break;
			 }


		      }
	      break;
	      case 3:
		    usertc();
	      break;
	      default:
	      cout<<"INVALID VALUE";
	      break;

	 }
     }

getch();
}