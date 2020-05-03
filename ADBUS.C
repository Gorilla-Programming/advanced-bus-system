#include<stdio.h>
#include<conio.h>
#include<string.h>
#define BACKSPACE 8
#include<stdlib.h>
#include<time.h>
#include<dos.h>

void frame();
void intro();
int menu();
void install();
void list();
void book();
void download();
int login();
int adminlogin();


int adminlogin()
{
 int chk4=0;
 char name[12]="STORM",pass[12]="WALKER",check_pass[12],check_name[12];
 frame();
 gotoxy(26,11);
 cprintf("Enter ADMIN ID :: ");
 fflush(stdin);
 gets(check_name);
 gotoxy(26,13);
 cprintf("Enter Password :: ");
 fflush(stdin);
 gets(check_pass);
 if(strcmp(name,check_name)==0 && strcmp(pass,check_pass)==0)
 {
  frame();
  gotoxy(23,12);
  cprintf("Login Successful...Click to Continue ");
  chk4=1;
 }
 else
 {
  frame();
  gotoxy(18,12);
  cprintf("Invalid ID....Sorry Admin Permission Required...");
 }
 return(chk4);
}






void frame()
{
 int i;
 clrscr();
 textcolor(GREEN);
 textbackground(BLACK);
 for(i=3;i<=24;i++)
 {
  gotoxy(77,i);
  cprintf("*");
  gotoxy(2,i);
  cprintf("*");
 }
 for(i=4;i<=76;i+=2)
 {
  gotoxy(i,24);
  cprintf("* ");
  gotoxy(i,2);
  cprintf("* ");
 }
}




void intro()
{
 char s[100]="Hi! WELCOME TO GO-PRO TRAVELS PVT LTD";
 char s1[100]="PROGRAM CREDIT - GORILLA PROGRAMMING || Mr - StOrM";
 char s2[100]="Enjoy Your Journey !! CLick to continue";
 int i=0;
 frame();
 gotoxy(22,12);
 while(s[i]!='\0')
 {
  sound(200);
  cprintf("%c",s[i]);
  delay(5);
  nosound();
  delay(100);
  i++;
 }
 delay(1000);
 i=0;
 frame();
 gotoxy(14,12);
 while(s1[i]!='\0')
 {
  sound(200);
  cprintf("%c",s1[i]);
  delay(5);
  nosound();
  delay(100);
  i++;
 }
 delay(1000);
 i=0;
 frame();
 gotoxy(21,12);
 while(s2[i]!='\0')
 {
  sound(200);
  cprintf("%c",s2[i]);
  delay(5);
  nosound();
  delay(100);
  i++;
 }
 getch();
 for(i=3;i>=0;i--)
 {
  frame();
  gotoxy(28,12);
  cprintf("Loading...Please Wait");
  delay(500);
  gotoxy(28,12);
  cprintf("Loading...Please Wait.");
  delay(500);
  gotoxy(28,12);
  cprintf("Loading...Please Wait..");
  delay(500);
  gotoxy(28,12);
  cprintf("Loading...Please Wait..._");
  delay(500);
 }
}
int menu()
{
 int menu_op;
 frame();
 gotoxy(21,8);
 cprintf("|...............MENU...............|");
 gotoxy(25,10);
 cprintf("1. Install Bus (Only For Admin)");
 gotoxy(25,11);
 cprintf("2. List of Available Buses");
 gotoxy(25,12);
 cprintf("3. Book Ticket");
 gotoxy(25,13);
 cprintf("4. Booked Ticket");
 gotoxy(25,14);
 cprintf("5. Exit");
 gotoxy(25,16);
 cprintf("Enter Your Choice_______");
 gotoxy(45,16);
 scanf("%d",&menu_op);
 return(menu_op);

}
int login()
{
 FILE *f1,*f2;
 int ch,chk=0,chk2=0,chk3=0;
 char name[12],pass[12],check_pass[12],check_name[12];
 registered:
 frame();
 gotoxy(26,11);
 cprintf("1. Sign Up");
 gotoxy(26,13);
 cprintf("2. Log In : :");
 gotoxy(37,13);
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:
	A :
	frame();
	f1=fopen("busuname.txt","a+");
	f2=fopen("buspass.txt","a+");
	rewind(f1);
	gotoxy(26,11);
	cprintf("Enter Username :: ");
	fflush(stdin);
	gets(check_name);
	while(fscanf(f1,"%s",&name)!=EOF)
	{
	 if(strcmp(name,check_name)==0)
	 {
	  frame();
	  gotoxy(26,11);
	  cprintf("Username already exist");
	  getch();
	  fclose(f1);
	  goto A;
	 }
	}
	gotoxy(26,13);
	cprintf("Enter Password :: ");
	gets(pass);
	strcpy(name,check_name);
	fprintf(f1,"%s \n",&name);
	fprintf(f2,"%s \n",&pass);
	frame();
	gotoxy(26,12);
	cprintf("Registration Successful....");
	getch();
	rewind(f1);
	rewind(f2);
	goto registered;
   case 2:
	B:
	frame();
	f1=fopen("busuname.txt","a+");
	f2=fopen("buspass.txt","a+");
	rewind(f1);
	rewind(f2);
	gotoxy(26,11);
	cprintf("Enter Username :: ");
	fflush(stdin);
	gets(check_name);
	gotoxy(26,13);
	cprintf("Enter Password :: ");
	fflush(stdin);
	gets(check_pass);
	while(fscanf(f1,"%s",&name)!=EOF)
	{
	 fscanf(f2,"%s",&pass);
	 if(strcmp(name,check_name)==0 && strcmp(pass,check_pass)==0)
	 {
	  chk=1;
	  break;
	 }
	 else
	 continue;
	}
	if(chk==1)
	{
	 frame();
	 gotoxy(23,12);
	 cprintf("Login Successful...Click to Continue ");
	 chk3=1;
	 fclose(f1);
	 fclose(f2);
	 getch();
	}
	else if(chk==0)
	{
	 frame();
	 gotoxy(24,12);
	 cprintf("Invalid Password or username");
	 fclose(f1);
	 fclose(f2);
	 getch();
	 chk2++;
	 if(chk2<2)
	 goto B;
	}
	else
	{
	 frame();
	 gotoxy(21,12);
	 cprintf("OOPS SOMETHING WENT WRONG...TRY AGAIN LATER");
	}
	break;
 }
 return(chk3);
}
struct bus
{
  int busnum,price_per_km,dep_time,arr_time;
  char driver_name[12],source[3],destination[3];
}s1[4];


