
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<time.h>
#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
void staff_op();
void admin_op();
void menu1();
void detmain();             //function declaration
void tmenu();
void vmenu();
char op;
struct date_reg   //for date of admission and joining
{
int d,m,y;
};

class staff      //class for staff register
{
char name[31],id[30],g,dob[10],city[21],place[21],state[21];
char phno[15],doj[10],quali[10],dep[20],job[21];
date_reg d1;int d,m,y;
long pay;
  public:
  void getdata();
  void show();

   char*getname()
  {
  return name;
  }
  char*getnum()
  {
  return phno;
  }
  char*getcity()
  {
  return city;
  }
  char*getplace()
  {
  return place;
  }
  char*getstate()
  {return state;
  }
  long getpay()
  {
  return pay;
  }
  char*getquali()
  {
  return quali;
  }
  char *getdep()
  {
  return dep;
  }
 date_reg getdoj()
  {
   return d1;
   }


};




class stud_reg    //class for student register
{
private:
char reg_no[15];
date_reg D;
char rno[10];
char name[30];
char gender;
int d,m,y;
char address[100];
char parent_phno[15];
char stud_class[4];
char section;
public:
void getdata();
void putdata();
char* getname()
{
return name;}
char* getregno()
{
return reg_no;
}
char* getrollno()
{return rno;
}
char* getphno()
{return parent_phno;
}
char*getclass()
{
return stud_class;
}
char getsec()
{
return section;
}
char getgend()
{
return gender;
}
date_reg getdoa()
{
return D;
}


};//End of class stud_reg



class stud2         //class for results register
{
private:
char regno[30];
char subname[20];
float marks,tot;
int pmark;
int maxmark;
char result[10];

public:
void input();
void output();
void addstud();
float gmark()
{
return marks;
}
char*gname()
{
return subname;
}
char*gno()
{
return regno;
}
};





void box(char ch='^',char ch2='*',int r1=2,int r2=25,int c1=5,int c2=75)
{
//for creating box(border)
clrscr();
for(int r=r1,c=c1;c<=c2;c++)
{
gotoxy(c,r);
cout<<ch;
}
for(r=r1,c=c2;r<=r2;r++)
{
gotoxy(c,r);
cout<<ch2;
}
for(r=r2,c=c1;c<=c2;c++)
{
gotoxy(c,r);
cout<<ch;
}
for(r=r1,c=c1;r<=r2;r++)
{
gotoxy(c,r);
cout<<ch2;
}

}

void staff::getdata()   // for getting details of staff
{
box(272,272);
gotoxy(12,8);cout<<"Enter name ";
gotoxy(43,8);cout<<":";
gotoxy(66,8);cout<<"(Max 30) ";
gotoxy(45,8);gets(name);
gotoxy(66,8);cout<<"        ";
gotoxy(12,9); cout<<"EnterID    "; gotoxy(43,9);cout<<":";
gotoxy(66,9);cout<<"(Max 30)";
gotoxy(45,9);gets(id);
gotoxy(66,9);cout<<"        ";
gotoxy(12,10);cout<<"Enter gender ";gotoxy(43,10);cout<<":";
gotoxy(66,10);cout<<"(M | F )";
do
 {
 gendergo:
 gotoxy(45,10);cout<<" ";
 cin>>g;
 gotoxy(66,10);cout<<"        ";
 }while(g!='M'&&g!='F'&&g!='m'&&g!='f');
struct date D;
getdate(&D);
d1.d=0,d1.m=0,d1.y=0;
doj_date:
 gotoxy(12,11);cout<<"Date Of Joining                   "; gotoxy(43,11);cout<<":";
do
 { gotoxy(60,11);cout<<"             ";
   gotoxy(60,11);cout<<"(1-31)";
   gotoxy(45,11);cout<<"  /";
   gotoxy(45,11);cin>>d1.d;
 }
while(d1.d<1||d1.d>31);
doj_month:
do
 { gotoxy(60,11);cout<<"(1-12)";
   gotoxy(48,11);cout<<"  /";
   gotoxy(48,11);cin>>d1.m;
   if((d1.m==2||d1.m==4||d1.m==6||d1.m==9||d1.m==11)&&d1.d==31)
     {goto doj_date;}
 }while(d1.m<1||d1.m>12);

do
 { gotoxy(60,11);cout<<"  (1970-"<<D.da_year<<")";
   gotoxy(51,11);cout<<"      ";
   gotoxy(51,11);cin>>d1.y;
   if(d1.y%4!=0&&d1.m==2&&d1.d==29)
   goto doj_date;
 }while(d1.y<1970||d1.y>D.da_year);

dob_date:
do
 { gotoxy(60,11);cout<<"              ";
   gotoxy(60,12);cout<<"(1-31)";
   gotoxy(12,12);cout<<"Date Of Birth(dd/MM/YY)  ";gotoxy(43,12);cout<<":";
   gotoxy(45,12);cin>>d;

 }
while(d<1||d>31);

dob_month:
do
 { gotoxy(60,12);cout<<"(1-12)";
   gotoxy(47,12);cout<<"/" ;
   gotoxy(48,12);cin>>m;
   if((m==2||m==4||m==6||m==9||m==11)&&d==31)
   {
   gotoxy(28,20);cout<<"Invalid date";
   getch();
   gotoxy(28,20);cout<<"            ";
   goto dob_date;
   }
}while(m<1||m>12);

dob_year:
do
 { gotoxy(60,12);cout<<"(1940-"<<d1.y-23<<")";
   gotoxy(50,12);cout<<"/";
   gotoxy(51,12);cout<<"     ";
   gotoxy(51,12);cin>>y;
   gotoxy(60,12);cout<<"            ";

   if(y%4!=0&&m==2&&d==29)
   goto dob_date;
 }
while(y<1940||y>d1.y-23);




gotoxy(60,12);cout<<"             ";
gotoxy(12,13);cout<<"Enter City  ";gotoxy(43,13);cout<<":";
gotoxy(66,13);cout<<"(Max 20)";
gotoxy(45,13);gets(city);
gotoxy(66,13);cout<<"        ";
gotoxy(12,14);cout<<"Enter Place    ";gotoxy(43,14);cout<<":";
gotoxy(66,14);cout<<"(Max 20)";
gotoxy(45,14);gets(place);
gotoxy(66,14);cout<<"        ";
gotoxy(12,15);cout<<"Enter State    "; gotoxy(43,15);cout<<":";
gotoxy(66,15);cout<<"(Max 20)";
gotoxy(45,15);gets(state);
gotoxy(66,15);cout<<"        ";
gotoxy(12,16);cout<<"Enter phno..   ";gotoxy(43,16);cout<<":";
gotoxy(58,16);cout<<"(Min 8)(Max 10)";
gotoxy(45,16);gets(phno);
gotoxy(58,16);cout<<"                ";
gotoxy(12,17);cout<<"Enter Qualification ";gotoxy(43,17);cout<<":";
gotoxy(66,17);cout<<"(Max 10)";
gotoxy(45,17);gets(quali);
gotoxy(66,17);cout<<"        ";
gotoxy(12,18);cout<<"Enter department";  gotoxy(43,18);cout<<":";
gotoxy(66,18);cout<<"(Max 20)";
gotoxy(45,18);gets(dep);
gotoxy(66,18);cout<<"        ";
gotoxy(12,19);cout<<"Enter ur Basic pay   ";      gotoxy(43,19);cout<<":";
gotoxy(60,19);cout<<"(Max 10 Digits)";
gotoxy(45,19);cin>>pay;
gotoxy(60,19);cout<<"               ";
gotoxy(12,20);cout<<"Enter ur Job title  ";gotoxy(43,20);cout<<":";
gotoxy(66,20);cout<<"(Max 20)";
gotoxy(45,20);gets(job);
gotoxy(66,20);cout<<"        ";

}

