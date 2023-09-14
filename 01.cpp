#include<iostream>
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
  void check_in();
  void check_out();
  void showRoomInfo();
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
