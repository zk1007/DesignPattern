#include<iostream>

using namespace std;

typedef enum productType
{
  typeA,
  typeB,
  typeC
}PRODUCTTYPE;

//产品类（抽象基类）
class Product
{
    public:
        virtual void show()=0;
};

//产品A
class ProductA:public Product
{
    public:
        void show()
        {
            cout<<"product A..."<<endl;
        }
};

//产品B
class ProductB:public Product
{
    public:
        void show()
        {
            cout<<"product B..."<<endl;
        }
};

//产品C
class ProductC:public Product
{
    public:
        void show()
        {
            cout<<"product C..."<<endl;
        }
};

//工厂类
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

    //销毁A
    delete productA;
    productA=NULL;

    //销毁B
    delete productB;
    productB=NULL;

    delete factoryA;
    factoryA=NULL;

    delete factoryB;
    factoryB=NULL;

    return 0;
}