void staff::show()   //for display of staff details
{
clrscr();
box(273,273);

gotoxy(20,5);cout<<"***DETAILS OF STAFF***";
gotoxy(20,6);cout<<"======================";
gotoxy(12,8);cout<<"Name             "; gotoxy(43,8);cout<<":";
gotoxy(45,8);puts(name);
gotoxy(12,9);cout<<"ID               "; gotoxy(43,9);cout<<":";
gotoxy(45,9);puts(id);
gotoxy(12,10);cout<<"Gender            ";  gotoxy(43,10);cout<<":";
gotoxy(45,10);cout<<g;
gotoxy(12,11);cout<<"Date of Birth                        "; gotoxy(43,11);cout<<":";
gotoxy(45,11);cout<<d<<"/"<<m<<"/"<<y;
gotoxy(12,12);cout<<"City             "; gotoxy(43,12);cout<<":";
gotoxy(45,12);puts(city);
gotoxy(12,13);cout<<"Place            ";  gotoxy(43,13);cout<<":";
gotoxy(45,13);puts(place);
gotoxy(12,14);cout<<"State           ";  gotoxy(43,14);cout<<":";
gotoxy(45,14);puts(state);
gotoxy(12,15);cout<<"phno..,         ";   gotoxy(43,15);cout<<":";
gotoxy(45,15);puts(phno);
gotoxy(12,16);cout<<"Qualification    ";  gotoxy(43,16);cout<<":";
gotoxy(45,16);puts(quali);
gotoxy(12,17);cout<<"Department       ";  gotoxy(43,17);cout<<":";
gotoxy(45,17);puts(dep);
gotoxy(12,18);cout<<"Job title        ";   gotoxy(43,18);cout<<":";
gotoxy(45,18);puts(job);
gotoxy(12,19);cout<<"Ur Basic pay is   ";   gotoxy(43,19);cout<<":";
gotoxy(45,19);cout<<pay;
gotoxy(12,20);cout<<"Date of Joining                    /  /    "; gotoxy(43,20);cout<<":";
gotoxy(45,20);cout<<d1.d;
gotoxy(48,20);cout<<d1.m;
gotoxy(51,20);cout<<d1.y;
delay(2000);

}
void insert()   //for inserting details of staff in file
{

int i=1;
staff s;
box(1054,543);
ofstream fout;
char ch='y';
fout.open("rec.dat",ios::binary|ios::out|ios::app);
gotoxy(10,6);cout<<" Inserting Staff Details!!!";
while(ch=='y')
{
s.getdata();
fout.write((char*)&s,sizeof(s));
gotoxy(10,23);cout<<"Do You Want to Continue?(Y/N): ";
gotoxy(43,23);cin>>ch;
i++;
clrscr();
box(272,272);

gotoxy(6,4);cout<<"INSERTING FILE DETAILS "<<i<<"is opened";
}
fout.close();

}

void searchnum()   // for searching staff by phone number
{
clrscr();
box(157);
int j=0;
staff s;
char snum[11],found='n';
ifstream fin;
fin.open("rec.dat ",ios::binary/ios::in);
ph:
j++;
gotoxy(10,7);cout<<"Enter num to be search :";
gotoxy(55,7);cout<<"(Max 10 digits)";
gotoxy(34,7);gets(snum);
gotoxy(55,7);cout<<"               ";
while(!fin.eof())
{
fin.read((char*)&s,sizeof(s));
if(strcmpi(s.getnum(),snum) ==0)
{

s.show();
delay(1000);
found='y';
}
if(found=='n')
{
gotoxy(10,8);cout<<"!!!no phno exist";
gotoxy(10,9);cout<<"Enter corect num";
getch();
gotoxy(10,8);cout<<"                                 ";
gotoxy(10,9);cout<<"                                 ";
gotoxy(34,7);cout<<"                          ";
if(j>=4)
{
gotoxy(20,10);cout<<"Sorry Try Again Later";
tmenu();
}
goto ph;
}
fin.close();
}
}
 void searchname()   //for searching staff details by name
{

 staff s;
 int j=0;
 char sname[30];
 char found='n';
 fstream fin;
 fin.open("rec.dat",ios::binary|ios::in);

 clrscr();
 box(157);
 rep:
 j++;
 gotoxy(10,7); cout<<"Enter name to be search : ";
 gotoxy(55,7);cout<<"(Max 30)";
 gotoxy(35,7);gets(sname);
 gotoxy(55,7);cout<<"        ";
 while(!fin.eof())
 {
 fin.read((char*)&s,sizeof(s));
 if(strcmpi(s.getname(),sname)==0)
 {

 s.show();
 found='y';
 }
 if(found=='n')
 {
 gotoxy(10,8); cout<<"!!!No Name Exist";
 gotoxy(10,9); cout<<" Enter corect name!!!";
 getch();
 gotoxy(10,8); cout<<"                            "              ;
 gotoxy(10,9); cout<<"                                ";
 gotoxy(35,7); cout<<"                ";
 if(j>=4)
 {
 cout<<"Sorry Try Again Later";
 tmenu();
 }
 goto rep;
  }
 fin.close();

}
  }

void change()  // to modify staff details
{
 clrscr();
 box(271,271);
 staff s;
 char sname[25];
 int pos=0;
 int flag=0;
 fstream fin;

 fin.open("rec.dat",ios::binary|ios::in|ios::out);
 gotoxy(10,7); cout<<"Enter name to modify: ";
 gotoxy(55,7);cout<<"(Max 25)";
 gotoxy(32,7);gets(sname);
 gotoxy(55,7);cout<<"         ";
 gotoxy(10,7); cout<<"                            ";
 gotoxy(10,7); cout<<"Modifying Details of"<<' '<<puts(sname);
 while(!fin.eof())
 {
 fin.read((char*)&s,sizeof(s));
 pos++;
 if(strcmpi(s.getname(),sname)==0)
 {
 fin.seekg((pos-1)*sizeof(s),ios::beg);

 s.getdata();
 fin.write((char*)&s,sizeof(s));
 flag=1;
 }
 }
 if(flag==0)
 cout<<"\n sorry..,You can't.....!!";
 fin.close();
 }








