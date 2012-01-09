
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: backwardEuler.h

#ifndef __BACK_EULER_H__
#define __BACK_EULER_H__

#include <iostream>
#include <cmath>
#include <cstdlib>

using std::ostream;
using std::endl;


class backwardEuler
{
  public:
    backwardEuler(const int n, const double delta);
    ~backwardEuler();
    void solve(double (*function)(const double y, const double t), const double y_init);
    friend ostream& operator<<(ostream &out, const backwardEuler &data);
    
  private:
    double * m_y;
    double * m_t;
    int m_n;
    double m_delta_t;
};


#endif
