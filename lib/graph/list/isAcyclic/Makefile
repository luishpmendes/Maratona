CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf isAcyclic

isAcyclic: isAcyclic.cpp
	$(COMPILER) $(CFLAGS) isAcyclic.cpp -o isAcyclic
