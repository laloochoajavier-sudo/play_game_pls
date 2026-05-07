#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
void gotoxy(int x, int y){
    HANDLE hconsole;
    hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hconsole, coord);
}
int main(){
    int x = 10, y = 10;
    gotoxy(x, y); std::cout << "*" << std::endl;
    bool gameover = false;
    while(!gameover){
    char tecla = _getch();
    gotoxy(x,y); std::cout<<" "<<'\n';
        switch(tecla){
            case 'w': y--; break;
            case 's': y++; break;
            case 'a': x--; break;
            case 'd': x++; break;
        }
        gotoxy(x, y);std::cout << "*" << std::endl;
        Sleep(30);    
    }
    return 0;
}