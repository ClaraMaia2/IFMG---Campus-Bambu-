#ifndef POINT2D_H
#define POINT2D_H
class point2d
{
public:
    point2d();  //Construtor default
    point2d(float nx, float ny);    //Construtor parametrizado
    point2d(const point2d &p);  //Construtor de c�pia
    virtual ~point2d(){}    //Destrutor
    float getX() const {return this->x;}    //M�todo getter de X
    float getY() const {return this->y;}    //M�todo getter de Y
    void setX(float nx);    //M�todo setter de X
    void setY(float ny);    //M�todo setter de Y

protected:
    float x;    //Atributo X da classe
    float y;    //Atributo Y da classe
};
#endif // POINT2D_H
