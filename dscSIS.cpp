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


public:
    friend void writeToFile(ofstream& of);
    friend void readFromFile(string USN,ifstream& io);
    void Attend(string sub,char att);
    friend void attend(string sub);

    student(int x)
    {
        cout<<"enter name: ";
        cin>>name;
        cout<<"\nenter usn: ";
        cin>>usn;

    }
    student(){}
    void display()
    {
        cout<<name;
        cout<<"\n"<<usn;
    }


};

int student::countAtt;
vector<student> s;
vector<student>::iterator it;




void student::Attend(string sub,char att)
{
    if(att=='p')
       attendance.insert(pair<string,int>(sub,++countAtt));
}
void writeToFile(ofstream& of)
{
    s.push_back(student(1));
    it=s.end(); --it;
    of.write((char*)&((*it).name),sizeof((*it).name));
    of.write((char*)&((*it).usn),sizeof((*it).usn));
}
void readFromFile(string USN,ifstream& io)
{

    student ob;
     io.read((char*)&((ob).name),sizeof((ob).name));
    io.read((char*)&((ob).usn),sizeof((ob).usn));
    if(io.bad())
        cout<<"bad";
    cout<<"\nname:"<<ob.name;
    cout<<"\nusn:"<<ob.usn;

}
void attend(string sub)
{
        it=s.begin();
        char att;
        cout<<"a:absent,p:present\n";
        for(;it!=s.end();it++)
        {
            cout<<"usn:";
            cout<<it->usn;
            cin>>att;
            it->Attend(sub,att);
        }
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
                ifstream io("studentRecords");
                readFromFile(USN,io);
                io.close();
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
                                case 1: attend(sub); break;
                                //case 2: mark(sub); break;
                            }
                            break;
                     case 2: sub="MATHS";
                            switch(ch3)
                            {
                                case 1: attend(sub); break;
                                //case 2: mark(sub); break;
                            }
                            break;
                     case 3: sub="OOPS";
                            switch(ch3)
                            {
                                case 1: attend(sub); break;
                               // case 2: mark(sub); break;
                            }
                            break;
                }
                break;
            case 3: cout<<"1.enter\n2.delete\n";
                    cin>>ch4;
                    switch(ch4)
                    {
                        case 1:{ofstream of("studentRecords");
                                writeToFile(of);
                                of.close();
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
