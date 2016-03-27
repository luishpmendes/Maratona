CPPC = g++
CFLAGS = -Wall
DEBUGFLAGS = -g -O0 -fno-inline

COMPILER = $(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf storeCredit

storeCredit: storeCredit.cpp
	$(COMPILER) $(CFLAGS) storeCredit.cpp -o storeCredit
