TARGET=src

ifndef BUILD_DIR
	BUILD_DIR=.
endif

CXX=g++
LIBS=../
FLAGS=-std=c++11 -I$(LIBS)
GTKMM_FLAGS=`pkg-config --cflags --libs gtkmm-3.0`

all: $(BUILD_DIR)/main.o $(BUILD_DIR)/error.o $(BUILD_DIR)/global_var.o $(BUILD_DIR)/signals.o
	

$(BUILD_DIR)/main.o: main.cpp
	$(CXX) $(GTKMM_FLAGS) $(FLAGS) -c $< -o $@

$(BUILD_DIR)/error.o: error.cpp error.h
	$(CXX) $(GTKMM_FLAGS) $(FLAGS) -c $< -o $@

$(BUILD_DIR)/global_var.o: global_var.cpp global_var.h
	$(CXX) $(GTKMM_FLAGS) $(FLAGS) -c $< -o $@

$(BUILD_DIR)/signals.o: signals.cpp signals.h
	$(CXX) $(GTKMM_FLAGS) $(FLAGS) -c $< -o $@

clean:
	rm $(BUILD_DIR)/*.o

