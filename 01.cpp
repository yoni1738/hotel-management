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
  int status=0;

};
class hotelmng{
private:
  int singleR=6;
  int doubleR=6;
  int familyR=6;
  room rm[18];
  int roomcount;
public:
  void check_in(){

		char choice;

		string name;

		if(singleR != 0 || doubleR != 0 || familyR != 0){

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

		if(roomtype=="Single"){

			roomcount=6-singleR;

			singleR--;

		}else if(roomtype=="Double"){

			roomcount=12-doubleR;

			doubleR--;

		}else if(roomtype=="Family"){

			roomcount=18-familyR;

			familyR--;

		}

		cout<<"\t Person name: ";

		cin>>rm[roomcount].cust.name;



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

		rm[roomcount].status=1;

		rm[roomcount].roomno = roomcount+1;

		rm[roomcount].day = rm[roomcount].cust.to_date - rm[roomcount].cust.from_date;

		show(rm[roomcount]);

		cout<<"\t\t Room checked in successfully \n";

		cout<<"\t---------------------------------------\n";

		save();

	}


void showpersonalinfo(){

		string name;

		int found=0;

		if(singleR != 6 || doubleR != 6 || familyR != 6){

			lable2:

			cout<<"\t enter customers first name (X to return): ";

			cin>>name;

			for(int i=0; i<18;i++){

				if(rm[i].status == 1 && rm[i].cust.name == name){

					found++;

					show(rm[i]);

					getch();

				}

			}

			if(name == "X" || name == "x"){

			}else if(found == 0){

				cout<<"\t there is no person found by the name "<<name<<endl;

				cout<<"\t try by another name \n";

				goto lable2;

			}

		}else{cout<<"\t Sorry there is no person in our room \n";}

	}

	void showallresurvedroom(){

		int found =0;

		system("cls");

		for(int i=0; i<18; i++){

			if(rm[i].status == 1){

					found++;

				cout<<"\t Room number: "<<rm[i].roomno<<endl;

				cout<<"\t Room type: "<<rm[i].type<<endl;

				cout<<"\t Customer First Name : "<<rm[i].cust.name<<endl;

				cout<<"\t Id Number : "<<rm[i].cust.idno<<endl;

				cout<<"\t Age: "<<rm[i].cust.age<<endl;

				cout<<"\t Sex: "<<rm[i].cust.sex<<endl;

				cout<<"\t Address: "<<rm[i].cust.address<<endl;

				cout<<"\t Phone: "<<rm[i].cust.phone<<endl;

				cout<<"\t From date: "<<rm[i].cust.from_date<<endl;

				cout<<"\t to date: "<<rm[i].cust.to_date<<endl;

				cout<<"\t price: "<<rm[i].price()<<endl;

				cout<<"\t---------------------------------------\n";

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

		if(singleR != 6 || doubleR != 6 || familyR != 6){

			lable:

			cout<<"\t Please enter room number (0 to exit): ";

			cin>>roomn;

			if (roomn>0 && roomn<=18 && rm[roomn-1].status == 1){

				show(rm[roomn-1]);

				second:

				cout<<"\t is this right(Y/N): ";

				cin>>answer;

				answer = toupper(answer);

				if(answer=='Y'){

						if(rm[roomn-1].type == "Single"){

							singleR++;

						}else if(rm[roomn-1].type == "Double"){

							doubleR++;

						}else if(rm[roomn-1].type == "Family"){

							familyR++;

						}

					rm[roomn -1] = room();

					save();

					cout<<"\t\t room checked out successfully \n";

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

			}else if(rm[roomn-1].status == 0){

				cout<<"\t this room is empty please enter a valid room number \n";

				goto lable;

			}else{}

		}else{cout<<"\t Sorry there is no person in our room \n";}

}

bool is_available(char roomtype){

		if(roomtype == 'S'){

			return bool(singleR);

		}else if(roomtype == 'D'){

			return bool(doubleR);

		}else if(roomtype == 'F'){

			return bool(familyR);

		}

}
  void check_out();
  void showallresurvedroom();
  void showpersonalinfo();
void getstatus(){
		int roomnum,i;
		ifstream infile("rooms.txt", ios::in);
		infile>>singleR>>doubleR>>familyR;
		infile.close();
		ifstream in("bookedstatus.txt", ios::in);
		while(in>>roomnum){

			i = roomnum - 1;
			rm[i].roomno=roomnum;
			rm[i].status=1;
			in>>rm[i].type;
			in>>rm[i].cust.name;
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
		ofstream outfile("rooms.txt", ios::out);
		outfile<<singleR<<"\t"<<doubleR<<"\t"<<familyR;
		outfile.close();

		ofstream out;
		out.open("bookedstatus.txt",ios::out);
		for(int i=0;i<18;i++){
			if(rm[i].status != 0){
				out<<rm[i].roomno;
				out<<"\t"<<rm[i].type;
				out<<"\t"<<rm[i].cust.name;
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
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Id Number : "<<rooms.cust.idno<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Age: "<<rooms.cust.age<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Sex: "<<rooms.cust.sex<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Address: "<<rooms.cust.address<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Phone: "<<rooms.cust.phone<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t From date: "<<rooms.cust.from_date<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t To date: "<<rooms.cust.to_date<<endl;
    cout<<setw(26)<<setiosflags(ios::left)<<"\t Price: "<<rooms.price()<<endl;
  }
  };
int main(){

}
