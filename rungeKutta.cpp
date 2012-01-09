
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: rungeKutta.cpp

#include "rungeKutta.h"

rungeKutta::rungeKutta(const int n, const double delta)
{
  m_y = new double[n+1];
  m_t = new double[n+1];
  m_n = n;
  m_delta_t = delta;
}

rungeKutta::~rungeKutta()
{
  delete [] m_y;
  delete [] m_t;
}

void rungeKutta::solve(double (*function)(const double y, const double t), const double y_init)
{
  double K1, K2, K3, K4;
  m_y[0] = y_init;
  m_t[0] = 0;
  for(int i = 1; i <= m_n; i++)
  {
    K1 = m_delta_t * function(m_y[i-1], m_t[i-1]);
    K2 = m_delta_t * function(m_y[i-1] + (0.5 * K1), m_t[i-1] + (0.5 * m_delta_t));
    K3 = m_delta_t * function(m_y[i-1] + (0.5 * K2), m_t[i-1] + (0.5 * m_delta_t));
    K4 = m_delta_t * function(m_y[i-1] + K3, m_t[i-1] + m_delta_t);
    m_y[i] = m_y[i-1] + ((K1 + (2 * K2) + (2 * K3) + K4) / 6);
    m_t[i] = i * m_delta_t;
  }
  return;
}

ostream& operator<<(ostream &out, const rungeKutta &data)
{
  for(int i = 0; i <= data.m_n; i++)
    out << data.m_t[i] << "\t" << data.m_y[i] << endl;
  return out;
}