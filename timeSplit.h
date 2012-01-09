
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: timeSplit.h


#ifndef __TIME_SPLIT_H__
#define __TIME_SPLIT_H__

#include <iostream>
#include <cmath>
#include <cstdlib>

using std::ostream;
using std::endl;

class timeSplit
{
  public:
    timeSplit(const int n, const double delta);
    ~timeSplit();
    void solve(double (*func1)(const double y, const double t), double (*func2)(const double y, const double t), const double y_init);
    friend ostream& operator<<(ostream &out, const timeSplit &data);
    
  private:
    double * m_y;
    double * m_t;
    int m_n;
    double m_delta_t;
};


#endif