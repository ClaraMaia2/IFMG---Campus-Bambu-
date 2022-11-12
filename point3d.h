#ifndef POINT3D_H
#define POINT3D_H
#include "point2d.h"

class point3d : public point2d  //Declarando que � heran�a da classe point2d
{
public:
    point3d();  //Construtor default
    point3d(float nx, float ny, float nz);  //Construtor parametrizado
    point3d(const point3d &p);  //Construtor de c�pia
    virtual ~point3d(){}    //Destrutor
    float getZ() const {return this->z;}    //M�todo getter de Z
    void setZ(float nz);    //M�todo setter de Z

protected:
    float z;    //Atributo z da classe
};
#endif // POINT3D_H
