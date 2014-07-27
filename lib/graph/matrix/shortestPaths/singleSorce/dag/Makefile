CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf dagShortestPaths

dagShortestPaths: dagShortestPaths.cpp
	$(COMPILER) $(CFLAGS) dagShortestPaths.cpp -o dagShortestPaths
