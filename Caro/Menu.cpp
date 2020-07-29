#include "Menu.h"
#include "Common.h"
#include <iostream>
#include <conio.h>
#include "Game.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <MMsystem.h>
#include <fstream>
using namespace std;

#pragma comment(lib, "Winmm.lib")

void _Menu::printLogo(const string inFile,int xAxis,int yAxis,int time) {
    fstream logo;
    logo.open(inFile);
    string temp;
    while (!logo.eof()) {
        _Common::gotoXY(xAxis, yAxis);
        getline(logo, temp);
        cout << temp << endl;
        yAxis++;
        Sleep(time);
    }
    logo.close();
}

void _Menu::printMenu() {
    system("color F0");
    printLogo("banner.txt", 36, 6,0);
    _Common::gotoXY(48, 15);
    cout << "-------MAIN MENU-------";
    _Common::gotoXY(55, 16);
    cout << "NEW GAME" << endl;
    _Common::gotoXY(55, 17);
    cout << "LOAD GAME" << endl;
    _Common::gotoXY(55, 18);
    cout << "SETTING" << endl;
    _Common::gotoXY(55, 19);
    cout << "HELP" << endl;
    _Common::gotoXY(55, 20);
    cout << "EXIT" << endl;
}

void _Menu::updateMenu(int i) {
    switch (i)
    {
    case 16:
        printMenu();
        _Common::gotoXY(leftMargin, i);
        _Common::TextColor(14);
        cout << "NEW GAME";
        break;
    case 17:
        printMenu();
        _Common::gotoXY(leftMargin, i);
        _Common::TextColor(14);
        cout << "LOAD GAME";
        break;
    case 18:
        printMenu();
        _Common::gotoXY(leftMargin, i);
        _Common::TextColor(14);
        cout << "SETTING";
        break;
    case 19:
        printMenu();
        _Common::gotoXY(leftMargin, i);
        _Common::TextColor(14);
        cout << "HELP";
        break;
    case 20:
        printMenu();
        _Common::gotoXY(leftMargin, i);
        _Common::TextColor(14);
        cout << "EXIT";
        break;

    }
}

void _Menu::selectMode(){
    _Common::drawBorder(0, 0, 29, 119);
    printLogo("selectMode.txt", 34, 8, 0);
    _Common::gotoXY(leftMargin-2, 17);
    cout << "Player vs Player" << endl;
    _Common::gotoXY(leftMargin-2, 18);
    _Common::TextColor(7);
    cout << "Player vs AI";
    int current = 17;
    _Common::gotoXY(leftMargin-2, 17);
    while (1) {
        char key = _getch();
        key = toupper(key);
        switch (key)
        {
        case 'W':
            PlaySound(TEXT("moveUp.wav"), NULL, SND_SYNC);
            if (current > 17) {
                current--;
                _Common::gotoXY(leftMargin-2, current + 1);
                _Common::TextColor(7);
                cout << "Player vs AI";
                _Common::gotoXY(leftMargin-2, current);
                _Common::TextColor(14);
                cout << "Player vs Player"<<endl;
                _Common::gotoXY(leftMargin-2, current);
            }
            break;
        case 'S':
            PlaySound(TEXT("moveDown.wav"), NULL, SND_SYNC);
            if (current < 18) {
                current++;
                _Common::gotoXY(leftMargin-2, current-1);
                _Common::TextColor(7);
                cout << "Player vs Player"<<endl;
                _Common::gotoXY(leftMargin-2, current);
                _Common::TextColor(14);
                cout << "Player vs AI";
                _Common::gotoXY(leftMargin-2, current);
            }
            break;
        case 13:
            PlaySound(TEXT("select.wav"), NULL, SND_ASYNC);
            _Common::clrscr();
            switch (current) {
            case 17:
                _Common::TextColor(14);
                _Game::newGame();
            }
            break;
        case 27:
            _Common::clrscr();
            _Menu::selecMenu();
            break;
        }
    }
}

void _Menu::switchMenu(int current) {
    switch (current)
    {
    case 16:
        system("cls");
        selectMode();
        break;
    case 17://load game
        _Common::clrscr();
        cout << "LOAD GAME";
        break;
    case 18://setting
        _Common::clrscr();
        cout << "SETTING";
        system("pause");
        _Common::clrscr();
        selecMenu();
        break;
    case 19://help
        _Common::clrscr();
        help();
        _Common::clrscr();
        selecMenu();
        break;
    case 20:
        system("cls");
        exit(0);
    }
}

int _Menu::selecMenu() {
    _Common::drawBorder(0, 0, 29, 119);
    PlaySound(TEXT("StartMenu.wav"), NULL, SND_ASYNC | SND_NOSTOP);
    printMenu();
    _Common::gotoXY(leftMargin, 16);
    _Common::TextColor(14);
    cout << "NEW GAME";
    int current = 16;
    while (1) {
        char key = _getch();
        key = toupper(key);
        switch (key)
        {
        case 'W':
            PlaySound(TEXT("moveUp.wav"), NULL, SND_SYNC);
            if (current > topMargin) {
                current--;
                _Common::gotoXY(leftMargin,current);
                updateMenu(current);
            }
            break;
        case 'S':
            PlaySound(TEXT("moveDown.wav"), NULL, SND_SYNC);
            if (current < botMargin) {
                current++;
                _Common::gotoXY(leftMargin, current);
                updateMenu(current);
            }
            break;
        case 13:
            PlaySound(TEXT("select.wav"), NULL, SND_ASYNC);
            _Common::clrscr();
            switchMenu(current);
            break;
        }
    }
}

void _Menu::help() {
    _Common::clrscr();
    _Common::TextColor(14);
    cout << "\t========TRONG GIAO DIEN TRO CHOI========" << endl;
    _Common::TextColor(11);
    cout << "\t1. Su dung cac phim W, A, S, D hoac cac phim mui ten de di chuyen." << endl;
    _Common::TextColor(14);
    cout << "\t2. Su dung phim Space hoac Enter de thuc hien 1 nuoc danh." << endl;
    _Common::TextColor(11);
    cout << "\t3. Su dung ESC de thoat khoi tro choi." << endl;
    _Common::TextColor(14);
    cout << "\t******************************************" << endl;
    _Common::TextColor(11);
    cout << "\t============TRONG GIAO DIEN MENU============" << endl;
    _Common::TextColor(14);
    cout << "\t1. Su dung cac phim W, A, S, D hoac cac phim mui ten de di chuyen." << endl;
    _Common::TextColor(11);
    cout << "\t2. Nhan phim Enter de lua chon." << endl;
    _Common::TextColor(14);
    cout << "\t3. Cac chuc nang trong Menu:" << endl;
    _Common::TextColor(11);
    cout << "\t\t+ NEW GAME: Tao mot van choi moi." << endl;
    _Common::TextColor(14);
    cout << "\t\t+ LOAD GAME: Tai lai van choi con choi do truoc do." << endl;
    _Common::TextColor(11);
    cout << "\t\t+ HELP: Huong dan su dung." << endl;
    _Common::TextColor(14);
    cout << "\t\t+ ABOUT: Thong tin va lien he cua nguoi lam game." << endl;
    _Common::TextColor(11);
    cout << "\t\t+ EXIT: Thoat khoi chuong trinh." << endl;
    _Common::TextColor(14);
    system("pause");
}