void stud_reg::getdata()//getdata function for getting values
{
 int s;
 struct date d12;
 getdate(&d12);
 textbackground(BLUE+BLACK);textcolor(YELLOW);
 clrscr();
 box(272,272);
 gotoxy(15,1);cout<<"======================================";
 gotoxy(15,2);cout<<"|    Student Details Registration    |";
 gotoxy(15,3);cout<<"======================================";
 gotoxy(7,6);cout<<"Name         "; gotoxy(35,6);cout<<":";
 gotoxy(66,6);cout<<"(Max 30)";
 gotoxy(37,6);gets(name);
 gotoxy(66,6);cout<<"        ";
 gotoxy(7,7);cout<<"Registration no.    "; gotoxy(35,7);cout<<":";
 gotoxy(66,7);cout<<"(Max 15)";
 gotoxy(37,7);gets(reg_no);
 gotoxy(66,7);cout<<"        ";
 admndate:
 gotoxy(7,8);cout<<"Date Of Admission/Register            "; gotoxy(35,8);cout<<":";
 do
 {
   gotoxy(66,8);cout<<"(1-31)";
   gotoxy(37,8);cout<<"  /";
   gotoxy(37,8);cin>>D.d;
 }
while(D.d<1||D.d>31);

do
 {
   gotoxy(66,8);cout<<"(1-12)";
   gotoxy(40,8);cout<<"  /";
   gotoxy(40,8);cin>>D.m;
   if((D.m==2||D.m==4||D.m==6||D.m==9||D.m==11)&&D.d==31)
     {goto admndate;}
 }
while(D.m<1||D.m>12);

do
 { gotoxy(62,8);cout<<"(1990-"<<d12.da_year<<")";
   gotoxy(43,8);cout<<"    ";
   gotoxy(43,8);cin>>D.y;
   if(D.y%4!=0&&D.m==2&&D.d==29)
   goto admndate;
 }
while(D.y<1990||D.y>d12.da_year);
gotoxy(62,8);cout<<"            ";
do
 { redodate:
   gotoxy(7,9);cout<<"Date Of Birth(DD/MM/YY)  "; gotoxy(35,9);cout<<":";
   gotoxy(66,9);cout<<"(1-31)";
   gotoxy(37,9);cout<<"  /";
   gotoxy(37,9);cin>>d;

 }
while(d<1||d>31);

do
 { gotoxy(66,9);cout<<"(1-12)";
   gotoxy(40,9);cout<<"  /" ;
   gotoxy(40,9);cin>>m;
   if((m==2||m==4||m==6||m==9||m==11)&&(d==31))
   {
   gotoxy(55,10);cout<<"Invalid date";
   getch();
   gotoxy(55,10);cout<<"            ";
   goto redodate;
   }
 }
while(m<1||m>12);

do
 {
   gotoxy(62,9);cout<<"("<<D.y-5<<"-"<<D.y-3<<")";
   gotoxy(43,9);cout<<"   ";
   gotoxy(43,9);cin>>y;
   if(y%4!=0&&m==2&&d==29)
   goto redodate;
 }
while(y<D.y-5||y>D.y-3);



do
 {gendergo:
 gotoxy(62,9);cout<<"             ";
 gotoxy(18,12);cout<<" ";
 gotoxy(7,12);cout<<"Gender(M/F)          ";  gotoxy(35,12);cout<<":";
 gotoxy(37,12);cin>>gender;
 }while(gender!='M'&&gender!='F'&&gender!='m'&&gender!='f');

 gotoxy(7,13);cout<<"Address                  "; gotoxy(35,13);cout<<":";
 gotoxy(66,13);cout<<"(Max 100)";
 gotoxy(37,13);gets(address);
 gotoxy(66,13);cout<<"         ";
 phno:
 gotoxy(7,15);cout<<"Phone No.                ";gotoxy(35,15);cout<<":";
 gotoxy(50,15);cout<<"( digits- 8(or)10 )";
 gotoxy(37,15);gets(parent_phno);
 gotoxy(50,15);cout<<"                   ";
 s=strlen(parent_phno);
 if(s!=10&&s!=8)
 { gotoxy(45,15);cout<<"Invalid Phone no.";
   getch();
   gotoxy(45,15);cout<<"                     ";
   goto phno;
   }
 gotoxy(7,18);cout<<"Class(in no.)            "; gotoxy(35,18);cout<<":";
 gotoxy(37,18);cin>>stud_class;
 gotoxy(7,19);cout<<"Section                  ";gotoxy(35,19);cout<<":";
 gotoxy(50,19);cout<<"( In alphabet )";
 gotoxy(37,19);cin>>section;
 gotoxy(50,19);cout<<"               ";
 gotoxy(7,20);cout<<"Roll Number             ";gotoxy(35,20);cout<<":";
 gotoxy(66,20);cout<<"(Max 10)";
 gotoxy(37,20);gets(rno);
 gotoxy(66,20);cout<<"        ";
}

//Putdata function for showing the details
void stud_reg::putdata()
{
 clrscr();
 box(273,273);
 textbackground(BLUE);textcolor(WHITE);
 gotoxy(15,1);cout<<"================================================";
 gotoxy(15,2);cout<<"|           "<<name<<" Details                 |";
 gotoxy(15,3);cout<<"================================================";
 gotoxy(7,6);cout<<"Name  ";                        gotoxy(35,6);cout<<":";
 gotoxy(37,6);puts(name);
 gotoxy(7,7);cout<<"Registration no.            "; gotoxy(35,7);cout<<":";
 gotoxy(37,7);puts(reg_no);
 gotoxy(7,8);cout<<"Date Of Admission/Register  ";  gotoxy(35,8);cout<<":";
 gotoxy(37,8);cout<<D.d<<"/"<<D.m<<"/"<<D.y;
 gotoxy(7,9);cout<<"Date Of Birth               "; gotoxy(35,9);cout<<":";
 gotoxy(37,9);cout<<d<<"/"<<m<<"/"<<y;
 gotoxy(7,10);cout<<"Gender(M/F)               ";   gotoxy(35,10);cout<<":";
 gotoxy(37,10);cout<<gender;
 gotoxy(7,11);cout<<"Address                   "; gotoxy(35,11);cout<<":";
 gotoxy(37,11);puts(address);
 gotoxy(7,13);cout<<"Phone No.                 "; gotoxy(35,13);cout<<":";
 gotoxy(37,13);puts(parent_phno);
 gotoxy(7,14);cout<<"Class(in no.)             "; gotoxy(35,14);cout<<":";
 gotoxy(37,14);cout<<stud_class;
 gotoxy(7,15);cout<<"Section                   ";gotoxy(35,15);cout<<":";
 gotoxy(37,15);cout<<section;
 gotoxy(7,16);cout<<"Roll No.                  ";gotoxy(35,16);cout<<":";
 gotoxy(37,16);puts(rno);
}//End of putdata function

//For saving Data in a file
void save_data()
{
clrscr();
box(1054,543);
stud_reg S;
ofstream fout;
char ch='y';
fout.open("sch_det.dat",ios::binary|ios::out|ios::app);
if(!fout)
{
 cout<<"\nError in opening file";
 delay(500);
 exit(0);
}
while(ch=='y')
{
 S.getdata();
 fout.write((char*)&S,sizeof(S));
 gotoxy(15,23);cout<<"Do you want to continue? (Reply y/n):";
 gotoxy(53,23);cin>>ch;
}
fout.close();
}//End of savedata function

//Modify Function for modifying details
void modify()
{
clrscr();
box(271,271);
stud_reg S;
char sname[30];
int pos=0;
int flag=0;
fstream fin;
fin.open("sch_det.dat",ios::binary|ios::in|ios::out);

if(!fin)
{
 cout<<"\nError in File Opening";
 getch();
 exit(0);
}

gotoxy(8,8);cout<<"  ||Enter the name of the student";
gotoxy(8,9);cout<<"  whose details are to be modified||: ";
gotoxy(66,8);cout<<"(Max 30)";
gotoxy(49,9);gets(sname);
gotoxy(66,8);cout<<"         ";
while(!fin.eof())
{
 fin.read((char*)&S,sizeof(S));
 pos++;

 if(strcmpi(S.getname(),sname)==0)
  {
    fin.seekg((pos-1)*sizeof(S),ios::beg);
    S.getdata();
    fin.write((char*)&S,sizeof(S));
    flag=1;
   }
}

if(flag==0)
  cout<<"\nSorry.No such Name is found!!!";
getch();
fin.close();
}//End of modify function

void search_name()//For searching a name
{
clrscr();
box(271,271);
stud_reg S;
char sname[30];
gotoxy(10,10);cout<<"Enter the name of the student";
gotoxy(66,10);cout<<"(Max 30)";
gotoxy(42,10);gets(sname);
gotoxy(66,10);cout<<"        ";
int flag=0;
ifstream fin;
fin.open("sch_det.dat",ios::binary|ios::in);
if(!fin)
{
 cout<<"Error in opening file";
 getch();
 exit(0);
}
while(!fin.eof())
{
fin.read((char*)&S,sizeof(S));
if(strcmpi(S.getname(),sname)==0)
 {

  S.putdata();
  flag=1;
 }
}
if(flag==0)
 {
  cout<<"\nNo such Name is found";
  delay(500);
  }
fin.close();
getch();
}//End of name search function

