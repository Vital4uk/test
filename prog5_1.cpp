//програма ні про що
//виправлені помилки аби виводила Success!
#include <iostream>
#include <stdio.h>
#include <vector>
//#include <stdexcept>

void f1 () {
    int res = 7; 
    std::vector<int> v(10); 
    v[5] = res; 
    if (v[5] == 7) {
        std::cout << "Success!\n";
    }

    std::string s = "ape";  
    if (s != "fool") {
        std::cout << "Success!\n";
    }

    int x = 4;
    double d = 5 / (x-2);
    if (d == x / 2 + 0.5) {
        std::cout << "Success!\n";
    }
}

void f2() {
    std::string s = "Success!\n"; 
    for(int i = 0; i < 10; ++i) {
        std::cout << s;
    }

    std::vector<char> v(5); 
    for(int i = 0; i < v.size(); ++i) { 
        std::cout << "Success!\n";
    }
    int x = 2000; double c = x;
    if (c == 2000) {
        std::cout << "Success!\n";
    }
}
void f3() {
    std::string s = "Success!\n"; 
    for(int i = 0; i < 6; ++i) {
        std::cout << s;
    }
    std::vector<char> v(5); 
    for(int i = 0; i < v.size(); ++i) { 
        std::cout << "Success!\n";
    }
}

void f4() {
    std::string s = "ape";  
    if (s != "fool") {
        std::cout << "Success!\n";
    }
}

void f5() {
    std::string s = "Success!\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << s;
    }
}

void error (std::string s) {
    throw std::runtime_error (s);
}

int main ()
{
    f1();
    f2();
    f3();
    f4();
    f5();

    std::cout << "Success!\n";
    std::cout << "Success!" << "\n";

    std::vector<char> v(5); 
    for(int i = 0; i < v.size(); ++i) {
        std::cout << "Success!\n";
    }

    int i = 9; 
    int j = 0; 
    while (j < 10) {
        ++j; 
        if (j < i) {
            std::cout << "Success!\n";
        }
    }

    std::string s = "ape"; 
    bool c = true; 
    if (c) {
        std::cout << "Success!\n";
    }

    if (true) {
        std::cout << "Success!\n";
    } else {
        std::cout << "Fail!\n";
    }

    try
    {
        f1();
        f2();
        f3();
        f4();
        f5();

        std::cout << "Success!\n";
        std::cout << "Success!" << "\n";

        std::vector<int> v(10); 
        v[5] = 7; 
        if (v[5] == 7) { 
            std::cout << "Success!\n";
        }

        bool c = true;
        if (c) {
            std::cout << "Success!\n";
        } else {
            std::cout << "Fail!\n";
        }

        if (true) {
            std::cout << "Success!\n";
        } else {
            std::cout << "Fail!\n";
        }

        std::string s = "ape";  
        if (s != "fool") {
            std::cout << "Success!\n";
        }

        int x = 4;
        double d = 5 / (x-2);
        if (d == x / 2 + 0.5) {
            std::cout << "Success!\n";
        }

        int i = 9; 
        int j = 0; 
        while (j < 10) {
            ++j; 
            if (j < i) {
                std::cout << "Success!\n";
            }
        }

        std::cout << "Success!\n";

        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Помилка: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Невідомий виняток!";
        return 2;
    }
}





