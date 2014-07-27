CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf dijkstra

dijkstra: dijkstra.cpp
	$(COMPILER) $(CFLAGS) dijkstra.cpp -o dijkstra
