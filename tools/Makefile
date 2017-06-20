SOURCE=main.cpp
TARGET=smart-panel-ctrl

ifndef BUILD_DIR
	BUILD_DIR=build
endif

CXX=g++
CPPFLAGS=-std=c++11
GTKMM_FLAGS=`pkg-config --cflags --libs gtkmm-3.0`

all:
	mkdir -p $(BUILD_DIR)
	$(MAKE) BUILD_DIR=$(CURDIR)/$(BUILD_DIR) -C drivers
	$(MAKE) BUILD_DIR=$(CURDIR)/$(BUILD_DIR) -C src
	$(CXX) $(CPPFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/uart.o $(BUILD_DIR)/error.o $(BUILD_DIR)/global_var.o $(BUILD_DIR)/signals.o -o $(BUILD_DIR)/$(TARGET).x $(GTKMM_FLAGS)

clean:
	rm -r $(BUILD_DIR)

