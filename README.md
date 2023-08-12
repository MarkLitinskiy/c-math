# s21_math  

Implementation of my own version of the math.h library.  
Project date: 11-2022

## Information

This learning project is a group project, I was responsible for implementing trigonometric functions as well as tests for them. The tests are written using the `check.h` library.

## Project Build

The project is built with the `make` command in the `src` folder, there are the following targets:  
- `s21_math.a` - building the library itself,  
- `test` - start testing,  
- `gcov_report` - view test coverage (the lcov utility is required),  
- `valgrind` - check for leaks with valgrind utility,  
- `rebuild` - rebuild the project,  
- `clean` - clean the project from temporary files.  
You can also test and check for leaks in Docker by running the `docker_run.sh` script  

### Overview of some "math.h" functions

| No. | Function | Description |
| --- | -------- | ----------- |
| 1 | `int abs(int x)` | computes absolute value of an integer value |
| 2 | `long double acos(double x)` | computes arc cosine |
| 3 | `long double asin(double x)` | computes arc sine |
| 4 | `long double atan(double x)` | computes arc tangent |
| 5 | `long double ceil(double x)` | returns the nearest integer not less than the given value |
| 6 | `long double cos(double x)` | computes cosine |
| 7 | `long double exp(double x)` | returns e raised to the given power |
| 8 | `long double fabs(double x)` | computes absolute value of a floating-point value |
| 9 | `long double floor(double x)` | returns the nearest integer not greater than the given value |
| 10 | `long double fmod(double x, double y)` | remainder of the floating-point division operation |
| 11 | `long double log(double x)` | computes natural logarithm |
| 12 | `long double pow(double base, double exp)` | raises a number to the given power |
| 13 | `long double sin(double x)` | computes sine |
| 14 | `long double sqrt(double x)` | computes square root |
| 15 | `long double tan(double x)` | computes tangent |  

## Description

- The library is developed in C11 C language using gcc compiler 
- The solution is designed as a static library (with header file s21_math.h).
- Full coverage of unit-tests of library functions with the help of Check library was prepared.
- A gcov report is generated in the gcov_report target as an html page. 
- Provide a Makefile for building the library and tests (with targets all, clean, test, s21_math.a, gcov_report).  
- The total verifiable precision is 16 significant digits
- Verifiable fractional precision - maximum 6 decimal places.