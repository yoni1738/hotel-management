#include<iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;
class custemer{
public:
  int from_date;
  int to_date;
  string name;
  string fname;
  int age;
  char sex;
  int idno;
  string address;
  int phone;
};
class room{
public:
  string type;
  int roomno;
  custemer cust;
  int day;
  float price(){
		if(type == "Single"){
			return day*500;
		}else if(type == "Double"){
			return day*1000;
		}else if(type == "Family"){
			return day*3000;
		}
	}
  string status="free";
};
class hotelmng{
private:
  room rm[18];
  int roomcount;
public:
  void check_in(){
		char choice;
		string name;
		if(haveFreeRoom()){
			cout<<"\t what kind of room do you went\n"
				<<"\t\t A, Single bedroom \n"
				<<"\t\t B, Double bedroom \n"
				<<"\t\t C, Family standard room \n"
				<<"\t\t D, back to main menu \n";
			first:
			cout<<"\t Choose: ";
			cin>>choice;
			choice = toupper(choice);
			switch(choice){
			case 'A':
				if(is_available('S')){
					book("Single");
				}else{
					cout<<"\t\t Sorry all single bed rooms are taken \n";
				}
				break;
			case 'B':
				if(is_available('D')){
					book("Double");
				}else{
					cout<<"\t\t Sorry all double bed rooms are taken \n";
				}
				break;
			case 'C':
				if(is_available('F')){
					book("Family");
				}else{
					cout<<"\t\t Sorry all family standard rooms are taken \n";
				}
				break;
			case 'D':
				break;
			default:
				cout<<"\t\t Please inter a valid choice \n";
				goto first;
				break;
			}
		}else{cout<<"\t Sorry all rooms are reserver \n";}
}
void book(string roomtype){
		char answer;

		cout<<"\t Person name: ";
		cin>>rm[roomcount].cust.name;

		cout<<"\t Person second Name: ";
		cin>>rm[roomcount].cust.fname;

		cout<<"\t Id number: ";
		cin>>rm[roomcount].cust.idno;

		cout<<"\t Enter persons sex: ";
		cin>>rm[roomcount].cust.sex;

		cout<<"\t Persons age: ";
		cin>>rm[roomcount].cust.age;

		cout<<"\t Enter Address: ";
		cin>>rm[roomcount].cust.address;

		cout<<"\t Enter Phone: ";
		cin>>rm[roomcount].cust.phone;

		cout<<"\t Enter From Date: ";
		cin>>rm[roomcount].cust.from_date;

		cout<<"\t Enter to  Date: ";
		cin>>rm[roomcount].cust.to_date;
	
		rm[roomcount].type=roomtype;
		rm[roomcount].status="taken";
		rm[roomcount].roomno = roomcount+1;
		rm[roomcount].day = rm[roomcount].cust.to_date - rm[roomcount].cust.from_date;
		show(rm[roomcount]);
		third:
		cout<<"\t Is this right(Y/N): ";
		cin>>answer;
		answer = toupper(answer);
		if(answer=='Y'){
			cout<<"\t\t Room checked in successfully \n";
			cout<<"\t---------------------------------------\n";
			save();
		}else if(answer == 'N'){
			rm[roomcount] = room();
			system("cls");
			cout<<"\t\t Please enter again \n";
			check_in();
		}else{
			cout<<"\t Please enter only (Y/N) \n";
			goto third;
		}
	}
void showpersonalinfo(){
		string name;
		string fname;
		int found=0;
		if(haveTakenRoom()){
			lable2:
			cout<<"\t Enter customers first name (X to return): ";
			cin>>name;
			cout<<"\t Enter customers second name : ";
			cin>>fname;
			for(int i=0; i<18;i++){
				if(rm[i].status == "taken" && rm[i].cust.name == name && rm[i].cust.fname == fname){
					found++;
					show(rm[i]);
					getch();
				}
			}
			if(name == "X" || name == "x"){
			}else if(found == 0){
				cout<<"\t there is no person found by the name "<<name<<" "<<fname<<endl;
				cout<<"\t try by another name \n";
				goto lable2;
			}
		}else{cout<<"\t Sorry there is no person in our room \n";}
	}
	void showallresurvedroom(){
		int found =0;
		system("cls");
		for(int i=0; i<18; i++){
			if(rm[i].status == "taken"){
					found++;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Room number: "<<rm[i].roomno<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Room type: "<<rm[i].type<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Customer First Name : "<<rm[i].cust.name<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Customer Second Name : "<<rm[i].cust.fname<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Id Number : "<<rm[i].cust.idno<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Age: "<<rm[i].cust.age<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Sex: "<<rm[i].cust.sex<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Address: "<<rm[i].cust.address<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Phone: "<<rm[i].cust.phone<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t From date: "<<rm[i].cust.from_date<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t To date: "<<rm[i].cust.to_date<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t Price: "<<rm[i].price()<<endl;
				cout<<setw(26)<<setiosflags(ios::left)<<"\t---------------------------------------\n";
				getch();
			}
		}
		if(found == 0){
			cout<<"\t there is no reserved room all rooms are free \n";
			getch();
		}
	}
void check_out(){
		int roomn;
		char answer;
		if(haveTakenRoom()){
			lable:
			cout<<"\t Please enter room number (0 to exit): ";
			cin>>roomn;
			if (roomn>0 && roomn<=18 && rm[roomn-1].status == "taken"){
				show(rm[roomn-1]);
				second:
				cout<<"\t is this right(Y/N): ";
				cin>>answer;
				answer = toupper(answer);
				if(answer=='Y'){
					rm[roomn -1].status = "needClean";
					save();
					cout<<"\t\t Room checked out successfully \n";
					cout<<"\t---------------------------------------\n";
				}else if(answer == 'N'){
					cout<<"\t Sorry we have only this information by room number "<<roomn<<"\n";
					cout<<"\t or you can try by changing room number \n";
					goto lable;
				}else{
					cout<<"\t please enter only (Y/N) \n";
					goto second;
				}
			}else if(roomn>18 || roomn<0){
				cout<<"\t Please enter a valid room number \n";
				goto lable;
			}else if(rm[roomn-1].status == "free" || rm[roomn-1].status == "needClean"){
				cout<<"\t this room is empty please enter a valid room number \n";
				goto lable;
			}
		}else{cout<<"\t Sorry there is no person in our room \n";}
}
bool is_available(char roomtype){
		if(roomtype == 'S'){
				for(int i = 0;i<6; i++){
					if(rm[i].status == "free"){
						roomcount = i;
						return true;
					}
				}
			return false;
		}else if(roomtype == 'D'){
			for(int i = 6;i<12; i++){
					if(rm[i].status == "free"){
						roomcount = i;
						return true;
					}
				}
			return false;
		}else if(roomtype == 'F'){
			for(int i = 12;i<18; i++){
					if(rm[i].status == "free"){
						roomcount = i;
						return true;
					}
				}
			return false;
		}
	}
void getstatus(){
		int roomnum,i;
		ifstream in("bookedstatus.txt", ios::in);
		while(in>>roomnum){
			i = roomnum - 1;
			rm[i].roomno=roomnum;
			in>>rm[i].status;
			in>>rm[i].type;
			in>>rm[i].cust.name;
			in>>rm[i].cust.fname;
			in>>rm[i].cust.idno;
			in>>rm[i].cust.age;
			in>>rm[i].cust.sex;
			in>>rm[i].cust.address;
			in>>rm[i].cust.phone;
			in>>rm[i].cust.from_date;
			in>>rm[i].cust.to_date;
			rm[i].day = rm[i].cust.to_date - rm[i].cust.from_date;
		}
		in.close();
	}
	void save(){
		ofstream out;
		out.open("bookedstatus.txt",ios::out);
		for(int i=0;i<18;i++){
			if(rm[i].status != "free"){
				out<<rm[i].roomno;
				out<<"\t"<<rm[i].status;
				out<<"\t"<<rm[i].type;
				out<<"\t"<<rm[i].cust.name;
				out<<"\t"<<rm[i].cust.fname;
				out<<"\t"<<rm[i].cust.idno;
				out<<"\t"<<rm[i].cust.age;
				out<<"\t"<<rm[i].cust.sex;
				out<<"\t"<<rm[i].cust.address;
				out<<"\t"<<rm[i].cust.phone;
				out<<"\t"<<rm[i].cust.from_date;
				out<<"\t"<<rm[i].cust.to_date<<endl;
			}
		}
		out.close();
	}
void show(room rooms){
    system("cls");
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Room number: "<<rooms.roomno<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Room type: "<<rooms.type<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Customer First Name : "<<rooms.cust.name<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Customer Second Name : "<<rooms.cust.fname<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Id Number : "<<rooms.cust.idno<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Age: "<<rooms.cust.age<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Sex: "<<rooms.cust.sex<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Address: "<<rooms.cust.address<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Phone: "<<rooms.cust.phone<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t From date: "<<rooms.cust.from_date<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t To date: "<<rooms.cust.to_date<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Price: "<<rooms.price()<<endl;
  }
void available(){
		cout<<setw(42)<<setiosflags(ios::left)<<"\t Available single room numbers: ";
		for(int i = 0; i<6;i++){
			if(rm[i].status == "free"){
				cout<<(i+1);
				if(i!=5){
					cout<<", ";
				}
			}
		}
		cout<<endl;
		cout<<setw(42)<<setiosflags(ios::left)<<"\t Available double room numbers: ";
		for(int i = 6; i<12;i++){
			if(rm[i].status == "free"){
				cout<<(i+1);
				if(i!=11){
					cout<<", ";
				}
			}
		}
		cout<<endl;
		cout<<setw(42)<<setiosflags(ios::left)<<"\t Available family standard room numbers: ";
		for(int i = 12; i<18;i++){
			if(rm[i].status == "free"){
				cout<<(i+1);
				if(i!=17){
					cout<<", ";
				}
			}
		}
		cout<<endl;
	}
void managerSide(){
		int roomno,j=0;
		while(true){
			cout<<"\t\t Rooms recently has been taken and need to be cleaned \n";
			for(int i=0; i<18; i++){
				if(rm[i].status == "needClean"){
					cout<<"\t\t\t room number: "<<(i+1)<<endl;
					j++;
				}
			}
			if(j==0){
				system("cls");
				cout<<"\t\t there is no room needs to clean \n";
				getch();
				break;
			}
			cout<<"\t\t Add Room number to clean list (0 to exit): ";
			cin>>roomno;
			if(roomno==0){
				break;
			}
			if(roomno>0 && roomno<=18){
				if(rm[roomno-1].status == "needClean"){
					rm[roomno-1].status = "free";
					save();
					j=0;
					cout<<"\t\t Room number "<<roomno<<" Successfully Added to free rooms\n";
					getch();
					system("cls");
				}else{
					system("cls");
					cout<<"\t\t Please enter a valid room number \n";
				}
			}else{
				system("cls");
				cout<<"\t\t Please enter a valid room number \n";
			}
		}
	}
bool haveFreeRoom(){
		for(int i=0; i<18; i++){
			if(rm[i].status == "free"){
				return true;
			}
		}
		return false;
	}
bool haveTakenRoom(){
		for(int i=0; i<18; i++){
			if(rm[i].status == "taken"){
				return true;
			}
		}
		return false;
	}
  };