void search_phno()//For searching details based on phone no.
{
clrscr();
box(271,271);
stud_reg S;
char sphno[13];
int flag=0;
gotoxy(10,10);cout<<"Enter the phone number of the student ";
gotoxy(61,10);cout<<"Digit-8(or)10";
gotoxy(50,10);gets(sphno);
gotoxy(66,10);cout<<"                    ";
ifstream fin;
fin.open("sch_det.dat",ios::binary|ios::in);
if(!fin)
{
 cout<<"\nError in opening file";
 getch();
 exit(0);
}
while(!fin.eof())
{
fin.read((char*)&S,sizeof(S));
if(strcmpi(S.getphno(),sphno)==0)
 {

  S.putdata();
  flag=1;
 }
}
if(flag==0)
 {
  cout<<"\nNo such Phone number is found";
  delay(500);
  }
fin.close();
getch();
}//End of phone no. search function

void search_rno()//For searching details based on roll no.
{
clrscr();
box(271,271);
stud_reg S;
char srno[10];
int flag=0;
gotoxy(10,10);cout<<"Enter the Roll Number of the student ";
gotoxy(66,10);cout<<"(Max 10)";
gotoxy(50,10);gets(srno);
gotoxy(66,10);cout<<"        ";
ifstream fin;
fin.open("sch_det.dat",ios::binary|ios::in);
if(!fin)
{
 cout<<"\nError in opening file";
 getch();
 exit(0);
}
while(!fin.eof())
{
fin.read((char*)&S,sizeof(S));
if(strcmpi(S.getrollno(),srno)==0)
 {

  S.putdata();
  flag=1;
 }
}
if(flag==0)
 {
  cout<<"\nNo such roll number is found";
  delay(500);
  }
fin.close();
getch();
}//End of roll no. search function

void search_regno()//For searching details based on registration no.
{
clrscr();
box(271,271);
stud_reg S;
char sregno[10];
int flag=0;
gotoxy(10,10);cout<<"||Enter the Registration Number of the student ";
gotoxy(66,10);cout<<"(Max 10)";
gotoxy(58,10);gets(sregno);
gotoxy(66,10);cout<<"        ";
ifstream fin;
fin.open("sch_det.dat",ios::binary|ios::in);
if(!fin)
{
 cout<<"\nError in opening file";
 getch();
 exit(0);
}
while(!fin.eof())
{
fin.read((char*)&S,sizeof(S));
if(strcmpi(S.getregno(),sregno)==0)
 {

  S.putdata();
  flag=1;
 }
}
if(flag==0)
 {
  cout<<"\nNo such Registration Number is found";
  delay(500);
  }
fin.close();
getch();
}//End of name search function








void stud2::input()  // for getting details of student
{
box(272,272);
gotoxy(12,5);cout<<"  RESULT DETAILS ";
gotoxy(12,8);cout<<"Enter Registration No.       ";gotoxy(35,8);cout<<":";
gotoxy(66,8);cout<<"(Max 30)";
gotoxy(37,8);gets(regno);
gotoxy(66,8);cout<<"        ";
gotoxy(12,10);cout<<"Enter Subject Name          ";gotoxy(35,10);cout<<":";
gotoxy(66,10);cout<<"(Max 20)";
gotoxy(37,10);gets(subname);
gotoxy(66,10);cout<<"        ";
m:
gotoxy(12,12);cout<<"Enter Total marks           ";gotoxy(35,12);cout<<":";
gotoxy(66,12);cout<<"(Max 100)";
gotoxy(37,12);cin>>tot;
gotoxy(66,12);cout<<"         ";
if(tot>101)
{
gotoxy(66,12);cout<<"Invalid marks";
gotoxy(37,12);cout<<"      ";
gotoxy(66,12);cout<<"              ";
goto m;
}
do
{
gotoxy(12,14);cout<<"Enter the mark Obtained    ";gotoxy(35,14);cout<<":";
gotoxy(62,14);cout<<"(Max "<<tot<<" )";
gotoxy(37,14);cin>>marks;
gotoxy(62,14);cout<<"             ";
if(marks<0||marks>tot)
{
gotoxy(20,16);cout<<"Invalid mark .    Enter below   "<<tot ;
getch();
gotoxy(20,16);cout<<"                                         ";
gotoxy(37,14);cout<<"                                         ";
}
}while(marks<0||marks>tot);
do
{
gotoxy(12,16);cout<<"Enter passmark              ";gotoxy(35,16);cout<<":";
gotoxy(37,16);cin>>pmark;

if(pmark<0||pmark>(tot/2))
{
gotoxy(20,18);cout<<"Invalid mark .    Enter below  "<<(tot/2) ;
getch();
gotoxy(20,18);cout<<"                                         ";
gotoxy(37,16);cout<<"                                        ";
}
}while(pmark<0||pmark>(tot/2));
do
{
gotoxy(12,18);cout<<"Enter Maximum mark          ";gotoxy(35,18);cout<<":";
gotoxy(66,18);cout<<"(Max 100)";
gotoxy(37,18);cin>>maxmark;
gotoxy(66,18);cout<<"         ";

if(maxmark<0||maxmark>tot||maxmark<marks)
{
gotoxy(20,20);cout<<"Invalid mark ";
getch();
gotoxy(20,20);cout<<"                                         ";
gotoxy(37,18);cout<<"                                        ";
}
}while(maxmark<0||maxmark>tot||maxmark<marks);
gotoxy(12,20);cout<<"Enter result                ";gotoxy(35,20);cout<<":";
gotoxy(37,20);gets(result);
gotoxy(66,20);cout<<"                ";
}
void stud2::output()   // for displaying details of student
{

clrscr();
box(273,273);
gotoxy(12,5);cout<<" RESULT DETAILS";
gotoxy(12,8);cout<<" Registration No.:";
gotoxy(45,8);puts(regno);
gotoxy(12,10);cout<<"Subject name    :";
gotoxy(45,10);puts(subname);
gotoxy(12,12);cout<<"Total marks     :";
gotoxy(45,12);cout<<tot;
gotoxy(12,14);cout<<"Marks obtained  :";
gotoxy(45,14);cout<<marks;
gotoxy(12,16);cout<<"Passmark        :";
gotoxy(45,16);cout<<pmark;
gotoxy(12,18);cout<<"Maximum mark    :";
gotoxy(45,18);cout<<maxmark;
gotoxy(12,20);cout<<"Result          :";
gotoxy(45,20);puts(result);

}

