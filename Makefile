LANGUAGE=cpp
MAIN_FILE=main
TARGET=ssc

ifndef BUILD_DIR
	BUILD_DIR=build
endif

F_CPU=16000000UL
BAUD_RATE=115200
MCU=atmega328p
DEVICE_ADR=/dev/ttyACM0

CXX=avr-g++
FLAGS=-Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
OBJ_COPY=avr-objcopy
FLASHER=avrdude
PROGRAMMER=arduino

$(TARGET): $(BUILD_DIR)/drivers.a $(BUILD_DIR)/src.a
#	$(CXX) $^ -o $(BUILD_DIR)/$@
	$(CXX) $(FLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/74hc4051.o $(BUILD_DIR)/74hc4052.o $(BUILD_DIR)/adc.o $(BUILD_DIR)/gpio.o $(BUILD_DIR)/uart.o $(BUILD_DIR)/ammeter.o $(BUILD_DIR)/packet.o $(BUILD_DIR)/smart_cell.o $(BUILD_DIR)/voltmeter.o $(BUILD_DIR)/switch.o -o $(BUILD_DIR)/$@

$(BUILD_DIR)/drivers.a:
	mkdir -p $(BUILD_DIR)
	$(MAKE) BUILD_DIR=$(CURDIR)/$(BUILD_DIR) -C drivers

$(BUILD_DIR)/src.a:
	$(MAKE) BUILD_DIR=$(CURDIR)/$(BUILD_DIR) -C src

.PHONY:hex
hex:
	$(OBJ_COPY) -O ihex -R .eeprom $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).hex

.PHONY:flash
flash:
	$(FLASHER) -F -V -c $(PROGRAMMER) -p $(MCU) -P $(DEVICE_ADR) -b $(BAUD_RATE) -U flash:w:$(BUILD_DIR)/$(TARGET).hex

.PHONY:list
list:
	$(OBJ_COPY) -d $(BUILD_DIR)/$(TARGET) >$(BUILD_DIR)/$(TARGET).lst

.PHONY:backup
backup:
	mkdir -p backup
	$(FLASHER) -F -V -c $(PROGRAMMER) -p $(MCU) -P $(DEVICE_ADR) -b $(BAUD_RATE) -U flash:r:backup/flash_backup.hex:i

clean:
	rm -r $(BUILD_DIR)

