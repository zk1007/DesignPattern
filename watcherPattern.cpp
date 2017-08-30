#include<iostream>
#include<list>

using namespace std;

//观察者类（抽象基类）
class Observer
{
    public:
        virtual void Update(int)=0;
};


class Subject
{
    public:
        virtual void Attach(Observer *)=0;
        virtual void Detach(Observer *)=0;
        virtual void Notify()=0;
};

class ConcreteObserver: public Observer
{
    public:
        ConcreteObserver(Subject *pSubject): m_pSubject(pSubject)
        {

        }

        void Update(int value)
        {
            cout<<"ConcreteObserver get the update.New State："<<value<<endl;
        }
    private:
        Subject *m_pSubject;
};

class ConcreteObserver2: public Observer
{
    public:
        ConcreteObserver2(Subject *pSubject): m_pSubject(pSubject)
        {

        }

        void Update(int value)
        {
            cout<<"ConcreteObserver get the update New State："<<value<<endl;
        }
    private:
        Subject *m_pSubject;
};

class ConcreteSubject:public Subject
{
    public:
        void Attach(Observer *pObserver);
        void Detach(Observer *pObserver);
        void Notify();

        void SetState(int state)
        {
            m_iState=state;
        }
    private:
        std::list<Observer *>m_ObserverList;
        int m_iState;
};

void ConcreteSubject::Attach(Observer *pObserver)
{
    m_ObserverList.push_back(pObserver);
}

void ConcreteSubject::Detach(Observer *pObserver)
{
    m_ObserverList.remove(pObserver);
}

void ConcreteSubject::Notify()
{
    std::list<Observer*>::iterator it=m_ObserverList.begin();
    while(it!=m_ObserverList.end())
    {
        (*it)->Update(m_iState);
        ++it;
    }
}

int main()
{
    //创建目标对象
    ConcreteSubject *pSubject=new ConcreteSubject();

    //创建观察者对象
    Observer *pObserver=new ConcreteObserver(pSubject);
    Observer *pObserver2=new ConcreteObserver2(pSubject);

    //注册观察者对象
    pSubject->Attach(pObserver);
    pSubject->Attach(pObserver2);

    //改变这个状态
    pSubject->SetState(2);

    //通知观察者对象
    pSubject->Notify();

    //删除观察者对象
    pSubject->Detach(pObserver);

    pSubject->SetState(3);
    pSubject->Notify();

    delete pObserver;
    pObserver=NULL;

    delete pObserver2;
    pObserver2=NULL;

    delete pSubject;
    delete pSubject;

    return 0;

}
