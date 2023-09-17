#include <iostream>

static bool running = true;

int main()
{
    int i = 0;
    while (running)
    {

        std::cout << "yoo : " << i << std::endl;

        i++;
    }
}