
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
class student
{
    string name;
    string usn;
    map<string, int> marks;
    map<string, int> attendance;

public:
    void updateAttendance(int i, char att,string sub);

    void mark(string sub);

    void attend(string sub);

    void displayAll();

};
vector<student> s;
for(int j=0;j<3;j++)
{
    s.push_back()

}


    void student::updateAttendance(int i, char att, string sub)
    {
        map<string, int>::iterator it=s[i].attendance.begin();
        for(;it!=s[i].attendance.end();++it)
           {
              if((it->first)==sub)
            {
                if(att='p')
                    it->second=it->(second++);
            }
           }
    }

     void student::attend(string sub)
    {
        char att;
        cout<<"\na=absent , p=present\n";
        for(int i=0;i<s.size();i++)
        {
            cin>>updateAttendance(i,att,sub);
        }
    }


     void student::mark(string sub)
    {
        map<string, int>::iterator it=s[i].attendance.begin();
        for(;it!=s[i].attendance.end();++it)
          {
              if((it->first)==sub)
            {
                cout<<"\nEnter Marks\n";
                cin>>(it->second);
            }
          }
    }
   void student::displayAll()
   {

   }

int main()
{
    int ch1,USN,ch2,ch3
    string sub;
    cout<<"1.STUDENT LOGIN\n2.TEACHER LOGIN\n";
    cin>>ch1;
    switch(ch1)
    {
        case 1: cout<<"\n Enter USN:\n";
                cin>>USN;
                displayAll(USN);
                break;
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
                                case 2: mark(sub); break;
                            }
                     case 2: sub="MATHS";
                            switch(ch3)
                            {
                                case 1: attend(sub); break;
                                case 2: mark(sub); break;
                            }
                     case 3: sub="OOPS";
                            switch(ch3)
                            {
                                case 1: attend(sub); break;
                                case 2: mark(sub); break;
                            }
                }
    }
    return 0;
}
