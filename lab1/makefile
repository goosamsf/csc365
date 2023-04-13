query: lab1.o query.o
	g++ lab1.o query.o -o lab1 

lab1.o: lab1.cpp
	g++ -c -g --std=c++17 lab1.cpp

query.o: query.cpp
	g++ -c -g --std=c++17 query.cpp
clean:
	rm *.o lab1 
