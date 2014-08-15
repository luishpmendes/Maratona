CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf slowAllPairsShortestPaths

slowAllPairsShortestPaths: slowAllPairsShortestPaths.cpp
	$(COMPILER) $(CFLAGS) slowAllPairsShortestPaths.cpp -o slowAllPairsShortestPaths
