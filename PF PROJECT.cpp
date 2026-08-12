#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
void registercomplaint();
void viewcomplaint();
void searchcomplaint();
void updatecomplaint();
void deletecomplaint();
int main()
    {
    int choice;
    do
    {
        cout<<"****!!! CYBER CRIME COMPLAINT REGISTERATION SYSTEM !!!*****"<<endl;
        cout<<"!!PRESS 1 FOR REGISTER COMPLAINT!!"<<endl;
        cout<<"!!PRESS 2 FOR VIEW COMPLAINT!!"<<endl;
        cout<<"!!PRESS 3 FOR SEARCH COMPLAINT!!"<<endl;
        cout<<"!!PRESS 4 FOR UPDATE COMPLAINT!!"<<endl;
        cout<<"!!PRESS 5 FOR DELETE COMPLAINT!!"<<endl;
        cout<<"*PRESS 6 FOR EXIT*"<<endl;
        cout<<"ENTER CHOICE:"<<endl;
        cin>>choice;
        switch(choice)
        {
                      case 1:
                            registercomplaint();
                            break;
                      case 2:
                           viewcomplaint();
                           break;
                      case 3:
                           searchcomplaint();
                           break;
                      case 4:
                           updatecomplaint();
                           break;
                      case 5:
                           deletecomplaint();
                           break;
                      case 6:
                           cout<<"EXIT";
                           break;
                           default:
                                   cout<<"INVALID CHOICE";
                                   }
                                   }while(choice!=6);
                                   return 0;
}
                                
void registercomplaint()
{
     ofstream fout;
     fout.open("complaint.txt",ios::app);
     string name;
     string cnic;
     string phone;
     string city;
     string crime_type;
     string detail;
     cout<<"ENTER NAME: "<<endl;
     cin>>name;
     cout<<"ENTER CNIC: "<<endl;
     cin>>cnic;
     cout<<"ENTER PHONE: "<<endl;
     cin>>phone;
     cout<<"ENTER CITY: "<<endl;
     cin>>city;
     cout<<"ENTER CRIME_TYPE: "<<endl;
     cin>>crime_type;
     cout<<"ENTER DETAL: "<<endl;
     cin>>detail;
     cout<<"\nComplaint Registered Successfully\n";
    fout<<"Name: "<<name<<endl;
    fout<<"CNIC: "<<cnic<<endl;
    fout<<"Phone: "<<phone<<endl;
    fout<<"City: "<<city<<endl;
    fout<<"Crime_Type: "<<crime_type<<endl;
    fout<<"Complaint: "<<detail<<endl;
    fout<<"-----------------------"<<endl;


    fout.close();

    
}



void viewcomplaint()
{
    ifstream fin;

    fin.open("complaint.txt");


    string line;
    string cnic;
       cout<<"ENTER CNIC"<<endl;
       cin>>cnic;

    while(getline(fin,line))
    {
    	if(line.find(cnic)!=string::npos)
    	{
    		cout<<line<<endl;
		}
        
    }


    fin.close();
}



void searchcomplaint()
{
    ifstream fin;

    fin.open("complaint.txt");


    string search;
    string line;

    bool found=false;


    cout<<"Enter  CNIC to  Search: ";
    cin>>search;


    while(getline(fin,line))
    {
        if(line.find(search)!=string::npos)
        {
            found=true;
            cout<<"\nComplaint Found\n";
            cout<<line<<endl;
        }
    }


    if(found==false)
    {
        cout<<"Complaint Not Found"<<endl;
    }



    fin.close();
}
     void updatecomplaint()
{
    ifstream fin("complaint.txt");
    ofstream fout("temp.txt");

    string search;
    string line;
    string update;

    cout<<"Enter CNIC to update: "<<endl;
    cin>>search;

    bool found = false;

    while(getline(fin,line))
    {
        if(line.find(search) != string::npos)
        {
            found = true;

            cout<<"Complaint Found"<<endl;
            cout<<"Enter new complaint details: "<<endl;
            cin.ignore();
            getline(cin, update);

            fout<<"Updated Complaint: "<<update<<endl;
        }
        else
        {
            fout<<line<<endl;
        }
    }

    fin.close();
    fout.close();


    if(found == true)
    {
        remove("complaint.txt");
        rename("temp.txt","complaint.txt");

        cout<<"Complaint Updated Successfully"<<endl;
    }
    else
    {
        cout<<"Complaint Not Found"<<endl;
    }
}
void deletecomplaint()
{
    ifstream fin("complaint.txt");
    ofstream fout("temp.txt");

    string search;
    string line;

    bool found = false;

    cout<<"Enter CNIC to delete complaint: "<<endl;
    cin>>search;


    while(getline(fin,line))
    {
        if(line.find(search) != string::npos)
        {
            found = true;
            cout<<"Complaint Deleted"<<endl;
            continue;
        }
        else
        {
            fout<<line<<endl;
        }
    }

    fin.close();
    fout.close();


    if(found == true)
    {
        remove("complaint.txt");
        rename("temp.txt","complaint.txt");

        cout<<"Complaint Deleted Successfully"<<endl;
    }
    else
    {
        cout<<"Complaint Not Found"<<endl;
}
}
