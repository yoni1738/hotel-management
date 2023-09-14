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
  float price;
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
  };
int main(){

}
