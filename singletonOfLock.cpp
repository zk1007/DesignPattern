#include<iostream>

using namespace std;

class Singleton
{
    public:
        static Singleton* getInstance()
        {
            if(m_instance==NULL)
            {

                lock();     //C++中没有直接的lock操作，请使用其他库的lock，比如boost,此处仅是为了说明
                if(m_instance==NULL)
                    m_instance=new Singleton();
                unlock();

            }
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

        //这个方法仅仅是一个操作实例
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
