#include <iostream>
#include <cmath>
#include "Point2D.h"
void Point2D::Set(int x, int y)
{
    mX = x;
    mY = y;
}

int Point2D::DistancePoint()
{
    return sqrt(mX*mX + mY*mY);
}

void Point2D::Print()
{
    std::cout << "( " << mX << ", " << mY << " )" << std::endl;
}
