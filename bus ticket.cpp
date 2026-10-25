#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class bus
{
    string name,name_of_pass[10];
    int n,age[10],v;
    int no_of_pass;
    
    public:

    bus()
    {
        cout<<"=================================="<<endl;
        cout<<"     Welcome To Arya Services     "<<endl;
        cout<<"=================================="<<endl;
    }



    void design()
    {
        int n,m,i,j,x,y,d=0;

        ifstream s("number_of_pass.txt");
            s>>x;
            s.close();

        n=10-x;
        y=11;
        m=y-n;
        cout<<"--------"<<endl;
    
    
        for(i=0;i<11;i++)
        {
            for(j=0;j<8;j++)
            {
                if((y-n)%2!=0)
                {
                    if(j==2 && i==(y-n))
                    {
                        cout<<"A";
                        d=1;
                    }

                    else if(j==5 && i==(y-n))
                    {
                        cout<<"A";
                        d=1;
                    }
                    else if(j==0 || j==7)
                    {
                        cout<<"|";
                    }
                    else if((j==2 || j==5) && i%2!=0)
                    {
                        cout<<"N";
                    }
                    else
                    {
                        cout<<" ";
                    }
                }
                else
                {
            
                    if(i==m-1 && j==2)
                    {
                        cout<<"N";
                    }
                    else if(j==2 && i==(y-n)-1)
                    {
                        cout<<"A";
                        d=1;
                    }

                    else if(j==5 && i==(y-n)-1)
                    {
                        cout<<"A";
                        d=1;
                    }
                    else if(j==0 || j==7)
                    {
                        cout<<"|";
                    }
                    else if((j==2 || j==5) && i%2!=0)
                    {
                        cout<<"N";
                    }
                    else
                    {
                        cout<<" ";
                    }
                }    
            }
            if(d==1)
            {
                y=y+2;
                d=0;
            }
            cout<<endl;
        }
        cout<<"--------";
    }


    

    void input()
    {
        int j;

        ifstream s("number_of_pass.txt");
        s>>j;
        s.close();

        v=j+1;


        cout<<"\nEnter number of passenger : ";
        cin>>n;

        if(n>10-j)
        {
            cout<<"\n\n**********************************"<<endl;
            cout<<"****** set are not avilable. *****"<<endl;
            cout<<"**********************************\n"<<endl;
            return;
        }

        else
        {
            j=j+n;
            cout<<"Enter name & age of all passenger:\n";
            for(int i=0;i<n;i++)
            {
                cout<<"Name : "<<i+1<<".";
                cin>>name_of_pass[i];
                cout<<"Age : ";
                cin>>age[i];
            }
            ofstream s1("number_of_pass.txt");
            s1<<j;
            s1.close();
        }
        ticket();
    }

    void ticket()
    {
        
        string s = "TICKET.txt";
        ofstream s2(s);
        s2<<"======================================"<<endl;
        s2<<"JAIPUR    ->      TO    ->       DELHI"<<endl;
        s2<<"SR.|NAME    | AGE | SET NUMBER|AMOUNT"<<endl;
        for(int i=0;i<n;i++)
        {
            s2<<1<<".  "<<name_of_pass[i]<<"      "<<age[i]<<"        "<<v+i<<"       "<<650<<endl;
        }
        s2<<"______________________________________"<<endl;
        s2<<"                TOTAL AMOUNT : "<<n*650<<endl;
        s2<<"______________________________________"<<endl;
        s2<<"              ARYA BUSES              "<<endl;
        s2<<"======================================"<<endl;
    }
};

int main()
{
    bus s;
    s.design();
    s.input();
}

