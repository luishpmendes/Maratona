CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf acpc10d

acpc10d: acpc10d.cpp
	$(COMPILER) $(CFLAGS) acpc10d.cpp -o acpc10d
