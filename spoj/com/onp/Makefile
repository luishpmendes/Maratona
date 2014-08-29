CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf onp

onp: onp.cpp
	$(COMPILER) $(CFLAGS) onp.cpp -o onp
