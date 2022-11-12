#ifndef POINT2DP_H
#define POINT2DP_H
#include <iostream>
#include "shape.h"

using namespace std;

//Classe Polimórfica
class point2d : public shape
{
public:
    //Construtor default
    point2d() : shape()
    {
        this->x = 0.0;
        this->y = 0.0;
    }

    //Construtor parametrizado
    point2d(float nx, float ny) : shape()
    {
        this->x = nx;
        this->y = ny;
    }

    //Construtor de cópia
    point2d(const point2d &p)
    {
        this->x = p.getX();
        this->y = p.getY();
    }

    virtual ~point2d(){}    //Destrutor

    //Getters
    float getX() const {return this->x;}
    float getY() const {return this->y;}

    //Setters
    void setX(float nx) {this->x = nx;}
    void setY(float ny) {this->y = ny;}

    //Métodos virtuais puros da classe abstrata shape
    virtual void printNameShape() const
    {
        cout << "Point2D";
    }
    virtual void print() const
    {
        cout << "(" << this->x << ", " << this->y << ")";
    }

protected:
    float x;    //Atributo X da classe
    float y;    //Atributo Y da classe
};
#endif // POINT2DP_H
