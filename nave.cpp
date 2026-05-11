#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y);
void ocultarCursor();
void pintarLimites();

class Nave{
    int x, y;
public:
    Nave(int _x, int _y): x(_x), y(_y) {}
    void pintar();
    void borrar();
    void mover();
};

void Nave::pintar(){
    gotoxy(x, y);   std::cout << "  /\\  ";
    gotoxy(x, y+1); std::cout << " /__\\ ";
    gotoxy(x, y+2); std::cout << "  ||  ";
    std::cout.flush();
}

void Nave::borrar(){
    gotoxy(x, y);   std::cout << "      ";
    gotoxy(x, y+1); std::cout << "      ";
    gotoxy(x, y+2); std::cout << "      ";
    std::cout.flush();
}

void Nave::mover(){
    if(_kbhit()){
        char tecla = _getch();
        borrar();
        switch(tecla){
            case 'w': y = std::max(0, y - 1); break;
            case 's': y = y + 1; break;
            case 'a': x = std::max(0, x - 1); break;
            case 'd': x = x + 1; break;
            case 'q': std::exit(0); break;
        }
        pintar();
    }
}

int main(){
    ocultarCursor();
    pintarLimites();
    Nave n(10, 10);
    n.pintar();

    while(true){
        n.mover();
        Sleep(50);
    }
    return 0;
}

void gotoxy(int x, int y){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = (SHORT)x;
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(hconsole, coord);
}

void ocultarCursor(){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = 1;
    SetConsoleCursorInfo(hconsole, &cursor);
}
void pintarLimites(){
    // horizontals
    for(int i = 3; i < 77; i++){
        gotoxy(i, 2);  std::cout << (char)205;
        gotoxy(i, 33); std::cout << (char)205;
    }
    // verticals
    for(int i = 3; i < 33; i++){
        gotoxy(2, i);  std::cout << (char)186;
        gotoxy(77, i); std::cout << (char)186;
    }
    // corners
    gotoxy(2, 2);   std::cout << (char)201;
    gotoxy(77, 2);  std::cout << (char)187;
    gotoxy(2, 33);  std::cout << (char)200;
    gotoxy(77, 33); std::cout << (char)188;
    std::cout.flush();
}