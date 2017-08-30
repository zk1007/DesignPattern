#include<iostream>

using namespace std;

class Singleton
{
    public:
        static Singleton* getInstance()
        {
            static Singleton m_instance;
            return &m_instance;
        }


        //�������������һ������ʵ��
        int getTest()
        {
            return ++m_Test;
        }
    private:
        Singleton(){m_Test=10;}

        int m_Test;
};

int main()
{
    Singleton *singletonObj=Singleton::getInstance();
    cout<<singletonObj->getTest()<<endl;

    singletonObj=Singleton::getInstance();
    cout<<singletonObj->getTest()<<endl;

    return 0;
}