void install()
{
  char back_space;
  int bus_exist,chk5=0;
  FILE *bus;
  bus=fopen("install.txt","a+");
  chk5=adminlogin();
  if(chk5==1)
  {
   ADD_BUS:
   rewind(bus);
   bus_exist=0;
   frame();
   gotoxy(10,6);
   cprintf("Enter BUS NUMBER :: ");
   fflush(stdin);
   scanf("%d",&s1[1].busnum);
   while(!feof(bus))
   {
    fscanf(bus,"%d %s %d %s %d %s %d",&s1[2].busnum,&s1[2].driver_name,&s1[2].price_per_km,&s1[2].source,&s1[2].dep_time,&s1[2].destination,&s1[2].arr_time);
    if(s1[1].busnum==s1[2].busnum)
    {
     bus_exist=1;
     break;
    }
    else
    continue;
   }
   if(bus_exist==0)
   {
    fseek(bus,0,SEEK_END);
    fprintf(bus,"%d ",s1[1].busnum);
    gotoxy(10,7);
    cprintf("Enter DRIVER NAME :: ");
    fflush(stdin);
    gets(s1[1].driver_name);
    fprintf(bus,"%s ",s1[1].driver_name);
    gotoxy(10,8);
    cprintf("Enter PRICE PER KM :: ");
    fflush(stdin);
    scanf("%d",&s1[1].price_per_km);
    fprintf(bus,"%d ",s1[1].price_per_km);
    gotoxy(10,9);
    cprintf("Enter SOURCE :: ");
    fflush(stdin);
    gets(s1[1].source);
    fprintf(bus,"%s ",s1[1].source);
    gotoxy(10,10);
    cprintf("Enter DEPARTURE TIME (IN 24 hr):: ");
    fflush(stdin);
    scanf("%d",&s1[1].dep_time);
    fprintf(bus,"%d ",s1[1].dep_time);
    gotoxy(10,11);
    cprintf("Enter DESTINATION :: ");
    fflush(stdin);
    gets(s1[1].destination);
    fprintf(bus,"%s ",s1[1].destination);
    gotoxy(10,12);
    cprintf("Enter ARRIVAL TIME (IN 24 hr) :: ");
    fflush(stdin);
    scanf("%d",&s1[1].arr_time);
    fprintf(bus,"%d\n",s1[1].arr_time);
    frame();
    gotoxy(19,12);
    cprintf("PRESS BACKSPACE IF YOU WANT TO ADD MORE BUS");
    back_space=getch();
    if(back_space==BACKSPACE)
    goto ADD_BUS;
    fclose(bus);
   }
   else
   {
    gotoxy(24,12);
    cprintf("BUS ALREADY EXIST TRY AGAIN");
    getch();
    goto ADD_BUS;
   }
  }
}

