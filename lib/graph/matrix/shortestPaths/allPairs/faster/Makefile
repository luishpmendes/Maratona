CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf fasterAllPairsShortestPaths

fasterAllPairsShortestPaths: fasterAllPairsShortestPaths.cpp
	$(COMPILER) $(CFLAGS) fasterAllPairsShortestPaths.cpp -o fasterAllPairsShortestPaths
