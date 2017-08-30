#include<iostream>

using namespace std;

typedef enum productType
{
  typeA,
  typeB,
  typeC
}PRODUCTTYPE;

//��Ʒ�ࣨ������ࣩ
class Product
{
    public:
        virtual void show()=0;
};

//��ƷA
class ProductA:public Product
{
    public:
        void show()
        {
            cout<<"product A..."<<endl;
        }
};

//��ƷB
class ProductB:public Product
{
    public:
        void show()
        {
            cout<<"product B..."<<endl;
        }
};

//��ƷC
class ProductC:public Product
{
    public:
        void show()
        {
            cout<<"product C..."<<endl;
        }
};

//������
class Factory
{
    public:
        virtual Product* createProduct()=0;
};

class FactoryA:public Factory
{
    public:
        Product* createProduct()
        {
            return new ProductA();
        }
};

class FactoryB:public Factory
{
    public:
        Product* createProduct()
        {
            return new ProductB();
        }
};

int main()
{
    FactoryA *factoryA=new FactoryA();
    Product *productA=factoryA->createProduct();
    if(productA!=NULL)
        productA->show();

    FactoryB *factoryB=new FactoryB();
    Product *productB=factoryB->createProduct();
    if(productB!=NULL)
        productB->show();

    //����A
    delete productA;
    productA=NULL;

    //����B
    delete productB;
    productB=NULL;

    delete factoryA;
    factoryA=NULL;

    delete factoryB;
    factoryB=NULL;

    return 0;
}
