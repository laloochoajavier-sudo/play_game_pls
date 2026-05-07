#include <iostream>
#include <stdio.h>
#include <windows.h>
int main(){
HANDLE hconsole;
hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
std::cout << "*" << std::endl;
    SetConsoleCursorPosition(hconsole, (COORD){10, 5}); //la posicion del cursor en la consola
        std::cout << "*" << std::endl;// Y esta invertida para que se imprima en la posicion del cursor
    SetConsoleCursorPosition(hconsole, (COORD){5, 10});
        std::cout << "*" << std::endl;
    return 0;
}