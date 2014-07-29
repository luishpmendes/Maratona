CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf pesca11

pesca11: pesca11.cpp
	$(COMPILER) $(CFLAGS) pesca11.cpp -o pesca11
