#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Big_integer
{
protected:
    std::string data = "";
public:
    std::string get_data()
    {
        return data;
    }
    Big_integer()
    {
        std::cout << "class created" << std::endl;
    }

    Big_integer(std::string data)
    {
        this->data = data;
    }

    Big_integer(Big_integer&& other) noexcept : data(std::exchange(other.data, "")) {} // конструктор перемещения

    Big_integer(const Big_integer& other) noexcept : Big_integer(other.data) {} // конструктор копирования

    Big_integer& operator =(const Big_integer& other) // оператор копирующего присваивания
    {
        return *this = Big_integer(other);
    }

    Big_integer& operator =(Big_integer&& other) noexcept // оператор перемещающего присваивания
    {
        std::swap(data, other.data);
        return *this;
    }

    Big_integer operator +(const Big_integer& other)
    {
        std::string rez;
        std::string a = data;
        std::string b = other.data;

        int data_size = data.length();
        int other_data_size = other.data.length();

        if (other_data_size > data_size) 
        {
            rez = b;
            for (int i = 0; i < (other_data_size - data_size); ++i)
            {
                a = '0' + a;
            };
        }
        else if (other_data_size < data_size)
        {
            rez = a;
            for (int i = 0; i < (data_size - other_data_size); ++i)
            {
                b = '0' + b;
            };
        }
        else 
        { 
            rez = a; 
        };

        int rez_size = rez.length();
        bool flag = false;
        for (int i = rez_size - 1; i >= 0; --i)
        {
            rez[i] = a[i] + b[i] - 48;
            if (flag)
            {
                rez[i]++;
            };
            if (rez[i] >= 58)
            {
                rez[i] -= 10;
                rez[i - 1] = rez[i - 1] + 1; 
                flag = true;
            }
            else 
            { 
                flag = false; 
            }
        }
        return rez;
    }

    ~Big_integer() // деструктор
    {
        std::cout << "class deleted: " << this << std::endl;
    }
};

std::ostream& operator <<(std::ostream& os, Big_integer& Bi)
{
    os << Bi.get_data() << std::endl;
    return os;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    auto number1 = Big_integer("114575");
    auto number2 = Big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099
}