void choose(); 
int main() 
{ 
 choose(); 
 return 0; 
} 
void choose(){ 
 hotelmng hotelroom; 
 hotelroom.getstatus(); 
 char choice; 
 while(true){ 
  system("cls"); 
  cout<<"\t what kind of serviec do you went\n" 
   <<"\t\t A, room check-in \n" 
   <<"\t\t B, room check-out \n" 
   <<"\t\t C, see available room\n" 
   <<"\t\t D, to see personal information\n" 
   <<"\t\t E, show all reserved rooms\n" 
   <<"\t\t F, Manager side\n"
   <<"\t\t G, Exit\n";
   first: 
  cout<<"\t choose: "; 
  cin>>choice; 
  choice = toupper(choice); 
  switch(choice){ 
   case 'A': 
    system("cls"); 
    hotelroom.check_in(); 
    getch(); 
    break; 
   case 'B': 
    system("cls"); 
    hotelroom.check_out(); 
    getch(); 
    break; 
   case 'C': 
    system("cls"); 
    hotelroom.available(); 
    getch(); 
    break; 
   case 'D': 
    system("cls"); 
    hotelroom.showpersonalinfo(); 
    getch(); 
    break; 
   case 'E': 
    system("cls"); 
    hotelroom.showallresurvedroom(); 
    break; 
   case 'F':
	system("cls");
	hotelroom.managerSide();
	break;
    case 'G':
    exit(1); 
    break; 
   default: 
    cout<<"\t\t Please inter a valid choice \n"; 
    goto first; 
  } 
 } 
}
