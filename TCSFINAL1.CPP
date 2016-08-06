#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
/*
TELEPHONE MANAGEMENT
President of INDIA
MEMBERS:
1.VIGNESH
2.SUNDAR
3.SOWMYA
4.SHIVANI
5.GAYATHRI
*/
class telephone
{
/*fname-father's name,sertype-sevice type(LOCAL/STD/ISD),addpr-address proof,
sdate-subscription start date,edate-subscription end date,bpd-bill payment date*/
 char address[60],name[25],city[15],state[15],distict,fname[25],sertype[6],addpr[30],sdate[11],edate[11],email[35],bpd[25],dob[11],mobno[11],pin[10],subno[15];
 int sd,sm,sy,ed,em,ey;//subscription starting,ending date
 public:
 void del(char*);
 void menu();
 void add();
 void search(char*);
 void delreport();
 void report1();
 int billpay1(char*,char*,char*,char*);
 void displayall();
 int billdate1(char*,char*);
}s;
class bill
{
  char subno[15],bpd[11],name[25],address[50],city[25],district[25],dob[10],pin[10];
  int bd,bm,by;
  double amount;
  public:
  void billpay();
  void billdisplay(char*);
  void billreport();
  void billdate(char*,char*);
}bp;
//GLOBAL FUNCTIONS
void loading();
void line();
void password();
void center();
void fields();
void temp(char*,char*);
void abc();
void settings();
void aboutus();

void main()
{
 clrscr();
 loading();
 password();
 s.menu();
 getch();
}
void telephone::menu()
{
 char str[20],str1[25];
 long ch,ch1;
 clrscr();
 abc();
 cout<<"\n\t\t\t\tMENU\n\n\n";
 cout<<"1.ADD THE NEW SUBSCRIBER\n\n\n";
 cout<<"2.DELETE A SUBCRIBER\n\n\n";
 cout<<"3.PRINT THE DETAILS OF A SUBSCRIBER\n\n\n";
 cout<<"4.BILL PAYMENT DETAILS\n\n\n";
 cout<<"5.PRINT BILL PAYMENT DETAILS\n\n\n";
 cout<<"6.REPORTS GENERATED\n\n\n";
 cout<<"7.PRINT ALL THE DETAILS FROM THE FILE\n\n\n";
 cout<<"8.EXIT\n\n\n";
 cout<<"9.SETTINGS\n\n\n";
 cout<<"10.ABOUT US\n\n\n";
 cout<<"\n\nEnter Your Choice\t";gets(str);
   int k;
   k=strlen(str);
   ch=atol(str);
   char a[15];
 if(k==1||ch==10)
 {
 switch(ch)
  {
   case 1:clrscr();s.add();break;
   case 2:clrscr();cout<<"Please Enter Your Subscriber Number\t";gets(a);s.del(a);break;
   case 3:clrscr();cout<<"Please Enter Your Subscriber Number\t";gets(a);s.search(a);break;
   case 4:clrscr();bp.billpay();break;
   case 5:clrscr();cout<<"Please Enter Your Subscriber Number\t";gets(a);bp.billdisplay(a);break;
   case 6:clrscr();
	  cout<<"\t\t REPORTS GENERATED\n\n\n";
	  cout<<"1.PRINT THE NEW SUBSCRIPTIONS ADDED IN THE QUARTER\n\n\n";
	  cout<<"2.PRINT THE SUBSCRIPTIONS CANCELLED IN THE QUARTER\n\n\n";
	  cout<<"3.PRINT THE TRANSACTIONS MADE IN THE QUARTER\n\n\n";
	  cout<<"4.EXIT TO MAIN MENU\n\n\n";
	  cout<<"ENTER YOUR CHOICE  :\t";
	  gets(str1);
	  int l;
	  l=strlen(str1);
	  ch1=atol(str1);
	  if(l==1)
	  {
	  switch(ch1)
	   {
	     case 1:clrscr();s.report1();getch();break;
	     case 2:clrscr();s.delreport();break;
	     case 3:clrscr();bp.billreport();break;
	     case 4:clrscr();
		    cout<<"EXITING TO MAIN MENU\a.\a.\a";s.menu();
	     default:cout<<"\n\nSorry!Wrong choice please try again!";getch();s.menu();
	  }
	  }
   else
  {cout<<"\n\nSorry!Wrong choice please try again!";getch();s.menu();}
   case 7:clrscr();s.displayall();break;
   case 8:clrscr();center();cout<<"\t\t\tProgram Terminating\a\a.\a\a.\a\a.";exit(0);
   case 9:settings();break;
   case 10:aboutus();break;
   default:cout<<"\n\nSorry!Wrong choice please try again!";getch();s.menu();
  }
  }
  else
  {cout<<"\n\nSorry!Wrong choice please try again!";getch();s.menu();}
}//void menu
void loading()
{
 for(int i=1;i<=1;++i)
  {
   clrscr();
   center();
   cout<<"\t\t\t\tLOADING";
   cout<<"\a.\a.\a.\a";
  }
}
void line()
{
 cout<<"\n";
 for(int i=1;i<=80;++i)
 cout<<"-";
}
int f1=0;

