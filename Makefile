# Makefile for map main.cpp
# Matt Russell
# 
# This Makefile will build unit_test for the unit_testing 
# framework.

CXX=clang++
CXXFLAGS=-Wall -Wextra -Wpedantic -Wshadow


map.o: map.cpp map.h
	${CXX} ${CXXFLAGS} -c map.cpp

main: main.o map.o
	${CXX} -o $@ $^

clean: 
	rm *.o a.out *~ *#