# name project
TAG := main

# name device
DEVICE := atmega8

# name compiler
GC := avr-gcc

# compiler flag
GCFLAG := -Wall
GCFLAG += -O3
GCFLAG += -std=c11
GCFLAG += -mmcu=$(DEVICE)

# avrdude
AD := avrdude

# avrdude flag
ADFLAG := -p $(DEVICE)
ADFLAG += -P usb
ADFLAG += -c usbasp

# include
INC := -I./

# source
SRC := *.c

# list mode
.PHONY: compile clean read write erase

# compile mode
release: $(TAG).bin
	@echo "[COMPILE]"

$(TAG).bin: $(SRC)
	@$(GC) $(INC) $(GCFLAG) $^ -o $@

# clean mode
clean:
	@echo "[CLEAN]"
	@rm $(TAG).bin

# read mode
read:
	@echo "[READ]"
	@$(AD) $(ADFLAG) -U flash:r:$(TAG).bin:r

# write mode
write:
	@echo "[WRITE]"
	@$(AD) $(ADFLAG) -U flash:w:$(TAG).bin

# erase mode
erase:
	@echo "[ERASE]"
	@$(AD) $(ADFLAG) -e
