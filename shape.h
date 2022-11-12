#ifndef SHAPE_H
#define SHAPE_H

//Classe Abstrata
class shape
{
public:
    shape(){};  //Construtor default
    virtual ~shape(){}  //Destrutor
    virtual float getArea() const {return 0.0;}
    virtual float getVolume() const {return 0.0;}

    //Métodos virtuais puros:
    virtual void printShapeName() const = 0;
    virtual void print() const = 0;
};
#endif // SHAPE_H
