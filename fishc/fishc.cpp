#include <iostream>
using namespace std;

class Person
{
public:
    int* m_Age;

    Person(int age)
    {
        m_Age = new int(age); // new int 的返回值是int*
    }

    // 错误的析构函数代码
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    // 重载赋值运算符
    void operator=(Person &p)
    {
        // 编译器提供的是浅拷贝
        // m_Age = p.m_Age;

        // 应该先判断是否有属性在堆区, 如果有, 则先释放干净, 然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }

        // 深拷贝: 让自身的指针指向新开辟的空间, 其值为传入的Person的年龄
        m_Age = new int(*p.m_Age);
    }
};

void test01()
{
    Person p1(18);
    Person p2(20);

    p2 = p1;                  // 赋值操作 (p1和p2的年龄都是18岁)

    cout << "p1的年龄是: " << *p1.m_Age << endl;
    cout << "p2的年龄是: " << *p2.m_Age << endl;
}

int main()
{
    test01();
}