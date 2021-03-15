#include <iostream>
#include <Windows.h>
#include <sstream>

int main()
{
    char name[1024] = "";
    int length      = 0;
    DWORD modifier  = 0;
    DWORD remainder = 0;
    std::ostringstream oss;
    std::string serial = "";

    std::cout << "Enter username: ";
    std::cin >> name;

    length = strlen(name);

    for (int i = 0; i < (length - 1); i++)
    {
        if (name[i] <= 0x5A && name[i] >= 0x41)
            modifier += (name[i] + 0x2C);
        else
            modifier += name[i];
    }

    modifier += 0x29A;
    modifier *= 0x3039;
    modifier -= 0x17;
    modifier *= 0x9;

    do
    {
        remainder = modifier % 0xA;
        modifier /= 0xA;
        remainder += 0x30;

        oss << (char)remainder;
    } while (modifier);

    serial += oss.str();

    reverse(serial.begin(), serial.end());

    oss.str("");

    for (int i = 3; i < length; i++)
    {
        oss << name[i];
    }
    serial += oss.str();

    std::cout << "Serial: " << serial << std::endl;

    system("pause");
    return 0;
}