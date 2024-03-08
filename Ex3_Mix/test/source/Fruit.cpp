#include "../include/Fruit.hpp"

Fruit::Fruit(void)
{}

Fruit::~Fruit(void)
{}

std::string         Fruit::getName(void) const
{
    return _name;
}

int                 Fruit::getVitamins(void) const
{
    return _vitamins;
}

void                Fruit::setName(std::string name)
{
    _name = name;
}

void                Fruit::setVitamins(int vitamins)
{
    _vitamins = vitamins;
}