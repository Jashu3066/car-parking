#include<iostream>
#include<vector>
#include<map>
#include <bits/stdc++.h>
using namespace std;
class Parking_tower
{
    public:
    static int smallslot;
    static int mediumslot;
    static int largeslot;
    public:
    Parking_tower()
    {
        cout<<"Small slots available are "<<smallslot<<endl;
        cout<<"Medium slots available are "<<mediumslot<<endl;
        cout<<"Large slots available are "<<largeslot<<endl;
    }

    virtual void verifyID(string id){}
    virtual void registerID(){}
    virtual string getID(){return 0;}
    virtual char getSlotType(){return ' ';}
};

class car: public Parking_tower
{
    private:
    static vector<string> id_record;  //Record of IDs
    string id;     //Id
    char slottype;  //Small or large
    //Setters 
    void setId(string id)
    {
        this->id = id;
    }
    void setSlotType(char st){
        this->slottype = st;
    }
    //Getters
    //map<string,pair<string,char>> 
    void verifyID(string id)
    {
        if(std::find(id_record.begin(),id_record.end(),id) != id_record.end())
        {
            cout<<"Verified"<<endl;
            if(this->slottype == 'M' && mediumslot>0)
            {
                cout<<"Medium Slot available for parking"<<endl;
                mediumslot--;
            }
            else if(this->slottype == 'L' && largeslot>0)
            {
                cout<<"Large slot available for parking"<<endl;
                largeslot--;
            }
            else{
                cout<<"Slots filled"<<endl;
            }
        }
    }
    void registerID()
    {
        char st;
        cout<<"Which type of slot fits your car?"<<endl;
        cout<<"Enter 'M' for medium and 'L' for large : ";
        cin>>st;
        cout<<"st inputted is "<<st<<endl;
        this->setSlotType(st);
        string st1 = "carM" ;
        if(st =='L') st1 = "carL";
        int pp =  (2 + rand() %100) *12;
        st1 = st1 + to_string(pp);
        cout<<st1<<endl;
        this->setId( st1 ) ;
        id_record.push_back(this->id);
        cout<<"We have registered ur car for "<<st<<" with ID no. "<<this->id<<endl;
    }
    string getID(){
        return this->id;
    }
    char getSlotType(){
        return this->slottype;
    }
};


class bike: public Parking_tower
{
    private:
    static vector<string> id_record;  //Record of IDs
    string id;     //Id
    
    //Setters 
    void setId(string id)
    {
        this->id = id;
    }
    
    //Getters
    //map<string,pair<string,char>> 
    void verifyID(string id)
    {
        if(std::find(id_record.begin(),id_record.end(),id) != id_record.end())
        {
            cout<<"Verified"<<endl;
            if(smallslot>0)
            {
                cout<<"Small slot available"<<endl;
                smallslot--;
            }
            else 
            {
                cout<<"Park at any medium or large slots as per space availability"<<endl;
            }

        }
    }
    void registerID()
    {
        setId("bykS" + to_string(( 2 + rand() %100) *12));
        id_record.push_back(this->id);
        cout<<"We have registered ur bike with ID no. "<<this->id<<endl;
    }
    string getID(){
        return this->id;
    }
    
};


class bus: public Parking_tower
{
    private:
    static vector<string> id_record;  //Record of IDs
    string id;     //Id
    
    //Setters 
    void setId(string id)
    {
        this->id = id;
    }
    
    //Getters
    void verifyID(string id)
    {
        if(std::find(id_record.begin(),id_record.end(),id) != id_record.end())
        {
            cout<<"Verified"<<endl;
            if(largeslot>=5)
            {
                
                largeslot = largeslot -5;
                cout<<"large slots available"<<endl;
            }
            else 
            {
                cout<<"Slots filled"<<endl;
            }

        }
    }
    void registerID()
    {
        setId("busL" + to_string(( 2 + rand() %100) *12));
        id_record.push_back(this->id);
        cout<<"We have registered ur bus with ID no. "<<this->id<<endl;
    }
    string getID(){
        return this->id;
    }
};
class Towers4
{
    public:
    string vehicle;
    string id;
    char slottype;
    
    void parking(string id){
        Parking_tower *p;
        if(id.substr(0,3) == "car")
        {
            car c;
            p = &c;
            
            p->verifyID(this->id);
        }
        else if(id.substr(0,3) == "byk")
        {
            bike b;
            p = &b;
            
            p->verifyID(this->id);
        }
        else if(id.substr(0,3) == "bus")
        {
            bus b;
            p = &b;
            
            p->verifyID(this->id);
        }
    }
    void registerID()
    {
        string v;
        cout<<"Which type of vehicle?? :"<<endl;
        cin>>v;
        Parking_tower *p;
        if(v == "car")
        {
            car c;
            p = &c;
            p->registerID();
            this->id =  p->getID();
            this->slottype = p->getSlotType();
        }
        else if(v == "bike")
        {
            bike b;
            p = &b;
            p->registerID();
            this->id =  p->getID();
            this->slottype = 'S';
        }
        else if(v == "bus")
        {
            bus b;
            p = &b;
            p->registerID();
            this->id = p->getID();
            this->slottype = 'L';
        }
        
    }
};
int Parking_tower:: smallslot = 5;
int Parking_tower:: mediumslot = 3;
int Parking_tower:: largeslot = 2;


vector<string> car:: id_record;
vector<string> bike:: id_record;
vector<string> bus:: id_record;
int main()
{
    Towers4 u1;
    u1.registerID();
    u1.parking(u1.id);
    return 0;
}