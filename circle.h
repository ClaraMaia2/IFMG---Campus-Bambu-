#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "point2dp.h"

using namespace std;

class circle : public point2d   //Classe herdeira de point2d
{
public:
    circle() : point2d() {this->radius = 0.0;}  //Construtor defautl
    circle(float nx, float ny, float nr) : point2d(nx, ny) {this->radius = nr;}     //Construtor parametrizado
    virtual ~circle(){}     //Destrutor
    void setRadius(float nr) {this->radius = nr;}   //Setter
    float getRadius() const (return radius;)    //Getter

    //Método que calcula a área do círculo
    virtual float getArea() const
    {
        return 3.14159 * radius * radius;
    }

    //Métodos virtuais puros:
    virtual void printShapeName() const
    {
        cout << "Circle";
    }
    virtual void print() const
    {
        cout << "Center: ";
        point2d :: print();
        cout << endl << "Radius: " << this->radius << endl;
    }

private:
    float radius;   //Atributo radius da classe
};
#endif // CIRCLE_H