void list()
{
 int j=7;
 FILE *list;
 frame();
 list=fopen("install.txt","r");
  gotoxy(5,6);
  cprintf("BUS NUM");
  gotoxy(15,6);
  cprintf("DRIVER");
  gotoxy(31,6);           //29
  cprintf("FROM");
  gotoxy(41,6);
  cprintf("DEP.TIME");
  gotoxy(51,6);           //52
  cprintf(" TO ");
  gotoxy(57,6);
  cprintf("ARR.TIME");
  gotoxy(70,6);
  cprintf("PPK");
 while(fscanf(list,"%d",&s1[0].busnum)!=EOF)
 {
   j=j+1;
   gotoxy(5,j);
   cprintf("%d",s1[0].busnum);
   fscanf(list,"%s",&s1[0].driver_name);
   gotoxy(15,j);
   cprintf("%s",s1[0].driver_name);
   fscanf(list,"%d",&s1[0].price_per_km);
   fscanf(list,"%s",&s1[0].source);
   gotoxy(31,j);
   cprintf("%s",s1[0].source);
   fscanf(list,"%d",&s1[0].dep_time);
   gotoxy(42,j);
   cprintf("%d:00",s1[0].dep_time);
   fscanf(list,"%s",&s1[0].destination);
   gotoxy(52,j);
   cprintf("%s",s1[0].destination);
   fscanf(list,"%d",&s1[0].arr_time);
   gotoxy(58,j);
   cprintf("%d:00",s1[0].arr_time);
   gotoxy(70,j);
   cprintf("%d.0",s1[0].price_per_km);
}
 getch();
}



void book()
{
  int bus_exist,pnr=0,randnum;
  char justforpnr[BUFSIZ],pass_age[2],passenger[20],pass_mob[10],pass_source[3],pass_dest[3];
  FILE *bus,*pass;
  pass=fopen("pass.txt","a+");
  bus=fopen("install.txt","a+");
  bus_exist=0;
  frame();
  gotoxy(10,6);
  cprintf("Enter BUS NUMBER :: ");
  fflush(stdin);
  scanf("%d",&s1[1].busnum);
  while(!feof(bus))
  {
   fscanf(bus,"%d %s %d %s %d %s %d",&s1[2].busnum,&s1[2].driver_name,&s1[2].price_per_km,&s1[2].source,&s1[2].dep_time,&s1[2].destination,&s1[2].arr_time);
   if(s1[1].busnum==s1[2].busnum)
   {
    bus_exist=1;
    break;
   }
   else
   continue;
  }
  if(bus_exist==1)
  {
   while(!feof(pass))
   {
    fgets(justforpnr,BUFSIZ,pass);
    pnr++;
   }
   rewind(pass);
   gotoxy(10,7);
   cprintf("Enter Passenger Name :: ");
   fflush(stdin);
   gets(passenger);
   gotoxy(10,8);
   cprintf("Age :: ");
   fflush(stdin);
   gets(pass_age);
   gotoxy(10,9);
   cprintf("Source :: ");
   fflush(stdin);
   gets(pass_source);
   gotoxy(10,10);
   cprintf("Destination :: ");
   fflush(stdin);
   gets(pass_dest);
   gotoxy(10,11);
   cprintf("Mobile Num. :: ");
   fflush(stdin);
   gets(pass_mob);
   fprintf(pass,"%d %s %d %s %s %s\n",pnr,passenger,s1[2].busnum,pass_source,pass_dest,pass_mob);
   frame();
   gotoxy(26,11);
   srand(time(0));
   randnum=rand()%50;
   cprintf("TOTAL AMOUNT TO BE PAID :: %d RS",s1[2].price_per_km*randnum);
   gotoxy(26,13);
   cprintf("CLICK TO PAY");
   getch();
   frame();
   gotoxy(26,11);
   cprintf("AMOUNT PAID :: BOOKING SUCCESSFUL");
   gotoxy(26,13);
   cprintf("YOUR PNR :: %d ",pnr);
   fclose(pass);
   fclose(bus);
  }
  getch();
}