void stud2::addstud()  // to insert the details of student in file
{
box(1054,543);
stud2 s;
ofstream fout;
gotoxy(12,5);cout<<" ADDING DETAILS OF STUDENT";
char ch='y';
fout.open("record.dat",ios::binary|ios::out|ios::app);
if(!fout)
{
gotoxy(12,24);cout<<"Unable to open the file";
getch();
exit(0);
}
while(ch=='y')
{
s.input();
fout.write((char*)&s,sizeof(s));
gotoxy(12,23);cout<<"Want to continue";
gotoxy(29,23);cin>>ch;
clrscr();
}
fout.close();
}
void search_sname()   // for searching details of student by name
{
box(271,271);
stud2 s;
int j=0;
char nsubname[20];
char valid='n';
char again='n';
ifstream folder;
folder.open("record.dat",ios::binary|ios::in);
if(!folder)
{
gotoxy(12,24);cout<<"Unable to open the file";
getch();
exit(0);
}
sub2:
gotoxy(9,6);cout<<"Enter the subject name to be searched: ";
gotoxy(66,6);cout<<"(Max 20)";
gotoxy(50,6);gets(nsubname);
gotoxy(66,6);cout<<"       ";
while(!folder.eof())
{
folder.read((char*)&s,sizeof(s));
if(strcmpi(s.gname(),nsubname)==0)
{
s.output();
valid='y';
gotoxy(9,23);cout<<"Want to search another register?";
gotoxy(42,23);cin>>again;
if(again=='y')
{
clrscr();
goto sub2;
}

else if(again!='y')
vmenu();

}
}
if(valid=='n')
{
gotoxy(9,22);cout<<"Invalid subject name";
gotoxy(9,23);cout<<" Enter valid subject name ";
gotoxy(9,22);cout<<"                    ";
gotoxy(9,23);cout<<"                           ";
if(j>=4)
{
cout<<"Sorry Try Again Later..";
vmenu();
}
goto sub2;
}
folder.close();
}
void search_regnos()    // for seraching details of
			//  student by registration number
{
box(271,271);
stud2 s;
char nregno[30];
char valid='n';
char again='n';
sub1:
ifstream folder;
folder.open("record.dat",ios::binary|ios::in);
if(!folder)
{
gotoxy(12,24);cout<<"Unable to open the file";
getch();
exit(0);
}
sub2:
gotoxy(9,6);cout<<"Enter the registration number to be searched";
gotoxy(66,7);cout<<"(Max 30)";
gotoxy(57,6);gets(nregno);
gotoxy(66,7);cout<<"        ";
while(!folder.eof())
{
folder.read((char*)&s,sizeof(s));
if(strcmpi(s.gno(),nregno)==0)
{
s.output();
gotoxy(9,23);cout<<"Want to search another register";
gotoxy(42,23);cin>>again;
if(again=='y')
{
clrscr();
goto sub2;
}
valid='y';
}
}
if(again=='n')
{
vmenu();
}

if(valid=='n')
{
gotoxy(9,22);cout<<"Invalid registration number";
gotoxy(9,23);cout<<"Enter valid registrstion number \n";
getch();

}
folder.close();
}



void modi()    // for  modifying details of student
{
box(157,157);
stud2 S;
char sname[30];
int pos=0;
int flag=0;
fstream fin;
fin.open("record.dat",ios::binary|ios::in|ios::out);

if(!fin)
{
 cout<<"\nError in File Opening";
 getch();
 exit(0);
}

gotoxy(8,6);cout<<" Enter the registration number of the student:";
gotoxy(66,6);cout<<"(Max 30)";
gotoxy(55,6);gets(sname);
gotoxy(66,6);cout<<"         ";
while(!fin.eof())
{
 fin.read((char*)&S,sizeof(S));
 pos++;


 if(strcmpi(S.gno(),sname)==0)
  {
    fin.seekg((pos-1)*sizeof(S),ios::beg);
    S.input();
    fin.write((char*)&S,sizeof(S));
    flag=1;
   }
}

if(flag==0)
  cout<<"\nSorry.No such Name is found!!!";
getch();
fin.close();
}//End of modify function





void opan()
{
textbackground(LIGHTBLUE);
clrscr();
gotoxy(9,6);cout<<"  NN     N                                 t    h             ! ! ! ";
gotoxy(9,7);cout<<"  N N    N                          ssss   t    h       eeee  ! ! ! ";
gotoxy(9,8);cout<<"  N  N   N  aaaa   m mm mm  aaaa   s       ttt  h hh   e      ! ! ! ";
gotoxy(9,9);cout<<"  N   N  N a   a   mm mm m a   a    ssss   t    hh  h  eeeee  ! ! ! ";
gotoxy(9,10);cout<<"  N    N N a   a   m  m  m a   a        s  t    h   h  e      ! ! !  ";
gotoxy(9,11);cout<<"  N     NN  aaa aa m  m  m  aaa aa  ssss   ttt  h   h   eeee  ! ! !  ";

delay(2613);
clrscr();
box(689,689);
gotoxy(6,7);cout<<"                     Welcome                           ";
gotoxy(8,12);cout<<"  SMT.NARBADA DEVI J.AGARWAL VIVEKANANDA VIDYALAYA ";
gotoxy(8,13);cout<<"		          JUNIOR  COLLEGE   "  ;
gotoxy(8,14);cout<<"              VYASARPADI,CHENNAI-600 039 ";
delay(1000);
textbackground(LIGHTGREEN);textcolor(WHITE);
clrscr();
box(856,856);
gotoxy(6,9);cout<<"                 SCHOOL MANAGEMENT SYSTEM";
gotoxy(6,12);cout<<"       A Simple Software which illustrates School Management";
gotoxy(8,16);cout<<" Developed By: ";delay(500);
gotoxy(8,17);cout<<"                   G.TAMILZHSELVAN";delay(500);
gotoxy(8,18);cout<<"                   G.VEERARAGHAVAN";delay(500);
gotoxy(8,19);cout<<"                   C.BALAJI        ";
delay(2613);
}




void staff_menu()
{
char c1,c2;
topline:
clrscr();
textbackground(BLACK);textcolor(WHITE);
int choice,ch;
stud_reg S;
box('=','|');
textbackground(WHITE);textcolor(BLACK);
gotoxy(25,1);cprintf(" ________________________");
gotoxy(25,2);cprintf("|STUDENT REGISTER MENU  |");
gotoxy(25,3);cprintf(" ________________________");
gotoxy(1,5);cout<<"     __________________________________________________________________";
gotoxy(8,7);cout<<"Select an Option (Options are Given below)";
gotoxy(7,8);cout<<"1.Add a new Student";
gotoxy(7,9);cout<<"2.Modify Student Details";
gotoxy(7,10);cout<<"3.Search";
gotoxy(7,11);cout<<"4.Exit from Student Register";
gotoxy(11,14);cout<<"                          Enter your Option ";
cin>>choice;
switch(choice)
{ case 1:{ save_data();
	   staff_menu();
	   break;     }
  case 2:{ modify();
	   staff_menu();
	   break;}
  case 3:  clrscr();
	   textbackground(BLUE);textcolor(WHITE);
	   box(249);
	   gotoxy(8,7);cout<<"Search by";
	   gotoxy(6,8);cout<<"1.Name";
	   gotoxy(6,9);cout<<"2.Phone Number";
	   gotoxy(6,10);cout<<"3.Registration Number";
	   gotoxy(6,11);cout<<"4.Roll Number";
	   gotoxy(10,12);cout<<"Enter Your Option ";

	   cin>>ch;
	   switch(ch)
	    { case 1:  search_name();

		       break;
	      case 2:  search_phno();

		       break;
	      case 3:  search_regno();

		       break;
	      case 4:  search_rno();

		       break;
	      default: gotoxy(8,18);cout<<" Invalid Option Entered ";
		       gotoxy(8,19);cout<<" Back to student register menu?(y/n)";
		       gotoxy(45,18);cin>>c2;
		       gotoxy(8,18);cout<<"                           ";
		       gotoxy(8,19);cout<<"                                      ";

		       if(c2!='n'||c2!='N')
			 goto topline;
		       if(c2=='y'||c2=='Y')
			{
			cout<<"\nThe Program will Exit now";
			delay(250);
			exit(0);                            }
	      }
  case 4:  gotoxy(8,20);cout<<" Exit from Student Register?(y/n)";
	   gotoxy(42,20);cin>>c1;
	   if(c1=='n'||c1=='N')
	   goto topline;
	   if(c1=='y'||c1=='Y')
	   {
	   if(op==1)
	     staff_op();
	   if(op==2)
	      admin_op();
	    }
  default: cout<<"\n You have entered an Invalid Option ";
	   getch();
	   goto topline;
}
}

