#include<iostream>

using namespace std;

typedef enum productType
{
  typeA,
  typeB,
  typeC
}PRODUCTTYPE;

//��Ʒ�ࣨ������ࣩ
class ProductA
{
    public:
        virtual void show()=0;
};

//��ƷA1
class ProductA1:public ProductA
{
    public:
        void show()
        {
            cout<<"product A1..."<<endl;
        }
};
//��ƷA2
class ProductA2:public ProductA
{
    public:
        void show()
        {
            cout<<"product A2..."<<endl;
        }
};

//��ƷB��������ࣩ
class ProductB
{
    public:
        virtual void show()=0;
};

//��ƷB1
class ProductB1:public ProductB
{
    public:
        void show()
        {
            cout<<"product B1..."<<endl;
        }
};

//��ƷB2
class ProductB2:public ProductB
{
    public:
        void show()
        {
            cout<<"product B2..."<<endl;
        }
};


//������
class Factory
{
    public:
        virtual ProductA* createProductA()=0;
        virtual ProductB* createProductB()=0;
};

class Factory1:public Factory
{
    public:
        ProductA* createProductA()
        {
            return new ProductA1();
        }
        ProductB* createProductB()
        {
            return new ProductB1();
        }
};

class Factory2:public Factory
{
    public:
        ProductA* createProductA()
        {
            return new ProductA2();
        }
        ProductB* createProductB()
        {
            return new ProductB2();
        }
};

int main()
{
    Factory1 *factory1=new Factory1();
    ProductA *productA1=factory1->createProductA();
    if(productA1!=NULL)
        productA1->show();
    ProductB *productB1=factory1->createProductB();
    if(productB1!=NULL)
        productB1->show();


    Factory2 *factory2=new Factory2();
    ProductA *productA2=factory2->createProductA();
    if(productA2!=NULL)
        productA2->show();
    ProductB *productB2=factory2->createProductB();
    if(productB2!=NULL)
        productB2->show();

    delete factory1;
    factory1=NULL;

    delete factory2;
    factory2=NULL;

    delete productA1;
    productA1=NULL;

    delete productA2;
    productA2=NULL;

    delete productB1;
    productB1=NULL;

    delete productB2;
    productB2=NULL;


    return 0;
}
