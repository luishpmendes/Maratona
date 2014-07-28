CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf expres11

expres11: expres11.cpp
	$(COMPILER) $(CFLAGS) expres11.cpp -o expres11
