CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf minimo

minimo: minimo.cpp
	$(COMPILER) $(CFLAGS) minimo.cpp -o minimo
