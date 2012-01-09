
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: multi_forwardEuler.h

#ifndef __MULTI_FOR_EULER_H__
#define __MULTI_FOR_EULER_H__

#include <iostream>
#include <cmath>
#include <cstdlib>

using std::ostream;
using std::endl;


class multi_forwardEuler
{
  public:
    multi_forwardEuler(const int n, const double delta);
    ~multi_forwardEuler();
    void solve(double (*x_func)(const double y, const double t), double (*y_func)(const double x, const double y), const double x_init, const double y_init);
    friend ostream& operator<<(ostream &out, const multi_forwardEuler &data);
    
  private:
    double * m_y;
    double * m_x;
    double * m_t;
    int m_n;
    double m_delta_t;
};


#endif
