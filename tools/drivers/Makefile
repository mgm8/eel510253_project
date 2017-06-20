TARGET=uart

ifndef BUILD_DIR
	BUILD_DIR=.
endif

CXX=g++
FLAGS=-std=c++11

$(BUILD_DIR)/$(TARGET).o: uart.cpp uart.h
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm $(BUILD_DIR)/*.o
