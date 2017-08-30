#include<iostream>

using namespace std;

class Singleton
{
    public:
        static Singleton* getInstance()
        {
            if(m_instance==NULL)
                m_instance=new Singleton();
            return m_instance;
        }
        static void destroyInstance()
        {
            if(m_instance!=NULL)
            {
                delete m_instance;
                m_instance=NULL;
            }
        }

        //�������������һ������ʵ��
        int getTest()
        {
            return m_Test;
        }
    private:
        Singleton(){m_Test=10;}
        static Singleton *m_instance;
        int m_Test;
};


Singleton* Singleton::m_instance=NULL;

int main()
{
    Singleton *singletonObj=Singleton::getInstance();
    cout<<singletonObj->getTest()<<endl;

    Singleton::destroyInstance();
    return 0;
}
