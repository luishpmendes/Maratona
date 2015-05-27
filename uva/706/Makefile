CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf 706

706: 706.cpp
	$(COMPILER) $(CFLAGS) 706.cpp -o 706
