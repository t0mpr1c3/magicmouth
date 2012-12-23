
# The name of the project
PRG            = magic_mouth_firmware
# Files owned by the user
OBJUSER        = magic_mouth_firmware.o 
# Files owned by the user to create pre-compiled headers
PCHUSER        = pch/magic_mouth_firmware.c 
# Generated files that are required
OBJREQD        = lib/gen_speech.o lib/lib_hardware.o lib/lib_timers.o lib/gen_clock.o lib/lib_timerdef.o lib/lib_iopins.o 
# Generated files that are optional
OBJOPT         = lib/opt_TimerCapture.o lib/opt_DeviceName.o lib/opt_pcint.o lib/opt_TimerOverflow.o lib/opt_TimerCompare.o 

# The processor target
MCU_TARGET     = atmega328p

# The processor speed
MCU_SPEED	   = 16000000

# The library where WebbotLib is installed
WEBBOT		   = webbotlibV2/webbotavrclib-2.09

# The library to link against
WEBBOT_LIB = $(WEBBOT)/libWebbot-ATmega328P.a


OPTIMIZE       = -Os
	

DEFS           = -gdwarf-2 -fpack-struct -fshort-enums  -funsigned-char -funsigned-bitfields -I"$(WEBBOT)" 
DEFS 		  +=  -MD -MP -MT $(*F).o -MF dep/$(@F).d


LIBS           = -L"$(WEBBOT)" -L"lib" -lWebbot-ATmega328P  -lPost -lm -lc
	


# Define the tools to be used
CC             = avr-gcc
CPP            = avr-g++
OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump
SIZE		   = avr-size
ARCHIVE		   = avr-ar

# Override is only needed by avr-lib build system.
# -Wall enable most warning errors
override CFLAGS        = -g -Wall  -DF_CPU=${MCU_SPEED} -mmcu=$(MCU_TARGET) $(DEFS)  -std=gnu99 
override CPPFLAGS      = -g -Wall  -DF_CPU=${MCU_SPEED} -mmcu=$(MCU_TARGET) $(DEFS) -fno-threadsafe-statics


# Use the minimal version of vfprintf
override LDFLAGS       = -Wl,-Map,$(PRG).map,-u,vfprintf -lprintf_min
	

# Default build target
all: $(PRG).elf lst text eeprom size

# Create pre-compiled headers for all the user files
pch: $(WEBBOT_LIB) $(PCHUSER)

pch/%.cpp: %.cpp
	$(CPP) -E $(CPPFLAGS) $(OPTIMIZE) -c -o $@ $<

pch/%.c: %.c
	$(CC) -E $(CFLAGS) $(OPTIMIZE) -c -o $@ $<

# How to create the elf file
$(PRG).elf: lib/libPost.a  $(WEBBOT_LIB) $(OBJUSER) $(OBJREQD)
	$(CC) -mmcu=$(MCU_TARGET) $(LDFLAGS) -o $@ $(OBJUSER) $(OBJREQD) $(LIBS)


# Create an archive for the optional items so they are only added if called
lib/libPost.a: $(OBJOPT)
	$(ARCHIVE) -r $@ $(OBJOPT)


# dependencies for compiling C files to O files

	
lib/opt_TimerCapture.o: lib/opt_TimerCapture.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/opt_TimerCapture.c
	
lib/opt_DeviceName.o: lib/opt_DeviceName.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/opt_DeviceName.c
	
lib/opt_pcint.o: lib/opt_pcint.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/opt_pcint.c
	
lib/opt_TimerOverflow.o: lib/opt_TimerOverflow.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/opt_TimerOverflow.c
	
lib/gen_speech.o: lib/gen_speech.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/gen_speech.c
	
lib/lib_hardware.o: lib/lib_hardware.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/lib_hardware.c
	
magic_mouth_firmware.o: magic_mouth_firmware.c
		$(CC) $(CFLAGS) $(OPTIMIZE) -c -o $@ magic_mouth_firmware.c
	
lib/lib_timers.o: lib/lib_timers.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/lib_timers.c
	
lib/gen_clock.o: lib/gen_clock.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/gen_clock.c
	
lib/lib_timerdef.o: lib/lib_timerdef.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/lib_timerdef.c
	
lib/lib_iopins.o: lib/lib_iopins.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/lib_iopins.c
	
lib/opt_TimerCompare.o: lib/opt_TimerCompare.c
		$(CC) $(CFLAGS) -Os -c -o $@ lib/opt_TimerCompare.c

# dependencies for compiling CPP files to O files


size: $(PRG).elf
	$(SIZE) --format=avr --mcu=${MCU_TARGET} $(PRG).elf	

# Clean the compiled stuff but leave any codegen'd files in place
clean:
	rm -rf *.o dep/* pch/* lib/*.o lib/*.a $(PRG).elf example.txt  
	rm -r dep
	rm -r pch
	rm -rf $(PRG).lst $(PRG).map $(EXTRA_CLEAN_FILES)

# Clean out everything - including any codegen'd files
cleanall:
	rm -rf *.o dep/* pch/* $(PRG).elf example.txt hardware.h  
	rm -r lib
	rm -rf $(PRG).lst $(PRG).map $(EXTRA_CLEAN_FILES)

lst:  $(PRG).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

# Rules for building the .text rom images
text: hex bin srec

hex:  $(PRG).hex
bin:  $(PRG).bin
srec: $(PRG).srec

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@

# Rules for building the .eeprom rom images
eeprom: ehex ebin esrec

ehex:  $(PRG)_eeprom.hex
ebin:  $(PRG)_eeprom.bin
esrec: $(PRG)_eeprom.srec

%_eeprom.hex: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@ \
	|| { echo empty $@ not generated; exit 0; }

%_eeprom.srec: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O srec $< $@ \
	|| { echo empty $@ not generated; exit 0; }

%_eeprom.bin: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O binary $< $@ \
	|| { echo empty $@ not generated; exit 0; }

EXTRA_CLEAN_FILES       = $(PRG).hex $(PRG)_eeprom.hex *.bin *.srec

## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)
-include $(shell mkdir pch 2>/dev/null) 

	