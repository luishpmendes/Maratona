CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf paprimas

paprimas: paprimas.cpp
	$(COMPILER) $(CFLAGS) paprimas.cpp -o paprimas
