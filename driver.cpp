
// Author: Joshua McCarville-Schueths
//  Class: Math 303
//   File: driver.cpp

#include "forwardEuler.h"
#include "backwardEuler.h"
#include "rungeKutta.h"
#include "crankNicolson.h"
#include "multi_forwardEuler.h"
#include "timeSplit.h"
#include "ConfigFile.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double problem1(const double y, const double t);
double problem2(const double y, const double t);
double problem2_1(const double y, const double t);
double problem2_2(const double y, const double t);
double problem3x(const double x, const double y);
double problem3y(const double x, const double y);

int main(int argc, char * argv[])
{
  ofstream log;
  string config_name = "default.cfg";
  double delta_t1, delta_t2, delta_t3;
  int n1, n2, n3;
  double x_init1, y_init2, x_init3, y_init3;
  bool run_p1, run_p2, run_p3;
  
  // Check command line:
  if(argc > 2)
  {
    cerr << "Incorrect number of arguments!" << endl;
    cerr << "Usage: driver <config_file>" << endl;
    return 1;
  }
  else
  {
    if(argc == 2)
      config_name = argv[1];
    cout << "Using config file: " << config_name << endl;
  }
  
  // Load the problem parameters:
  ConfigFile config(config_name);
  run_p1 = config.read<bool>("problem1");
  run_p2 = config.read<bool>("problem2");
  run_p3 = config.read<bool>("problem3");
  
    // Problem 1 Parameters:
  delta_t1 = config.read<double>("p1_delta_t");
  n1 = config.read<int>("p1_n");
  x_init1 = config.read<double>("p1_x_init");
    // Problem 2 Parameters:
  delta_t2 = config.read<double>("p2_delta_t");
  n2 = config.read<int>("p2_n");
  y_init2 = config.read<double>("p2_y_init");
    // Problem 3 Parameters:
  delta_t3 = config.read <double>("p3_delta_t");
  n3 = config.read<int>("p3_n");
  x_init3 = config.read<double>("p3_x_init");
  y_init3 = config.read<double>("p3_y_init");
  
  
  /******** Problem 1 *************/
  // Forward Euler:
  forwardEuler feP1(n1, delta_t1);
  feP1.solve(&problem1, x_init1);
  
  // Backward Euler:
  backwardEuler bkP1(n1, delta_t1);
  bkP1.solve(&problem1, x_init1);
  
  // Crank-Nicolson:
  crankNicolson cnP1(n1, delta_t1);
  cnP1.solve(&problem1, x_init1);
  
  // Runge Kutta:
  rungeKutta rkP1(n1, delta_t1);
  rkP1.solve(&problem1, x_init1);
  
  /******** Problem 2 *************/
  // Backward Euler:
  backwardEuler beP2(n2, delta_t2);
  beP2.solve(&problem2, y_init2);
  
  // Time Splitting:
  timeSplit tsP2(n2, delta_t2);
  tsP2.solve(&problem2_1, &problem2_2, y_init2);
  
  /******** Problem 3 *************/
  // Multivariable Forward Euler:
  multi_forwardEuler mfeP3(n3, delta_t3);
  mfeP3.solve(&problem3x, &problem3y, x_init3, y_init3);
    
  
  /******** Output ****************/
  if(run_p1)
  {
    log.open("forwardEuler_P1.log");
    log << feP1 << endl;    
    log.close();
    log.open("backwardEuler_P1.log");
    log << bkP1 << endl;
    log.close();
    log.open("crankNicolson_P1.log");
    log << cnP1 << endl;
    log.close();
    log.open("rungeKutta_P1.log");
    log << rkP1 << endl;
    log.close();
  }
  if(run_p2)
  {
    log.open("backwardEuler_P2.log");
    log << beP2 << endl;
    log.close();
    log.open("timeSplitting_P2.log");
    log << tsP2 << endl;
  }
  if(run_p3)
  {
    log.open("multi_forwardEuler_P3.log");
    log << mfeP3 << endl;
    log.close();
  }
  
  return 0;
}

double problem1(const double x, const double t)
{
  return t/x;
}

double problem2(const double y, const double t)
{
  return ((pow(t, 2) * y) + (pow(t, 2) * sin(pow(t, 3))));
}

double problem2_1(const double y, const double t)
{
  return (pow(t, 2) * y);
}

double problem2_2(const double y, const double t)
{
  return (pow(t, 2) * sin(pow(t, 3)));
}

double problem3x(const double x, const double y)
{
  return (2 - x - y);
}

double problem3y(const double x, const double y)
{
  return (pow(x, 2) - y);
}

