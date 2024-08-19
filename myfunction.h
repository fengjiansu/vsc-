#ifndef MYFUNCTION_H
#define MYFUNCTION_H

template<typename T>
T  BinarySearch(T left,T right, T target , double epsion = 0.0)
{
    T result;
    while(fabs(right-left)> epsion) //
    {
        result = (left + right) / 2;
        if((result * result * result - target)<= epsion)
        {
            left = result;
        }
        else
        {
            right = result;
        }
    }
    return result;
    
}

#endif