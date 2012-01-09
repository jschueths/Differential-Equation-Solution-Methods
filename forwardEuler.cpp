
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: forwardEuler.cpp

#include "forwardEuler.h"

forwardEuler::forwardEuler(const int n, const double delta)
{
  m_y = new double[n+1];
  m_t = new double[n+1];
  m_n = n;
  m_delta_t = delta;
}

forwardEuler::~forwardEuler()
{
  delete [] m_y;
  delete [] m_t;
}


// Applies the Forward Euler method of solving:
void forwardEuler::solve(double (*function)(const double y, const double t), const double y_init)
{
  m_y[0] = y_init;
  for(int i = 0; i < m_n; i++)
  {
    m_t[i] = i * m_delta_t;
    m_y[i+1] = m_y[i] + (m_delta_t * function(m_y[i], m_t[i]));
  }
  m_t[m_n] = m_n * m_delta_t;
  
  return;
}

ostream& operator<<(ostream &out, const forwardEuler &data)
{
  for(int i = 0; i <= data.m_n; i++)
    out << data.m_t[i] << "\t" << data.m_y[i] << endl;
  return out;
}
