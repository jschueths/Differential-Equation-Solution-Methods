
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: timeSplit.cpp

#include "timeSplit.h"

timeSplit::timeSplit(const int n, const double delta)
{
  m_y = new double[n+1];
  m_t = new double[n+1];
  m_n = n;
  m_delta_t = delta;
}

timeSplit::~timeSplit()
{
  delete [] m_y;
  delete [] m_t;
}

void timeSplit::solve(double (*func1)(const double y, const double t), double (*func2)(const double y, const double t), const double y_init)
{
  double y_temp;
  m_y[0] = y_init;
  for(int i = 0; i < m_n; i++)
  {
    m_t[i] = i * m_delta_t;
    y_temp = m_y[i] + (m_delta_t * func1(m_y[i], m_t[i]));
    m_y[i+1] = m_y[i] + (m_delta_t * func2(y_temp, m_t[i]));
  }
  m_t[m_n] = m_n * m_delta_t;
  return;
}

ostream& operator<<(ostream &out, const timeSplit &data)
{
  for(int i = 0; i < data.m_n; i++)
    out << data.m_t[i] << "\t" << data.m_y[i] << endl;
  return out;
}
