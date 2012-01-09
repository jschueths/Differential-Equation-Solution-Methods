# gnuplot script to plot hw7 problems:

# Problem 1 Plots
set term png
set output 'problem1_forEuler.png'
set key off
set xlabel "t"
set ylabel "x"
plot "forwardEuler_P1.log", sqrt(1 + x**2)

set output 'problem1_backEuler.png'
set key off
set xlabel "t"
set ylabel "x"
plot "backwardEuler_P1.log", sqrt(1 + x**2)

set output 'problem1_crank_nicolson.png'
set key off
set xlabel "t"
set ylabel "x"
plot "crankNicolson_P1.log", sqrt(1 + x**2)

set output 'problem1_runge_kutta.png'
set key off
set xlabel "t"
set ylabel "x"
plot "rungeKutta_P1.log", sqrt(1 + x**2)

# Problem 2 Plots
set output 'problem2_backEuler.png'
set key off
set xlabel "t"
set ylabel "y"
plot "backwardEuler_P2.log", (3 * exp((x**3)/3) - sin(x**3) - 3 * cos(x**3))/10

set output 'problem2_timeSplit.png'
set key off
set xlabel "t"
set ylabel "y"
plot "timeSplitting_P2.log", (3 * exp((x**3)/3) - sin(x**3) - 3 * cos(x**3))/10
# Problem 3 Plot
set output 'problem3_forward_euler.png'
set key off
set xlabel "x"
set ylabel "y"
plot "multi_forwardEuler_P3.log" 
