CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf mc

mc: mc.cpp
	$(COMPILER) $(CFLAGS) mc.cpp -o mc
