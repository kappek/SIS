#include<fstream>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;
class student
{
    static int countAtt;
    string name;
    string usn;
    map<string, int> marks;
    map<string, int> attendance;
    map<string, int>::iterator mit;

public:
     student(int x)
    {
        cout<<"enter name: ";
        cin>>name;
        cout<<"\nenter usn: ";
        cin>>usn;
        attendance.insert(pair<string,int>("EC",0));
        attendance.insert(pair<string,int>("OOPS",0));
        attendance.insert(pair<string,int>("MATHS",0));
        marks.insert(pair<string,int>("EC",0));
        marks.insert(pair<string,int>("OOPS",0));
        marks.insert(pair<string,int>("MATHS",0));
    }
    student(){}
    void writeToFile(ofstream& of);
    void readFromFile(ifstream& io);
    void displayAll(string USN, ifstream& of);
    void display();
    friend void attend(string sub);
    friend void rewrite(ofstream& of);
    friend void mark(string sub);

};
void student::writeToFile(ofstream& of)
{
    of<<name<<"\n"<<usn<<"\n";
    mit=marks.begin();
    for(;mit!=marks.end();++mit)
        of<<mit->first<<"\n"<<mit->second<<"\n";
    mit=attendance.begin();
    for(;mit!=attendance.end();++mit)
        of<<mit->first<<"\n"<<mit->second<<"\n";

    of.close();
}
void student::readFromFile(ifstream& io)
{


        io>>name;
        io>>usn;
        string s1; int n;
        for(int i=0;i<3;i++)
                {
                    io>>s1;
                    io>>n;
                    attendance.insert(pair<string,int>(s1,n));

                }
        for(int i=0;i<3;i++)
                {
                    io>>s1;
                    io>>n;
                    marks.insert(pair<string,int>(s1,n));

                }


}
void student::display()
{
    cout<<"\nname: "<<name;
                cout<<"\nusn: "<<usn<<"\n";

                cout<<"attendance\n";
                mit=attendance.begin();
                for(;mit!=attendance.end();++mit)
                {
                     cout<<mit->first<<":\t"<<mit->second;
                     cout<<"\n";
                }

                cout<<"marks\n";
                 mit=marks.begin();
                for(;mit!=marks.end();++mit)
                {
                     cout<<mit->first<<":\t"<<mit->second;
                     cout<<"\n";
                }
}
void student::displayAll(string USN,ifstream& io)
    {

        while(!(io.eof()))
        {
            readFromFile(io);
            if(io.eof())
                break;
            //display();
            if(usn==USN)
            {
                display();
                io.close();
                return;
            }

        }


        cout<<"\nNo such student\n";
        io.close();
    }

int student::countAtt;
vector<student> s;
vector<student>::reverse_iterator rit;
vector<student> atte;
vector<student>:: iterator ait;
void rewrite()
{cout<<"\nREWRITING\n";

    ait=atte.begin();
    for(;ait!=atte.end();++ait)
    {
        ofstream of("student.dat",ios::binary|ios::app);
        ait->writeToFile(of);

    }

}
void attend(string sub)
{
    ifstream io("student.dat",ios::binary);
    char att;

    while(!(io.eof()))
    {
        student ob;
        char att;
        ob.readFromFile(io);
        if(io.eof())
            break;
        cout<<"\na:absent,p:present\n";

                cout<<"\n"<<ob.usn<<":\t";
                cin>>att;
                if(att=='p')
                ++((ob.attendance.find(sub))->second);

        atte.push_back(ob);


    }
    io.close();
    //rewrite
    ofstream of("student.dat",ios::binary);
    of.close();
    rewrite();


}
void mark(string sub)
{
    int m;
    ifstream io("student.dat",ios::binary);

    while(!(io.eof()))
    {
        student ob;
        ob.readFromFile(io);
        if(io.eof())
            break;
        cout<<"\nenter marks\n";

                cout<<"\n"<<ob.usn<<":\t";
                cin>>m;
                ob.marks[sub]=m;
        atte.push_back(ob);


    }
    io.close();
    //rewrite
    ofstream of("student.dat",ios::binary);
    of.close();
    rewrite();


}

int main()
{

    int ch1,ch2,ch3,ch4;
    string sub,USN;

    while(1)
    { cout<<"1.STUDENT LOGIN\n2.TEACHER LOGIN\n3.Admin\n4.exit\n";

    cin>>ch1;


    switch(ch1)
    {
        case 1: {cout<<"\n Enter USN:\n";
                cin>>USN;
                ifstream io("student.dat",ios::binary);
                student ob;
                ob.displayAll(USN,io);

                break;}
        case 2: cout<<"\n1.EC\n2.MATHS\n3.OOPS\n";
                cin>>ch2;
                cout<<"\n1.Attendance\n2.Marks\n";
                cin>>ch3;
                switch(ch2)
                {
                    case 1: sub="EC";
                            switch(ch3)
                            {
                                case 1:attend(sub); break;
                                case 2: mark(sub); break;
                            }
                            break;
                     case 2: sub="MATHS";
                            switch(ch3)
                            {
                                case 1: attend(sub); break;
                                case 2: mark(sub); break;
                            }
                            break;
                     case 3: sub="OOPS";
                            switch(ch3)
                            {
                                case 1: attend(sub); break;
                                case 2: mark(sub); break;
                            }
                            break;
                }
                break;
            case 3: cout<<"1.enter\n2.delete\n";
                    cin>>ch4;
                    switch(ch4)
                    {
                        case 1:{
                                s.push_back(student(1));
                                rit=s.rbegin();
                                ofstream of("student.dat",ios::binary|ios::app);
                                rit->writeToFile(of);

                                break;}
                        //case 2: Delete();
                                //break;
                    }
                    break;
            case 4: exit(0);
}
    }
    return 0;
}

