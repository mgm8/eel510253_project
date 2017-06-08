TARGET=drivers

ifndef F_CPU
	F_CPU=16000000UL
endif

ifndef MCU
	MCU=atmega328p
endif

ifndef BUILD_DIR
	BUILD_DIR=.
endif

CXX=avr-g++
FLAGS=-Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)

$(TARGET).a: $(BUILD_DIR)/74hc4051.o $(BUILD_DIR)/74hc4052.o $(BUILD_DIR)/gpio.o $(BUILD_DIR)/adc.o $(BUILD_DIR)/uart.o
	ar rcs $(BUILD_DIR)/$@ $^

$(BUILD_DIR)/74hc4051.o: 74hc4051.cpp 74hc4051.h
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD_DIR)/74hc4052.o: 74hc4052.cpp 74hc4052.h
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD_DIR)/gpio.o: gpio.cpp gpio.h
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD_DIR)/adc.o: adc.cpp adc.h
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD_DIR)/uart.o: uart.cpp uart.h
	$(CXX) $(FLAGS) -DF_OSC=$(F_CPU) -c -o $@ $<

clean:
	rm $(BUILD_DIR)/*.o $(BUILD_DIR)/*.a

