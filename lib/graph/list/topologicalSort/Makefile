CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf topologicalSort

topologicalSort: topologicalSort.cpp
	$(COMPILER) $(CFLAGS) topologicalSort.cpp -o topologicalSort