void secret(char a[20])
{
int size,ch1=0;
size=strlen(a);
textbackground(BLACK);
textcolor(WHITE);
int i=0;
char ch=250;
pw:
clrscr();
char pw[20],pass[20];
strcpy(pass,a);
cprintf("Enter Password ");
cout<<'\n';
while(i<size)
{
 pw[i]=getch();
 putchar(249);
 i++;
}
pw[i]='\0';
int j=0;
for(i=0;i<size,j<size;i++,j++)
{
   if(ch1==3)
   {gotoxy(6,17);cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    cprintf("\r\n||||Sorry You are not smarter than us||||    ");
    delay(1000);
    cprintf("\r\n||||      The PrOgram will eXiT nOW  ||||    ");
    delay(1000);
    exit(0);}
 if(pw[i]!=pass[j])
 {
   ch1++;
   textbackground(RED);
   textcolor(WHITE);
   clrscr();
   cprintf("       Access DENIED!!!!!!");
   gotoxy(8,12);cout<<"You Have "<<4-ch1<<" chances remaining";
   delay(1000);
   gotoxy(8,12);cout<<"                                      ";
   delay(500);
   goto pw;}
 }
textbackground(GREEN);
textcolor(WHITE);
cout<<"\n\n\n             Access Granted ";
delay(1000);
clrscr();
gotoxy(40,3);cout<<"THE SILENT SNIPERS LOCKED ON YOU!!! ";
gotoxy(20,10);
cprintf("||| Wait it's Loading");
int pos=0;
i=1;
gotoxy(41,10);
for(;pos<50;pos++,i++)
{
textbackground(BLACK);
textcolor(LIGHTGREEN+BLINK);cout<<ch;delay(250);
if(i%6==0)
{
gotoxy(41,10);
cout<<"              ";
gotoxy(41,10);}
}
}

void tmenu()
{

clrscr();
textbackground(BLUE);
textcolor(WHITE);
clrscr();
char ch;
do
{


box(789,554);
gotoxy(15,6);cout<<"*** MENU *** ";
gotoxy(15,7);cout<<"============ ";
gotoxy(10,9);cout<<"1.INSERT             (Code word is - i)";
gotoxy(10,10);cout<<"2.SEARCH BY NUMBER   (Code word s - p)";
gotoxy(10,11);cout<<"3.SEARCH BY NAME     (Code word is - n)";
gotoxy(10,12);cout<<"4.MODIFY             (Code word is - m)";
gotoxy(10,13);cout<<"5.BACK TO ADMIN MENU (code word is-b )";
gotoxy(10,18);cout<<"                          Enter the Code :"<<' ';
cin>>ch;
 if(ch=='i')
 {
 clrscr();
 insert();
 }

else if(ch=='p')
 {
 clrscr();

 searchnum();
 getch();
 }

else if(ch=='n')
 {
 clrscr();

 searchname();
 getch();
 }

else if(ch=='m')
 {
 clrscr();

 change();
 }

 else if(ch=='b')
 admin_op();
 }while(ch!='b');
 }






void staff_pass()
{
clrscr();
box(529,5654);
int i;
char ch=249;
staff s;
char snum[11],found='n';
int t=1;
ifstream fin;
fin.open("rec.dat ",ios::binary|ios::in);
ph:
t++;
gotoxy(10,7);cout<<"Enter the password:";
for(int j=0;((j<10)||(j<8));j++)
{
 snum[j]=getch();
  putchar(249);
}
snum[j]='\0';

fin.read((char*)&s,sizeof(s));
if(strcmpi(s.getnum(),snum) ==0)
{
clrscr();
textbackground(BLUE);
textcolor(WHITE);
cout<<"\n\n\n             Access Granted ";
delay(1000);
clrscr();
gotoxy(20,10);
cprintf("Authenticiating");
int pos=0;
i=1;
gotoxy(35,10);
for(;pos<50;pos++,i++)
{
textbackground(BLACK);
textcolor(LIGHTGREEN+BLINK);cout<<ch;delay(250);
if(i%6==0)
{
gotoxy(35,10);
cout<<"              ";
gotoxy(35,10);}
}
found='y';
}
if(found=='n')
{
gotoxy(10,8);cout<<"Incorrect Password";
gotoxy(10,9);cout<<"Enter corect password";
getch();
gotoxy(10,8);cout<<"                          ";
gotoxy(10,9);cout<<"                            ";

gotoxy(30,7);cout<<"                                 ";
if(t>=4)
{
gotoxy(10,9);cout<<"You are not too Smart";
delay(2500);
exit(0);
}
goto ph;
}
fin.close();
}


void vmenu()
{
textbackground(BLUE);
textcolor(YELLOW);
clrscr();
stud2 s;
clrscr();
int choice;
char ch=177;
box(250,250);
gotoxy(15,5);
cout<<"      "<<ch<<ch<<"       RESULTS REGISTER      "<<ch<<ch<<"         ";
gotoxy(15,7);
cout<<"          1.   WANT TO ADD STUDENT              ";
gotoxy(15,9);
cout<<"          2.   WANT TO MODIFY RESULTS           ";
gotoxy(15,11);
cout<<"          3.   SEARCH BY REGISTRATION NUMBER    ";
gotoxy(15,13);
cout<<"          4.   SEARCH BY SUBJECT NAME           ";
gotoxy(15,15);
cout<<"          5.   EXIT FROM STUDENTS REGISTER      ";
gotoxy(15,18);cout<<"  ENTER YOUR CHOICE  ";gotoxy(37,18);cout<<"      ";gotoxy(38,18);cin>>choice;
switch(choice)
{
case 1:{


	 clrscr();

	 s.addstud();
	 vmenu();
	 getch();
	 break;
       }
case 2:{

	 clrscr();


	 modi();
	 vmenu();
	 getch();
	 break;
       }
case 3:{

	 clrscr();


	 search_regnos();
	 vmenu();
	 getch();
	 break;
       }
case 4:{


	 clrscr();

	 search_sname();

	 vmenu();
	 getch();
	 break;
       }
case 5:{


	  clrscr();
	  box(251,251);
	  if(op==1)
	  {
	  staff_op();
	   }
	   if(op==2)
	   {
	   admin_op();
	   }
       }
}
}




void dis4()
{
clrscr();
gotoxy(15,4);
cout<<"DETAILS OF THE STUDENT BASED ON MARKS";
gotoxy(4,7);cout<<"_________________________________________________________________";
gotoxy(6,8);cout<<" REG NO ";
gotoxy(4,10);cout<<"_________________________________________________________________";
for(int j=8;j<24;j++)
{
gotoxy(15,j);
cout<<"|";
}
gotoxy(16,8);cout<<" SUBJECT NAME ";
for(j=8;j<24;j++)
{
gotoxy(32,j);
cout<<"|";
}

gotoxy(34,8);cout<<"marks";
gotoxy(33,9);cout<<" (<50)";
for(j=8;j<24;j++)
{
gotoxy(41,j);
cout<<"|";
}

gotoxy(43,8);cout<<"marks";
gotoxy(42,9);cout<<" (>50)";

for(j=8;j<24;j++)
{
gotoxy(50,j);
cout<<"|";
}


gotoxy(52,8);cout<<"marks";
gotoxy(51,9);cout<<" (=50)";
for(j=8;j<24;j++)
{
gotoxy(58,j);
cout<<"|";
}



gotoxy(60,8);cout<<"RESULT";
for(j=8;j<24;j++)
{
gotoxy(68,j);
cout<<"|";
}

for(j=8;j<24;j++)
{
gotoxy(4,j);
cout<<"|";
}

gotoxy(4,23);cout<<"  ________________________________________________________________";

getch();
}