void main()
{
 int menu_op,checklogin;
 frame();
 intro();
 TRY_AGAIN:
 menu_op=menu();
 switch(menu_op)
 {
  case 1 :
	install();
	break;
  case 2 :
	list();
	break;
  case 3 :
	checklogin=login();
	if(checklogin==1)
	{
	 book();
	 break;
	}
  case 4 :
	checklogin=login();
	if(checklogin==1)
	{
	 download();
	 break;
	}
  case 5:
	exit(0);
  default :
	frame();
	gotoxy(26,12);
	cprintf("INVALID CHOICE !! TRY AGAIN");
	getch();
	goto TRY_AGAIN;
 }




 getch();
}





void download()
{
 int pnr,pnr_ent,pnr_checked;
 char pass_age[2],passenger[20],pass_mob[10],pass_source[3],pass_dest[3];
 FILE *bus,*pass;
 pass=fopen("pass.txt","r");
 bus=fopen("install.txt","r");
 frame();
 gotoxy(10,6);
 cprintf("Enter PNR NUMBER :: ");
 fflush(stdin);
 scanf("%d",&pnr_ent);
 while((fscanf(pass,"%d %s %d %s %s %s ",&pnr,&passenger,&s1[4].busnum,&pass_source,&pass_dest,&pass_mob))!=NULL)
 {
  if(pnr==pnr_ent)
  {
   pnr_checked=1;
   break;
  }
  else
  continue;
 }
 if(pnr_checked==1)
 {
  while((fscanf(bus,"%d %s %d %s %d %s %d ",&s1[2].busnum,&s1[2].driver_name,&s1[2].price_per_km,&s1[2].source,&s1[2].dep_time,&s1[2].destination,&s1[2].arr_time))!=NULL)
  {
   if(s1[4].busnum==s1[2].busnum)
   {
    break;
   }
  }
   frame();
   gotoxy(31,7);
   cprintf("TICKET DETAIL");
   gotoxy(26,9);
   cprintf("PASSENGER NAME :: %s ",passenger);
   gotoxy(26,10);
   cprintf("BUS NUMBER :: %d ",s1[2].busnum);
   gotoxy(26,11);
   cprintf("DRIVER NAME :: %s ",s1[2].driver_name);
   gotoxy(26,12);
   cprintf("SOURCE :: %s ",pass_source);
   gotoxy(26,13);
   cprintf("DESTINATION :: %s ",pass_dest);
   gotoxy(26,14);
   cprintf("AMOUNT PAID :: %d ",s1[2].price_per_km);
   gotoxy(26,15);
   cprintf("REG. MOBILE :: %s ",pass_mob);
   gotoxy(26,16);
   cprintf("DEPARTURE TIME :: %d ",s1[2].dep_time);
   gotoxy(26,17);
   cprintf("ARRIVAL TIME :: %d ",s1[2].arr_time);
   gotoxy(5,22);
   cprintf("NOTE :: REACH TO EXPECTED BUS STOP BEFORE 30 MIN... OF DEPARTURE TIME");
  }
  else
  {
   frame();
   gotoxy(26,12);
   cprintf("SORRY ENTERED PNR IS INVALID");
   getch();
  }
}