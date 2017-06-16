TARGET=uart

ifndef BUILD_DIR
	BUILD_DIR=.
endif

CXX=g++

$(BUILD_DIR)/$(TARGET).o: uart.cpp uart.h
	$(CXX) -c $< -o $@

clean:
	rm $(BUILD_DIR)/*.o
