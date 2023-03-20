#include "UserInterface.h"
#include "Entity.h"
#include "patrat.hpp"
#include "vector2.hpp"
#include <iostream>
#include <string>
#include "graphics.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#pragma comment(lib,"graphics.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")

const int WIDTH = 700, HEIGHT = 700;

void runMenu() {
	system("CLS");
	std::string x = R"(
			  __  __            _       
			 |  \/  |          (_)      
			 | \  / | ___ _ __  _ _   _ 
			 | |\/| |/ _ \ '_ \| | | | |
			 | |  | |  __/ | | | | |_| |
			 |_|  |_|\___|_| |_|_|\__,_|
                            )"; 
	std::cout << " \033[0;32m" << x << std::endl;
	std::cout << "\033[0;32m    (1)\033[0;37m Adauga un patrat" << std::endl;
	std::cout << "\033[0;32m    (2)\033[0;37m Afiseaza toate patratele" << std::endl;
	std::cout << "\033[0;32m    (3)\033[0;33m [INDISPONIBIL]\033[0;37mDeseneaza pe axa <DESENEZI PATRATUL PE AXA>" << std::endl;
	std::cout << "\033[0;32m    (4)\033[0;37m Determina cea mai mare entitate" << std::endl;
	std::cout << "\033[0;32m    (5)\033[0;37m Identificare entitati situate [complet] in cadranul I" << std::endl;
	std::cout << "\033[0;32m    (6)\033[0;37m Cea mai mare secventa de entitati egale" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[0;32m    (x)\033[0;37m EXIT" << std::endl;
	std::cout << std::endl;
}

void drawLine(int MOVE_X, int MOVE_Y, int DRAW_X, int DRAW_Y, int COLOR, int TEXT_X, int TEXT_Y, char name[])
{
	moveto(MOVE_X, MOVE_Y);
	setcolor(COLOR);
	lineto(DRAW_X, DRAW_Y);
	outtextxy(TEXT_X, TEXT_Y, name);
}

void openGraph(Entity entity)
{
	initwindow(WIDTH, HEIGHT);
	runGraph(entity);
}

void showHighlighted(Entity entity, int color)
{
	if (color == 0)
		setcolor(YELLOW);
	else
		setcolor(GREEN);
	for (int i = 0; i < entity.get_lenght(); i++)
	{
		setlinestyle(0, 0, 5);
		//AFISARE PATRAT PE AXA

		double x = WIDTH / 2 + 44 * entity.get_patrate()[i].getCentru().x;
		double y = HEIGHT / 2 - 44 * entity.get_patrate()[i].getCentru().y;
		rectangle(x - 40 * (entity.get_patrate()[i].getLatura() / 2), y - 40 * (entity.get_patrate()[i].getLatura() / 2), x + 40 * (entity.get_patrate()[i].getLatura() / 2), y + 40 * (entity.get_patrate()[i].getLatura() / 2));


		// AFISARE LINII COORDONATE CENTRU

		setlinestyle(3, 0, 2);
		line(x, y, WIDTH / 2, y);
		line(x, y, x, HEIGHT / 2);
		setlinestyle(0, 0, 1);

		// AFISARE DATE PATRAT
		char v[2];
		_itoa_s(entity.get_patrate()[i].getLatura(), v, 10);
		outtextxy(x, y - 20 - 40 * (entity.get_patrate()[i].getLatura() / 2), v);

	}
}

void runGraph(Entity entity) 
{
	cleardevice();
	// REPREZENTARE GRAFIC
	moveto(WIDTH / 2, HEIGHT / 2);

	char X[2] = "X";
	char Y[2] = "Y";

	drawLine(0, HEIGHT / 2, WIDTH, HEIGHT / 2, WHITE, WIDTH - 20, HEIGHT / 2 + 10, X);
	drawLine(WIDTH / 2, 0, WIDTH / 2, HEIGHT, WHITE, WIDTH / 2 + 10, 0, Y);
	setcolor(GREEN);
	rectangle(30, 30, HEIGHT - 30, WIDTH - 30);
	setcolor(WHITE);
	
	for (int i = 0; i < entity.get_lenght(); i++)
	{
		//AFISARE PATRAT PE AXA
		
		double x = WIDTH / 2 + 44 * entity.get_patrate()[i].getCentru().x;
		double y = HEIGHT / 2 - 44 * entity.get_patrate()[i].getCentru().y;
		setcolor(i%8 + 2);
		rectangle(x - 40 * (entity.get_patrate()[i].getLatura() / 2), y - 40 * (entity.get_patrate()[i].getLatura() / 2), x + 40 * (entity.get_patrate()[i].getLatura() / 2), y + 40 * (entity.get_patrate()[i].getLatura() / 2));
		
		
		// AFISARE LINII COORDONATE CENTRU
		setlinestyle(2, 0, 1);
		line(x, y, WIDTH / 2, y);
		line(x, y, x, HEIGHT / 2);
		setlinestyle(0, 0, 1);

		// AFISARE DATE PATRAT
		setcolor(WHITE);
		char v[2];
		_itoa_s(entity.get_patrate()[i].getLatura(), v, 10);
		outtextxy(x, y - 20 - 40 * (entity.get_patrate()[i].getLatura() / 2), v);

	}

	setcolor(WHITE);
	for (int i = -6; i <= 6; i++)
	{
		char c[4];
		_itoa_s(i, c, 10);
		outtextxy(WIDTH / 2 + 50 * i, 0, c);
		outtextxy(0, HEIGHT / 2 + 50 * (-i), c);
	}

	

}

