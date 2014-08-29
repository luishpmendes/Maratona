CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf phonelst

phonelst: phonelst.cpp
	$(COMPILER) $(CFLAGS) phonelst.cpp -o phonelst
