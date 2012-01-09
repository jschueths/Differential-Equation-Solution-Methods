
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: rungeKutta.h

#ifndef __RUNGE_KUTTA_H__
#define __RUNGE_KUTTA_H__

#include <iostream>
#include <cmath>
#include <cstdlib>

using std::ostream;
using std::endl;

class rungeKutta
{
  public:
    rungeKutta(const int n, const double delta);
    ~rungeKutta();
    void solve(double (*function)(const double y, const double t), const double y_init);
    friend ostream& operator<<(ostream &out, const rungeKutta &data);
    
  private:
    double * m_y;
    double * m_t;
    int m_n;
    double m_delta_t;
};


#endif