void dis3()
{
clrscr();
gotoxy(15,4);
cout<<"DETAILS OF THE STUDENT BASED ON CLASS";
gotoxy(4,7);cout<<"_____________________________________________________________________";
gotoxy(6,8);cout<<" NAME ";
gotoxy(4,10);cout<<"_____________________________________________________________________";

for(int j=8;j<24;j++)
{
gotoxy(15,j);
cout<<"|";
}

gotoxy(16,8);cout<<" ROLL NO";
for(j=8;j<24;j++)
{
gotoxy(32,j);
cout<<"|";
}

gotoxy(34,8);cout<<"CLASS";
for(j=8;j<24;j++)
{
gotoxy(41,j);
cout<<"|";
}

gotoxy(43,8);cout<<"SECTION";
for(j=8;j<24;j++)
{
gotoxy(50,j);
cout<<"|";
}

gotoxy(52,8);cout<<"GENDER";
gotoxy(51,9);cout<<"(M/F)";
for(j=8;j<24;j++)
{
gotoxy(58,j);
cout<<"|";
}

gotoxy(60,8);cout<<"PARENT";
gotoxy(59,9);cout<<"PHONE NO";
for(j=8;j<24;j++)
{
gotoxy(73,j);
cout<<"|";
}
for(j=8;j<24;j++)
{
gotoxy(4,j);
cout<<"|";
}


gotoxy(3,23);cout<<"  ____________________________________________________________________";

getch();
}



void det_class()
{

box(250);
dis3();

int r=12,i=0;
stud_reg s;
ifstream folder;
folder.open("sch_det.dat",ios::binary|ios::in);
if(!folder)
{
gotoxy(r,24);cout<<"Unable to open the file";
getch();
detmain();
}



{
folder.read((char*)&s,sizeof(s));
gotoxy(6,r);puts(s.getname());
gotoxy(16,r);puts(s.getrollno());
gotoxy(34,r);puts(s.getclass());
gotoxy(43,r);cout<<s.getsec();
gotoxy(52,r);cout<<s.getgend();
gotoxy(60,r);puts(s.getphno());
i++;
r=r+1;

}
folder.close();



}






void det_mark()
{
box(250);
dis4();
int r=12,i=0;
stud2 s;
ifstream folder;
folder.open("record.dat",ios::binary|ios::in);
if(!folder)
{
gotoxy(r,24);cout<<"Unable to open the file";
getch();
detmain();
}



{
folder.read((char*)&s,sizeof(s));
if(s.gmark()<50)
{
gotoxy(6,r);puts(s.gno());
gotoxy(16,r);puts(s.gname());
gotoxy(34,r);cout<<"**";
gotoxy(60,r);cout<<"Fail ! ";
}
else if(s.gmark()>50)
{
gotoxy(6,r);puts(s.gno());
gotoxy(16,r);puts(s.gname());
gotoxy(43,r);cout<<"**";
gotoxy(60,r);cout<<"Pass ! ";
}
else if(s.gmark()==50)
{
gotoxy(6,r);puts(s.gno());
gotoxy(16,r);puts(s.gname());
gotoxy(52,r);cout<<"**";
gotoxy(60,r);cout<<"Pass ! ";
}
r=r+2;
i++;
}
folder.close();
}


void dis1()
{
clrscr();
gotoxy(15,4);
cout<<"DETAILS OF THE STAFF BASED ON DATE OF JOINING";
gotoxy(2,7);cout<<"______________________________________________________________________________";
gotoxy(5,8);cout<<"MONTH ";
gotoxy(2,10);cout<<"________________________________________________________________________________";
for(int j=8;j<24;j++)
{
gotoxy(11,j);
cout<<"|";
}
for(j=8;j<24;j++)
{
gotoxy(1,j);
cout<<"|";
}








gotoxy(20,8);cout<<"NAME";
for(j=8;j<24;j++)
{
gotoxy(35,j);
cout<<"|";
}

gotoxy(37,8);cout<<"GRADUATE";
for(j=8;j<24;j++)
{
gotoxy(46,j);
cout<<"|";
}

gotoxy(48,8);cout<<"Ph.Num";
for(j=8;j<24;j++)
{
gotoxy(59,j);
cout<<"|";
}

gotoxy(60,8);cout<<" SALARY";
for(j=8;j<24;j++)
{
gotoxy(68,j);
cout<<"|";
}


gotoxy(70,8);cout<<"DEPARTMENT";
for(j=8;j<24;j++)
{
gotoxy(80,j);
cout<<"|";
}

gotoxy(1,23);cout<<"_______________________________________________________________________________";


getch();
}



void det_doj()
{

staff s;
date_reg r;
box(250);
dis1();

int e=12;

ifstream folder;
folder.open("rec.dat",ios::binary|ios::in);
if(!folder)
{
gotoxy(e,24);cout<<"Unable to open the file";
getch();
detmain();
}


{
folder.read((char*)&s,sizeof(s));
r=s.getdoj();

switch(r.m)
{
case 1:{
       gotoxy(2,e);
       cout<<"January";
       break;
       }
case 2:{
       gotoxy(2,e);
       cout<<"February";
       break;
       }
case 3:{
       gotoxy(2,e);
       cout<<"March";
       break;
       }
case 4:{
       gotoxy(2,e);
       cout<<"April";
       break;
       }
case 5:{
       gotoxy(2,e);
       cout<<"May";
       break;
       }
case 6:{
       gotoxy(2,e);
       cout<<"June";
       break;
       }
case 7:{
       gotoxy(2,e);
       cout<<"July";
       break;
       }
case 8:{
       gotoxy(2,e);
       cout<<"August";
       break;
       }
case 9:{
       gotoxy(2,e);
       cout<<"September";
       break;
       }
case 10:{
	 gotoxy(2,e);
	 cout<<"October";
	 break;
	 }
case 11:{
	gotoxy(2,e);
	cout<<"November";
	break;
	}
case 12:{
	gotoxy(2,e);
	cout<<"December";
	break;
	}
default:;
}


gotoxy(20,e);puts(s.getname());
gotoxy(37,e);puts(s.getquali());
gotoxy(48,e);puts(s.getnum());
gotoxy(60,e);cout<<s.getpay();
gotoxy(70,e);puts(s.getdep());

e=e+2;

}
folder.close();



}






void dis2()
{
clrscr();
gotoxy(15,4);
cout<<"DETAILS OF THE STUDENTS BASED ON DATE OF ADMISSSION";
gotoxy(2,7);cout<<"______________________________________________________________________________";
gotoxy(6,8);cout<<"MONTH ";
gotoxy(2,10);cout<<"________________________________________________________________________________";

for(int j=8;j<24;j++)
{
gotoxy(11,j);
cout<<"|";
}

for(j=8;j<24;j++)
{
gotoxy(1,j);
cout<<"|";
}






gotoxy(12,8);cout<<" YEAR ";
for(j=8;j<24;j++)
{
gotoxy(18,j);
cout<<"|";
}


gotoxy(20,8);cout<<"NAME";
for(j=8;j<24;j++)
{
gotoxy(35,j);
cout<<"|";
}

gotoxy(37,8);cout<<"CLASS";
for(j=8;j<24;j++)
{
gotoxy(43,j);
cout<<"|";
}

gotoxy(48,8);cout<<"Ph.Num";
for(j=8;j<24;j++)
{
gotoxy(59,j);
cout<<"|";
}

gotoxy(60,8);cout<<" ROLL No";
for(j=8;j<24;j++)
{
gotoxy(68,j);
cout<<"|";
}


gotoxy(70,8);cout<<"REG. No";
for(j=8;j<24;j++)
{
gotoxy(80,j);
cout<<"|";
}

gotoxy(1,23);cout<<"_______________________________________________________________________________";


getch();
}

