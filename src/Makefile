TARGET=src

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
LIBS=../
FLAGS=-Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -I$(LIBS)

$(TARGET).a: $(BUILD_DIR)/main.o $(BUILD_DIR)/voltmeter.o $(BUILD_DIR)/ammeter.o $(BUILD_DIR)/smart_cell.o $(BUILD_DIR)/packet.o
	ar rcs $(BUILD_DIR)/$@ $^

$(BUILD_DIR)/main.o: main.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD_DIR)/voltmeter.o: voltmeter.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD_DIR)/ammeter.o: ammeter.cpp ammeter.h
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD_DIR)/smart_cell.o: smart_cell.cpp smart_cell.h
	$(CXX) $(FLAGS) -c -o $@ $<

$(BUILD_DIR)/packet.o: packet.cpp packet.h
	$(CXX) $(FLAGS) -c -o $@ $<

clean:
	rm $(BUILD_DIR)/*.o $(BUILD_DIR)/*.a

