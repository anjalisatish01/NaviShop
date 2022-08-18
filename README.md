# NaviShop
I’ve programmed an app that acts as a Google Maps for mall shopping. Have you ever been shopping in a giant shopping mall and had to look at a map directory to figure out where Macy’s is? It feels incredibly esoteric that we still need physical maps to find our way to a store. So I created an app in C++ that uses Dijkstra’s Algorithm to determine how far away a store is from your current position and  determines the path you must take to get to your desired destination. This is a project I’ve published on GitHub.

How to compile: make main
How to Run: ./main

File Descriptions:
main.cpp - the execution file for the NaviShop program
map.cpp - the impelementation of Map class
map.h - the interface /header file of Map class
Makefile - this file helps you easily compile and run the program
map.txt - the file that holds the map of the mall. Each line is formatted with the "start_store#-end_store#=path_distance". For example, "1-2=3" means distance from store 1 to store 2 is 3. You are only required to enter adjacent store distances, and once you enter "1-2=3", you don't need to enter "2-1=3". 

Future Project Improvements:
- The numbers could be replaced with the store names
- the capacity of the arrays should not be fixed numbers, they should be expandable based on necessity
- 