void det_doa()
{

stud_reg s;
date_reg r;

box(250);
dis2();

int e=12,i=0;

ifstream folder;
folder.open("sch_det.dat",ios::binary|ios::in);
if(!folder)
{
gotoxy(e,24);cout<<"Unable to open the file";
getch();
detmain();
}


{
folder.read((char*)&s,sizeof(s));
r=s.getdoa();


switch(r.m)
{
case 1:{gotoxy(3,e);cout<<"January";break;}
case 2:{gotoxy(3,e);cout<<"February";break;}
case 3:{gotoxy(3,e);cout<<"March";break;}
case 4:{gotoxy(3,e);cout<<"April";break;}
case 5:{gotoxy(3,e);cout<<"May";break;}
case 6:{gotoxy(3,e);cout<<"June";break;}
case 7:{gotoxy(3,e);cout<<"July";break;}
case 8:{gotoxy(3,e);cout<<"August";break;}
case 9:{gotoxy(3,e);cout<<"September";break;}
case 10:{gotoxy(3,e);cout<<"October";break;}
case 11:{gotoxy(3,e);cout<<"November";break;}
case 12:{gotoxy(3,e);cout<<"December";break;}
}



gotoxy(12,e);cout<<r.y;
gotoxy(20,e);puts(s.getname());
gotoxy(37,e);puts(s.getclass());
gotoxy(48,e);puts(s.getphno());
gotoxy(60,e);puts(s.getrollno());
gotoxy(70,e);puts(s.getregno());
i++;
e=e+2;

}
folder.close();



}







void detmain()
{
clrscr();
int c;
box(467,765);
s:
gotoxy(29,5);cout<<" DETAILS OF ";
gotoxy(29,10);cout<<"1.STAFF - DATE OF JOINING";
gotoxy(29,11);cout<<"2.STUDENTS - DATE OF ADMISSION";
gotoxy(29,12);cout<<"3.STUDENTS - CLASS";
gotoxy(29,13);cout<<"4.STUDENTS - MARKS";
gotoxy(29,14);cout<<"5.BACK TO MAIN MENU";
gotoxy(32,18);cout<<"                Your Option:";
cin>>c;
switch(c)
{
case 1:clrscr();
       det_doj();
       getch();
       clrscr();
       detmain();
       break;
case 2:clrscr();
       det_doa();
       getch();
       clrscr();
       detmain();
       break;
case 3:clrscr();
	det_class();
	getch();
	clrscr();
	detmain();
	break;

case 4:clrscr();
       det_mark();
       getch();
       clrscr();
       detmain();
       break;

case 5:clrscr();
       menu1();
       break;

default:gotoxy(34,18);cout<<"Invalid Option Entered";
	getch();
	gotoxy(34,18);cout<<"                      ";
	goto s;

}
}

void staff_op()
{
int o;
char c=179;
box(342,342);
textbackground(WHITE);
textcolor(BLACK);
clrscr();
f:
gotoxy(12,6);cout<<c<<c<<c<<"STAFF MENU"<<c<<c<<c;
gotoxy(12,7);cout<<"================";
gotoxy(10,9);cout<<"   1. STUDENT REGISTER  ";
gotoxy(10,10);cout<<"   2. RESULTS REGISTER  ";
gotoxy(10,11);cout<<"   3. BACK TO MAIN MENU  ";
gotoxy(10,12);cout<<" YOUR CHOICE: ";
gotoxy(25,12);cin>>o;
if(o==1)
{
clrscr();
staff_menu();
getch();
}
else if(o==2)
{
clrscr();
vmenu();
getch();
}
else if(o==3)
{
clrscr();
box(271);
menu1();
}
else
{
clrscr();
goto f;
}

}


void admin_op()
{
int o;
char c=256;
textbackground(BLUE);
textcolor(WHITE);
clrscr();
box(4);
f:
gotoxy(18,5);cout<<c<<c<<c<<"ADMINISTRATOR MENU"<<c<<c<<c;
gotoxy(18,6);cout<<"========================";
gotoxy(18,8);cout<<"   1. STAFF   REGISTER  ";
gotoxy(18,9);cout<<"   2. STUDENT REGISTER  ";
gotoxy(18,10);cout<<"   3. RESULTS REGISTER  ";
gotoxy(18,11);cout<<"   4.BACK TO MAIN MENU";
gotoxy(18,14);cout<<"                    YOUR CHOICE:  ";
gotoxy(53,14);cin>>o;
if(o==1)
{
clrscr();
tmenu();
getch();
}
else if(o==2)
{
clrscr();
staff_menu();
getch();
}
else if(o==3)
{
clrscr();
vmenu();
getch();
}
else if(o==4)
{
clrscr();
menu1();
}
else
{
clrscr();
goto f;
}

}

void bulletload()
{
clrscr();
char ch=272;
gotoxy(5,11);cout<<"          __________              ";
cout<<"\n	 ____|__________|+_______   ";
//gotoxy(5,13);
cout<<"\n       /                 _______ |o   ";
//gotoxy(5,14);
cout<<"\n      /   ____________\\\\  \\\\             ";
//gotoxy(5,15);
cout<<"\n     /   /(            \\\\  \\\\               ";
//gotoxy(5,16);
cout<<"\n    /   /               \\\\__\\\\              ";
//gotoxy(5,17);
cout<<"\n   /___/                            ";
gotoxy(5,18);
gotoxy(40,13);
//cprintf("|||  Loading |||");
int pos=0;
int i=1;
gotoxy(42,13);
for(;pos<3;pos++,i++)
{
textbackground(BLACK);
textcolor(LIGHTGREEN+BLINK);cout<<ch;delay(300);

}
gotoxy(45,14);cout<<"YOU";delay(250);cout<<" ARE";delay(250);cout<<" BAILED";delay(250);cout<<" BY";delay(250);cout<<" OUR ";delay(250);cout<<" SUPERADMIN";delay(250);
delay(2000);

gotoxy(45,14);cout<<"                                        ";
gotoxy(45,16);cout<<"THANK FOR USING OUR SERVICE ";delay(1300);
exit(0);
}


void menu1()
{
textbackground(BLUE);
textcolor(YELLOW);
clrscr();
box(272,272);
int ch,r=0;
char c=177;
f:
r++;
gotoxy(20,7);cout<<c<<c<<c<<"    MAIN MENU "<<c<<c<<c;
gotoxy(20,8);cout<<"   =================";
gotoxy(7,11);cout<<"               1.ARE YOU A STAFF ??";
gotoxy(7,13);cout<<"               2.ARE YOU A ADMINISTRATOR ??";
gotoxy(7,15);cout<<"               3.DO YOU WANT ANY DETAILS ??";
gotoxy(7,17);cout<<"               4.WANT TO EXIT ?? ";
gotoxy(7,19);cout<<"                             ENTER YOUR CHOICE:";
gotoxy(54,19);cin>>ch;
switch(ch)
{

case 1:{
       clrscr();
       op=1;
       staff_pass();
       textbackground(WHITE);
       textcolor(BLACK);
       clrscr();
       staff_op();
       break;
       }


case 2:{
       op=2;
       char ad[]="6213";
       secret(ad);
       admin_op();
       break;


       }
case 3:{

	detmain();
	break;
       }
case 4:{
       char c;
      gotoxy(10,21);
      cout<<"Are You Sure?(y/n):";
      cin>>c;
      if(c=='y'||c=='Y')
      bulletload();
      else if(c=='N'||c=='n')
      {
      gotoxy(10,21);
      cout<<"                     ";
      gotoxy(54,19);cout<<" ";
      }

      }
default:{
       gotoxy(10,21);
       cout<<"                     ";
	gotoxy(12,22);cout<<"INVALID CHOICE";
	gotoxy(12,23);cout<<" ENTER VALID CHOICE";
	getch();
	gotoxy(12,22);cout<<"                  ";
	gotoxy(12,23);cout<<"                    ";
	 gotoxy(54,19);cout<<"   ";
	if(r<3)
	goto f;
	if(r>3)
	textbackground(BLACK);
	textcolor(RED);clrscr();
	gotoxy(20,10);cout<<"Better Luck Next Time !!!  BYE!!!!!!!!!";
	delay(2000);
	exit(0);
	}

}
}

void main()
{
clrscr();
//opan();
menu1();
getch();
}
