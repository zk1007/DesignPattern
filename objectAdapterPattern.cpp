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
        void SpecificRequest()
        {
            cout<<"Adaptee::SpecificRequest"<<endl;
        }
};

//Adapter
class Adapter:public Target
{
    public:
        Adapter(): m_Adaptee(new Adaptee)
        {

        }
        ~Adapter()
        {
            if(m_Adaptee!=NULL)
            {
                delete m_Adaptee;
                m_Adaptee=NULL;
            }
        }

        void Request()
        {
            //Adaptee::SpecifiRequest();
            m_Adaptee->SpecificRequest();
        }
    private:
        Adaptee *m_Adaptee;
};

int main()
{
    Target *targetObj=new Adapter();
    targetObj->Request();

    delete targetObj;
    targetObj=NULL;

    return 0;
}
