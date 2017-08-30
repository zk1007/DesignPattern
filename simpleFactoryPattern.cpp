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
    //����һ����������
    Factory *factory=new Factory();

    //��ƷA
    Product *productA=factory->createProduct(typeA);
    if(productA!=NULL)
        productA->show();

    //��ƷB
    Product *productB=factory->createProduct(typeB);
    if(productB!=NULL)
        productB->show();

    //��ƷC
    Product *productC=factory->createProduct(typeC);
    if(productC!=NULL)
        productC->show();

    //����A
    delete productA;
    productA=NULL;

    //����B
    delete productB;
    productB=NULL;

    //����C
    delete productC;
    productC=NULL;

    return 0;
}
