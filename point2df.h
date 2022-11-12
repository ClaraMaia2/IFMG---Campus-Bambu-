//Classes amigas (biblioteca)
#ifndef POINT2DF_H
#define POINT2DF_H
#include <iostream>

using namespace std;
/*Uma classe friend pode redefinir m�todos de outras classes, n�o envolvidas em heran�as
Viola o princ�pio de encapsulamento de POO, por isso deve ser usado com cautela
*/
class point2d
{
    //O m�todo friend deve ser declarado dentro da classe, mas n�o pode ser implementado dentro dela ou ser associado a ela
    friend ostream &operator << (ostream &output, const point2d &p);

public:
    point2d()
    {
        this->x = 0.0;
        this->y = 0.0;
    }

    point2d(float nx, float ny)
    {
        this->x = nx;
        this->y = ny;
    }

    virtual ~point2d() {}
    float getX() const {return this->x;}
    float getY() const {return this->y;}
    void setX(float nx) {this->x = nx;}
    void setY(float ny) {this->y = ny;}
protected:
    float x;
    float y;
};

/*Modificando a fun��o do operador << da classe ostream para adequar a
M�todo friend que sobrecarrega o operador <<
*/
ostream &operator << (ostream &output, const point2d &p)
{
    output << "(" << p.getX() << ", " << p.getY() << ")";
    return output;
}
#endif // POINT2DF_H
