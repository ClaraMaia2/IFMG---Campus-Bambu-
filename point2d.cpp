#include "point2d.h"    //Incluindo a biblioteca .h criada anteriormente

//Construtor default
point2d :: point2d()
{
    this->x = 0.0;
    this->y = 0.0;
}

//Construtor parametrizado
point2d :: point2d(float nx, float ny)
{
    this->x = nx;
    this->y = ny;
}

//Construtor de cópia
point2d :: point2d(const point2d &p)
{
    this->x = p.getX();
    this->y = p.getY();
}

//Setters
void point2d :: setX(float nx)
{
    this->x = nx;
}

void point2d :: setY(float ny)
{
    this->y = ny;
}
