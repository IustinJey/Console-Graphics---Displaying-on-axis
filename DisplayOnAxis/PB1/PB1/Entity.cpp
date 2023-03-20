#include <iostream>
#include "Entity.h"
#include "patrat.hpp"

void Entity::ADD_PATRAT()
{
    Patrat p;
    std::cin >> p;
    this->patrate.push_back(p);

}
void Entity::ADD_PATRAT(Patrat p)
{
    this->patrate.push_back(p);
}
void Entity::SHOW_ALL()
{
    std::cout << "\n";
    for (size_t i = 0; i < this->patrate.size(); i++)
        std::cout << "\033[36m" << this->patrate[i] << "\033[m" << std::endl;
}
int Entity::get_lenght()
{
    return int(this->patrate.size());
}
std::vector<Patrat> Entity::get_patrate()
{
    return this->patrate;
}
Patrat Entity::BIGGEST_ENTITY()
{
    Patrat p;
    for (size_t i = 0; i < this->patrate.size(); i++)
        if (this->patrate[i].getLatura() > p.getLatura())
            p = this->patrate[i];
    return p;
}
Entity Entity::DIAL_ONE()
{
    Entity dial_one;
    for (size_t i = 0; i < this->patrate.size(); i++)
        if (this->patrate[i].getCentru().x > 0 && this->patrate[i].getCentru().y > 0)
            if (this->patrate[i].getLatura() / 2 <= this->patrate[i].getCentru().x)
                if (this->patrate[i].getLatura() / 2 <= this->patrate[i].getCentru().y)
                    dial_one.ADD_PATRAT(this->patrate[i]);
    return dial_one;
}
Entity Entity::SEQUENCE()
{
    int start = 1, end = 0;
    Entity sequence;
    for (size_t i = 0; i < this->patrate.size(); i++)
    {
        int j = i;
        while (this->patrate[i].getLatura() == this->patrate[j].getLatura() && ((j+1) < this->patrate.size()))
            j++;
        if (j - i + 1 >= end - start + 1)
            end = j; start = i;
        i = j;
    }
    for (int i = start; i < end; i++)
    {
        sequence.ADD_PATRAT(this->patrate[i]);
    }
    return sequence;
}