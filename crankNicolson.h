
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: crankNicolson.h

#ifndef __CRANK_NICOLSON_H__
#define __CRANK_NICOLSON_H__

#include <iostream>
#include <cmath>
#include <cstdlib>

using std::ostream;
using std::endl;

class crankNicolson
{
  public:
    crankNicolson(const int n, const double delta);
    ~crankNicolson();
    void solve(double (*function)(const double y, const double t), const double y_init);
    friend ostream& operator<<(ostream &out, const crankNicolson &data);
    
  private:
    double * m_y;
    double * m_t;
    int m_n;
    double m_delta_t;
};


#endif