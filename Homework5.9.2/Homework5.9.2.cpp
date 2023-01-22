// Homework5.9.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Big_integer
{
protected:
    char* data;
public:
    Big_integer()
    {
        std::cout << "class created" << std::endl;
    }

    Big_integer(char* data)
    {
        this->data = data;
    }

    Big_integer(Big_integer&& other) noexcept : data(std::exchange(other.data, nullptr)) {} // конструктор перемещения

    Big_integer(const Big_integer&& other) noexcept : Big_integer(other.data) {} // конструктор копирования

    Big_integer& operator =(const Big_integer& other) // оператор копирующего присваивания
    {
        delete &data;
    }

    Big_integer& operator =(Big_integer&& other) noexcept // оператор перемещающего присваивания
    {
        delete& data;
    }

    char operator ()(char* data)
    {
        this->data = data;
    }

    Big_integer operator +(const Big_integer& other)
    {
        return atoi(this->data) + atoi(other.data);
    }

    ~Big_integer() // деструктор
    {
        std::cout << "class deleted: " << this << std::endl;
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    Big_integer big_integer;

    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
