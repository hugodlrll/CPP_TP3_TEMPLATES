#include <iostream>
#include "pointT.hpp"

using namespace std;

int main ()
{
    PointT<int> point(1, 3);
    cout << point;
    return 0;
}