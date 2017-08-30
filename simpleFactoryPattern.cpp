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
        Product* createProduct(PRODUCTTYPE type)
        {
            switch(type)
            {
                case typeA:
                    return new ProductA();
                case typeB:
                    return new ProductB();
                case typeC:
                    return new ProductC();
                default:
                    return NULL;
            }
        }
};

int main()
{
    //创建一个工厂对象
    Factory *factory=new Factory();

    //产品A
    Product *productA=factory->createProduct(typeA);
    if(productA!=NULL)
        productA->show();

    //产品B
    Product *productB=factory->createProduct(typeB);
    if(productB!=NULL)
        productB->show();

    //产品C
    Product *productC=factory->createProduct(typeC);
    if(productC!=NULL)
        productC->show();

    //销毁A
    delete productA;
    productA=NULL;

    //销毁B
    delete productB;
    productB=NULL;

    //销毁C
    delete productC;
    productC=NULL;

    return 0;
}
