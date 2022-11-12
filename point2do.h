//Sobrecarga de Operadores (biblioteca)
#ifndef POINT2DO_H
#define POINT2DO_H

class point2d
{
public:
    point2d();
    point2d(float nx, float ny);
    point2d(const point2d &p);
    float getX() const {return this->x;}
    float getY() const {return this->y;}
    void setX(float nx);
    void setY(float ny);
    point2d operator = (const point2d &p);  //Função que ensina ao compilador como usar o operador =
    bool operator == (const point2d &p);    //Função que ensina ao compilador como usar o operador ==
protected:
    float x;
    float y;
};
#endif // POINT2DO_H
