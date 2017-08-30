#include<iostream>
using namespace std;

//Targets
class Target
{
    public:
        virtual void Request()
        {
            cout<<"Target::Request"<<endl;
        }
};

//Adaptee
class Adaptee
{

    public:
        void SpecifiRequest()
        {
            cout<<"Adaptee::SpecifiRequest"<<endl;
        }
};

//Adapter
class Adapter:public Target,Adaptee
{
    public:
        void Request()
        {
            Adaptee::SpecifiRequest();
        }
};

int main()
{
    Target *targetObj=new Adapter();
    targetObj->Request();

    delete targetObj;
    targetObj=NULL;

    return 0;
}

