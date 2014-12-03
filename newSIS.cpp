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
    void readFromFile(string USN,ifstream& io);


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
void student::readFromFile(string USN,ifstream& io)
    {
        while(io)
        {
            io>>name;
            io>>usn;
            if(usn==USN)
            {
                string s1; int n;
                cout<<"\nname: "<<name;
                cout<<"\nusn: "<<usn<<"\n";

                cout<<"marks\n";
                for(int i=0;i<3;i++)
                {
                   io>>s1;
                    io>>n;

                    cout<<s1<<":\t"<<n;
                    cout<<"\n";
                }

                cout<<"attendance\n";
                for(int i=0;i<3;i++)
                {
                    io>>s1;
                    io>>n;

                    cout<<s1<<":\t"<<n;
                    cout<<"\n";
                }
                io.close();
                return;
            }
            else
            {
                string str;
                int i=0,x;
                while(i<6)
                {
                    io>>str;
                    io>>x;
                    ++i;
                }
            }
        }


        cout<<"\nNo such student\n";
        io.close();
    }

int student::countAtt;
vector<student> s;
vector<student>::reverse_iterator rit;

//void student::attend(ifstream& io,ofstream& of,string sub)
//{
//
//}

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
                ob.readFromFile(USN,io);

                break;}
//        case 2: cout<<"\n1.EC\n2.MATHS\n3.OOPS\n";
//                cin>>ch2;
//                cout<<"\n1.Attendance\n2.Marks\n";
//                cin>>ch3;
//                switch(ch2)
//                {
//                    case 1: sub="EC";
//                            switch(ch3)
//                            {
//                                case 1: attend(sub); break;
//                                //case 2: mark(sub); break;
//                            }
//                            break;
//                     case 2: sub="MATHS";
//                            switch(ch3)
//                            {
//                                case 1: attend(sub); break;
//                                //case 2: mark(sub); break;
//                            }
//                            break;
//                     case 3: sub="OOPS";
//                            switch(ch3)
//                            {
//                                case 1: attend(sub); break;
//                               // case 2: mark(sub); break;
//                            }
//                            break;
//                }
//                break;
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

