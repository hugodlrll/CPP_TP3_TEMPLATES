#ifndef pointt_hpp
#define pointt_hpp

#include <ostream>
#include <algorithm>

using namespace std;

template<typename T> 
class PointT;

template<typename T> 
ostream& operator<<(ostream& os, PointT<T> const &);

template<typename T> 
class PointT 
{
    public:
        PointT(T x,T y);
        PointT();
        PointT(const PointT *p1);
        void translater(T x, T y);
        T getX() const;
        void setX(T x);
        T getY() const;
        void setY(T x);
        friend ostream& operator<< <T>(ostream& os, PointT<T> const &);
    protected:
        T x;
        T y;
};

template<typename T> 
PointT<T>::PointT(T x,T y){
    this->x = x;
    this->y = y;
 }

template<typename T> 
PointT<T>::PointT(){
    this->x = T();
    this->y = T();
}

template<typename T> 
PointT<T>::PointT(const PointT *p1){
    this->x = T();
    this->y = T();
}

template<typename T>
void PointT<T>::translater(T x, T y){
    this->x += x;
    this->y += y;
}

template <>
void PointT<string>::translater(string x, string y)
{
    swap(x,this->x);
    swap(y, this->y);
}

template<typename T> 
T PointT<T>::getX() const{
    return this->x;
 }

template<typename T> 
void PointT<T>::setX(T x){
    this->x = x;
 }

template<typename T> 
T PointT<T>::getY() const{
    return this->y;
 }

template<typename T> 
void PointT<T>::setY(T y){
    this->y = y;
}

template<typename T>
ostream& operator<<(ostream& os, PointT<int> point)
{
    os << "(X : " << point.getX() << ",Y : " << point.getY() << ")" << endl;
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, PointT<float> point)
{
    os << "(X : " << point.getX() << ",Y : " << point.getY() << ")" << endl;
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, PointT<double> point)
{
    os << "(X : " << point.getX() << ",Y : " << point.getY() << ")" << endl;
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, PointT<T> const & point)
{
    os << "(X : " << point.getX() << ",Y : " << point.getY() << ")" << endl;
    return os;
}

#endif

