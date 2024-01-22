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

//check avalablit of book in file

void bookshop::checkbook(){

    system("cls");
    fstream file;
    int nobook,count=0;
    string bid,bname,aname,bidd;

    cout<<"\n\n\n\n\t\t\tCheck"<<"Particular Book";

    file.open("D:/book.txt", ios::in);
    if(!file)
    cout<<"\n\nFile opening error!";
    else{
        cout<<"\n\nBook Id : ";
        cin>>bidd;
        file>>bid>>bname;
        file>>aname>>nobook;

        while(!file.eof()){

            if(bidd == bid){

system("cls");
cout<<"\n\n\n\t\t\t"<<"check particular book";

cout<<"\n\nBook Id : "<<bid<<endl;
cout<<"\nName : "<<bname<<endl;
cout<<"\nAuthor : "<<aname<<endl;
cout<<"\nNo. of Books : "<<nobook<<endl;
cout<<endl<<endl;
break;

            }
            file>>bid>>bname;
            file>>aname>>nobook;
        }
        system("pause");
        file.close();
        if(count == 0)
        {
            cout<<"Book ID Not Found"<<endl;
        }
    }

}

void bookshop::updatebook()
{
    system("cls");
    fstream file,file1;
    int nobook, noco,count =0;
    string bname,bna,aname,ana,bidd,bid;

    cout<<"\n\n\n\t\t\tUpdate Book Record";
    file1.open("D:/book1.txt",ios::app | ios::out);
    file.open("D:/book.txt",ios::in);

    if(!file)
    cout<<"\n\n\nFile opening error!";
    else{

        cout<<"\n\nBook ID : ";
        cin>>bid;
        file>>bidd>>bname;
        file>>aname>>nobook;



  while (!file.eof()) {

            if (bid == bidd) {

                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete a Book";
                cout << "\n\nBook is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << bidd
                      << " " << bname
                      << " " << aname
                      << " " << nobook
                      << "\n\n";
            file >> bidd >> bname;
            file >> aname >> nobook;
        }
        if (count == 0)
            cout << "\n\nBook ID "
                 << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("D:// book.txt");
    rename("D:// book1.txt",
           "D:// book.txt");
}
//function for delete the book
void bookshop::deletebook()
{
    system("cls");
    fstream file, file1;
    int nobook, noco, count = 0;
    string bname, bna, aname, ana, bidd, bid;

    cout << "\n\n\n\t\t\tDelete Book Record";
    file1.open("D:/book1.txt", ios::app | ios::out);
    file.open("D:/book.txt", ios::in);

    if (!file)
        cout << "\n\n\nFile opening error!";
    else
    {
        cout << "\n\nBook ID to be deleted: ";
        cin >> bid;
        file >> bidd >> bname;
        file >> aname >> nobook;

        while (!file.eof())
        {
            if (bid == bidd)
            {
                system("cls");
                cout << "\n\n\t\t\t\tDelete a Book";
                cout << "\n\nBook is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << bidd
                      << " " << bname
                      << " " << aname
                      << " " << nobook
                      << "\n\n";
            file >> bidd >> bname;
            file >> aname >> nobook;
        }
        if (count == 0)
            cout << "\n\nBook ID "
                 << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("D://book.txt");
    rename("D://book1.txt", "D://book.txt");
}



// Function for book shop record
void bookShopRecord()
{
    int choice;
    char x;
    bookshop b;

    while (1) {

        b.controlpanel();
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.addbook();
                cout << "\n\nWant to add"
                     << " another book? "
                        "(y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.showbook();
            break;

        case 3:
            b.checkbook();
            break;
        case 4:
            b.updatebook();
            break;

        case 5:
            b.deletebook();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}

// Driver Code
int main()
{
    // Function Call
    bookShopRecord();

    return 0;
}
