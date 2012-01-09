
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: multi_forwardEuler.cpp

#include "multi_forwardEuler.h"

multi_forwardEuler::multi_forwardEuler(const int n, const double delta)
{
  m_y = new double[n+1];
  m_x = new double[n+1];
  m_t = new double[n+1];
  m_n = n;
  m_delta_t = delta;
}

multi_forwardEuler::~multi_forwardEuler()
{
  delete [] m_y;
  delete [] m_t;
}

void multi_forwardEuler::solve(double (*x_func)(const double y, const double t), double (*y_func)(const double x, const double y), const double x_init, const double y_init)
{
  m_x[0] = x_init;
  m_y[0] = y_init;
  for(int i = 0; i < m_n; i++)
  {
    m_t[i] = i * m_delta_t;
    m_x[i+1] = m_x[i] + (m_delta_t * x_func(m_x[i], m_y[i]));
    m_y[i+1] = m_y[i] + (m_delta_t * y_func(m_x[i], m_y[i]));
  }
  m_t[m_n] = m_n * m_delta_t;
  return;
}

ostream& operator<<(ostream &out, const multi_forwardEuler &data)
{
  for(int i = 0; i <= data.m_n; i++)
    out << data.m_x[i] << "\t" << data.m_y[i] << endl;
  return out;
}

