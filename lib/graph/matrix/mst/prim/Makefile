CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf prim

prim: prim.cpp
	$(COMPILER) $(CFLAGS) prim.cpp -o prim
