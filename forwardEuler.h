
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: forwardEuler.h

#ifndef __FOR_EULER_H__
#define __FOR_EULER_H__

#include <iostream>
#include <cmath>
#include <cstdlib>

using std::ostream;
using std::endl;


class forwardEuler
{
  public:
    forwardEuler(const int n, const double delta);
    ~forwardEuler();
    void solve(double (*function)(const double y, const double t), const double y_init);
    friend ostream& operator<<(ostream &out, const forwardEuler &data);
    
  private:
    double * m_y;
    double * m_t;
    int m_n;
    double m_delta_t;
};


#endif

