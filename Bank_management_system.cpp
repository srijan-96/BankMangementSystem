#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#include<windows.h>
#include<fstream>
using namespace std;

char * hidePass(char *,int,int);

void gotoxy(short x, short y) {
	
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int basic_display()                                                                     // Function for Home Page
{

    gotoxy(24,1);
    cout<<"*** GOTHAM NATIONAL BANK ***";
    gotoxy(17,2);
    cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
    gotoxy(26,8);
    cout<<"Please Select you Log-in option:\n";
    gotoxy(26,10);
    cout<<"1. System Admin";
    gotoxy(26,12);
    cout<<"2. Manager";
    gotoxy(26,14);
    cout<<"3. Customer";
    gotoxy(26,16);
    cout<<"4. Fresh Application";
    gotoxy(26,18);
    cout<<"5. Check Application Status";
    gotoxy(26,20);
    cout<<"6. About us";
    gotoxy(26,22);
    cout<<"7. Exit";
    int ch;
    gotoxy(26,25);
    cout<<"Enter your choice:";
    cin>>ch;
    cin.ignore();
    return ch;
}


class closeAccount;
class transfer;
class manager;
class customer;

class DepositOrWithdrawl                                                                //Deposit and Withdrawl class
{

    unsigned long long acno;
    char type[10];
    int balance;
    int amount;
    int dd,mm,yy,hh,mi,ss;


public:

    void setAcno(unsigned long long acno) {
        this->acno=acno;
    }

    void setType(char *type) {
        strcpy(this->type,type);
    }

    void setBalance(int balance) {
        this->balance=balance;
    }

    void setAmount(int amount) {
        this->amount=amount;
    }

    void setDate(int dd,int mm,int yy) {
        this->dd=dd;
        this->mm=mm;
        this->yy=yy;
    }

    void setTime(int hh,int mi,int ss) {
        this->hh=hh;
        this->mi=mi;
        this->ss=ss;
    }

    unsigned long long getAcno() {
        return acno;
    }

    char * getType() {
        return type;
    }

    int getBalance() {
        return balance;
    }

    int getAmount() {
        return amount;
    }

    int getDate() {
        return dd;
    }

    int getMonth() {
        return mm;
    }

    int getYear() {
        return yy;
    }


    int getHour() {
        return hh;
    }

    int getMinute() {
        return mi;
    }

    int getSecond() {
        return ss;
    }


};



class SystemAdmin {   																		// System Admin class
    ofstream out;
    ifstream inp;
    char name[20];
    char pw[20];

public:

    int menu() {

        system("cls");
        gotoxy(20,4);
        cout<<"Activities available:";
        gotoxy(20,7);

        cout<<"1. Assign Manager";
        gotoxy(20,9);
        cout<<"2. Remove Manager";

        gotoxy(20,11);
        cout<<"3. Pending Applications";
        gotoxy(20,13);
        cout<<"4. Verified Applications";
        gotoxy(20,15);
        cout<<"5. Change Password";


        gotoxy(20,17);
        cout<<"6. View Manager Details";



        gotoxy(20,19);
        cout<<"7. Back";

        gotoxy(20,21);
        cout<<"8. Home";

        gotoxy(20,23);
        cout<<"9. Exit";

        gotoxy(20,26);
        int ch;
        cout<<"Enter your choice:";
        cin>>ch;

        return ch;

    }


    void setCountini()
    {
        out.open("Counter.txt",ios::trunc);
        out<<"0";
        out.close();
    }


    void setCount(int c)
    {
        int p;
        inp.open("Counter.txt",ios::in);
        inp>>p;
        inp.close();
        out.open("Counter.txt",ios::trunc);
        out<<p+c;
        out.close();

    }



    void setname(char* name)
    {
        strcpy(this->name,name);
    }


    void set_pw(char* pw)
    {
        strcpy(this->pw,pw);
    }


    bool login() {

        system("cls");
        int i,j,c=0;
        char usr[20],p[20],ch;
        gotoxy(24,1);
        cout<<"*** GOTHAM NATIONAL BANK ***";
        gotoxy(17,2);
        cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
        gotoxy(20,8);
        cout<<"*** Welcome to System Admin log-in Portal ***\n";
        gotoxy(25,12);
        cout<<"Username : ";
        // cin.ignore();
        gets(usr);
        gotoxy(10,17);
        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
        gotoxy(25,14);
        cout<<"Password : ";
        int outer =1,inner =1;

        while(outer)
        {

            ch=getche();
            cout<<"\b";

            if(ch==13) {
                outer = 0;
                break;
            }
            else if(ch==8)
            {
                system("cls");
                c--;
                gotoxy(24,1);
                cout<<"*** GOTHAM NATIONAL BANK ***";
                gotoxy(17,2);
                cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
                gotoxy(20,8);
                cout<<"*** Welcome to System Admin log-in Portal ***\n";
                gotoxy(25,12);
                cout<<"Username : ";
                puts(usr);
                gotoxy(10,17);
                cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                gotoxy(25,14);
                cout<<"Password : ";

                for(j=0; j<c; j++ ) {
                    cout<<"*";
                }
            }

            else if(ch==32) {


                int inner = 1;
                char ch1;
                system("cls");
                gotoxy(24,1);
                cout<<"*** GOTHAM NATIONAL BANK ***";
                gotoxy(17,2);
                cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
                gotoxy(20,8);
                cout<<"*** Welcome to System Admin log-in Portal ***\n";
                gotoxy(25,12);
                cout<<"Username : ";
                puts(usr);
                gotoxy(10,17);
                cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                gotoxy(25,14);
                cout<<"Password : ";
                for(int k =0; k<c; k++) {
                    cout<<p[k];
                }

                while(inner)
                {

                    ch1 = getche();

                    if(ch1==13) {
                        outer = 0;
                        inner = 0;
                        break;
                    }
                    else if(ch1==8)
                    {
                        system("cls");
                        c--;
                        gotoxy(24,1);
                        cout<<"*** GOTHAM NATIONAL BANK ***";
                        gotoxy(17,2);
                        cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
                        gotoxy(20,8);
                        cout<<"*** Welcome to System Admin log-in Portal ***\n";
                        gotoxy(25,12);
                        cout<<"Username : ";
                        puts(usr);
                        gotoxy(10,17);
                        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                        gotoxy(25,14);
                        cout<<"Password : ";
                        for(int k=0; k<c; k++ ) {
                            cout<<p[k];
                        }
                    }
                    else if(ch1 == 32)
                    {

                        system("cls");
                        gotoxy(24,1);
                        cout<<"*** GOTHAM NATIONAL BANK ***";
                        gotoxy(17,2);
                        cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
                        gotoxy(20,8);
                        cout<<"*** Welcome to System Admin log-in Portal ***\n";
                        gotoxy(25,12);
                        cout<<"Username : ";
                        puts(usr);
                        gotoxy(10,17);
                        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                        gotoxy(25,14);
                        cout<<"Password : ";

                        for(j=0; j<c; j++ ) {
                            cout<<"*";
                        }

                        inner= 0;

                    }
                    else
                    {
                        p[c]=ch1;
                        c++;
                    }


                }


            }

            else
            {
                p[c]=ch;
                c++;
                cout<<"*";
            }
        }


        p[c]='\0';

        gotoxy(25,16);
        if(strcmp(usr,name )==0 && strcmp(p,pw)==0)
        {
            gotoxy(20,21);
            cout<<"Log in Succesful! Loading.....";
            delay(1500);
            return true;
        }

        else
            return false;

    }


    bool is_pw(char *p)
    {
        return (strcmp(p,pw)?false:true);
    }



    bool is_namw(char* i)
    {
        return (strcmp(i,name)?false:true);
    }


    void change_pw(char *pw)
    {
        strcpy(this->pw,pw);
    }


    char * getusername()
    {
        return name;
    }

    char * getpass()
    {
        return pw;
    }

    void viewManagerDetails();
    void verifiedList(customer ob2);
    int verification(customer ob1);
    friend ostream & operator << (ostream &os,customer &b);
    friend istream & operator >> (istream &is,customer &b);

};



class manager {																					// Manager Class

    int update;
    int FLAG;
    char name[20];
    char usr[20];
    char pass[20];
    char id[20];
    int age;
    char addr[20];
    unsigned long long phone;
    char gender;
    char dob[15];

public:



    manager()
    {
        FLAG=0;
        update=0;
    }


    void setPhone(unsigned long long phone) {
        this->phone = phone;
    }

    void setGender(char gender) {
        this->gender = gender;
    }

    void setDob(char * dob) {
        strcpy(this->dob,dob);
    }



    void setName(char *name)
    {
        strcpy(this->name,name);
    }

    void setUsr(char *usr)
    {
        strcpy(this->usr,usr);
    }

    void setPass(char *pass)
    {
        strcpy(this->pass,pass);
    }

    void setId(char *id)
    {
        strcpy(this->id,id);
    }

    void setAge(int age) {
        this->age=age;
    }

    void setAddr(char  *addr)
    {
        strcpy(this->addr,addr);
    }
    char * getName()
    {
        return name;
    }
    char * getUsr()
    {
        return usr;
    }

    char * getPass()
    {
        return pass;
    }


    unsigned long long getPhone() {
        return phone;
    }

    char * getDob() {
        return dob;
    }

    char getGender()
    {
        return gender;
    }


    int getAge() {
        return age;
    }

    char * getAddr() {
        return addr;
    }
    int getUpdate()
    {
        return update;
    }


    char * getId() {
        return id;
    }
    int getFLAG() {

        return FLAG;
    }

    int menu() {
        system("cls");
        gotoxy(20,4);
        cout<<"Activities available:";
        gotoxy(20,7);
        cout<<"1. View personal Details";
        gotoxy(20,9);
        cout<<"2. Pending Approval Requests";
        gotoxy(20,11);
        cout<<"3. Pending Money Transfer Applications";
        gotoxy(20,13);
        cout<<"4. Pending Account Closing Applications";
        gotoxy(20,15);
        cout<<"5. Verified  Approved Applications";

        gotoxy(20,17);
        cout<<"6. Customer Details";
        gotoxy(20,19);
        cout<<"7. View particular Customer Details";


        gotoxy(20,21);
        cout<<"8. Change Password";

        gotoxy(20,23);
        cout<<"9. Home";

        gotoxy(20,25);
        cout<<"10. Exit";

        gotoxy(20,29);
        int ch;
        cout<<"Enter your choice:";
        cin>>ch;

        return ch;

    }

    void viewDetails() {

        manager m;
        system("cls");
        ifstream in("ManagerDetails.txt",ios::in|ios::binary);

        in.seekg(0,ios::beg);
        in.read((char*)&m,sizeof(m));
        gotoxy(18,5);
        cout<<"Personal Details:";
        gotoxy(18,6);
        cout<<"-----------------";

        gotoxy(20,8);
        cout<<">> Name : ";
        puts(m.name);
        gotoxy(20,10);
        cout<<">> Date of Birth : ";
        puts(m.dob);
        gotoxy(20,12);
        cout<<">> Age : ";
        cout<<m.age;
        gotoxy(20,14);
        cout<<">> Address : ";
        puts(m.addr);
        gotoxy(20,16);
        cout<<">> Email : ";
        puts(m.id);
        gotoxy(20,18);
        cout<<">> Phone : ";
        cout<<m.phone;
        gotoxy(20,20);
        cout<<">> Sex :";
        cout<<m.gender;

        in.close();

        getche();

    }

    bool login() {

        system("cls");
        int i,j,c=0;
        char us[20],p[20],ch;
        int outer = 1;
        gotoxy(24,1);
        cout<<"*** GOTHAM NATIONAL BANK ***";
        gotoxy(17,2);
        cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
        gotoxy(20,8);
        cout<<"*** Welcome to Managerial log-in Portal ***\n";
        gotoxy(25,12);
        cout<<"Username : ";
        gets(us);
        gotoxy(10,17);
        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
        gotoxy(25,14);
        cout<<"Password : ";

        while(outer)
        {

            ch=getche();
            cout<<"\b";
            if(ch==13) {
                outer = 0;
                break;
            }
            else if(ch==8)
            {
                system("cls");
                c--;
                gotoxy(24,1);
                cout<<"*** GOTHAM NATIONAL BANK ***";
                gotoxy(17,2);
                cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
                gotoxy(20,8);
                cout<<"*** Welcome to Managerial log-in Portal ***\n";
                gotoxy(25,12);
                cout<<"Username : ";
                puts(us);
                gotoxy(10,17);
                cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                gotoxy(25,14);
                cout<<"Password : ";

                for(j=0; j<c; j++ ) {
                    cout<<"*";
                }

            }
            else if(ch==32)
            {

                int inner = 1;
                char ch1;
                system("cls");
                gotoxy(24,1);
                cout<<"*** GOTHAM NATIONAL BANK ***";
                gotoxy(17,2);
                cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
                gotoxy(20,8);
                cout<<"*** Welcome to Managerial log-in Portal ***\n";
                gotoxy(25,12);
                cout<<"Username : ";
                puts(us);
                gotoxy(10,17);
                cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                gotoxy(25,14);
                cout<<"Password : ";
                for(int k =0; k<c; k++) {
                    cout<<p[k];
                }

                while(inner)
                {

                    ch1 = getche();

                    if(ch1==13) {
                        outer = 0;
                        inner = 0;
                        break;
                    }
                    else if(ch1==8)
                    {
                        system("cls");
                        c--;
                        gotoxy(24,1);
                        cout<<"*** GOTHAM NATIONAL BANK ***";
                        gotoxy(17,2);
                        cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
                        gotoxy(20,8);
                        cout<<"*** Welcome to Managerial log-in Portal ***\n";
                        gotoxy(25,12);
                        cout<<"Username : ";
                        puts(us);
                        gotoxy(10,17);
                        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                        gotoxy(25,14);
                        cout<<"Password : ";
                        for(int k=0; k<c; k++ ) {
                            cout<<p[k];
                        }
                    }
                    else if(ch1 == 32)
                    {

                        system("cls");
                        gotoxy(24,1);
                        cout<<"*** GOTHAM NATIONAL BANK ***";
                        gotoxy(17,2);
                        cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
                        gotoxy(20,8);
                        cout<<"*** Welcome to Managerial log-in Portal ***\n";
                        gotoxy(25,12);
                        cout<<"Username : ";
                        puts(us);
                        gotoxy(10,17);
                        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                        gotoxy(25,14);
                        cout<<"Password : ";

                        for(j=0; j<c; j++ ) {
                            cout<<"*";
                        }

                        inner= 0;

                    }
                    else
                    {
                        p[c]=ch1;
                        c++;
                    }


                }



            }

            else
            {
                p[c]=ch;
                c++;
                cout<<"*";
            }
        }


        p[c]='\0';

        gotoxy(25,16);
        if(strcmp(us,usr )==0 && strcmp(p,pass)==0)
        {
            gotoxy(20,21);
            cout<<"Log in Succesful! Loading.....";
            delay(1500);
            return true;
        }

        else
            return false;

    }

    void viewSpecific();
    void viewCustomerDetails(customer);
    int checkClosingApplication(closeAccount);
    int checkTransferApplication(transfer);
    friend int UpdateDetails(char *);
    void verifiedListM(customer ) ;
    friend int createManager();
    friend void removeManager();
    friend ostream & operator << (ostream &os,customer &b);
    friend istream & operator >> (istream &is,customer &b);
    int fileVerification(customer);


};





class customer																			// Customer Class
{

    char name[20];
    char addr[30];
    char id[10];
    int age;
    int amount;
    char actype[20];
    unsigned long long acno;
    char v1[5];
    char v2[5];
    char apid[10];
    char usr[20];
    char pw[20];
    int FLAG;
    int update;
    char dob[15];
    char gender;
    unsigned long long phone;
    int dd,mm,yy,hh,mi,ss;
public:

    customer(int p)
    {
        char ap[5];
        char gn[9];
        strcpy(gn,"GNB");
        ifstream inp;
        int p1;
        inp.open("Counter.txt",ios::in);
        inp>>p1;
        inp.close();
        strcpy(v1,"No");
        strcpy(v2,"No");
        acno=0;
        itoa(p1+1,ap,10);
        strcat(gn,ap);
        strcpy(apid,gn);
        FLAG=0;
        update=0;
    }
    customer(int x,int p) {
        FLAG=x*p;
    }




    void setPhone(unsigned long long phone) {
        this->phone = phone;
    }

    void setGender(char gender) {
        this->gender = gender;
    }

    void setDob(char * dob) {
        strcpy(this->dob,dob);
    }


    void setUpdate(int update) {
        this->update=update;
    }

    void setFlag(int FLAG)
    {
        this->FLAG=FLAG;
    }
    void setName(char *name)
    {
        strcpy(this->name,name);
    }
    void setActype(char * actype)
    {
        strcpy(this-> actype,actype);
    }

    void setId(char *id)
    {
        strcpy(this->id,id);
    }
    void setAmount(int amount)
    {
        this->amount=amount;
    }
    void setAge(int age)
    {
        this->age=age;
    }


    void setAddr(char *addr) {

        strcpy(this->addr,addr);
    }

    void setAcno(unsigned long long acno)
    {
        this->acno=acno;
    }



    void setUsr(char *usr)
    {
        strcpy(this->usr,usr);
    }

    void setPass(char *pw)
    {
        strcpy(this->pw,pw);
    }


    void setDate(int dd,int mm,int yy) {
        this->dd=dd;
        this->mm=mm;
        this->yy=yy;
    }

    void setTime(int hh,int mi,int ss) {
        this->hh=hh;
        this->mi=mi;
        this->ss=ss;
    }

    int getFlag()
    {
        return FLAG;
    }


    int getUpdate() {
        return update;
    }


    char * getName()
    {

        return name;

    }


    char * getAddr()
    {
        return addr;
    }


    char * getId()
    {

        return id;
    }


    int getAge()
    {
        return age;
    }

    char * getActype()
    {
        return actype;
    }

    unsigned long long getAcno()
    {
        return acno;


    }


    unsigned long long getPhone() {
        return phone;
    }

    char * getDob() {
        return dob;
    }

    char getGender()
    {
        return gender;
    }



    int getAmount()
    {
        return amount;
    }


    char * getApid() {
        return apid;
    }


    char * getUsr()
    {
        return usr;
    }

    char * getPw()
    {
        return pw;
    }

    char * getV1()
    {
        return v1;
    }


    char * getV2()
    {
        return v2;
    }


    void viewDetails() {


        system("cls");
        gotoxy(15,4);
        cout<<"Personal Detials: ";
        gotoxy(15,5);
        cout<<"----------------";
        gotoxy(17,7);
        cout<<">> Name: ";
        puts(name);
        gotoxy(17,9);
        cout<<">> Address: ";
        puts(addr);
        gotoxy(17,11);
        cout<<">> Date of Birth : ";
        puts(dob);
        gotoxy(17,13);
        cout<<">> Age: ";
        cout<<age;
        gotoxy(17,15);
        cout<<">> Email: ";
        puts(id);
        gotoxy(17,17);
        cout<<">> Phone: ";
        cout<<phone;
        gotoxy(17,19);
        cout<<">> Sex: ";
        cout<<gender;
        gotoxy(15,22);
        cout<<"Account Details:";
        gotoxy(15,23);
        cout<<"-----------------";
        gotoxy(17,25);
        cout<<">> Account type: ";
        puts(actype);
        gotoxy(17,27);
        cout<<">> Account number: ";
        cout<<acno;
        gotoxy(17,29);
        cout<<">> Balance: ";
        cout<<amount;

    }



    int menu() {

        system("cls");
        gotoxy(20,2);
        cout<<"Activities available:";
        gotoxy(20,5);
        cout<<"1.  View Account Details";
        gotoxy(20,7);
        cout<<"2.  Deposit Money";
        gotoxy(20,9);
        cout<<"3.  Withdraw Money";

        gotoxy(20,11);
        cout<<"4.  Apply for money Transfer";
        gotoxy(20,13);
        cout<<"5.  Check Transfer Status";

        gotoxy(20,15);
        cout<<"6.  Account Summary";
        gotoxy(20,17);
        cout<<"7.  Transfer Summary";
        gotoxy(20,19);
        cout<<"8.  Change Password";
        gotoxy(20,21);
        cout<<"9.  Edit profile";
        gotoxy(20,23);
        cout<<"10. Close Account";
        gotoxy(20,25);
        cout<<"11. Home";

        gotoxy(20,27);
        cout<<"12. Exit";

        gotoxy(20,30);
        int ch;
        cout<<"Enter your choice:";
        cin>>ch;

        return ch;

    }


    int updateUsrPw() {

        system("cls");
        gotoxy(15,5);
        cout<<"Please update your log-in Details-";
        char usr[20],pw[20];
        gotoxy(17,7);
        cout<<"Set your username: ";
        gets(usr);
        gotoxy(17,9);
        cout<<"Set your password: ";
        strcpy(pw,hidePass("Set your password: ",17,9));
        setUsr(usr);
        setPass(pw);
        update=1;
        return 1;
    }






    int deposit()
    {
        system("cls");
        int am;
        cout<<"Enter the amount you want to deposit: ";
        cin>>am;
        amount+=am;
        gotoxy(25,6);
        cout<<"Amount Deposited Succesfully!";
        delay(2000);
        return am;

    }


    int withdrawl()
    {
        system("cls");
        int am;
        cout<<"Enter the amount you want to withdraw: ";
        cin>>am;
        if(am>amount) {
            gotoxy(25,6);
            cout<<"Insufficient funds!Cannot withdraw money!";
            delay(2000);
            return 0;
        }
        amount-=am;
        gotoxy(25,6);
        cout<<"Amount withdrawn Succesfully!";
        delay(2000);
        return am;
    }



    void write(ofstream &os)
    {
        os.write(name,strlen(name));
        os<<ends;
        os.write((char*)&age,sizeof(age));
        os<<endl;
        os.write(id,strlen(id));
        os<<ends;
        os.write((char*)&amount,sizeof(amount));
        os<<endl;
    }



    int read(ifstream &is)
    {
        is.get(name,20,0);
        name[is.gcount()]=0;
        is.ignore(1);
        is.read((char*)&age,sizeof(age));
        is.get(id,10,0);
        id[is.gcount()]=0;
        is.ignore(1);
        is.read((char*)&amount,sizeof(amount));
        return is.good();
    }


    void edit() {
        int flag=1;
        while(flag)
        {
            system("cls");
            cout<<"Details you can edit are :\n\n";
            cout<<"     1.Address\n";
            cout<<"     2.Email\n";
            cout<<"     3.Phone Number\n";
            int ch;
            cout<<"\nEnter your choice : ";
            cin>>ch;
            char x,add[20],id[20];
            unsigned long long ph;

            switch(ch)
            {
            case 1:
                cout<<"\nAre you sure you want to change your current Address? (Y/N) : ";
                cin>>x;
                if(x=='Y') {
                    cout<<"Enter your new Address : ";
                    cin.ignore();
                    gets(add);
                    setAddr(add);

                }
                break;

            case 2:
                cout<<"\nAre you sure you want to change your current Email id? (Y/N) : ";
                cin>>x;
                if(x=='Y') {
                    cout<<"Enter your new Email : ";
                    cin.ignore();
                    gets(id);
                    setId(id);

                }
                break;


            case 3:
                cout<<"\nAre you sure you want to change your current phone Number? (Y/N) : ";
                cin>>x;
                if(x=='Y') {
                    cout<<"Enter your new Phone Number : ";
                    cin>>ph;
                    setPhone(ph);

                }
                break;

            default:
                cout<<"Wrong input!";
                break;

            }

            cout<<"\n\nDo you want to edit more ? (0/1) :";
            cin>>flag;

        }

    }



    char * MoneyTransfer(transfer);
    char * close(closeAccount);
    friend void manager::viewCustomerDetails(customer);
    friend void manager::verifiedListM(customer);
    friend int manager::fileVerification(customer);
    friend void SystemAdmin::verifiedList(customer);
    friend int SystemAdmin::verification(customer ob1);
    friend ostream & operator << (ostream &os,customer &b);
    friend istream & operator >> (istream &is,customer &b);


};




class transfer																				// Class for money Transfer
{

    unsigned long long acFrom;
    unsigned long long acTo;
    int dd,mm,yy,hh,mi,ss;
    int dd1,mm1,yy1,hh1,mi1,ss1;
    int amount;
    char v[5];
    char tid[5];
    int balFrom;
    int balTo;

public:
    transfer() {
        char ap[5];
        char gn[9];
        strcpy(gn,"TID");
        ifstream inp;
        int p1;
        inp.open("TransferCount.txt",ios::in);
        inp>>p1;
        inp.close();
        itoa(p1+1,ap,10);
        strcat(gn,ap);
        strcpy(tid,gn);
        strcpy(v,"No");
    }

    void setAc(unsigned long long acFrom,unsigned long long acTo) {
        this->acFrom=acFrom;
        this->acTo=acTo;
    }


    void setDate(int dd,int mm,int yy) {
        this->dd=dd;
        this->mm=mm;
        this->yy=yy;
    }

    void setTime(int hh,int mi,int ss) {
        this->hh=hh;
        this->mi=mi;
        this->ss=ss;
    }


    void setAppDate(int dd1,int mm1,int yy1) {
        this->dd1=dd1;
        this->mm1=mm1;
        this->yy1=yy1;
    }

    void setAppTime(int hh1,int mi1,int ss1) {
        this->hh1=hh1;
        this->mi1=mi1;
        this->ss1=ss1;
    }





    void setV(char *v) {
        strcpy(this->v,v);
    }

    void setAmount(int amount) {
        this->amount=amount;
    }

    void setBalFrom(int balFrom) {
        this->balFrom=balFrom;

    }

    void setBalTo(int balTo) {
        this->balTo=balTo;
    }


    unsigned long long getAcfrom() {
        return acFrom;
    }

    unsigned long long getActo() {
        return acTo;
    }


    char * getTid() {
        return tid;
    }


    char * getV() {
        return v;
    }


    int getBalFrom() {

        return balFrom;
    }


    int getBalTo() {
        return balTo;
    }


    int getAmount() {
        return amount;
    }

    int getDate() {
        return dd;
    }

    int getMonth() {
        return mm;
    }

    int getYear() {
        return yy;
    }


    int getHour() {
        return hh;
    }

    int getMinute() {
        return mi;
    }

    int getSecond() {
        return ss;
    }

    friend char* customer::MoneyTransfer(transfer);
    friend int manager::checkTransferApplication(transfer);
};



class closeAccount
{

    unsigned long long ac;
    char name[20];
    char apid[5];
    char v[5];
    int age;
    int balance;
    char actype[20];
    char id[10];
    char addr[30];
    int dd,mm,yy,hh,mi,ss;

public:


    void setApid(int x)
    {

        char ap[5];
        char gn[9];
        strcpy(gn,"CLA");
        itoa(x,ap,10);
        strcat(gn,ap);
        strcpy(apid,gn);

    }


    closeAccount()
    {

        strcpy(v,"No");
    }

    void setDate(int dd,int mm,int yy) {
        this->dd=dd;
        this->mm=mm;
        this->yy=yy;
    }

    void setTime(int hh,int mi,int ss) {
        this->hh=hh;
        this->mi=mi;
        this->ss=ss;
    }

    void setAc(unsigned long long ac) {
        this->ac=ac;
    }

    void setName(char * name) {
        strcpy(this->name,name);
    }

    void setApId(char * apid) {
        strcpy(this->apid,apid);
    }

    void setV(char * v) {
        strcpy(this->v,v);
    }

    unsigned long long getAc() {
        return ac;
    }

    int getAge()
    {
        return age;
    }
    int getBalance()
    {
        return balance;
    }

    char * getApid()
    {
        return apid;
    }

    char * getAddr()
    {
        return addr;
    }

    char * getActype()
    {
        return actype;
    }
    char * getName() {
        return name;
    }

    char * getId() {
        return id;
    }

    char * getV() {
        return v;
    }

    friend char* customer::close(closeAccount);
    friend int manager::checkClosingApplication(closeAccount);

};


                                       // ******************************** FUNCTIONS *******************************//
                                       



char * hidePass(char * s,int x ,int y)                                   // Function shows/hides password
{

    char p[20];
    int c=0;
    int j,i,outer =1;
    char ch,ch1;
    while(outer)
    {

        ch=getche();
        cout<<"\b";
        if(ch==13) {
            outer = 0;
            break;
        }
        else if(ch==8)
        {
            c--;

            gotoxy(x,y);
            cout<<"                                                                         ";
            gotoxy(x,y);
            cout<<s;
            for(j=0; j<c; j++ ) {
                cout<<"*";
            }

        }
        else if(ch==32)
        {

            int inner = 1;
            char ch1;
            gotoxy(x,y);
            cout<<"                                                                             ";
            gotoxy(x,y);
            cout<<s;
            for(int k =0; k<c; k++) {
                cout<<p[k];
            }

            while(inner)
            {

                ch1 = getche();

                if(ch1==13) {
                    outer = 0;
                    inner = 0;
                    break;
                }
                else if(ch1==8)
                {

                    c--;

                    gotoxy(x,y);
                    cout<<"                                                                             ";
                    gotoxy(x,y);
                    cout<<s;
                    for(int k=0; k<c; k++ ) {
                        cout<<p[k];
                    }
                }
                else if(ch1 == 32)
                {

                    gotoxy(x,y);
                    cout<<"                                                                             ";
                    gotoxy(x,y);
                    cout<<s;

                    for(j=0; j<c; j++ ) {
                        cout<<"*";
                    }

                    inner= 0;

                }
                else
                {
                    p[c]=ch1;
                    c++;
                }


            }



        }

        else
        {
            p[c]=ch;
            c++;
            cout<<"*";
        }
    }


    p[c]='\0';

    return p;

}





int validateDob(char * dob) { 																// Function validates entered Date Of Birth
    char dd[3];
    char mm[3];
    char yy[5];
    int d,m,y;
    int i;
    int l = strlen(dob);
    if(l>10 || l<8) {
        return 0;
    }
    else {

        if(dob[l-5]=='/') {

            if(dob[l-7]=='/') {

                int p =0;
                for( i =l-4; i<l; i++) {
                    yy[p] = dob[i];
                    p++;
                }


                yy[p] = '\0';

                for( i =0 ; i<l-7; i++)
                    dd[i] = dob[i];

                dd[i] = '\0';

                p =0;
                for(int j =i+1; j<l-5; j++) {
                    mm[p] = dob[j];
                    p++;
                }
                mm[p] = '\0';

                d = atoi(dd);
                m = atoi(mm);
                y = atoi(yy);


                if(m>0 && m<=12)
                {
                    if(m<=7) {
                        if(m%2==0) {
                            if(d>0 && d<=30) {

                                if((2017-y)>=20 && 2017-y<80)
                                    return 2017-y;
                            }
                            else
                                return 0;
                        }
                        else
                        {
                            if(d>0 && d<=31) {
                                if((2017-y)>=20 && 2017-y<80)
                                    return 2017-y;
                            }
                            else
                                return 0;
                        }

                    }
                    else if(m>7)
                    {

                        if(m%2==0) {
                            if(d>0 && d<=31) {

                                if((2017-y)>=20 && 2017-y<80)
                                    return 2017-y;
                            }
                            else
                                return 0;
                        }
                        else if(m%2!=0)
                        {
                            if(d>0 && d<=30) {
                                if(2017-y>=20 && 2017-y<80)
                                    return 2017-y;
                            }
                            else
                                return 0;
                        }
                    }

                }
                else
                    return 0;



            }
            else if(dob[l-8]=='/') {
                int p =0;
                for(i = l-4; i<l; i++) {

                    yy[p] = dob[i];
                    p++;
                }

                yy[p]= '\0';

                for( i =0 ; i<l-8; i++) {
                    dd[i] = dob[i];
                }

                dd[i] = '\0';

                p =0;
                for(int j =i+1; j<l-5; j++) {
                    mm[p] = dob[j];
                    p++;
                }
                mm[p] = '\0';




                d = atoi(dd);
                m = atoi(mm);
                y = atoi(yy);


                if(m>0 && m<=12)
                {
                    if(m<=7) {
                        if(m%2==0) {
                            if(d>0 && d<=30) {

                                if(2017-y>=20 && 2017-y<80 )
                                    return 2017-y;
                            }
                            else
                                return 0;
                        }
                        else
                        {
                            if(d>0 && d<=31) {
                                if(2017-y>=20 && 2017-y<80)
                                    return 2017-y;
                            }
                            else
                                return 0;
                        }

                    }
                    else if(m>7)
                    {

                        if(m%2==0) {
                            if(d>0 && d<=31) {

                                if(2017-y>=20 && 2017-y<80)
                                    return 2017-y;
                            }
                            else
                                return 0;
                        }
                        else if(m%2!=0)
                        {
                            if(d>0 && d<=30) {
                                if(2017-y>=20 && 2017-y<80)
                                    return 2017-y;
                            }
                            else
                                return 0;
                        }
                    }

                }
                else
                    return 0;



            }


        }
        else
            return 0;



    }

}



char * customer::close(closeAccount ob)                                                         // Function for Closing an existing Account
{

    system("cls");
    gotoxy(22,3);
    cout<<"Account Closing Application";
    gotoxy(22,4);
    cout<<"---------------------------";
    gotoxy(2,7);
    cout<<"This is to request you to kindly close my account (Account number: "<< this->acno<<",";
    gotoxy(2,9);
    cout<<"Account type: "<<this->actype<<") "<<"with your bank under the name";
    gotoxy(2,11);
    cout<<"Mr. "<<this->name<<",resident of "<<this->addr;
    gotoxy(2,13);
    cout<<"which i have been holding in this branch.";
    char ch;
    gotoxy(2,16);
    cout<<"Do you really want to close your account permanently?(Y/N) :";
    cin>>ch;
    if(ch=='Y') {

        ifstream in("CloseCount.txt",ios::in);
        int p;
        in>>p;
        in.close();
        ofstream o("CloseCount.txt",ios::trunc);
        o<<p+1;
        o.close();
        ofstream out("CloseApplication.txt",ios::binary|ios::app);
        ob.setApid(p+1);
        ob.ac=this->acno;
        strcpy(ob.actype,this->actype);
        strcpy(ob.addr,this->addr);
        strcpy(ob. name,this->name);
        ob.age=this->age;
        strcpy(ob.id,this->id);
        ob.balance=this->amount;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        ob.setDate(ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
        ob.setTime(1 + ltm->tm_hour,1 + ltm->tm_min,1 + ltm->tm_sec);
        out.write((char*)&ob,sizeof(ob));

        out.close();
        return ob.apid;

    }
    else
        return "null";

}





int closeView(closeAccount ob)                                                     // Function to view Closing application and take required actions
{

    system("cls");
    gotoxy(22,3);
    cout<<"Account Closing Application";
    gotoxy(22,4);
    cout<<"---------------------------";
    gotoxy(2,7);
    cout<<"This is to request you to kindly close my account (Account number: ";
    cout<<ob.getAc();
    cout<<",";
    gotoxy(2,9);
    cout<<"Account type: ";
    cout<<ob.getActype();
    cout<<") "<<"with your bank under the name";
    gotoxy(2,11);
    cout<<"Mr. ";
    cout<<ob.getName();
    cout<<",resident of ";
    cout<<ob.getAddr();
    cout<<",";
    gotoxy(2,13);
    cout<<"which i have been holding in this branch.";

    gotoxy(0,15);
    cout<<"\n\nAdditional Details : \n";
    cout<<"Name: "<<ob.getName();
    cout<<"\nAddress: "<<ob.getAddr();
    cout<<"\nID: "<<ob.getId();
    cout<<"\nAge: "<<ob.getAge();
    cout<<"\nAccount type: "<<ob.getActype();
    cout<<"\nAccount Number: "<<ob.getAc();
    cout<<"\nBalance: "<<ob.getBalance();
    cout<<"\nApplication id: "<<ob.getApid();
    cout<<"\nApproval Status: "<<ob.getV();


    gotoxy(3,25);
    cout<<"\n\nDo you want to approve this application ? (Y/N) :";
    char ch;
    cin>>ch;

    if(ch=='Y')
        return 1;
    else
        return -1;
}




int manager::checkClosingApplication(closeAccount ob)                                 // Function to check List of pending Account Closing Applications
{
    int flag=1;
    while(flag)
    {
        system("cls");
        int p;
        ifstream in("CloseCount.txt",ios::in);
        in>>p;
        in.close();
        int i=0;
        int count=0,lc=5;
        char ch;
        fstream op("CloseApplication.txt",ios::in|ios::out|ios::binary);
        cout<<"Pending Accounnt Closing Applications : \n\n";
        while(count<p) {
            int loc=(count*sizeof(ob));
            op.seekg(loc,ios::beg);
            op.read((char*)&ob,sizeof(ob));
            if(strcmp(ob.v,"No")==0) {

                gotoxy(6,3);
                cout<<"Application ID";
                gotoxy(27,3);
                cout<<"Date of Submission";
                gotoxy(50,3);
                cout<<"Time of submission";
                gotoxy(1,lc);
                cout<<"**";
                gotoxy(6,lc);
                puts(ob.apid);
                gotoxy(27,lc);
                cout<<ob.dd<<"/"<<ob.mm<<"/"<<ob.yy;
                gotoxy(50,lc);
                cout<<ob.hh<<":"<<ob.mi<<":"<<ob.ss;
                lc+=2;
                i++;
            }
            count++;
        }


        if(i==0) {
            op.close();
            return 0;
        }


        char ch1;
        cout<<"\n\nDo you want to approve any application ? (Y/N) : ";
        cin>>ch1;

        if(ch1=='Y')
        {

            customer cu(3);
            int id,p1;
            cout<<"\n\nEnter the id serial which you want to verify:";
            cin>>id;
            int loc=(id-1)*sizeof(ob);
            op.seekg(loc,ios::beg);
            op.read((char*)&ob,sizeof(ob));

            int re = closeView(ob);

            if(re==1)
            {
                strcpy(ob.v,"Yes");
                op.seekp(loc,ios::beg);
                op.write((char*)&ob,sizeof(ob));

                ifstream in("CustomerCount.txt",ios::in);
                in>>p1;
                in.close();

                fstream oi("CustomerDetails.txt",ios::in|ios::out|ios::binary);

                int c=0,lc1;
                while(c<p1)
                {
                    lc1=c*sizeof(cu);
                    oi.seekg(lc1,ios::beg);
                    oi.read((char*)&cu,sizeof(cu));
                    if(cu.getAcno()==ob.ac)
                        break;
                    c++;

                }
                cu.setFlag(0);
                oi.seekp(lc1,ios::beg);
                oi.write((char*)&cu,sizeof(cu));
                oi.close();

            }
            op.close();
        }
        else
        {
            op.close();
            return -1;
        }

        cout<<"\n\nAnother ?(0/1) :";
        cin>>flag;

    }
    return 1;
}





void manager::viewSpecific() {                                                 // Function displays Specific Customer Detail

    system("cls");
    customer cu(8);
    unsigned long long ac;

    ifstream re("CustomerDetails.txt",ios::in|ios::binary);
    if(!re)
    {
        cout<<"No Customer Accounts Created yet!";
        return;
    }
    else {
        cout<<"Enter the account number : ";
        cin>>ac;
        int c=0;
        while(true) {
            re.read((char*)&cu,sizeof(cu));

            if(re.eof())
                break;

            if(cu.getAcno()==ac) {
                c++;
                if(cu.getFlag()==1)
                {
                    cout<<"\nDetails:-\n\n";
                    cout<<"\t>> Name : ";
                    puts(cu.getName());
                    cout<<"\t   Address : ";
                    puts(cu.getAddr());
                    cout<<"\t   Date of Birth : ";
                    puts(cu.getDob());
                    cout<<"\t   Age : ";
                    cout<<cu.getAge()<<endl;
                    cout<<"\t   Email : ";
                    puts(cu.getId());
                    cout<<"\t   Sex: ";
                    cout<<cu.getGender()<<endl;
                    cout<<"\t   Phone: ";
                    cout<<cu.getPhone()<<endl;
                    cout<<"\t   Account number : ";
                    cout<<ac<<endl;
                    cout<<"\t   Account type : ";
                    puts(cu.getActype());
                    cout<<"\t   Balance : ";
                    cout<<cu.getAmount();
                    break;
                }
                else {
                    cout<<"Account no longer Active.";
                    break;
                }
            }


        }

        if(c==0)
            cout<<"No account with specified Account number exists!";

        re.close();
    }
    return;

}



 
int doTransfer(unsigned long long acFrom, unsigned long long acTo,int amount) {                // Function carries out the money
																						   	  //  transfer between two accounts

    customer ob(8);
    fstream ff("CustomerDetails.txt",ios::in|ios::out|ios::binary);
    int p;
    ifstream in("CustomerCount.txt",ios::in);
    in>>p;
    in.close();
    int loc,bal;
    int count=0;

    while(count<p)
    {

        loc=count*sizeof(ob);
        ff.seekg(loc,ios::beg);

        ff.read((char*)&ob,sizeof(ob));
        if(ob.getFlag()==1) {

            if(ob.getAcno()==acFrom)
            {

                ob.setAmount(ob.getAmount()-amount);
                bal=ob.getAmount();
                break;
            }

        }
        count++;
    }

    ff.seekp(loc,ios::beg);
    ff.write((char*)&ob,sizeof(ob));

    count=0;

    while(count<p)
    {
        loc=count*sizeof(ob);
        ff.seekg(loc,ios::beg);

        ff.read((char*)&ob,sizeof(ob));
        if(ob.getFlag()==1) {

            if(ob.getAcno()==acTo)
            {

                ob.setAmount(ob.getAmount()+amount);
                break;
            }

        }
        count++;
    }


    ff.seekp(loc,ios::beg);
    ff.write((char*)&ob,sizeof(ob));


    ff.close();

    return bal;
}




void writeTransferApp(char * nameto, unsigned long long acto, char * name, unsigned long long ac, int amount, char * actype, char * id)   // Function used to apply
{ 																																		 // for money transfer 
    system("cls");

    gotoxy(25,3);
    cout<<"Transfer Application";
    gotoxy(25,4);
    cout<<"--------------------";

    gotoxy(3,6);
    cout<<"Dear Sir/Madam,";
    gotoxy(3,8);
    cout<<"I,"<<name<<" with "<<actype<<" Account (Account no : "<<ac<<"),would ";
    gotoxy(3,10);
    cout<<"like to request for the transfer of "<<amount<<" rupees to";
    gotoxy(3,12);
    cout<<nameto<<" with (Account no : "<<acto<<").";
    gotoxy(3,14);
    cout<<"If you have any questions please contact me at "<<id;
    gotoxy(3,16);
    cout<<"Hoping that you will grant my request as soon as possible.";

    gotoxy(27,19);
    cout<<"Regards : "<<name;



}



int manager::checkTransferApplication(transfer ob) {                                       // Function to check pending Money Transfer Applications


    int flag = 1;
    while(flag)
    {

        system("cls");
        int p;
        ifstream in("TransferCount.txt",ios::in);
        in>>p;
        in.close();
        int i=0;
        int count=0,lc= 5;
        char ch;
        fstream op("TransferApplication.txt",ios::in|ios::out|ios::binary);
        cout<<"Pending Transfer Applications Details:\n\n";

        while(count<p) {
            int loc=(count*sizeof(ob));
            op.seekg(loc,ios::beg);
            op.read((char*)&ob,sizeof(ob));
            if(strcmp(ob.v,"No")==0) {
                gotoxy(6,3);
                cout<<"Application ID";
                gotoxy(27,3);
                cout<<"Date of Submission";
                gotoxy(50,3);
                cout<<"Time of submission";
                gotoxy(1,lc);
                cout<<"**";
                gotoxy(6,lc);
                puts(ob.tid);
                gotoxy(27,lc);
                cout<<ob.dd1<<"/"<<ob.mm1<<"/"<<ob.yy1;
                gotoxy(50,lc);
                cout<<ob.hh1<<":"<<ob.mi1<<":"<<ob.ss1;
                lc+=2;
                i++;
            }
            count++;
        }


        if(i==0) {
            op.close();
            return 0;
        }


        cout<<"\n\nDo you want to verify any application? (y/n) : ";
        cin>>ch;

        if(ch=='y')
        {
            customer o1(1);
            customer o2(2);
            customer oi(3);
            int bal,id;
            cout<<"\n\nEnter the id serial which you want to verify:";
            cin>>id;
            int loc=(id-1)*sizeof(ob);
            op.seekg(loc,ios::beg);
            op.read((char*)&ob,sizeof(ob));

            fstream oo("CustomerDetails.txt",ios::in|ios::binary);

            while(true)
            {

                oo.read((char*)&o1,sizeof(o1));
                if(oo.eof())
                    break;
                if(o1.getAcno()==ob.acTo) {
                    break;
                }

            }
            oo.close();
            oo.open("CustomerDetails.txt",ios::in|ios::binary);
            while(true)
            {

                oo.read((char*)&o2,sizeof(o2));
                if(oo.eof())
                    break;
                if(o2.getAcno()==ob.acFrom) {
                    break;
                }

            }
            oo.close();

            writeTransferApp(o1.getName(),o1.getAcno(),o2.getName(),o2.getAcno(),ob.amount,o2.getActype(),o2.getId());

            gotoxy(3,24);
            char choice;
            cout<<"Do you want to approve this transfer request ? (Y/N) : ";
            cin>>choice;
            if(choice=='Y')
            {


                strcpy(ob.v,"Yes");
                bal=doTransfer(ob.acFrom,ob.acTo,ob.amount);
                ob.balFrom=bal;
                oo.open("CustomerDetails.txt",ios::in|ios::binary);
                while(true)
                {

                    oo.read((char*)&oi,sizeof(oi));
                    if(oo.eof())
                        break;
                    if(oi.getAcno()==ob.acTo) {
                        ob.balTo=oi.getAmount();
                    }

                }

                time_t now = time(0);
                tm *ltm = localtime(&now);
                ob.dd=ltm->tm_mday;
                ob.mm=1 + ltm->tm_mon;
                ob.yy=1900 + ltm->tm_year;
                ob.hh=1 + ltm->tm_hour;
                ob.mi=1 + ltm->tm_min;
                ob.ss=1 + ltm->tm_sec;
                op.seekp(loc,ios::beg);
                op.write((char*)&ob,sizeof(ob));

            }
            oo.close();
            op.close();
        }

        else
        {
            op.close();
            return -1;
        }
        gotoxy(3,30);
        cout<<"Another ?(0/1) :";
        cin>>flag;

    }
    return 1;

}


void SystemAdmin::verifiedList(customer ob2)                 // Function displays list of all Applications verified by System Admin
{

    int x=0;
    char ch;
    system("cls");
    cout<<"Detailed List of Verified Applications are:\n\n";
    ifstream in;
    int p2;
    int count=0;
    fstream iofile("ApplicationDraft1.txt",ios::binary|ios::in|ios::out);
    in.open("Counter.txt",ios::in);
    in>>p2;
    in.close();
    while(count<p2)
    {


        int loc=count*sizeof(ob2);
        iofile.seekg(loc,ios::beg);
        iofile.read((char*)&ob2,sizeof(ob2));
        if(strcmp(ob2.v1,"Yes")==0) {
            // cout<<ob2<<endl;
            cout<<"\t"<<(char)175<<" Name:";
            puts(ob2.name);
            cout<<"\t  Address:";
            puts(ob2.addr);
            cout<<"\t  Email:";
            puts(ob2.id);
            cout<<"\t  Date of Birth: ";
            puts(ob2.dob);
            cout<<"\t  Age:";
            cout<<ob2.age;
            cout<<"\n\t  Sex: ";
            cout<<ob2.gender;
            cout<<"\n\t  Phone: ";
            cout<<ob2.phone;
            cout<<"\n\t  Account type: ";
            cout<<ob2.actype;
            cout<<"\n\t  Application id: ";
            cout<<ob2.apid;
            cout<<"\n\t  Verification by Admin: ";
            cout<<ob2.v1;
            cout<<"\n\t  Verification by Manager: ";
            cout<<ob2.v2;
            cout<<"\n\n";
            cout<<"\t*******************************\n\n";
            x++;
        }
        count++;

    }
    iofile.close();

    if(x==0) {
        system("cls");
        cout<<"No Applications Verified yet!";
        delay(2000);
    }

}




int readApplication(customer ob,char * name,char * type) {               // Function used to read a Account opening Application
																		//  and take necessary actions

    system("cls");
    char ch;
    gotoxy(24,2);
    cout<<"Applcation Letter";
    gotoxy(24,3);
    cout<<"-----------------";

    gotoxy(2,5);
    cout<<"With reference to the above-mentioned subject, my name is ";
    puts(name);
    gotoxy(2,7);
    cout<<"and I am interested in opening a ";

    for(int i=0; type[i]!='\0'; i++)
        cout<<type[i];


    cout<<" Account with a reputed ";
    gotoxy(2,9);
    cout<<"bank as yours.Thereby, I am enclosing the required filled application ";
    gotoxy(2,11);
    cout<<"form, documents as per the requirements. It would be highly appreciable ";
    gotoxy(2,13);
    cout<<"if you do the needful and initiate the process as soon as possible.";
    gotoxy(35,15);
    cout<<"Reagards : ";
    puts(name);
    gotoxy(0,19);
    cout<<"Additional Details : \n\n";
    cout<<ob;
    gotoxy(2,29);
    cout<<"\n\nDo you want to approve this application? (Y/N) :";
    cin>>ch;
    if(ch=='Y')
        return 1;
    else
        return -1;


}



int SystemAdmin::verification(customer ob)                                   // Function displays List of pending account opening Applications

{
    int flag=1;
    while(flag)
    {
        system("cls");
        int c=0;
        fstream io;
        io.open("ApplicationDraft1.txt",ios::in|ios::out|ios::binary);
        int loc;
        cout<<"List of Pending Applications are:\n\n";
        ifstream in;
        int p;
        int count=0;
        in.open("Counter.txt",ios::in);
        in>>p;
        in.close();
        int lc=5;
        while(count<p)
        {
            loc=count*sizeof(ob);
            io.seekg(loc,ios::beg);
            io.read((char*)&ob,sizeof(ob));
            if(strcmp(ob.v1,"No")==0)
            {
                gotoxy(6,3);
                cout<<"Application ID";
                gotoxy(27,3);
                cout<<"Date of Submission";
                gotoxy(50,3);
                cout<<"Time of submission";


                gotoxy(1,lc);
                cout<<"**";
                gotoxy(6,lc);
                puts(ob.apid);
                gotoxy(27,lc);
                cout<<ob.dd<<"/"<<ob.mm<<"/"<<ob.yy;
                gotoxy(50,lc);
                cout<<ob.hh<<":"<<ob.mi<<":"<<ob.ss;
                lc+=2;
                c++;
            }
            count++;
        }


        if(c==0) {
            io.close();
            return 0;
        }

        char ch;

        cout<<"\n\n\nDo you want to verify any application ? (y/n)";
        cin>>ch;
        if(ch=='y') {
            cout<<endl;
            int id;
            char us[20],p[20];
            cout<<"\nEnter the id serial which you want to verify:";
            cin>>id;
            loc=(id-1)*sizeof(ob);
            io.seekg(loc,ios::beg);
            io.read((char*)&ob,sizeof(ob));
            system("cls");
            int re = readApplication(ob,ob.name,ob.actype);

            if(re==1)
            {
                system("cls");
                strcpy(ob.v1,"Yes");
                io.seekp(loc,ios::beg);
                io.write((char*)&ob,sizeof(ob));
            }

            io.close();
        }
        else {
            io.close();
            return -1;
        }
        cout<<"\n\nAnother ?(0/1) :";
        cin>>flag;

    }
    return 1;
}




istream &operator >> (istream &is,customer &b)
{


    cout<<"Name:";
    is>>ws;
    is.get(b.name,20);
    cout<<"Age:";
    is>>ws>>b.age;
    cout<<"Address:";
    is>>ws;
    is.get(b.addr,30);

    cout<<"Id:";
    is>>ws;
    is.get(b.id,10);
    cout<<"Deposited Amount:";
    is>>ws>>b.amount;
    cout<<"Account type:";
    is>>ws;
    is.get(b.actype,20);
    return is;
}




ostream &operator << (ostream &os,customer &b)
{

    os<<"Name:"<<b.name<<endl;
    os<<"Age:"<<b.age<<endl;
    os<<"Email id:"<<b.id<<endl;
    os<<"Deposited Amount:"<<b.amount<<endl;
    os<<"Address:"<<b.addr<<endl;
    os<<"Account type:"<<b.actype<<endl;
    os<<"Application Id:"<<b.apid<<endl;
    os<<"Verification by System admin:"<<b.v1<<endl;
    os<<"Verification by Manager:"<<b.v2<<endl;
    return os;
}






void manager::viewCustomerDetails(customer ob) {                             // Function Displays all Customer Details

    system("cls");
    ifstream in("CustomerDetails.txt",ios::in|ios::binary);

    int c=0,loc;
    if(!in) {
        cout<<"NO CUSTOMER ACCOUNTS CREATED CURRENTLY!";
        delay(2000);
        return;
    }
    else
    {
        cout<<"Detailed list of customers : \n\n";
        while(true) {

            loc=(c*sizeof(ob));
            in.read((char*)&ob,sizeof(ob));

            if(in.eof())
                break;

            if(ob.FLAG==1) {
                cout<<"\t"<<(char)175<<" Name:";
                puts(ob.name);
                cout<<"\t  Address:";
                puts(ob.addr);
                cout<<"\t  Email:";
                puts(ob.id);
                cout<<"\t  Date of Birth: ";
                puts(ob.dob);

                cout<<"\t  Age:";
                cout<<ob.age;
                cout<<"\n\t  Sex: ";
                cout<<ob.gender;
                cout<<"\n\t  Phone: ";
                cout<<ob.phone;

                cout<<"\n\t  Current Amount:";
                cout<<ob.amount;

                cout<<"\n\t  Account type:";
                puts(ob.actype);

                cout<<"\t  Account number:";
                cout<<ob.acno;

                cout<<"\n\n";
                cout<<"\t*******************************\n\n";
            }
            c++;
        }

        in.close();
    }

    getche();
}





void manager::verifiedListM(customer ob2) {                        // Function displays list of Account opening Applications verified by Manager

    int x=0;
    char ch;
    system("cls");
    cout<<"Detailed List of Verified Applications are:\n\n";
    ifstream in;
    int p2;
    int count=0;
    fstream iofile("ApplicationDraft1.txt",ios::binary|ios::in|ios::out);
    in.open("Counter.txt",ios::in);
    in>>p2;
    in.close();
    while(count<p2)
    {


        int loc=count*sizeof(ob2);
        iofile.seekg(loc,ios::beg);
        iofile.read((char*)&ob2,sizeof(ob2));
        if(strcmp(ob2.v2,"Yes")==0) {
            cout<<"\t"<<(char)175<<" Name:";
            puts(ob2.name);
            cout<<"\t  Address:";
            puts(ob2.addr);
            cout<<"\t  Email:";
            puts(ob2.id);
            cout<<"\t  Date of Birth: ";
            puts(ob2.dob);
            cout<<"\t  Age:";
            cout<<ob2.age;
            cout<<"\n\t  Sex: ";
            cout<<ob2.gender;
            cout<<"\n\t  Phone: ";
            cout<<ob2.phone;
            cout<<"\n\t  Account type: ";
            cout<<ob2.actype;
            cout<<"\n\t  Application id: ";
            cout<<ob2.apid;
            cout<<"\n\t  Verification by Admin: ";
            cout<<ob2.v1;
            cout<<"\n\t  Verification by Manager: ";
            cout<<ob2.v2;
            cout<<"\n\n";
            cout<<"\t*******************************\n\n";
            x++;
        }
        count++;

    }
    iofile.close();

    if(x==0)
    {
        system("cls");
        cout<<"No Verified Applications yet!";
        delay(2000);
    }
}





int manager::fileVerification(customer ob) {                 // Function displays list of pending Account opening Applications
															//   to be verified by the Manager

    int flag=1;
    while(flag)
    {
        system("cls");
        int c=0;
        fstream io;
        io.open("ApplicationDraft1.txt",ios::in|ios::out|ios::binary);
        int loc;
        cout<<"List of Pending Applications are:\n\n";
        ifstream in;
        int p;
        int count=0;
        in.open("Counter.txt",ios::in);
        in>>p;
        in.close();
        int lc=5;
        while(count<p)
        {
            loc=count*sizeof(ob);
            io.seekg(loc,ios::beg);
            io.read((char*)&ob,sizeof(ob));
            if(strcmp(ob.v1,"Yes")==0)
            {

                if(strcmp(ob.v2,"No")==0)
                {

                    gotoxy(6,3);
                    cout<<"Application ID";
                    gotoxy(27,3);
                    cout<<"Date of Submission";
                    gotoxy(50,3);
                    cout<<"Time of submission";


                    gotoxy(1,lc);
                    cout<<"**";
                    gotoxy(6,lc);
                    puts(ob.apid);
                    gotoxy(27,lc);
                    cout<<ob.dd<<"/"<<ob.mm<<"/"<<ob.yy;
                    gotoxy(50,lc);
                    cout<<ob.hh<<":"<<ob.mi<<":"<<ob.ss;
                    lc+=2;
                    c++;

                }
            }
            count++;
        }


        if(c==0) {
            io.close();
            return 0;
        }

        char ch;

        cout<<"\n\n\nDo you want to verify any application ? (y/n)";
        cin>>ch;
        if(ch=='y') {
            cout<<endl;
            int id;
            char us[20],p[20];
            cout<<"\nEnter the id serial which you want to verify:";
            cin>>id;
            loc=(id-1)*sizeof(ob);
            io.seekg(loc,ios::beg);
            io.read((char*)&ob,sizeof(ob));
            system("cls");
            int re =   readApplication(ob,ob.name,ob.actype);

            if(re==1)
            {
                system("cls");
                strcpy(ob.v2,"Yes");
                cout<<"Set a default username: ";
                cin.ignore();
                gets(us);
                strcpy(ob.usr,us);
                cout<<"Set a default password: ";
                gets(p);
                strcpy(ob.pw ,p);
                io.seekp(loc,ios::beg);
                io.write((char*)&ob,sizeof(ob));
            }

            io.close();
        }
        else {
            io.close();
            return -1;
        }
        cout<<"\n\nAnother ?(0/1) :";
        cin>>flag;

    }
    return 1;
}




 
void SystemAdmin::viewManagerDetails() {                         // Function displays All details of appointed Manager
    system("cls");
    manager mn;

    ifstream in("ManagerDetails.txt",ios::in|ios::binary);
    if(!in)
    {
        cout<<"No manager account created!";
        return;
    }
    else
    {
        in.read((char*)&mn,sizeof(mn));
        gotoxy(18,5);
        cout<<"Manager Details:";
        gotoxy(18,6);
        cout<<"-----------------";

        gotoxy(20,8);
        cout<<">> Name : ";
        puts(mn.getName());
        gotoxy(20,10);
        cout<<">> Date of Birth : ";
        puts(mn.getDob());
        gotoxy(20,12);
        cout<<">> Age : ";
        cout<<mn.getAge();
        gotoxy(20,14);
        cout<<">> Address : ";
        puts(mn.getAddr());
        gotoxy(20,16);
        cout<<">> Email : ";
        puts(mn.getId());
        gotoxy(20,18);
        cout<<">> Phone : ";
        cout<<mn.getPhone();
        gotoxy(20,20);
        cout<<">> Sex :";
        cout<<mn.getGender();

    }

    in.close();
    return;
}






int createManager()                                              // Function creates a Manager
{

    manager ob;
    system("cls");
    char p[20];
    ifstream file("ManagerDetails.txt",ios::in|ios::binary);
    if(file)
    {
        file.seekg(0,ios::beg);
        file.read((char*)&ob,sizeof(ob));


        file.close();
        if(ob.FLAG==1)
            return 0;
    }


    ofstream out("ManagerDetails.txt",ios::binary|ios::trunc);
    gotoxy(15,3);
    cout<<"Input Manager Details:\n";
    gotoxy(15,5);
    cout<<"Name:";
    cin.ignore();
    gets(ob.name);
    gotoxy(15,7);
    cout<<"Assign a username for the Manager:";
    gets(ob.usr);
    gotoxy(15,9);
    cout<<"Assign a Password : ";
    strcpy(p,hidePass("Assign a Password : ",15,9));
    strcpy(ob.pass,p);
    ob.FLAG=1;
    ob.update=0;
    out.write((char*)&ob,sizeof(ob));
    out.close();

    return 1;

}





void removeManager()                            							// Function removes a Manager
{

    manager ob;
    system("cls");
    ifstream in("ManagerDetails.txt",ios::binary|ios::in);

    if(!in)
    {
        cout<<"No manager account active!";
        return;
    }
    else
    {
        in.seekg(0,ios::beg);
        in.read((char*)&ob,sizeof(ob));


        in.close();


        if(ob.FLAG==0)
        {
            cout<<"No manager account active!";
            return;
        }
        else
        {
            ob.FLAG=0;


            ofstream out("ManagerDetails.txt",ios::binary|ios::trunc);

            out.write((char*)&ob,sizeof(ob));
            out.close();
            cout<<"Manager Removed Succesfully!";
            return;
        }

    }

}




int noofdigits(unsigned long long d) {
    int x= 0;
    while(d>0) {
        d = d/10;
        x++;
    }

    return x;
}

int UpdateDetails(char *n) {                                         // Function used to update Manager Details
																	//  after first Log-in.

    manager ob;
    system("cls");

    gotoxy(20,3);
    cout<<"Hello Manager!\n";
    delay(1000);
    gotoxy(20,5);
    cout<<"Please update your personal details:\n";
    delay(1500);
    char gen;
    unsigned long long p;
    int r;
    while(true) {
        char dob[15];
        gotoxy(24,14);
        cout<<"                                                                    ";
        gotoxy(24,7);
        cout<<"                                                                                                      ";
        gotoxy(40,11);
        cout<<"Format : dd/mm/yyyy";
        gotoxy(24,7);
        cout<<">> Date of Birth : ";
        gets(dob);
        r = validateDob(dob);
        if(r) {
            gotoxy(40,11);
            cout<<"                                                        ";
            strcpy(ob.dob,dob);

            break;
        }
        else {
            gotoxy(24,14);
            cout<<"Enter a valid Date of Birth!!";
            delay(2000);
        }

    }

    ob.age = r;
    gotoxy(24,9);
    cout<<">> Address :";
    gets(ob.addr);
    gotoxy(24,11);
    cout<<">> Email :";
    gets(ob.id);


    while(true) {

        gotoxy(24,19);
        cout<<"                                          ";
        gotoxy(24,13);
        cout<<"                      ";
        gotoxy(24,13);
        cout<<">> Sex(M/F/T) : ";
        cin>>gen;
        if(tolower(gen)=='m' || tolower(gen)=='f' || tolower(gen)=='t' ) {
            ob.gender = gen;
            break;
        }
        else
        {
            gotoxy(24,19);
            cout<<"Enter a valid character!";
            delay(2000);
        }

    }

    while(true) {
        gotoxy(24,21);
        cout<<"                                             ";
        gotoxy(24,15);
        cout<<"                                                                                        ";
        gotoxy(24,15);
        cout<<">> Phone : ";
        cin>>p;
        if(noofdigits(p)!=10)
        {
            gotoxy(24,21);
            cout<<"Enter a valid phone number!!";
            delay(2000);
        }
        else {
            ob.phone = p;
            break;
        }

    }
    gotoxy(20,17);
    cout<<"-------------------------------------------------";
    gotoxy(24,19);
    cout<<"Enter your new username and password:\n";
    gotoxy(24,20);
    cout<<">> Username : ";
    cin.ignore();
    gets(ob.usr);
    gotoxy(24,21);
    cout<<">> Password : ";
    char p1[20];
    strcpy(p1,hidePass(">> Password : ",24,21));
    strcpy(ob.pass,p1);
    ob.FLAG=1;
    ob.update=1;
    strcpy(ob.name,n);
    ofstream out("ManagerDetails.txt",ios::trunc|ios::binary);

    out.write((char*)&ob,sizeof(ob));
    out.close();
    return 1;

}





int writeApplication(char * name,char * type) {                     // Function to write an application for a new Account set up

    system("cls");
    char ch;
    gotoxy(24,2);
    cout<<"Applcation Letter";
    gotoxy(24,3);
    cout<<"-----------------";

    gotoxy(2,5);
    cout<<"With reference to the above-mentioned subject, my name is ";
    puts(name);
    gotoxy(2,7);
    cout<<"and I am interested in opening a ";

    for(int i=0; type[i]!='\0'; i++)
        cout<<type[i];


    cout<<" Account with a reputed ";
    gotoxy(2,9);
    cout<<"bank as yours.Thereby, I am enclosing the required filled application ";
    gotoxy(2,11);
    cout<<"form, documents as per the requirements. It would be highly appreciable ";
    gotoxy(2,13);
    cout<<"if you do the needful and initiate the process as soon as possible.";
    gotoxy(35,15);
    cout<<"Reagards : ";
    puts(name);

    gotoxy(2,17);
    cout<<"Are you sure you want to submit and proceed to next page (Y/N): ";
    cin>>ch;
    if(ch=='Y')
        return 1;
    else
        return -1;

}




char * FreshApplication ()                                         // Function to complete the application procedure to open a new Account
{
    char name[20],addr[20];
    int age,amount;
    char id[20];
    int c,flag=1;
    char gen;
    unsigned long long p;
    char dob[15];
    system("cls");
    customer ob2(4);
    ofstream ofile("ApplicationDraft1.txt",ios::app|ios::binary);

    cout<<"Enter your name : ";
    gets(name);
    ob2.setName(name);
    cout<<"Type of Account :\n";
    cout<<"    1. Savings Account\n\n";
    cout<<"    2. Reccuring Deposit Account\n\n";
    cout<<"    3. Fixed Deposit Account\n\n";
    cout<<"    4. Student Account";

    cout<<"\n\nEnter your choice: ";
    cin>>c;
    while(flag)
    {
        switch(c) {
        case 1:
            ob2.setActype("Savings");
            flag=0;
            break;

        case 2:
            ob2.setActype("Recurring Deposit");
            flag=0;
            break;


        case 3:
            ob2.setActype("Fixed Deposit");
            flag=0;
            break;

        case 4:
            ob2.setActype("Student Account");
            flag=0;
            break;

        default:
            cout<<"Wrong input!";
            break;


        }
    }


    cout<<"\n\nProceeding to next page.....";
    delay(2000);



    int re = writeApplication(name,ob2.getActype());

    if(re==-1) {
        system("cls");
        cout<<"The task of filling the application form terminated.Returning to home page...";
        delay(2000);
        ofile.close();
        return "null";
    }
    else
    {
        system("cls");
        gotoxy(20,5);
        cout<<"Enter additional details:"<<endl;
        gotoxy(20,6);
        cout<<"------------------------";
        int r;
        while(true) {
            char dob[15];
            gotoxy(24,14);
            cout<<"                                                                    ";
            gotoxy(24,7);
            cout<<"                                                                                                      ";
            gotoxy(40,11);
            cout<<"Format : dd/mm/yyyy";
            gotoxy(24,7);
            cout<<">> Enter your Date of Birth : ";
            gets(dob);
            r = validateDob(dob);
            if(r) {
                gotoxy(40,11);
                cout<<"                                                        ";
                ob2.setDob(dob);

                break;
            }
            else {
                gotoxy(24,14);
                cout<<"Enter a valid Date of Birth!!";
                delay(2000);
            }

        }

        ob2.setAge(r);
        gotoxy(24,9);

        cout<<">> Enter your address : ";
        gets(addr);
        ob2.setAddr(addr);
        gotoxy(24,11);
        cout<<">> Enter Email : ";
        gets(id);
        ob2.setId(id);

        while(true) {

            gotoxy(24,19);
            cout<<"                                          ";
            gotoxy(24,13);
            cout<<"                      ";
            gotoxy(24,13);
            cout<<">> Sex(M/F/T) : ";
            cin>>gen;
            if(tolower(gen)=='m' || tolower(gen)=='f' || tolower(gen)=='t' ) {
                ob2.setGender(gen);
                break;
            }
            else
            {
                gotoxy(24,19);
                cout<<"Enter a valid character!";
                delay(2000);
            }

        }

        while(true) {
            gotoxy(24,21);
            cout<<"                                             ";
            gotoxy(24,15);
            cout<<"                                                                                        ";
            gotoxy(24,15);
            cout<<">> Phone : ";
            cin>>p;
            if(noofdigits(p)!=10)
            {
                gotoxy(24,21);
                cout<<"Enter a valid phone number!!";
                delay(2000);
            }
            else {
                ob2.setPhone(p);
                break;
            }

        }
        gotoxy(24,17);
        cout<<">> Enter initial deposit Amount : ";
        cin>>amount;
        ob2.setAmount(amount);
        time_t now = time(0);
        tm *ltm = localtime(&now);
        ob2.setDate(ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
        ob2.setTime(1 + ltm->tm_hour,1 + ltm->tm_min,1 + ltm->tm_sec);
        ofile.write((char*)&ob2,sizeof(ob2));
        ofile.close();
        ifstream inp;
        ofstream out;
        int p;
        inp.open("Counter.txt",ios::in);
        inp>>p;
        inp.close();
        out.open("Counter.txt",ios::trunc);
        out<<p+1;
        out.close();

        return ob2.getApid();
    }

}





unsigned long long bigrandom()
{
    unsigned long long n = 0;
    do
    {
        n = rand() % 10;
    } while(n == 0);
    for(int i = 1; i <10; i++)
    {
        n *= 10;
        n += rand() % 10;
    }
    return n;
}



 
void checkApplciationStatus() {                                        // Function to check the status of submitted Application

    system("cls");
    customer ob(2);
    fstream inp("ApplicationDraft1.txt",ios::in|ios::binary|ios::out);
    char ap[10];
    cout<<"Enter your application id : ";
    gets(ap);
    int loc;
    ifstream in;
    int p;
    int count=0;
    in.open("Counter.txt",ios::in);
    in>>p;
    in.close();
    int FLAG=0;
    while(count<p)
    {
        unsigned long long t;
        int x;

        loc=count*sizeof(ob);
        inp.seekg(loc,ios::beg);
        inp.read((char*)&ob,sizeof(ob));
        char io[20];
        strcpy(io,ob.getApid());


        if(strcmp(io,ap)==0)
        {
            FLAG=1;
            if(strcmp( ob.getV1(),"Yes")==0)
            {

                if(strcmp( ob.getV2(),"Yes")==0)
                {

                    if(ob.getFlag()==1)
                    {

                        cout<<"Account already created!";
                        delay(2000);
                        inp.close();
                        return;
                    }


                    srand(time(NULL));
                    t=bigrandom();
                    cout<<"Application Verified by both SystemAdmin and Manager!\n";
                    cout<<"Account created succesfully!\n";
                    cout<<"Allocated Account number is:"<<t<<endl;
                    cout<<"Your default username is : ";
                    puts(ob.getUsr());
                    cout<<"Your default password is : ";
                    puts(ob.getPw());
                    ob.setFlag(1);
                    ob.setAcno(t);
                    ofstream out("CustomerDetails.txt",ios::app|ios::binary);
                    out.write((char*)&ob,sizeof(ob));
                    out.close();
                    inp.seekp(loc,ios::beg);
                    inp.write((char*)&ob,sizeof(ob));
                    inp.close();
                    ifstream op("CustomerCount.txt",ios::in);
                    op>>x;
                    op.close();
                    ofstream ou("CustomerCount.txt",ios::trunc);
                    ou<<x+1;
                    ou.close();
                    cout<<"Loading home page....";
                    delay(8000);
                    return;
                }
                else {
                    cout<<"Application Verified by SystemAdmin.Waiting for verification by Manager...";
                    inp.close();
                    delay(3000);

                    return ;
                }

            }
            else
            {
                cout<<"Waiting for Verification by SystemAdmin...";
                inp.close();
                delay(3000);
                return;
            }


        }
        count++;

    }
    inp.close();
    if(FLAG==0) {
        cout<<"Something is wrong.Enter correct id!";
        delay(2000);
    }

    return;

}







int CustomerLogin() {                                                               // Log-in function for Customer

    customer ob(4);
    ifstream in("CustomerDetails.txt",ios::in|ios::binary);

    if(!in) {

        return -2;
    }

    else {
        int count=0,loc,x;
        system("cls");
        int i,j,c=0;
        char usr[20],p[20],ch;
        int outer = 1;
        gotoxy(26,2);
        cout<<"*** GOTHAM NATIONAL BANK ***";
        gotoxy(20,8);
        cout<<"*** Welcome to Customer log-in Portal ***\n";
        gotoxy(25,12);
        cout<<"Username : ";
        gets(usr);
        gotoxy(10,17);
        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
        gotoxy(25,14);
        cout<<"Password : ";

        while(outer)
        {

            ch=getche();
            cout<<"\b";

            if(ch==13) {
                outer=0;
                break;
            }
            else if(ch==8)
            {
                system("cls");
                c--;
                gotoxy(26,2);
                cout<<"*** GOTHAM NATIONAL BANK ***";
                gotoxy(20,8);
                cout<<"*** Welcome to Customer log-in Portal ***\n";
                gotoxy(25,12);
                cout<<"Username : ";
                puts(usr);
                gotoxy(10,17);
                cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                gotoxy(25,14);
                cout<<"Password : ";

                for(j=0; j<c; j++ ) {
                    cout<<"*";
                }

            }
            else if(ch==32)
            {


                int inner = 1;
                char ch1;
                system("cls");
                gotoxy(26,2);
                cout<<"*** GOTHAM NATIONAL BANK ***";
                gotoxy(20,8);
                cout<<"*** Welcome to Customer log-in Portal ***\n";
                gotoxy(25,12);
                cout<<"Username : ";
                puts(usr);
                gotoxy(10,17);
                cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                gotoxy(25,14);
                cout<<"Password : ";
                for(int k =0; k<c; k++) {
                    cout<<p[k];
                }

                while(inner)
                {

                    ch1 = getche();

                    if(ch1==13) {
                        outer = 0;
                        inner = 0;
                        break;
                    }
                    else if(ch1==8)
                    {
                        system("cls");
                        c--;
                        gotoxy(26,2);
                        cout<<"*** GOTHAM NATIONAL BANK ***";
                        gotoxy(20,8);
                        cout<<"*** Welcome to Customer log-in Portal ***\n";
                        gotoxy(25,12);
                        cout<<"Username : ";
                        puts(usr);
                        gotoxy(10,17);
                        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                        gotoxy(25,14);
                        cout<<"Password : ";
                        for(int k=0; k<c; k++ ) {
                            cout<<p[k];
                        }
                    }
                    else if(ch1 == 32)
                    {

                        system("cls");
                        gotoxy(26,2);
                        cout<<"*** GOTHAM NATIONAL BANK ***";
                        gotoxy(20,8);
                        cout<<"*** Welcome to Customer log-in Portal ***\n";
                        gotoxy(25,12);
                        cout<<"Username : ";
                        puts(usr);
                        gotoxy(10,17);
                        cout<<"(Show/Hide your password using the Space-bar key on your keyboard)";
                        gotoxy(25,14);
                        cout<<"Password : ";

                        for(j=0; j<c; j++ ) {
                            cout<<"*";
                        }

                        inner= 0;

                    }
                    else
                    {
                        p[c]=ch1;
                        c++;
                    }


                }


            }
            else
            {
                p[c]=ch;
                c++;
                cout<<"*";
            }
        }


        p[c]='\0';

        ifstream inp("CustomerCount.txt",ios::in);
        inp>>x;
        inp.close();
        while(count<x)
        {
            loc=count*sizeof(ob);
            in.seekg(loc,ios::beg);
            in.read((char*)&ob,sizeof(ob));


            if((strcmp(ob.getUsr(),usr)==0) && (strcmp(ob.getPw(),p)==0)) {

                if(ob.getFlag()==0) {
                    system("cls");
                    gotoxy(20,5);
                    cout<<"Account closed Permanently!";
                    delay(2000);
                    return -3;
                }
                gotoxy(20,21);
                cout<<"Log in Succesful! Loading.....";
                delay(2500);
                in.close();
                return loc;

            }
            count++;

        }
        in.close();

        return -1;


    }

}





char * customer::MoneyTransfer(transfer ob) {                                     // Function to apply for a Money Transfer

    customer cu(7);
    char c;
    unsigned long long ac;
    int FLAG=0;
    system("cls");
    cout<<"Enter the details regarding the transfer: \n\n";
    cout<<"Enter the Account Number you want to trasnfer to:";
    cin>>ac;
    ifstream in("CustomerDetails.txt",ios::in|ios::binary);

    while(true) {
        in.read((char*)&cu,sizeof(cu));
        if(in.eof())
            break;

        if(cu.getAcno()==ac && cu.getFlag()==1) {
            FLAG=1;
            break;
        }
    }
    in.close();
    if(FLAG==1) {

        cout<<"Enter the Amount: ";
        cin>>ob.amount;

        writeTransferApp(cu.getName(),cu.getAcno(),name,acno,ob.amount,actype,id);

        gotoxy(3,23);
        cout<<"Do you want to submit this application?(Y/N) : ";
        cin>>c;
        if(c =='Y') {

            ifstream i("TransferCount.txt",ios::in);
            int p;
            i>>p;
            i.close();
            ofstream o("TransferCount.txt",ios::trunc);
            o<<p+1;
            o.close();
            ofstream out("TransferApplication.txt",ios::binary|ios::app);
            ob.acFrom=acno;
            ob.acTo=ac;
            time_t now = time(0);
            tm *ltm = localtime(&now);
            ob.setAppDate(ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
            ob.setAppTime(1 + ltm->tm_hour,1 + ltm->tm_min,1 + ltm->tm_sec);
            out.write((char*)&ob,sizeof(ob));
            out.close();
            return ob.tid;

        }

        else
        {
            system("cls");
            cout<<"Returning to main-page...";
            delay(2000);
            return "xxx";
        }

    }
    else {
        system("cls");
        cout<<"Enter a valid account number!";
        delay(2000);
        return "Null";
    }


}


void checkTranferStatus() {                                    // Function to check Transfer Application Status

    transfer tu;
    fstream in("TransferApplication.txt",ios::in|ios::binary);
    if(!in)
    {
        system("cls");
        gotoxy(15,15);
        cout<<"No Transfer Application Submitted!";
        return;
    }
    int c=0;
    system("cls");
    char id[10];
    cout<<"Enter your transfer ID: ";
    cin.ignore();
    gets(id);


    while(true)
    {
        in.read((char*)&tu,sizeof(tu));
        if(in.eof())
            break;

        if(strcmp(tu.getTid(),id)==0)
        {
            c=1;
            if(strcmp(tu.getV(),"Yes")==0)
            {
                cout<<"\nApplication for transfer has been approved by the manager.\n";
                cout<<"View Transfer Summary for Details!";
                delay(1000);
                in.close();
                return ;
            }
            else {
                cout<<"\nSorry,Application yet to be approved by the manager!";
                in.close();
                return ;
            }
        }
    }


    in.close();
    if(c==0)
        cout<<"Enter a valid Application ID!";

    return;

}


// ********************************************** main() Function *****************************************************************//


int main()
{

    SystemAdmin ob;
    manager mn;
    ifstream iofile("SystemAdmin.txt",ios::in|ios::binary);
    if(!iofile)
    {
        ofstream outf("SystemAdmin.txt",ios::trunc|ios::binary);

        ob.setname("aa");
        ob.set_pw ("12");
        outf.write((char*)&ob,sizeof(ob));
        outf.close();

    }
    else
    {
        iofile.seekg(0,ios::beg);
        iofile.read((char*)&ob,sizeof(ob));
        iofile.close();
    }


    ifstream ifile("ManagerDetails.txt",ios::in|ios::binary);

    if(!ifile) {
        delay(2000);
    }
    else
    {
        ifile.seekg(0,ios::beg);
        ifile.read((char*)&mn,sizeof(mn));
        ifile.close();
    }



    ifstream in("Counter.txt",ios::in);
    system("cls");
    if(!in)
    {

        ob.setCountini();
    } else
        in.close();


    ifstream ino("CustomerCount.txt",ios::in);

    if(!ino) {
        ofstream ou("CustomerCount.txt",ios::trunc);
        ou<<"0";
        ou.close();
    }

    ifstream inoo("TransferCount.txt",ios::in);

    if(!inoo) {
        ofstream ou("TransferCount.txt",ios::trunc);
        ou<<"0";
        ou.close();
    }


    ifstream inooo("CloseCount.txt",ios::in);

    if(!inooo) {
        ofstream ou("CloseCount.txt",ios::trunc);
        ou<<"0";
        ou.close();
    }


    int FLAG=1;


    while(FLAG)
    {

        int x;
        ifstream file("ManagerDetails.txt",ios::in|ios::binary);
        if(file)
        {
            file.seekg(0,ios::beg);
            file.read((char*)&mn,sizeof(mn));

            file.close();
        }
        int m=1,chance = 4;
        char pass[20];
        char usr[20];
        char newp[20];
        int p;
        int loc;
        ofstream out;
        fstream op;
        customer cu(7);
        customer ob6(6);
        customer ob5(8);
        customer oo(7);
        time_t now;
        tm* ltm;
        system("cls");
        int choice=basic_display();

        switch(choice)
        {

        case 1:

            while(m)
            {

                if(ob.login())
                {

                    int fg=1;
                    while(fg)
                    {
                        int choice0=ob.menu();
                        switch(choice0)
                        {
                        case 1:
                            x=createManager();
                            if(x==1)
                            {
                                gotoxy(10,15);
                                cout<<"Manager account Created succesfully!";
                                getche();
                            }
                            else if(x==0)
                            {
                                gotoxy(10,15);
                                cout<<"Manager Already Assigned!";
                                getche();
                            }
                            else
                            {
                                gotoxy(10,15);
                                cout<<"Something went wrong!";
                                getche();
                            }
                            break;

                        case 2:


                            removeManager();
                            delay(2000);
                            break;

                        case 4:

                            ob.verifiedList(ob6);
                            getche();
                            break;

                        case 3:

                            p=ob.verification(ob5)  ;
                            system("cls");
                            if(p==1)
                            {

                                cout<<"Verification session complete!"<<endl;
                                delay(1000);
                            }
                            else if(p==0)
                            {
                                cout<<"No Pending Applications remaining!";
                                delay(2000);
                            }
                            else if(p==-1)
                            {
                                cout<<"Returning to main-page...";
                                delay(1000);
                            }
                            else
                            {
                                cout<<"Something went wrong";
                                delay(1000);
                            }

                            break;




                        case 5:

                            system("cls");
                            gotoxy(23,6);
                            cout<<"Enter your old Password : ";
                            strcpy(newp,hidePass("Enter your old Password : ",23,6));
                            if((strcmp(ob.getpass(),newp)==0)) {
                                gotoxy(23,8);
                                cout<<"Enter your new password : ";
                                strcpy(newp,hidePass("Enter your new password : ",23,8));
                            }
                            else
                            {
                                gotoxy(23,8);
                                cout<<"Wrong password entered.Try Again.";
                                delay(2000);
                                break;
                            }
                            gotoxy(23,11);
                            cout<<"Password Saved Succesfull!Loading Log-in Page...";
                            ob.change_pw(newp);
                            out.open("SystemAdmin.txt",ios::trunc|ios::binary);
                            out.write((char*)&ob,sizeof(ob));

                            out.close();

                            delay(1000);
                            break;


                        case 6:

                            ob.viewManagerDetails();
                            delay(1000);
                            getche();
                            break;


                        case 7:

                            fg=0;
                            m=0;
                            break;


                        case 8:
                            fg=0;
                            m=0;
                            break;

                        case 9:
                            fg=0;
                            m=0;
                            FLAG=0;
                            break;


                        }


                    }

                }
                else
                {
                    chance--;
                    if(chance==0) {

                        gotoxy(12,21);
                        cout<<"You have exhausted the number of chances Allowed.Try again later!";
                        delay(2000);
                        m=0;
                    }
                    else
                    {
                        gotoxy(20,21);
                        cout<<"Unidentified username or password!Try again.";
                        gotoxy(20,23);
                        cout<<"Number of chances remaining : "<<chance;
                        delay(2500);

                    }
                }

            }

            break;


        case 2:

            if(mn.getFLAG()==0)
            {
                system("cls");
                cout<<"No manager created!";
                delay(2000);
                break;
            }

            while(m)
            {


                if(mn.login())
                {
                    if(mn.getUpdate()==0)
                    {
                        int x=UpdateDetails(mn.getName());
                        if(x==1) {
                            system("cls");
                            cout<<"Details updated Succesfully!";
                            delay(1000);


                            ifstream ifile("ManagerDetails.txt",ios::in|ios::binary);
                            if(ifile)
                            {
                                ifile.seekg(0,ios::beg);
                                ifile.read((char*)&mn,sizeof(mn));

                                ifile.close();
                            }
                        }

                    }
                    int fg=1;
                    while(fg)
                    {
                        transfer ti;
                        closeAccount ci;
                        int x=0;
                        char newp[20];
                        int choice0=mn.menu();
                        switch(choice0)

                        {

                        case 1:
                            mn.viewDetails();

                            break;
                        case 2:

                            p=mn.fileVerification(ob5);
                            system("cls");
                            if(p==1)
                            {

                                cout<<"Verification session complete!"<<endl;
                                delay(1000);
                            }
                            else if(p==0)
                            {
                                cout<<"No Pending Applications remaining!";
                                delay(2000);
                            }
                            else if(p==-1)
                            {
                                cout<<"Returning to main-page...";
                                delay(1000);
                            }
                            else
                            {
                                cout<<"Something went wrong";
                                delay(1000);
                            }

                            break;
                        case 3:
                            x=mn.checkTransferApplication(ti);
                            if(x==0) {
                                system("cls");
                                cout<<"No pending Applications!";
                                delay(2000);
                            }
                            else {
                                system("cls");
                                cout<<"Verification task completed!";
                                delay(2000);
                            }


                            break;

                        case 4:
                            x=mn.checkClosingApplication(ci);
                            if(x==0) {
                                system("cls");
                                cout<<"No pending Applications!";
                                delay(2000);
                            }
                            else if(x==-1)
                            {
                                system("cls");
                                cout<<"Returning to main page...";
                                delay(2000);
                            }
                            else {
                                system("cls");
                                cout<<"Verification task completed!";
                                delay(2000);
                            }

                            break;


                        case 5:

                            mn.verifiedListM(ob6);
                            getche();
                            break;


                        case 6:


                            mn.viewCustomerDetails(oo);
                            break;



                        case 8:

                            system("cls");
                            gotoxy(23,6);
                            cout<<"Enter your old Password : ";
                            strcpy(newp,hidePass("Enter your old Password : ",23,6));
                            if((strcmp(mn.getPass(),newp)==0)) {
                                gotoxy(23,8);
                                cout<<"Enter your new password : ";
                                strcpy(newp,hidePass("Enter your new password : ",23,8));
                            }
                            else
                            {
                                gotoxy(23,8);
                                cout<<"Wrong password entered.Try Again.";
                                delay(2000);
                                break;
                            }
                            gotoxy(23,11);
                            cout<<"Password Saved Succesfull!Loading Log-in Page...";
                            mn.setPass(newp);
                            out.open("ManagerDetails.txt",ios::trunc|ios::binary);
                            out.write((char*)&mn,sizeof(mn));

                            out.close();

                            delay(1000);

                            break;

                        case 7:

                            mn.viewSpecific();
                            delay(1000);
                            getche();
                            break;


                        case 9:
                            fg=0;
                            m=0;

                            break;

                        case 10:
                            fg=0;
                            m=0;
                            FLAG=0;
                            break;


                        }

                    }
                }
                else
                {
                    chance--;
                    if(chance==0) {

                        gotoxy(12,21);

                        cout<<"You have exhausted the number of chances Allowed.Try again later!";
                        delay(2000);
                        m=0;
                    }
                    else {
                        gotoxy(20,21);
                        cout<<"Unidentified username or password!Try again.";
                        gotoxy(20,24);
                        cout<<"Number of chances remaining : "<<chance;
                        delay(2500);
                    }
                }

            }

            break;


        case 3:

            while(m)
            {


                char ti[5];
                int xx=CustomerLogin();
                int am;
                if(xx>=0)
                {

                    ifstream i("CustomerDetails.txt",ios::in|ios::binary);
                    i.seekg(xx,ios::beg);
                    i.read((char*)&cu,sizeof(cu));
                    i.close();
                    if(cu.getUpdate()==0)
                    {
                        int z= cu.updateUsrPw();
                        if(z==1)
                        {
                            fstream o("CustomerDetails.txt",ios::in|ios::out|ios::binary);
                            o.seekp(xx,ios::beg);
                            o.write((char*)&cu,sizeof(cu));
                            o.close();
                            gotoxy(20,15);
                            cout<<"Update Succesful!Loading main-page....";
                            delay(2000);
                        }
                        else
                        {
                            cout<<"Something went wrong!";
                            break;
                        }
                    }
                    int fg=1;
                    while(fg)
                    {
                        ofstream ai;
                        ifstream rr;
                        ifstream rea;
                        char ci[5];
                        int uu=0;
                        int loc;
                        ifstream ii("CustomerDetails.txt",ios::in|ios::binary);
                        ii.seekg(xx,ios::beg);
                        ii.read((char*)&cu,sizeof(cu));
                        ii.close();
                        transfer tn;
                        closeAccount ca;
                        DepositOrWithdrawl dw;
                        int choice0=cu.menu();

                        switch(choice0) {

                        case 1:
                            cu.viewDetails();
                            getche();
                            break;

                        case 2:

                            am=cu.deposit();
                            op.open("CustomerDetails.txt",ios::out|ios::in|ios::binary);
                            op.seekp(xx,ios::beg);
                            op.write((char*)&cu,sizeof(cu));
                            op.close();
                            now = time(0);
                            ltm = localtime(&now);
                            dw.setDate(ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
                            dw.setTime(1 + ltm->tm_hour,1 + ltm->tm_min,1 + ltm->tm_sec);
                            dw.setAcno(cu.getAcno());
                            dw.setBalance(cu.getAmount());
                            dw.setAmount(am);
                            dw.setType("Deposit");
                            ai.open("AccountSummary.txt",ios::binary|ios::app);
                            ai.write((char*)&dw,sizeof(dw));
                            ai.close();
                            break;

                        case 3:

                            am=cu.withdrawl();
                            if(am>0) {
                                op.open("CustomerDetails.txt",ios::out|ios::in|ios::binary);
                                op.seekp(xx,ios::beg);
                                op.write((char*)&cu,sizeof(cu));
                                op.close();
                                now = time(0);
                                ltm = localtime(&now);
                                dw.setDate(ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
                                dw.setTime(1 + ltm->tm_hour,1 + ltm->tm_min,1 + ltm->tm_sec);
                                dw.setAcno(cu.getAcno());
                                dw.setBalance(cu.getAmount());
                                dw.setAmount(am);
                                dw.setType("Withdrawl");
                                ai.open("AccountSummary.txt",ios::binary|ios::app);
                                ai.write((char*)&dw,sizeof(dw));
                                ai.close();
                            }

                            break;


                        case 4:

                            strcpy(ti,cu.MoneyTransfer(tn));
                            if(strcmp(ti,"Null")==0) {
                                break;
                            }
                            else if(strcmp(ti,"xxx")==0) {
                                break;
                            }
                            else {

                                system("cls");
                                cout<<"Application submitted succesfully!\n";
                                cout<<"Transfer ID is:";
                                puts(ti);
                                delay(2000);

                            }

                            break;

                        case 5:

                            checkTranferStatus();
                            delay(2000);
                            break;


                        case 6:

                            system("cls");
                            loc=7;
                            rea.open("AccountSummary.txt",ios::binary|ios::in);
                            gotoxy(28,2);
                            cout<<"Account Summary";
                            gotoxy(6,5);
                            cout<<"Account no";
                            gotoxy(20,5);
                            cout<<"Activity";
                            gotoxy(32,5);
                            cout<<"Amount";
                            gotoxy(45,5);
                            cout<<"Balance";
                            gotoxy(56,5);
                            cout<<"Date";
                            gotoxy(68,5);
                            cout<<"Time\n\n";


                            if(!rea)
                            {
                                gotoxy(2,15);
                                cout<<"file not found";
                                gotoxy(10,7);
                                cout<<"-";
                                gotoxy(24,7);
                                cout<<"-";
                                gotoxy(34,7);
                                cout<<"-";
                                gotoxy(48,7);
                                cout<<"-";
                                gotoxy(57,7);
                                cout<<"-";
                                gotoxy(70,7);
                                cout<<"-";
                                gotoxy(6,11);
                                cout<<"No Account Summary details available!";
                            }
                            else
                            {
                                while(true) {

                                    rea.read((char*)&dw,sizeof(dw));

                                    if(rea.eof()) {

                                        break;
                                    }

                                    if(dw.getAcno()==cu.getAcno())
                                    {

                                        uu++;
                                        cout<<"  "<<uu<<".";
                                        gotoxy(6,loc);
                                        cout<<dw.getAcno();
                                        gotoxy(20,loc);
                                        cout<<dw.getType();
                                        gotoxy(32,loc);
                                        cout<<dw.getAmount();
                                        gotoxy(45,loc);
                                        cout<<dw.getBalance();
                                        gotoxy(56,loc);
                                        cout<<dw.getDate()<<"/"<<dw.getMonth()<<"/"<<dw.getYear();
                                        gotoxy(68,loc);
                                        cout<<dw.getHour()<<":"<<dw.getMinute()<<":"<<dw.getSecond();
                                        cout<<"\n\n";
                                        loc+=2;

                                        delay(1000);

                                    }

                                }

                                if(uu==0) {
                                    gotoxy(2,14);
                                    cout<<"Account not found";
                                    gotoxy(10,7);
                                    cout<<"-";
                                    gotoxy(24,7);
                                    cout<<"-";
                                    gotoxy(34,7);
                                    cout<<"-";
                                    gotoxy(48,7);
                                    cout<<"-";
                                    gotoxy(57,7);
                                    cout<<"-";
                                    gotoxy(70,7);
                                    cout<<"-";
                                    gotoxy(6,11);
                                    cout<<"No Account Summary details available!";
                                }

                                rea.close();

                            }
                            getche();
                            break;



                        case 7:

                            loc=9;
                            system("cls");
                            rr.open("TransferApplication.txt",ios::binary|ios::in);
                            gotoxy(28,2);
                            cout<<"Transfer Summary";
                            gotoxy(48,2);
                            cout<<"Account no: "<<cu.getAcno();
                            gotoxy(4,6);
                            cout<<"Transfer From";
                            gotoxy(4,7);
                            cout<<"Account no";
                            gotoxy(20,6);
                            cout<<"Transfer to";
                            gotoxy(20,7);
                            cout<<"Account number";
                            gotoxy(36,7);
                            cout<<"Amount";
                            gotoxy(45,7);
                            cout<<"Balance";
                            gotoxy(56,7);
                            cout<<"Date";
                            gotoxy(68,7);
                            cout<<"Time\n\n";

                            if(!rr)
                            {

                                gotoxy(8,9);
                                cout<<"-";
                                gotoxy(24,9);
                                cout<<"-";
                                gotoxy(39,9);
                                cout<<"-";
                                gotoxy(49,9);
                                cout<<"-";
                                gotoxy(58,9);
                                cout<<"-";
                                gotoxy(70,9);
                                cout<<"-";
                                gotoxy(4,13);
                                cout<<"No Transfer Summary Details available!";

                            }

                            else
                            {


                                while(true) {

                                    rr.read((char*)&tn,sizeof(tn));

                                    if(rr.eof())
                                        break;


                                    if(strcmp(tn.getV(),"Yes")==0)
                                    {

                                        if(tn.getAcfrom()==cu.getAcno())
                                        {

                                            uu++;
                                            cout<<"  "<<uu<<".";

                                            gotoxy(4,loc);
                                            cout<<tn.getAcfrom();
                                            gotoxy(20,loc);
                                            cout<<tn.getActo();
                                            gotoxy(36,loc);
                                            cout<<tn.getAmount();
                                            gotoxy(45,loc);
                                            cout<<tn.getBalFrom();
                                            gotoxy(56,loc);
                                            cout<<tn.getDate()<<"/"<<tn.getMonth()<<"/"<<tn.getYear();
                                            gotoxy(68,loc);
                                            cout<<tn.getHour()<<":"<<tn.getMinute()<<":"<<tn.getSecond();
                                            cout<<"\n\n";
                                            loc+=2;

                                            delay(1000);
                                        }
                                        else if(tn.getActo()==cu.getAcno())
                                        {
                                            uu++;
                                            cout<<"  "<<uu<<".";

                                            gotoxy(4,loc);
                                            cout<<tn.getAcfrom();
                                            gotoxy(20,loc);
                                            cout<<tn.getActo();
                                            gotoxy(36,loc);
                                            cout<<tn.getAmount();
                                            gotoxy(45,loc);
                                            cout<<tn.getBalTo();
                                            gotoxy(56,loc);
                                            cout<<tn.getDate()<<"/"<<tn.getMonth()<<"/"<<tn.getYear();
                                            gotoxy(68,loc);
                                            cout<<tn.getHour()<<":"<<tn.getMinute()<<":"<<tn.getSecond();
                                            cout<<"\n\n";
                                            loc+=2;

                                            delay(1000);


                                        }

                                    }

                                }

                                rr.close();
                                if(uu==0)
                                {
                                    gotoxy(8,9);
                                    cout<<"-";
                                    gotoxy(24,9);
                                    cout<<"-";
                                    gotoxy(39,9);
                                    cout<<"-";
                                    gotoxy(49,9);
                                    cout<<"-";
                                    gotoxy(58,9);
                                    cout<<"-";
                                    gotoxy(70,9);
                                    cout<<"-";
                                    gotoxy(4,13);
                                    cout<<"No Transfer Summary Details available!";
                                }

                            }
                            getche();
                            break;

                        case 8:

                            system("cls");
                            cout<<"Old Password:\n";
                            puts(cu.getPw());
                            cout<<"\nEnter your new password:\n";
                            cin.ignore();
                            gets(pass);
                            cout<<"Password Saved Succesfull!Loading Log-in Page...";
                            cu.setPass(pass);
                            op.open("CustomerDetails.txt",ios::out|ios::in|ios::binary);
                            op.seekp(xx,ios::beg);
                            op.write((char*)&cu,sizeof(cu));
                            op.close();
                            delay(1000);

                            break;

                        case 9:

                            system("cls");
                            cu.edit();
                            op.open("CustomerDetails.txt",ios::out|ios::in|ios::binary);
                            op.seekp(xx,ios::beg);
                            op.write((char*)&cu,sizeof(cu));
                            op.close();
                            cout<<"Returning to main-page...";
                            delay(2000);
                            break;

                        case 10:

                            strcpy(ci,cu.close(ca));
                            system("cls");
                            if(strcmp(ci,"null")==0)
                            {
                                cout<<"Returning to main page....";
                                delay(2000);
                            }
                            else
                            {
                                cout<<"Application submitted succesfully!\n";
                                cout<<"Application id is: ";
                                puts(ci);
                                delay(2000);
                            }
                            break;


                        case 11:
                            fg=0;
                            m=0;
                            break;

                        case 12:
                            fg=0;
                            m=0;
                            FLAG=0;

                            break;


                        }
                    }
                }
                else if(xx==-1)
                {
                    chance--;
                    if(chance==0) {
                        gotoxy(12,21);
                        cout<<"You have exhausted the number of chances Allowed.Try again later!";
                        delay(2000);
                        m=0;
                    }

                    else
                    {
                        gotoxy(20,21);
                        cout<<"Unidentified username or password!Try again.";
                        gotoxy(20,23);
                        cout<<"Number of chances remaining : "<<chance;
                        delay(2500);
                    }
                }
                else if(xx==-2) {
                    system("cls");
                    cout<<"No Customer Account created yet!";
                    m=0;
                    delay(2000);
                }


            }


            break;

        case 4:

            char ap[9];
            strcpy(ap,FreshApplication());

            if(strcmp(ap,"null")!=0)
            {
                gotoxy(20,18);
                cout<<"Application submitted for verification succesfully!"<<endl;
                gotoxy(20,19);
                cout<<"Application ID is:";
                puts(ap);
                delay(2500);
            }
            else if(strcmp(ap,"null")==0) {
                delay(500);
            } else {
                cout<<"Something went wrong!:(";
                delay(2000);
            }
            break;

        case 5:

            checkApplciationStatus();
            break;

        case 6:
            system("cls");
            gotoxy(24,1);
            cout<<"*** GOTHAM NATIONAL BANK ***";
            gotoxy(17,2);
            cout<<"72 Faxcol Road, Gotham City, New Jersey 12345";
            gotoxy(26,8);
            gotoxy(4,7);
            cout<<"ABOUT US";
            gotoxy(4,8);
            cout<<"--------";
            gotoxy(4,10);
            cout<<"Gotham National Bank welcomes you to explore the world of premier bank in";
            gotoxy(4,11);
            cout<<"the US.The Bank is actively involved since 1973 in non-profit activity" ;
            gotoxy(4,12);
            cout<<"Community Services Banking. All our branches and administrative offices";
            gotoxy(4,13);
            cout<<"throughout the country sponsor and participate in large number of welfare";
            gotoxy(4,14);
            cout<<"activities and social causes. Our business is more than banking because";
            gotoxy(4,15);
            cout<<"we touch the lives of people anywhere in many ways.";


            gotoxy(4,19);
            cout<<"BRANCH INFO";
            gotoxy(4,20);
            cout<<"-----------";
            gotoxy(4,22);
            cout<<">> Branch Name : Gotham City Branch";
            gotoxy(4,24);
            cout<<">> Branch Code : GNNB1234";
            gotoxy(4,26);
            cout<<">> IFSC Code : 995450992390GNNB1234";
            gotoxy(4,28);
            cout<<">> Email : gothambankadmin123@gmail.com";
            gotoxy(4,30);
            cout<<">> Phone :  (0321) 234-33-34\n";
            cout<<"\t\t(0321) 236-78-95";

            getche();
            break;



        case 7:
            FLAG=0;
            break;


        default :
            system("cls");
            cout<<"Wrong input!";
            delay(1000);
            break;

        }

    }
    system("cls");
    gotoxy(18,10);
    cout<<"Press any key to exit!!";
    getche();
    return 0;
}