void password()
{
 char a[15],b[15];
 temp(a,b);
 if(strcmp(a,"password")!=0&&strcmpi(b,"user")!=0)
  {
   ++f1;
   if(3-f1!=0)
    cout<<"\n\nInvalid ID and Password!  "<<3-f1<<" chance(s)left! Press any key to try again..";
   else
    cout<<"\n\nInvalid ID and Password!  No more chances left..Press any Key!";
    getch();
   if(3-f1!=0)
    password();
   else
    {
     clrscr();
     center();cout<<"\t\tSorry!! Program terminating due to security reasons\a\a\a.\a\a\a.\a\a\a.\a\a";
     exit(0);
    }
  }//1 if
else
 if(strcmp(a,"password")!=0&&strcmpi(b,"user")==0)
  {
   ++f1;
   if(3-f1!=0)
    cout<<"\n\nInvalid Password!  "<<3-f1<<" chance(s) left! Press any key to try again..";
   else
    cout<<"\n\nInvalid Password!  No more chances left..Press any Key!";
    getch();
   if(3-f1!=0)
    password();
   else
    {
     clrscr();
     center();
     cout<<"\t\tSorry!! Program terminating due to security reasons\a\a\a.\a\a\a.\a\a\a.\a\a";
     exit(0);
    }
  }//1 if
else
 if(strcmpi(b,"user")!=0&&strcmp(a,"password")==0)
  {
   ++f1;
   if(3-f1!=0)
    cout<<"\n\nInvalid User ID!  "<<3-f1<<" chance(s) left! Press any key to try again..";
   else
    cout<<"\n\nInvalid User ID!  No more chances left..Press any Key!";
    getch();
   if(3-f1!=0)
    password();
   else
    {
     clrscr();
     center();
     cout<<"\t\tSorry!! Program terminating due to security reasons\a\a\a.\a\a\a.\a\a\a.\a\a";
     exit(0);
    }
  }//1 if
}//void
void temp(char a[15],char b[15])
{
 int z=0;
 clrscr();
 abc();
 cout<<"\n\t\t\t\tLOGIN";
 line();
 cout<<"\n\nHINT:Password is Case Sensitive but User ID is not Case Sensitive\n";
 cout<<"\nPlease Enter Login ID\t";gets(b);
 cout<<"\nPlease Enter The Password\t";
 gotoxy(27,14);
 char ch;
 ch=getch();
 int r=-1;
 while(ch!=13)
  {                              //BACKSPACE
   if(ch!=8)
   {
   a[++r]=ch;
   cout<<"*";
   ch=getch();
   ++z;
   }
   else
   {
   gotoxy(27+z-1,14);
   cout<<" ";
   gotoxy(27+z-1,14);
   --z;
   a[r]=8;
   ch=getch();--r;
  }
  }
 a[++r]=NULL;
}//temp
void center()
{
 for(int i=1;i<=25;++i)
 cout<<"\n";
}
void abc()
{
 cout<<"\n\n\t\t\tMODERN TELEPHONES (Since 20 Years)";
 line();
}
void telephone::add()
{
 char subno[15];
 abc();
 cout<<"\t\t\t\tHINTS:\n\n1.Please Enter The Following Details To Add A New Subscriber Onto The Database..";
 line();
 cout<<"SUBSCRIPTION NUMBER*:\t";gets(subno);
 while(strcmp(subno,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field.. Please Enter Again..";getch();
   cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(subno);
  }
 int i,j=0;
 for(i=0;subno[i];++i)
 if(isdigit(subno[i]))
  ++j;
 while(strcmp(subno,NULL)!=0)
  {
   if(strlen(subno)!=j)
    {
     cout<<"\n\nSorry!!Invalid Entry..Please Try Again..";getch();
     cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(subno);
    }
   while(strcmp(subno,NULL)==0)
    {
     cout<<"\n\nThis is a mandatory field.. Please Enter Again..";getch();
     cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(subno);
    }
   j=0;
   for(i=0;subno[i];++i)
   if(isdigit(subno[i]))
    ++j;
   if(strlen(subno)==j)
    break;
  }//while
ifstream g;
g.open("inventor.dat",ios::binary);
int k=0,m=0;
while(g.read((char*)&s,sizeof(telephone)))
 {
  if(strcmp(s.subno,subno)==0)
   {++k;}
  if(k==1)
   break;
 }
if(k==1)
{
 center();
 cout<<"\t\tSorry! Subscriber Already Exists..Try again..";getch();s.menu();}
 g.close();
 strcpy(s.subno,subno);
 int q,u=0,flag=0,dd,mm,yyyy,f1,d1,m1,y1,f2;
 char o[12];

 do
 {
 //SDATE

 u=flag=f2=k=d1=m1=y1=f1=s.sd=s.sm=s.sy=s.ed=s.em=s.ey=dd=mm=yyyy=0;
 cout<<"\n\nPlease Enter SUBSCRIPTION START DATE in the format  \"dd/mm/yyyy\":";gets(s.sdate);
 while(strcmp(s.sdate,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
   cout<<"SUBSCRIPTION START DATE*:\t";gets(s.sdate);
  }
 for(i=0;s.sdate[i];++i)
 if(s.sdate[i]=='/')
  ++k;
 sscanf(s.sdate,"%d/%d/%d",&s.sd,&s.sm,&s.sy);
 q=s.sy;
 while(q)
  {
   q/=10;
   ++u;
  }
 if(s.sm<1||s.sm>12||s.sd<1||u!=4)
  flag=1;
 switch(s.sm)
  {
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12:
    if(s.sd>31)flag=1;break;
   case 2:
    if(s.sy%4==0&&s.sd>29)flag=1;
     else
    if(s.sy%4!=0&&s.sd>28)flag=1;
    break;
   case 4:
   case 6:
   case 9:
   case 11:
    if(s.sd>30)flag=1;break;
  }
//MAIN
while(flag==1||k!=2)
 {//*
  u=flag=k=0;
  cout<<"\n\nSorry!Invalid Date! Please Try Again..";getch();
  cout<<"\n\nSUBSCRIPTION START DATE*:\t";gets(s.sdate);
  while(strcmp(s.sdate,NULL)==0)
   {
    cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
    cout<<"SUBSCRIPTION START DATE*:\t";gets(s.sdate);
   }
   for(i=0;s.sdate[i];++i)
   if(s.sdate[i]=='/')
    ++k;
sscanf(s.sdate,"%d/%d/%d",&s.sd,&s.sm,&s.sy);
q=s.sy;
while(q)
{
 q/=10;
 ++u;
}
if(s.sm<1||s.sm>12||s.sd<1||u!=4)
 flag=1;
 switch(s.sm)
  {
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12:
    if(s.sd>31)flag=1;break;
   case 2:
    if(s.sy%4==0&&s.sd>29)flag=1;
     else
    if(s.sy%4!=0&&s.sd>28)flag=1;
     break;
   case 4:
   case 6:
   case 9:
   case 11:
    if(s.sd>30)flag=1;break;
  }
 }//*
_strdate(o);
sscanf(o,"%d/%d/%d",&m1,&d1,&y1);
y1+=2000;
if(s.sy<y1)f2=2;
if(s.sy==y1&&s.sm<m1)f2=2;
if(s.sy==y1&&s.sm==m1&&s.sd<d1)f2=2;
if(f2==2)
{
cout<<"\n\nSORRY!! SUBSCRIPTION START DATE CANNOT BE LESS THAN CURRENT DATE!!\n\nTRY AGAIN";
}
}while(f2==2);
//EDATE
u=flag=k=0;
cout<<"\n\nPlease Enter SUBSCRIPTION END DATE in the format  \"dd/mm/yyyy\":";gets(s.edate);
while(strcmp(s.edate,NULL)==0)
{
 cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
 cout<<"SUBSCRIPTION END DATE*:\t";gets(s.edate);
}
for(i=0;s.edate[i];++i)
if(s.edate[i]=='/')
 ++k;
sscanf(s.edate,"%d/%d/%d",&s.ed,&s.em,&s.ey);
q=s.ey;
while(q)
 {
  q/=10;
  ++u;
 }
if(s.em<1||s.em>12||s.ed<1||u!=4)
 flag=1;
switch(s.em)
 {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
   if(s.ed>31)flag=1;break;
  case 2:
   if(s.ey%4==0&&s.ed>29)flag=1;
    else
   if(s.ey%4!=0&&s.ed>28)flag=1;
   break;
  case 4:
  case 6:
  case 9:
  case 11:
   if(s.ed>30)flag=1;break;
 }
f1=0;
if(s.ey<s.sy)f1=2;
else
if(s.ey==s.sy&&s.em==s.sm&&s.ed==s.sd)f1=2;
else
if(s.ey==s.sy&&s.em<s.sm)f1=2;
else
if(s.ey==s.sy&&s.em==s.sm&&s.ed<s.sd)f1=2;
//MAIN
while(flag==1||k!=2||f1==2)
{//*
 if(flag==1)
  {
   cout<<"\n\nSorry!Invalid Date! Please Try Again..";getch();
   cout<<"\n\nSUBSCRIPTION END DATE*:\t";gets(s.edate);
  }
 if(f1==2&&flag!=1)
  {
   cout<<"\n\nSorry!Subscriber End Date cannot be less than or equal to Subscriber Start Date.\n\nTry Again";getch();
   cout<<"\n\nSUBSCRIPTION END DATE*:\t";gets(s.edate);
  }
 u=flag=k=0;
 while(strcmp(s.edate,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
   cout<<"SUBSCRIPTION END DATE*:\t";gets(s.edate);
  }
 for(i=0;s.edate[i];++i)
 if(s.edate[i]=='/')
  ++k;
 sscanf(s.edate,"%d/%d/%d",&s.ed,&s.em,&s.ey);
 q=s.ey;
 while(q)
  {
   q/=10;
   ++u;
  }
 if(s.em<1||s.em>12||s.ed<1||u!=4)
 flag=1;
 switch(s.em)
  {
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12:
    if(s.ed>31)flag=1;break;
   case 2:
    if(s.ey%4==0&&s.ed>29)flag=1;
     else
    if(s.ey%4!=0&&s.ed>28)flag=1;
    break;
   case 4:
   case 6:
   case 9:
   case 11:
    if(s.ed>30)flag=1;break;
  }
 f1=0;
 if(s.ey<s.sy)f1=2;
  else
 if(s.ey==s.sy&&s.em==s.sm&&s.ed==s.sd)f1=2;
  else
 if(s.ey==s.sy&&s.em<s.sm)f1=2;
  else
 if(s.ey==s.sy&&s.em==s.sm&&s.ed<s.sd)f1=2;
  else
  f1=0;
}//*
cout<<"\n\nSUBSCRIBER NAME*:\t";gets(s.name);
int p=1;
while(strcmp(s.name,NULL)==0)
{
 cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
 cout<<"SUBSCRIBER NAME*:\t";gets(s.name);
}
while(strcmp(s.name,NULL)!=0&&p!=0)
{
 p=0;
 for(i=0;s.name[i];++i)
 if((!isalpha(s.name[i]))&&s.name[i]!='.'&&s.name[i]!=' ')
  ++p;
 if(p!=0)
  {
   cout<<"\n\nINVALID NAME!! Try Again..";getch();
   cout<<"\n\nSUBSCRIBER NAME*:\t";gets(s.name);
  }//if
 while(strcmp(s.name,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
   cout<<"SUBSCRIBER NAME*:\t";gets(s.name);
  }
}//whilein
cout<<"\n\nFATHER'S NAME:\t";gets(s.fname);
p=1;
while(strcmp(s.fname,NULL)!=0&&p!=0)
 {
  p=0;
  for(i=0;s.fname[i];++i)
  if((!isalpha(s.fname[i]))&&s.fname[i]!='.'&&s.fname[i]!=' ')
   ++p;
  if(p!=0)
   {
    cout<<"\n\nINVALID NAME!! Try Again..";getch();
    cout<<"\n\nFATHER'S NAME*:\t";gets(s.fname);
   }//if
 }//whilein
cout<<"\n\nADDRESS*:\t";gets(s.address);
while(strcmp(s.address,NULL)==0)
{
 cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
 cout<<"ADDRESS*:\t";gets(s.address);
}
cout<<"\n\nCITY:\t";gets(s.city);
p=1;
while(strcmp(s.city,NULL)!=0&&p!=0)
{
 p=0;
 for(i=0;s.city[i];++i)
 if((!isalpha(s.city[i]))&&s.city[i]!=' ')
  ++p;
 if(p!=0)
  {
   cout<<"\n\nINVALID CITY NAME!! Try Again..";getch();
   cout<<"\n\nCITY:\t";gets(s.city);
  }//if
}
cout<<"\n\nSTATE:\t";gets(s.state);
p=1;
while(strcmp(s.state,NULL)!=0&&p!=0)
{
 p=0;
 for(i=0;s.state[i];++i)
 if((!isalpha(s.state[i]))&&s.state[i]!=' ')
  ++p;
 if(p!=0)
  {
   cout<<"\n\nINVALID STATE NAME!! Try Again..";getch();
   cout<<"\n\nSTATE:\t";gets(s.state);
  }//if
 }
cout<<"\n\nPINCODE:\t";gets(s.pin);
k=strlen(s.pin);
m=0;
for(i=0;s.pin[i];++i)
if(isdigit(s.pin[i]))
 ++m;
 while((strcmp(s.pin,NULL)!=0)&&m!=k||k!=6)
  {
   m=0;
   if(m!=k)
    {
     cout<<"\n\nSorry!INVALID PIN CODE!! (pincode should be of 6-digits)  Try Again..";getch();
     cout<<"\n\nPINCODE:\t";gets(s.pin);k=strlen(s.pin);
     for(i=0;s.pin[i];++i)
     if(isdigit(s.pin[i]))
      ++m;
    }
    else
     break;
  }
k=flag=dd=mm=yyyy=0;
cout<<"\n\nDATE  OF  BIRTH*:\t";gets(s.dob);
while(strcmp(s.dob,NULL)==0)
{
 cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
 cout<<"\n\nDATE  OF  BIRTH*:\t";gets(s.dob);
}
for(i=0;s.dob[i];++i)
if(s.dob[i]=='/')
 ++k;
sscanf(s.dob,"%d/%d/%d",&dd,&mm,&yyyy);
q=yyyy;
u=0;
while(q)
{
 q/=10;
 ++u;
}
if(mm<1||mm>12||dd<1||u!=4)
 flag=1;
switch(mm)
 {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
   if(dd>31)flag=1;break;
  case 2:
   if(yyyy%4==0&&dd>29)flag=1;
  else
   if(yyyy%4!=0&&dd>28)flag=1;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
   if(dd>30)flag=1;break;
 }
//MAIN
while(flag==1||k!=2)
{//*
 u=flag=k=0;
 cout<<"\n\nSorry!Invalid Date!Date should be of the form \"dd/mm/yyyy\" Please Try Again..";getch();
 cout<<"\n\nDATE OF BIRTH*:\t";gets(s.dob);
 while(strcmp(s.dob,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
   cout<<"DATE OF BIRTH*:\t";gets(s.dob);
  }
 for(i=0;s.dob[i];++i)
 if(s.dob[i]=='/')
  ++k;
 sscanf(s.dob,"%d/%d/%d",&dd,&mm,&yyyy);
 q=yyyy;
 while(q)
  {
   q/=10;
   ++u;
  }
 if(mm<1||mm>12||dd<1||u!=4)
 flag=1;
 switch(mm)
  {
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12:
    if(dd>31)flag=1;break;
   case 2:
    if(yyyy%4==0&&dd>29)flag=1;
   else
    if(yyyy%4!=0&&dd>28)flag=1;
     break;
   case 4:
   case 6:
   case 9:
   case 11:
    if(dd>30)flag=1;break;
  }
}//*
if(s.sy-yyyy<18)
 {
  cout<<"\n\nSorry! You Must Attain A minimum Age Of 18 To Subscribe..";getch();s.menu();}
  m=0;
  cout<<"\n\nEMAIL ADDRESS:\t";gets(s.email);
  while(strcmp(s.email,NULL)!=0&&m==0)
   {
    k=0;
    if(isdigit(s.email[0]))
     k=-20;
    for(int i=0;s.email[i];++i)
     {
      if(s.email[i]=='@')
       {++k;u=i;}
      if(s.email[i]=='.')
       ++k;
      if((s.email[i]=='@'&&s.email[i+1]=='.')||(s.email[i]=='.'&&s.email[i]=='@'))
       k=-20;
      if(s.email[i]==' ')
       k=-20;
     }
    for(i=u;s.email[i];++i)
    if(isdigit(s.email[i]))
     k=-20;
    if(k<2)
     {
      cout<<"\n\nSorry!Wrong Email Address!Try Again..";
      cout<<"\n\nEMAIL ADDRESS:\t";gets(s.email);
     }
     else
      ++m;
   }
cout<<"\n\nMOBILE NUMBER:\t";gets(s.mobno);
k=0;int c;
p=strlen(s.mobno);
while(strcmp(s.mobno,NULL)!=0&&k==0)
{
 m=0;
 c=strlen(s.mobno);
 for(i=0;s.mobno[i];++i)
  if(isalpha(s.mobno[i])||ispunct(s.mobno[i])||isspace(s.mobno[i]))++m;
   if(c<10||m!=0)
    {
     cout<<"\n\nSorry!Wrong Mobile Number!Try Again!\n\n";
     cout<<"MOBILE NUMBER:\t";gets(s.mobno);
    }
    else
     ++k;
}
cout<<"\n\nADDRESS PROOF ATTACHED*:\t";gets(s.addpr);
while(strcmp(s.addpr,NULL)==0)
{
 cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
 cout<<"ADDRESS PROOF ATTACHED*:\t";gets(s.addpr);
}
cout<<"\n\nTYPE OF SERVICE (STD/ISD/LOCAL)*:\t";gets(s.sertype);
while(strcmp(s.sertype,NULL)==0)
{
 cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
 cout<<"TYPE OF SERVICE*:\t";gets(s.sertype);
}
k=0;
if(strcmpi(s.sertype,"LOCAL")==0||strcmpi(s.sertype,"STD")==0||strcmpi(s.sertype,"ISD")==0)
 ++k;
while(k==0)
{
 cout<<"\n\nSorry! Invalid Entry! Please Try Again!\n\n";
 cout<<"TYPE OF SERVICE*:\t";gets(s.sertype);
 if(strcmpi(s.sertype,"LOCAL")==0||strcmpi(s.sertype,"STD")==0||strcmpi(s.sertype,"ISD")==0)
  ++k;
}
clrscr();
ofstream f;
f.open("inventor.dat",ios::binary|ios::app);
f.write((char*)&s,sizeof(telephone));
f.close();
center();
cout<<"\t\t\tTHANK YOU!\a\a";
s.menu();
}

void telephone::search(char a[15])
{
 while(strcmp(a,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field.. Please Enter Again..";getch();
   cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
  }
 int i,j=0;
 for(i=0;a[i];++i)
 if(isdigit(a[i]))
  ++j;
 while(strcmp(a,NULL)!=0)
  {
   if(strlen(a)!=j)
    {
     cout<<"\n\nSorry!!Invalid Entry..Please Try Again..";getch();
     cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
    }
   while(strcmp(a,NULL)==0)
    {
     cout<<"\n\nThis is a mandatory field.. Please Enter Again..";getch();
     cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
    }
   j=0;
   for(i=0;a[i];++i)
   if(isdigit(a[i]))
    ++j;
   if(strlen(a)==j)
    break;
  }
char sno[15];
strcpy(sno,a);
int k=0;
ifstream f;
f.open("inventor.dat",ios::binary|ios::app);
while(f.read((char*)&s,sizeof(telephone)))
{
 if(strcmp(s.subno,sno)==0)
  {++k;
   cout<<"\n\nSUBSCRIPTION NUMBER:\t"<<s.subno;
   cout<<"\n\nSUBSCRIBER NAME:\t"<<s.name;
   cout<<"\n\nSUBSCRIBER START DATE:\t"<<s.sdate;
   cout<<"\n\nSUBSCRIBER END DATE:\t"<<s.edate;
   cout<<"\n\nFATHER NAME:\t\t"<<s.fname;
   cout<<"\n\nADDRESS:\t\t"<<s.address;
   cout<<"\n\nCITY:\t\t\t"<<s.city;
   cout<<"\n\nSTATE:\t\t\t"<<s.state;
   cout<<"\n\nPINCODE:\t\t"<<s.pin;
   cout<<"\n\nDATE OF BIRTH:\t\t"<<s.dob;
   cout<<"\n\nE-MAIL:\t\t\t"<<s.email;
   cout<<"\n\nMOBILE NUMBER:\t\t"<<s.mobno;
   cout<<"\n\nADDRESS-PROOF:\t\t"<<s.addpr;
   cout<<"\n\nSERVICE TYPE:\t\t"<<s.sertype;
  }
 if(k==1)
  break;
}
if(k!=1)
{
 cout<<"\n\nSorry!Subscriber not found..Please check the subscriber no. and try again..";getch();s.menu();
}
f.close();
getch();
s.menu();
}//void

void telephone::del(char a[15])
{
clrscr();
 char ch;
 while(strcmp(a,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field.. Please Enter Again..";getch();
   cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
  }
 int i,j=0;
 for(i=0;a[i];++i)
 if(isdigit(a[i]))
  ++j;
 while(strcmp(a,NULL)!=0)
  {
   if(strlen(a)!=j)
    {
     cout<<"\n\nSorry!!Invalid Entry..Please Try Again..";getch();
     cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
    }

 while(strcmp(a,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field.. Please Enter Again..";getch();
   cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
  }
 j=0;
 for(i=0;a[i];++i)
 if(isdigit(a[i]))
  ++j;
 if(strlen(a)==j)
  break;
}
char sno[15];
strcpy(sno,a);
int k=0;
ifstream f;
ofstream x;
ofstream b;
f.open("inventor.dat",ios::binary);
x.open("temp.dat",ios::binary);
b.open("del.dat",ios::binary|ios::app);
while(f.read((char*)&s,sizeof(telephone)))
{
 if(strcmp(s.subno,sno)==0)
  {
   ++k;
   cout<<"\n\nSUBSCRIPTION NUMBER:\t"<<s.subno;
   cout<<"\n\nSUBSCRIBER NAME:\t"<<s.name;
   cout<<"\n\nSUBSCRIBER START DATE:\t"<<s.sdate;
   cout<<"\n\nSUBSCRIBER END DATE:\t"<<s.edate;
   cout<<"\n\nFATHER NAME:\t\t"<<s.fname;
   cout<<"\n\nADDRESS:\t\t"<<s.address;
   cout<<"\n\nCITY:\t\t\t"<<s.city;
   cout<<"\n\nSTATE:\t\t\t"<<s.state;
   cout<<"\n\nPINCODE:\t\t"<<s.pin;
   cout<<"\n\nDATE OF BIRTH:\t\t"<<s.dob;
   cout<<"\n\nE-MAIL:\t\t\t"<<s.email;
   cout<<"\n\nMOBILE NUMBER:\t\t"<<s.mobno;
   cout<<"\n\nADDRESS-PROOF:\t\t"<<s.addpr;
   cout<<"\n\nSERVICE TYPE:\t\t"<<s.sertype;
  }
 if(k==1)
  break;
}
if(k==0)
{
 center();
 cout<<"\t\t\tSorry!Record not found!";getch();s.menu();}
 if(k!=0)
  cout<<"\n\nAre You Sure That You Want To Delete This Subscriber (Y/N)?\t";
  ch=getch();
 if(ch=='n'||ch=='N')
 s.menu();
 else
 if(ch=='y'||ch=='Y')
  {
   f.seekg(0);
   while(f.read((char*)&s,sizeof(telephone)))
    {
     if(strcmp(sno,s.subno)!=0)
     x.write((char*)&s,sizeof(telephone));
     else
     b.write((char*)&s,sizeof(telephone));
    }
   f.close();
   x.close();
   ofstream f("inventor.dat",ios::binary|ios::trunc);
   ifstream x("temp.dat",ios::binary);
   while(x.read((char*)&s,sizeof(telephone)))
    {
     f.write((char*)&s,sizeof(telephone));
    }
   f.close();
   x.close();
   cout<<"\n\n\t\t\tDELETION SUCCESSFULL";
   getch();
  }
 else
  {
   cout<<"\n\nYou must Enter Either 'Y'or 'N' ..Try Again..";getch();
   s.del(a);
  }
 b.close();
 s.menu();
}//void

void bill::billpay()
{
 clrscr();
 int k,q,u;
 cout<<"\t\t\t"<<"BILL PAYMENT FORM";
 line();
 char subno[15];
 cout<<"SUBSCRIPTION NUMBER*:\t";gets(subno);
 cout<<"\n\nNAME OF THE SUBSCRIBER*:\t";gets(bp.name);
 while(strcmp(bp.name,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
   cout<<"\n\nSUBSCRIBER NAME*:\t";gets(bp.name);
  }
 int p=1;
 while(strcmp(bp.name,NULL)!=0&&p!=0)
  {
   p=0;
   for(int i=0;bp.name[i];++i)
   if((!isalpha(bp.name[i]))&&bp.name[i]!='.'&&bp.name[i]!=' ')
    ++p;
   if(p!=0)
    {
     cout<<"\n\nINVALID NAME!! Try Again..";getch();
     cout<<"\n\nSUBSCRIBER NAME*:\t";gets(bp.name);
    }//if
   while(strcmp(bp.name,NULL)==0)
    {
     cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
     cout<<"SUBSCRIBER NAME*:\t";gets(bp.name);
    }
  }//whilein
 int h;
 char address[60],dob[11];
 h=s.billpay1(subno,bp.name,address,dob);
 strcpy(bp.subno,subno);
 strcpy(bp.address,address);
 strcpy(bp.dob,dob);
 getch();
 char ch;
 if(h==2)
  {
   cout<<"\n\n\t\t\tProceed?(Y/N) :\t";ch=getch();
   switch(ch)
    {
     case 'y':
     case 'Y':
     clrscr();abc();
     int flag;
     flag=u=k=0;
     cout<<"\n\nBILL PAYMENT DATE*:\t";gets(bp.bpd);
     while(strcmp(bp.bpd,NULL)==0)
      {
       cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
       cout<<"BILL PAYMENT DATE*:\t";gets(bp.bpd);
      }
     for(int i=0;bp.bpd[i];++i)
     if(bp.bpd[i]=='/')
      ++k;
     sscanf(bp.bpd,"%d/%d/%d",&bp.bd,&bp.bm,&bp.by);
     q=bp.by;
     while(q)
      {
       q/=10;
       ++u;
      }
     if(bp.bm<1||bp.bm>12||bp.bd<1||u!=4)
      flag=1;
     switch(bp.bm)
      {
       case 1:
       case 3:
       case 5:
       case 7:
       case 8:
       case 10:
       case 12:
	if(bp.bd>31)flag=1;break;
       case 2:
	if(bp.by%4==0&&bp.bd>29)flag=1;
	 else
	if(bp.by%4!=0&&bp.bd>28)flag=1;
	 break;
       case 4:
       case 6:
       case 9:
       case 11:
	if(bp.bd>30)flag=1;break;
      }
   //MAIN
  while(flag==1||k!=2)
   {//*
    u=flag=k=0;
    cout<<"\n\nSorry!Invalid Date!Date should be of the form \"dd/mm/yyyy\" Please Try Again..";getch();
    cout<<"\n\nBILL PAYMENT DATE*:\t";gets(bp.bpd);
    while(strcmp(bp.bpd,NULL)==0)
     {
      cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
      cout<<"BILL PAYMENT DATE*:\t";gets(bp.bpd);
     }
    for(i=0;bp.bpd[i];++i)
    if(bp.bpd[i]=='/')
     ++k;
    sscanf(bp.bpd,"%d/%d/%d",&bp.bd,&bp.bm,&bp.by);
    q=bp.by;
    while(q)
     {
      q/=10;
      ++u;
     }
    if(bp.bm<1||bp.bm>12||bp.bd<1||u!=4)
     flag=1;
    switch(bp.bm)
     {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
       if(bp.bd>31)flag=1;break;
      case 2:
       if(bp.by%4==0&&bp.bd>29)flag=1;
	else
       if(bp.by%4!=0&&bp.bd>28)flag=1;
	break;
       case 4:
       case 6:
       case 9:
       case 11:
	if(bp.bd>30)flag=1;break;
     }
   }//*
  billdate(bp.subno,bp.bpd);
  cout<<"\n\nAMOUNT PAID*:\t";cin>>bp.amount;
  ofstream f;
  f.open("bill.dat",ios::binary|ios::app);
  f.write((char*)&bp,sizeof(bill));
  clrscr();
  center();
  cout<<"\t\t\tTHANK YOU!\a\a";
  f.close();
  s.menu();
  break;
  case 'n':
  case 'N':
  s.menu();break;
  default:cout<<"\n\nSorry!!You Must Either 'Y' or 'N'..Try Again.";getch();bp.billpay();
 }//switch
}//if
s.menu();
}//VOID

void bill::billdisplay(char a[15])
{
 while(strcmpi(a,NULL)==0)
  {
   cout<<"\n\nThis is a mandatory field.. Please Enter Again..";getch();
   cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
  }
  int i,j=0;
  for(i=0;a[i];++i)
  if(isdigit(a[i]))
   ++j;
  while(strcmp(a,NULL)!=0)
   {
    if(strlen(a)!=j)
     {
      cout<<"\n\nSorry!!Invalid Entry..Please Try Again..";getch();
      cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
     }
     while(strcmp(a,NULL)==0)
      {
       cout<<"\n\nThis is a mandatory field.. Please Enter Again..";getch();
       cout<<"\n\nSUBSCRIPTION NUMBER*:\t";gets(a);
   }
  j=0;
  for(i=0;a[i];++i)
  if(isdigit(a[i]))
   ++j;
   if(strlen(a)==j)
    break;
  }
 int k=0;
 ifstream f;
 f.open("bill.dat",ios::binary,ios::app);
 while(f.read((char*)&bp,sizeof(bill)))
  {
   if(strcmpi(a,bp.subno)==0)
    {
     ++k;
     cout<<"\n\nSUBSCRIBER NUMBER:\t";cout<<bp.subno;
     cout<<"\n\nBILL PAYMENT DATE:\t";cout<<bp.bpd;
     cout<<"\n\nNAME OF THE SUBSCRIBER:\t";cout<<bp.name;
     cout<<"\n\nADDRESS:\t\t";cout<<bp.address;
     cout<<"\n\nDATE OF BIRTH:\t\t";cout<<bp.dob;
     cout<<"\n\nAMOUNT PAID:\t\t";cout<<bp.amount;
     line();
    }
  }
 if(k==0)
  {
   cout<<"\n\nSorry!Record not found..Please Check your Subscription Number And Try Again..";getch();s.menu();f.close();
  }
 f.close();
 getch();
 s.menu();
}//void

void bill::billreport()
{
 int m,k,y,ch1,t,h=0;char l[11],str3[10],y1[10];
 long int b1,b2,b3,b4;
 k=b1=b2=b3=b4=0;
clrscr();
abc();
cout<<"\nENTER THE YEAR FOR WHICH THE REPORT HAS TO BE DISPLAYED:";gets(y1);
 for(int i=0;y1[i];++i)
 if(isdigit(y1[i]))
 ++h;
 if(h!=4||strlen(y1)!=4){cout<<"\n\nSorry!! Invalid Year!! Try Again..";getch();bp.billreport();}
 y=atol(y1);
clrscr();
abc();
cout<<"\t\t\t\tMENU";line();
cout<<"\n\n1.JANUARY-MARCH";
cout<<"\n\n2.APRIL-JUNE";
cout<<"\n\n3.JULY-SEPTEMBER";
cout<<"\n\n4.OCTOBER-DECEMBER";
cout<<"\n\n5.EXIT";
cout<<"\n\nEnter Your Choice\t";gets(str3);
 m=strlen(str3);
 ch1=atol(str3);
 clrscr();
if(m==1&&ch1!=0&&ch1!=6&&ch1!=7&&ch1!=8&&ch1!=9)
{
clrscr();
ifstream f;
f.open("bill.dat",ios::binary);
 clrscr();
 switch(ch1)
  {
   case 1:
   while(f.read((char*)&bp,sizeof(bill)))
    {
     if(bp.bd>=1&&(bp.bm>=1&&bp.bm<=3)&&bp.by==y)
      {++k;
       cout<<"\n\nSUBSCRIBER NUMBER:\t"<<bp.subno;
       cout<<"\n\nSUBSCRIBER NAME:\t"<<bp.name;
       cout<<"\n\nAMOUNT PAID:\t"<<bp.amount;
       cout<<"\n\nBILL PAYMENT DATE:\t"<<bp.bpd;
       line();
       b1+=bp.amount;
      }//if
    }//while
   if(k==0)
   cout<<"\n\nSorry!No Records Found In This Date..";
   else
   cout<<"THE TOTAL AMOUNT PAID IN THE QUARTER IS RS."<<b1;
   getch();s.menu();
   f.close();
   break;
   case 2:
    while(f.read((char*)&bp,sizeof(bill)))
     {
      if(bp.bd>=1&&(bp.bm>=4&&bp.bm<=6)&&bp.by==y)
       {++k;
	cout<<"\n\nSUBSCRIBER NUMBER:\t"<<bp.subno;
	cout<<"\n\nSUBSCRIBER NAME:\t"<<bp.name;
	cout<<"\n\nAMOUNT PAID:\t\t"<<bp.amount;
	cout<<"\n\nBILL PAYMENT DATE:\t"<<bp.bpd;
	line();
	b2+=bp.amount;
       }//if
     }//while
    if(k==0)
     cout<<"\n\nSorry!No Records Found In This Date..";
     else
     cout<<"THE TOTAL AMOUNT PAID IN THE QUARTER IS RS."<<b2;
     getch();s.menu();
     break;
   case 3:
    while(f.read((char*)&bp,sizeof(bill)))
     {
      if(bp.bd>=1&&(bp.bm>=7&&bp.bm<=9)&&bp.by==y)
       {++k;
	cout<<"\n\nSUBSCRIBER NUMBER:\t"<<bp.subno;
	cout<<"\n\nSUBSCRIBER NAME:\t"<<bp.name;
	cout<<"\n\nAMOUNT PAID:\t\t"<<bp.amount;
	cout<<"\n\nBILL PAYMENT DATE:\t"<<bp.bpd;
	line();
	b3+=bp.amount;
       }//if
     }//while
   if(k==0)
    cout<<"\n\nSorry!No Records Found In This Date..";
    else
    cout<<"THE TOTAL AMOUNT PAID IN THE QUARTER IS RS."<<b3;
    getch();s.menu();
    break;
   case 4:
    while(f.read((char*)&bp,sizeof(bill)))
     {
      if(bp.bd>=1&&(bp.bm>=10&&bp.bm<=12)&&bp.by==y)
       {++k;
	cout<<"\n\nSUBSCRIBER NUMBER:\t"<<bp.subno;
	cout<<"\n\nSUBSCRIBER NAME:\t"<<bp.name;
	cout<<"\n\nAMOUNT PAID:\t\t"<<bp.amount;
	cout<<"\n\nBILL PAYMENT DATE:\t"<<bp.bpd;
	line();
	b4+=bp.amount;
       }//if
     }//while
   if(k==0)
    cout<<"\n\nSorry!No Records Found In This Date..";
    else
    cout<<"THE TOTAL AMOUNT PAID IN THE QUARTER IS RS."<<b4;
    f.close();
    getch();s.menu();
    break;
   case 5:clrscr();center();cout<<"\t\t\tProgram Terminating\a.\a.\a";exit(0);
   default:cout<<"\n\nSorry! Invalid Choice! Please Try Again..";getch();bp.billreport();
   }
 getch();
 f.close();
}
else
{cout<<"\n\nSorry! Invalid Choice.. Please Try Again..";++k;getch();clrscr();bp.billreport();}
  getch();
  s.menu();

}

void telephone::delreport()
{
 clrscr();
 abc();                                //DELETE REPORT
 int y,p=0,ch,l,j=0,n=0,h=0;
char y1[10],str2[20];
 cout<<"ENTER THE YEAR FOR WHICH THE DELETED REPORT HAS TO BE DISPLAYED:";gets(y1);
 for(int i=0;y1[i];++i)
 if(isdigit(y1[i]))
 ++h;
 if(h!=4||strlen(y1)!=4){cout<<"\n\nSorry!! Invalid Year!! Try Again..";getch();s.delreport();}
 y=atol(y1);
 clrscr();
 cout<<"\t\t\tSUBSCRIPTIONS DELETED IN THE QUARTER\n";line();
 cout<<"1.FIRST QUARTER (JAN-MAR)\n\n";
 cout<<"2.SECOND QUARTER (APR-JUN)\n\n";
 cout<<"3.THIRD QUARTER (JUL-SEP)\n\n";
 cout<<"4.FOURTH QUARTER (OCT -DEC)\n\n";
 cout<<"5.EXIT TO MAIN MENU\n\n";
 cout<<"ENTER YOUR CHOICE\t";
 gets(str2);
 l=strlen(str2);
 ch=atol(str2);

clrscr();abc();
if(l==1&&ch!=0&&ch!=6&&ch!=7&&ch!=8&&ch!=9)
{
ifstream f;
 f.open("del.dat",ios::binary|ios::app);
 while(f.read((char*)&s,sizeof(telephone)))
  {
   if(s.ey==y)
    {
     switch(ch)
      {
       case 1:++j;
       switch(s.em)
	{
	 case 1:
	 case 2:
	 case 3:
	  ++p;
	  cout<<"SUBSCRIPTION NO:"<<s.subno<<"\n\nSUBSCRIBER NAME:"<<s.name<<"\n\n SUBSCRIBER START DATE:"<<s.sdate<<"\n\nSUBSCRIBER END DATE:"<<s.edate<<"\n\nFATHER'S NAME:"<<s.fname<<"\n\nADDRESS:"<<s.address<<"\n\nCITY:" <<s.city<<"\n\nSTATE:"<<s.state<<"\n\nPINCODE:"<<s.pin<<"\n\nDATE OF BIRTH:"<<s.dob<<"\n\nEMAIL:"<<s.email<<"\n\nMOBILE NUMBER:"<<s.mobno<<"\n\nADDRESS PROOF:"<<s.addpr<<"\n\nTYPE OF SERVICE:"<<s.sertype;
	}break;
       case 2:++j;
	switch(s.em)
	 {
	  case 4:
	  case 5:
	  case 6:
	   ++p;
	   cout<<"SUBSCRIPTION NO:"<<s.subno<<"\n\nSUBSCRIBER NAME:"<<s.name<<"\n\n SUBSCRIBER START DATE:"<<s.sdate<<"\n\nSUBSCRIBER END DATE:"<<s.edate<<"\n\nFATHER'S NAME:"<<s.fname<<"\n\nADDRESS:"<<s.address<<"\n\nCITY:" <<s.city<<"\n\nSTATE:"<<s.state<<"\n\nPINCODE:"<<s.pin<<"\n\nDATE OF BIRTH:"<<s.dob<<"\n\nEMAIL:"<<s.email<<"\n\nMOBILE NUMBER:"<<s.mobno<<"\n\nADDRESS PROOF:"<<s.addpr<<"\n\nTYPE OF SERVICE:"<<s.sertype;
	  }break;
       case 3:++j;
	switch(s.em)
	 {
	  case 7:
	  case 8:
	  case 9:
	   ++p;
	   cout<<"SUBSCRIPTION NO:"<<s.subno<<"\n\nSUBSCRIBER NAME:"<<s.name<<"\n\n SUBSCRIBER START DATE:"<<s.sdate<<"\n\nSUBSCRIBER END DATE:"<<s.edate<<"\n\nFATHER'S NAME:"<<s.fname<<"\n\nADDRESS:"<<s.address<<"\n\nCITY:" <<s.city<<"\n\nSTATE:"<<s.state<<"\n\nPINCODE:"<<s.pin<<"\n\nDATE OF BIRTH:"<<s.dob<<"\n\nEMAIL:"<<s.email<<"\n\nMOBILE NUMBER:"<<s.mobno<<"\n\nADDRESS PROOF:"<<s.addpr<<"\n\nTYPE OF SERVICE:"<<s.sertype;
	   break;
	 }break;
       case 4:++j;
	switch(s.em)
	 {
	  case 10:
	  case 11:
	  case 12:
	   ++p;
	   cout<<"SUBSCRIPTION NO:"<<s.subno<<"\n\nSUBSCRIBER NAME:"<<s.name<<"\n\n SUBSCRIBER START DATE:"<<s.sdate<<"\n\nSUBSCRIBER END DATE:"<<s.edate<<"\n\nFATHER'S NAME:"<<s.fname<<"\n\nADDRESS:"<<s.address<<"\n\nCITY:" <<s.city<<"\n\nSTATE:"<<s.state<<"\n\nPINCODE:"<<s.pin<<"\n\nDATE OF BIRTH:"<<s.dob<<"\n\nEMAIL:"<<s.email<<"\n\nMOBILE NUMBER:"<<s.mobno<<"\n\nADDRESS PROOF:"<<s.addpr<<"\n\nTYPE OF SERVICE:"<<s.sertype;
	   line();
	   break;
	 }break;
       case 5:s.menu();break;
       default:cout<<"\n\nSorry! Invalid Choice.. Please Try Again..";++n;getch();clrscr();s.delreport();
     }//switch
    }//if
   }//while
  if(p==0&&j!=0&&n==0){cout<<"NO RECORDS WERE ADDED IN THIS QUARTER";getch();}
  if(p==0&&j==0){cout<<"NO RECORDS WERE ADDED IN THIS YEAR";getch();}
  }//if
else
{
cout<<"\n\nSorry! Invalid Choice.. Please Try Again..";getch();clrscr();s.delreport();++p;
}
getch();
s.menu();
 }



void telephone::report1()
{
 clrscr();
 int l1=0,l2=0,l3=0,l4=0,k=0,ch3=0,m=0,h=0,y;
 char y1[5];
 s.ey=s.ed=s.em=0;
 abc();
 char str3[20];
 cout<<"ENTER THE YEAR FOR WHICH THE REPORT HAS TO BE DISPLAYED:";gets(y1);
 for(int i=0;y1[i];++i)
 if(isdigit(y1[i]))
 ++h;
 if(h!=4||strlen(y1)!=4){cout<<"\n\nSorry!! Invalid Year!! Try Again..";getch();s.report1();}
 y=atol(y1);
 clrscr();abc();
 cout<<"\t\t\tNEW SUBSCRIPTIONS ADDED IN THE QUARTER";line();
 cout<<"1.FIRST QUARTER (JAN-MAR)\n\n";
 cout<<"2.SECOND QUARTER (APR-JUN)\n\n";
 cout<<"3.THIRD QUARTER (JUL-SEP)\n\n";
 cout<<"4.FOURTH QUARTER (OCT -DEC)\n\n";
 cout<<"5.EXIT TO MAIN MENU\n\n";
 cout<<"ENTER YOUR CHOICE\n\n";
 gets(str3);
 m=strlen(str3);
 ch3=atol(str3);
 clrscr();
if(m==1&&ch3!=0&&ch3!=6&&ch3!=7&&ch3!=8&&ch3!=9)
{
abc();
 ifstream f;
 f.open("inventor.dat",ios::binary);
 while(f.read((char*)&s,sizeof(telephone)))
  {
   if(s.sy==y)
    {
     switch(ch3)
      {
	case 1:++k;
	switch(s.sm)
	 {
	  case 1:
	  case 2:
	  case 3:
	   ++l1;
	   cout<<"SUBSCRIPTION NO:"<<s.subno<<"\n\nSUBSCRIBER NAME:"<<s.name<<"\n\n SUBSCRIBER START DATE:"<<s.sdate<<"\n\nSUBSCRIBER END DATE:"<<s.edate<<"\n\nFATHER'S NAME:"<<s.fname<<"\n\nADDRESS:"<<s.address<<"\n\nCITY:" <<s.city<<"\n\nSTATE:"<<s.state<<"\n\nPINCODE:"<<s.pin<<"\n\nDATE OF BIRTH:"<<s.dob<<"\n\nEMAIL:"<<s.email<<"\n\nMOBILE NUMBER:"<<s.mobno<<"\n\nADDRESS PROOF:"<<s.addpr<<"\n\nTYPE OF SERVICE:"<<s.sertype;
	   line();
	   getch();
	   clrscr();
	 }
	break;
       case 2:++k;
	switch(s.sm)
	 {
	  case 4:
	  case 5:
	  case 6:
	   ++l2;
	   cout<<"SUBSCRIPTION NO:"<<s.subno<<"\n\nSUBSCRIBER NAME:"<<s.name<<"\n\n SUBSCRIBER START DATE:"<<s.sdate<<"\n\nSUBSCRIBER END DATE:"<<s.edate<<"\n\nFATHER'S NAME:"<<s.fname<<"\n\nADDRESS:"<<s.address<<"\n\nCITY:" <<s.city<<"\n\nSTATE:"<<s.state<<"\n\nPINCODE:"<<s.pin<<"\n\nDATE OF BIRTH:"<<s.dob<<"\n\nEMAIL:"<<s.email<<"\n\nMOBILE NUMBER:"<<s.mobno<<"\n\nADDRESS PROOF:"<<s.addpr<<"\n\nTYPE OF SERVICE:"<<s.sertype;
	   line();
	   getch();
	   clrscr();
	 }
	break;
       case 3:++k;
	switch(s.sm)
	 {
	  case 7:
	  case 8:
	  case 9:
	   ++l3;
	   cout<<"SUBSCRIPTION NO:"<<s.subno<<"\n\nSUBSCRIBER NAME:"<<s.name<<"\n\n SUBSCRIBER START DATE:"<<s.sdate<<"\n\nSUBSCRIBER END DATE:"<<s.edate<<"\n\nFATHER'S NAME:"<<s.fname<<"\n\nADDRESS:"<<s.address<<"\n\nCITY:" <<s.city<<"\n\nSTATE:"<<s.state<<"\n\nPINCODE:"<<s.pin<<"\n\nDATE OF BIRTH:"<<s.dob<<"\n\nEMAIL:"<<s.email<<"\n\nMOBILE NUMBER:"<<s.mobno<<"\n\nADDRESS PROOF:"<<s.addpr<<"\n\nTYPE OF SERVICE:"<<s.sertype;
	   line();
	   getch();
	   clrscr();
	 }
	break;
       case 4:++k;
	switch(s.sm)
	 {
	  case 10:
	  case 11:
	  case 12:
	   ++l4;
	   cout<<"SUBSCRIPTION NO:"<<s.subno<<"\n\nSUBSCRIBER NAME:"<<s.name<<"\n\n SUBSCRIBER START DATE:"<<s.sdate<<"\n\nSUBSCRIBER END DATE:"<<s.edate<<"\n\nFATHER'S NAME:"<<s.fname<<"\n\nADDRESS:"<<s.address<<"\n\nCITY:" <<s.city<<"\n\nSTATE:"<<s.state<<"\n\nPINCODE:"<<s.pin<<"\n\nDATE OF BIRTH:"<<s.dob<<"\n\nEMAIL:"<<s.email<<"\n\nMOBILE NUMBER:"<<s.mobno<<"\n\nADDRESS PROOF:"<<s.addpr<<"\n\nTYPE OF SERVICE:"<<s.sertype;
	   line();
	   getch();
	   clrscr();
	 }
	break;
       case 5:s.menu();break;
       default:cout<<"\n\nSorry! Invalid Choice.. Please Try Again..";++k;getch();clrscr();s.report1();
      }//switch
     }//if
    }//while
 f.close();
}//if
else
{cout<<"\n\nSorry! Invalid Choice.. Please Try Again..";++k;getch();clrscr();s.report1();}
   if(k!=0&&l1==0&&l2==0&&l3==0&&l4==0)
    {cout<<"\n\nNO RECORDS WERE ADDED IN THIS QUARTER";k=0;}
      if(k==0&&l1==0&&l2==0&&l3==0&&l4==0)
    {cout<<"\n\nNO RECORDS WERE ADDED IN THIS YEAR";k=0;}
    if(ch3==1&&k!=0)
     cout<<"\n\nNO OF RECORDS ADDED IN THE FIRST QUARTER IS "<<l1;
    if(ch3==2&&k!=0)
     cout<<"\n\nNO OF RECORDS ADDED IN THE SECOND QUARTER IS "<<l2;
    if(ch3==3&&k!=0)
     cout<<"\n\nNO OF RECORDS ADDED IN THE THIRD QUARTER IS "<<l3;
    if(ch3==4&&k!=0)
     cout<<"\n\nNO OF RECORDS ADDED IN THE FOURTH QUARTER IS "<<l4;
    getch();
    s.menu();
   }

int telephone::billpay1(char subno[15],char name[25],char address[60],char dob[11])
{
 ifstream f;
 f.open("inventor.dat",ios::binary|ios::app);
 int flag=0,k,g;
 k=g=-1;
 while(f.read((char*)&s,sizeof(telephone)))
  {
   if(strcmp(s.subno,subno)==0)
    g=0;
  }
 f.close();
 f.open("inventor.dat",ios::binary|ios::app);
 while(f.read((char*)&s,sizeof(telephone)))
  {
   if((strcmp(s.subno,subno)==0)&&(strcmpi(name,s.name)!=0))
    k=1;
  }
 f.close();
 f.seekg(0);
 f.open("inventor.dat",ios::binary|ios::app);
 while(f.read((char*)&s,sizeof(telephone)))
  {
   if((strcmpi(s.subno,subno)==0)&&(strcmpi(name,s.name)==0))
    {++flag;
     clrscr();
     abc();
     cout<<"\n\t\t\tDETAILS\n\n";line();
     cout<<"\n\nSUBSCRIPTION NUMBER:\t"<<s.subno;
     cout<<"\n\nSUBSCRIBER NAME:\t"<<s.name;
     cout<<"\n\nSUBSCRIBER START DATE:\t"<<s.sdate;
     cout<<"\n\nSUBSCRIBER END DATE:\t"<<s.edate;
     cout<<"\n\nFATHER NAME:\t\t"<<s.fname;
     cout<<"\n\nADDRESS:\t\t"<<s.address;
     strcpy(address,s.address);
     cout<<"\n\nCITY:\t\t\t"<<s.city;
     cout<<"\n\nSTATE:\t\t\t"<<s.state;
     cout<<"\n\nPINCODE:\t\t"<<s.pin;
     cout<<"\n\nDATE OF BIRTH:\t\t"<<s.dob;
     strcpy(dob,s.dob);
     cout<<"\n\nE-MAIL:\t\t\t"<<s.email;
     cout<<"\n\nMOBILE NUMBER:\t\t"<<s.mobno;
     cout<<"\n\nADDRESS-PROOF:\t\t"<<s.addpr;
     cout<<"\n\nSERVICE TYPE:\t\t"<<s.sertype;
    }
   if(flag!=0)
    break;
  }
 if(g==-1)
  cout<<"\n\nSorry! No subscriber exists with this Subscriber No.. Try Again..";
 else
  if(k==1)
   cout<<"\n\nSorry! This Name Does Not Match To the Given Subscriber No..Try Again..";
  strcpy(subno,s.subno);
  f.close();
  if(k==-1&&g==0)
   return 2;
 else
  return 0;
}

void telephone::displayall()
{
ifstream f;
f.open("inventor.dat",ios::binary);
while(f.read((char*)&s,sizeof(telephone)))
{
   cout<<"\n\nSUBSCRIPTION NUMBER:\t"<<s.subno;
   cout<<"\n\nSUBSCRIBER NAME:\t"<<s.name;
   cout<<"\n\nSUBSCRIBER START DATE:\t"<<s.sdate;
   cout<<"\n\nSUBSCRIBER END DATE:\t"<<s.edate;
   cout<<"\n\nFATHER NAME:\t\t"<<s.fname;
   cout<<"\n\nADDRESS:\t\t"<<s.address;
   cout<<"\n\nCITY:\t\t\t"<<s.city;
   cout<<"\n\nSTATE:\t\t\t"<<s.state;
   cout<<"\n\nPINCODE:\t\t"<<s.pin;
   cout<<"\n\nDATE OF BIRTH:\t\t"<<s.dob;
   cout<<"\n\nE-MAIL:\t\t\t"<<s.email;
   cout<<"\n\nMOBILE NUMBER:\t\t"<<s.mobno;
   cout<<"\n\nADDRESS-PROOF:\t\t"<<s.addpr;
   cout<<"\n\nSERVICE TYPE:\t\t"<<s.sertype;
   line();
  }
f.close();
getch();
s.menu();
}

void settings()
{
clrscr();
int h,i;
char ch;
char col[2],col1[2];
abc();
cout<<"\t\t\tMENU"<<"\n\n1.TEXT COLOUR\n\n2.BACKGROUND COLOUR\n\n3.BLINK\n\n4.Exit To Main Menu\n\n\nEnter Your Choice\t";
ch=getch();clrscr();abc();
switch(ch)
{
case '1':
cout<<"\n\n1.BLACK\n\n2.BLUE\n\n3.GREEN\n\n4.CYAN\n\n5.RED\n\n6.MAGENTA\n\n7.BROWN\n\n8.LIGHT GRAY\n\n9.DARK GRAY\n\n10.LIGHT BLUE\n\n11.LIGHT GREEN\n\n12.LIGHT CYAN\n\n13.LIGHT RED\n\n14.LIGHT MAGENTA\n\n15.YELLOW\n\n16.WHITE\n\n17.EXIT TO MAIN MENU\n";
cout<<"\nEnter Your Choice\t";gets(col);if(strcmp(col,0)!=0){h=atol(col);
if((h>16)||h<=0)
{
if(h!=17)
{cout<<"\n\nSorry!!INVALID CHOICE..Try Again..";getch();s.menu();}
}
textcolor(h-1);
}
if(h==17)s.menu();
break;
case '2':
cout<<"\n\n1.BLACK\n\n2.BLUE\n\n3.GREEN\n\n4.CYAN\n\n5.RED\n\n6.MAGENTA\n\n7.BROWN\n\n8.LIGHT GRAY\n\n9.DARK GRAY\n\n10.LIGHT BLUE\n\n11.LIGHT GREEN\n\n12.LIGHT CYAN\n\n13.LIGHT RED\n\n14.LIGHT MAGENTA\n\n15.YELLOW\n\n16.WHITE\n\n";
cout<<"\nEnter Your Choice\t";gets(col1);if(strcmp(col1,0)!=0){i=atol(col1);textbackground(i-1);}
break;
case '3':textcolor(WHITE+128);s.menu();break;
case '4':s.menu();break;
default:cout<<"Sorry!! Wrong Choice!! Try Again..";getch();settings();
}
s.menu();
}

 void aboutus()
 {
 clrscr();cout<<"\t\t\tABOUT US";line();
 cout<<"\n\nSOFTWARE OWNER: MODERN TELEPHONES\n\n"<<"SOFTWARE CREATION :I-GATE\n\n"<<"\t\t\tMEMBERS:\n\n"<<"1. T.V.VIGNESH"<<"\n\n2.SUNDARAKRISHNAN"<<"\n\n3.SOWMYA"<<"\n\n4.SHIVANI"<<"\n\n5. V.GAYATHRI";
 cout<<"\n\nDate Of Creation:27th APRIL,2009";
 line();
 cout<<"\n\nPress Any Key To Go To Main Menu..";
 getch();
 s.menu();
 }

 void bill::billdate(char a[15],char b[11])
 {
 int v=0,flag,u,q,k;
 v=s.billdate1(a,b);
 while(v==2)
 {
     v=flag=u=k=0;
     cout<<"\n\nBILL PAYMENT DATE*:\t";gets(bp.bpd);
     while(strcmp(bp.bpd,NULL)==0)
      {
       cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
       cout<<"BILL PAYMENT DATE*:\t";gets(bp.bpd);
      }
     for(int i=0;bp.bpd[i];++i)
     if(bp.bpd[i]=='/')
      ++k;
     sscanf(bp.bpd,"%d/%d/%d",&bp.bd,&bp.bm,&bp.by);
     q=bp.by;
     while(q)
      {
       q/=10;
       ++u;
      }
     if(bp.bm<1||bp.bm>12||bp.bd<1||u!=4)
      flag=1;
     switch(bp.bm)
      {
       case 1:
       case 3:
       case 5:
       case 7:
       case 8:
       case 10:
       case 12:
	if(bp.bd>31)flag=1;break;
       case 2:
	if(bp.by%4==0&&bp.bd>29)flag=1;
	 else
	if(bp.by%4!=0&&bp.bd>28)flag=1;
	 break;
       case 4:
       case 6:
       case 9:
       case 11:
	if(bp.bd>30)flag=1;break;
      }
   //MAIN
  while(flag==1||k!=2)
   {//*
    u=flag=k=0;
    cout<<"\n\nSorry!Invalid Date!Date should be of the form \"dd/mm/yyyy\" Please Try Again..";getch();
    cout<<"\n\nBILL PAYMENT DATE*:\t";gets(bp.bpd);
    while(strcmp(bp.bpd,NULL)==0)
     {
      cout<<"\n\nThis is a mandatory field!Please Enter Again..\n\n";
      cout<<"BILL PAYMENT DATE*:\t";gets(bp.bpd);
     }
    for(i=0;bp.bpd[i];++i)
    if(bp.bpd[i]=='/')
     ++k;
    sscanf(bp.bpd,"%d/%d/%d",&bp.bd,&bp.bm,&bp.by);
    q=bp.by;
    while(q)
     {
      q/=10;
      ++u;
     }
    if(bp.bm<1||bp.bm>12||bp.bd<1||u!=4)
     flag=1;
    switch(bp.bm)
     {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
       if(bp.bd>31)flag=1;break;
      case 2:
       if(bp.by%4==0&&bp.bd>29)flag=1;
	else
       if(bp.by%4!=0&&bp.bd>28)flag=1;
	break;
       case 4:
       case 6:
       case 9:
       case 11:
	if(bp.bd>30)flag=1;break;
     }
   }//*
 v=s.billdate1(a,bp.bpd);
 }
 }

 int telephone::billdate1(char a[15],char b[11])
 {
 int dd,mm,yyyy,f2=3;
 sscanf(b,"%d/%d/%d",&dd,&mm,&yyyy);
 ifstream f;
 f.open("inventor.dat",ios::binary);
 while(f.read((char*)&s,sizeof(telephone)))
 {
 if(strcmpi(a,s.subno)==0)
 {
if(s.sy>yyyy)f2=2;
if(s.sy==yyyy&&s.sm>mm)f2=2;
if(s.sy==yyyy&&s.sm==mm&&s.sd>dd)f2=2;
 break;
 }//if
 }//while
 if(f2==2)
 {
 cout<<"\n\nSorry!!Bill Payment Date Cannot be less than Start Date..Try Again..";getch();
 }
 f.close();
 return f2; //2-error, 3-noerr
 }//function