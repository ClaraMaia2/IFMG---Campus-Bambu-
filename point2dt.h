//Classes Template (biblioteca)
#ifndef POINT2DF_H
#define POINT2DF_H

//Classe template T
template <class T>

class point2d
{
public:
    point2d();
    point2d(T nx, T ny);
    point2d(const point2d<T> &p);
    virtual ~point2d() {};
    T getX() const {return this->x;}
    T getY() const {return this->y;}
    void setX(T nx);
    void setY(T ny);
protected:
    T x;
    T y;
};

template <class T>
point2d<T> :: point2d()
{
    this->x = 0;
    this->y = 0;
}

template <class T>
point2d<T> :: point2d(T nx, Tny)
{
    this->x = nx;
    this->y = ny;
}

template <class T>
point2d<T> :: point2d(const point2d<T> &p)
{
    this->x = p.getX();
    this->y = p.getY();
}

template <class T>
void point2d<T> :: setX(T nx)
{
    this->x = nx;
}

template <class T>
void point2d<T> :: setY(T ny)
{
    this->y = ny;
}
#endif // POINT2DF_H
