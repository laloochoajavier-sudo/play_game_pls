#include <iostream>
#include <stdio.h>
#include <windows.h>
int main(){
    std::cout << "*" << std::endl;
    HANDLE hconsole;
    hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hconsole, (COORD){10, 5});
    std::cout << "*" << std::endl;
    return 0;
}