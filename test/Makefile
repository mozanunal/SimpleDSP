########################################################
# SimpleDSP                                            #
#                                                      #
#                                                      #
#                                                      #
#                                                      #
########################################################
CC = gcc
INCLUDE = 

SRC = testIIR.c simpleDSP_iir.c

OUT = testFIR
CCFLAGS = 
LDFLAGS = 

all: build

build: $(SRC)
	@echo Compiling $(basename $<)...
	$(CC) $(CCFLAGS) $(INCLUDE) $(SRC) -o $(OUT) $(LDFLAGS)

run:
	./$(OUT)

clean:
	rm -rf *.dSYM