#pragma once
#include "patrat.hpp"
#include <vector>

class Entity {
private:
	std::vector<Patrat> patrate;
public:

	// DESTRUCTOR
	~Entity() = default;

	// SETTERI

	// GETTERI
	int get_lenght();
	std::vector<Patrat> get_patrate();

	// FUNCTIONALITATI
	void ADD_PATRAT();
	void ADD_PATRAT(Patrat);
	void SHOW_ALL();
	Patrat BIGGEST_ENTITY();
	Entity DIAL_ONE();
	Entity SEQUENCE();

};