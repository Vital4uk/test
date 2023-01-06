#include <iostream>
 
class DateClass
{
public:
    int m_day;
    int m_month;
    int m_year;
 
    void print()
    {
        std::cout << m_day << "/" << m_month << "/" << m_year;
    }
};
 
int main()
{
    DateClass today { 12, 11, 2018 };
 
    today.m_day = 18; // используем оператор выбора членов для выбора переменной-члена m_day объекта today класса DateClass
    today.print(); // используем оператор выбора членов для вызова метода print() объекта today класса DateClass
 
    return 0;

}
