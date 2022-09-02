CC = cc

PNAME = ctactoe

SRC  = $(shell find src -name "*.c")
OBJ  = $(SRC:.c=.o)
BIN = build

INSTALL_PATH = /usr/local/bin

all: build

run: build
	$(BIN)/$(PNAME) $*

build: $(OBJ)
	./build.sh

clean:
	rm $(BIN)/* $(OBJ)

install: build
	cp $(BIN)/$(PNAME) $(INSTALL_PATH)

