CXX      = g++
CXXFLAGS = -std=c++23 -Os -Wall -Wextra
LDFLAGS  = -s -Wl,--gc-sections -ffunction-sections -fdata-sections
SRC      = ./cmd/main.cpp
OUT      = ./bin/a.out

all: build

build:
	@mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run:
	@mkdir -p ./bin
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC) -o $(OUT)
	@echo "--- Running Program ---"
	@$(OUT)

start:
	@$(OUT)

clean:
	rm -rf ./bin
