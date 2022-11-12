#include "point3d.h"    //Incluindo a biblioteca criada anteriormente

//Construtor default
point3d :: point3d() : point2d()
{
    this->z = 0.0;
}

//Construtor parametrizado
point3d :: point3d(float nx, float ny, float nz) : point2d(nx, ny)
{
    this->z = nz;
}

//Construtor de cópia
point3d :: point3d(const point3d &p)
{
    this->setX(p.getX());   //Usando setter para evitar violar o encapsulamento
    this->setY(p.getY());
    this->z = p.getZ();
}

//Setter
void point3d :: setZ(float nz)
{
    this->z = nz;
}
