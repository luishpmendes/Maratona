CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf escalo11

escalo11: escalo11.cpp
	$(COMPILER) $(CFLAGS) escalo11.cpp -o escalo11
