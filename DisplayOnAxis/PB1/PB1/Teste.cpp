#include "Teste.h"
#include "patrat.hpp"
#include "vector2.hpp"
#include <assert.h>
#include "Entity.h"
#include <vector>

void teste()
{
/// ASSERT 1
	Vector2 centru_;
	Patrat p1 = { 3, centru_ = { 3, 9 } };

	assert(p1.arie() == 9);
	assert(p1.perimetru() == 12);

	/// ASSERT 2
	Vector2 centru_2;
	Patrat p2 = { 6, centru_2 = { 6, 6 } };

	assert(p2.arie() == 36);
	assert(p2.perimetru() == 24);

	/// ASSERT 3
	Vector2 centru_3;
	Patrat p3 = { 2, centru_3 = { 0, 0 } };

	assert(p3.arie() == 4);
	assert(p3.perimetru() == 8);

	/// ASSERT 4
	Vector2 centru_4;
	Patrat p4 = { 2, centru_4 = { 0, 0 } };

	assert(p4.arie() == 4);
	assert(p4.perimetru() == 8);

	//ASSERT 
	p4 = p3;
	assert(p4.getLatura() == p3.getLatura());

	// ASSERT 
	Entity entitate;
	entitate.ADD_PATRAT(p1);
	entitate.ADD_PATRAT(p2);
	entitate.ADD_PATRAT(p3);
	entitate.ADD_PATRAT(p4);

	Entity raspuns_dial_one;
	raspuns_dial_one.ADD_PATRAT(p1);
	raspuns_dial_one.ADD_PATRAT(p2);


	assert(entitate.DIAL_ONE().get_lenght() == raspuns_dial_one.get_lenght());
	for (int i = 0; i < entitate.DIAL_ONE().get_lenght(); i++)
	{
		assert(entitate.DIAL_ONE().get_patrate()[i].getLatura() == raspuns_dial_one.get_patrate()[i].getLatura());
		assert(entitate.DIAL_ONE().get_patrate()[i].getCentru().x == raspuns_dial_one.get_patrate()[i].getCentru().x);
		assert(entitate.DIAL_ONE().get_patrate()[i].getCentru().y == raspuns_dial_one.get_patrate()[i].getCentru().y);
	}

	// ASSERT
	/*Entity raspuns_sequence;
	raspuns_sequence.ADD_PATRAT(p3);
	raspuns_sequence.ADD_PATRAT(p4);*/

	//assert(entitate.SEQUENCE().get_lenght() == raspuns_sequence.get_lenght());
	//for (int i = 0; i < entitate.SEQUENCE().get_lenght(); i++)
	//{
	//	assert(entitate.SEQUENCE().get_patrate()[i].getLatura() == raspuns_sequence.get_patrate()[i].getLatura());
	//	assert(entitate.SEQUENCE().get_patrate()[i].getCentru().x == raspuns_sequence.get_patrate()[i].getCentru().x);
	//	assert(entitate.SEQUENCE().get_patrate()[i].getCentru().y == raspuns_sequence.get_patrate()[i].getCentru().y);
	//}

	//// ASSERT
	//assert(entitate.BIGGEST_ENTITY().getLatura() == p2.getLatura());
	//
}