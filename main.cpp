#include<iostream>
#include<fstream>//files
#include<stdio.h>//input ouput operations
#include<stdlib.h>//for mermoy allocation

using namespace std;


class bookshop{
    public:

    void controlpanel();
    void addbook();
    void showbook();
    void checkbook();
    void updatebook();
    void deletebook();
};

void bookshop :: controlpanel()
{
    system("cls");//used for clear the screen in mingw gnu
    cout<<"\n\n\t\t\t CONTROL PANEL";
    cout<<"\n\n1. ADD BOOK";
    cout<<"\n2. DISPLAY BOOKS";
    cout<<"\n3. CHECK PARTICULAR BOOK";
    cout<<"\n4. UPDATE BOOK";
    cout<<"\n5. DELETE BOOK";
    cout<<"\n6. EXIT";
}

//function to add book
void bookshop:: addbook(){
    system("cls");
    fstream file;
    int nbook;
    string bname,aname,bid;
    cout<<"\n\n\t\t\tADD BOOKS";
    cout<<"\n\nBOOK ID : ";
    cin>>bid;
    cout<<"BOOK NAME : " <<endl;
    cin>>bname;
    cout<<"AUTHER NAME : "<<endl;
    cin>>aname;
    cout<<"Year of Book : "<<endl;
    cin>>nbook;


file.open("D:/book.txt", ios::out | ios::app);
file <<" " <<bid<<" "<<bname<<" "<<aname<<" "<<nbook<<endl;
file.close();

}

//display the book
void bookshop :: showbook()
{

system("cls");
fstream file;
int nobook;
string bname,aname,bid;


}


int main()
{
   
    bookShopRecord();

    return 0;
}
