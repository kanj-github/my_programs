arbitrage : arbitrage.o floyd_warshall.o
	g++ -o arbitrage arbitrage.o floyd_warshall.o
	
arbitrage.o : arbitrage.cpp floyd_warshall.h
	g++ -c arbitrage.cpp

floyd_warshall.o : floyd_warshall.cpp floyd_warshall.h
	g++ -c floyd_warshall.cpp
