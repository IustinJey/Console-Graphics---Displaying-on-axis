#include <iostream>
#include "Teste.h"
#include "patrat.hpp"
#include "vector2.hpp"
#include "UserInterface.h"
#include <stack>
#include "Entity.h"
#include <Windows.h>
#include <vector>


void pressEnter()
{
    std::cout << std::endl;
    system("pause");
}


int main() {
    
    teste();
    Entity entity;

    while (true)
    {
        runMenu();
        char option;
        std::cout << "\033[0;33m    Selecteaza optiunea: ";
        std::cin >> option;

        if (option == '1')
        {
            entity.ADD_PATRAT();
            if (FindWindowA(NULL, "Windows BGI"))
                runGraph(entity);

            pressEnter();
        }

        else if (option == '2')
        {
            entity.SHOW_ALL();
            pressEnter();
        }
        else if (option == '3')
        {
            openGraph(entity);
        }
        else if (option == '4')
        {
            std::cout << entity.BIGGEST_ENTITY();
            pressEnter();
        }
        else if (option == '5')
        {
            Entity dial_one = entity.DIAL_ONE();
            dial_one.SHOW_ALL();
            if (FindWindowA(NULL, "Windows BGI"))
                showHighlighted(dial_one, 0);
            pressEnter();
        }
        else if (option == '6')
        {
            Entity sequence = entity.SEQUENCE();
            sequence.SHOW_ALL();
            if (FindWindowA(NULL, "Windows BGI"))
                showHighlighted(sequence, 1);
            pressEnter();
        }
        else if (option == 'x')
        {
            break;
        }
        else
        {
            std::cout << "\033[31m    Aceasta optiune nu exista, incercati una diferita. \033[m" << std::endl;
            pressEnter();
        }
    }
}