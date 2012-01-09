
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: backwardEuler.cpp

#include "backwardEuler.h"

backwardEuler::backwardEuler(const int n, const double delta)
{
  m_y = new double[n+1];
  m_t = new double[n+1];
  m_n = n;
  m_delta_t = delta;
}

backwardEuler::~backwardEuler()
{
  delete [] m_y;
  delete [] m_t;
}

void backwardEuler::solve(double (*function)(const double y, const double t), const double y_init)
{
  double y_temp;
  m_y[0] = y_init;
  m_t[0] = 0;
  for(int i = 0; i < m_n; i++)
  {
    m_t[i+1] = m_t[i] + m_delta_t;
    y_temp = m_y[i] + m_delta_t * function(m_y[i], m_t[i]);
    m_y[i+1] = m_y[i] + m_delta_t * function(y_temp, m_t[i+1]);
  }
  return;
}

ostream& operator<<(ostream& out, const backwardEuler &data)
{
  for(int i = 0; i <= data.m_n; i++)
    out << data.m_t[i] << "\t" << data.m_y[i] << endl;
  return out;
}
