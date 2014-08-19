CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf 2sat

2sat: 2sat.cpp
	$(COMPILER) $(CFLAGS) 2sat.cpp -o 2sat
