//Sobrecarga de operadores (implementação)
#include "point2d.h"    //Incluindo a biblioteca .h criada anteriormente
#include "point2do.h"   //Incluindo a biblioteca point2do.h criada anteriormente

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

/*Função que ensina ao código a realizar uma operação com o operador =
Deve retornar um objeto da classe porque = é um operador aritmético
*/
point2d point2d :: operator = (const point2d &p)
{
    point2d aux(p);     //Copiando p para aux

    this->x = p.getX();
    this->y = p.getY();

    return aux;
}

/*Função que ensina ao código a realizar uma operação com o operador ==
Deve retornar tipo bool porque == é um operador lógico
*/
bool point2d :: operator == (const point2d &p)
{
    return this->x == p.getX() && this->y == p.getY();
}
