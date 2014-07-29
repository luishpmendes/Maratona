CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf magico11

magico11: magico11.cpp
	$(COMPILER) $(CFLAGS) magico11.cpp -o magico11
