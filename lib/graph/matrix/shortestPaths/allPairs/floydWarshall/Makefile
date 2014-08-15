CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf floydWarshall

floydWarshall: floydWarshall.cpp
	$(COMPILER) $(CFLAGS) floydWarshall.cpp -o floydWarshall
